// Fill out your copyright notice in the Description page of Project Settings.


#include "Actions/DiscordUpdateActivityAction.h"

#include "DiscordObject.h"
#include "types.h"

UDiscordUpdateActivityAction* UDiscordUpdateActivityAction::UpdateActivity(
	const FString State,
	const FString Details
)
{
	UDiscordUpdateActivityAction* Node = NewObject<UDiscordUpdateActivityAction>();
	Node->State = State;
	Node->Details = Details;
	return Node;
}

void UDiscordUpdateActivityAction::Activate()
{
	auto Core = UDiscordObject::GetCore();
	if (!Core) { return; }

	discord::Activity activity{};

	const auto ConvertedState = StringCast<ANSICHAR>(*State).Get();
	const auto ConvertedDetails = StringCast<ANSICHAR>(*Details).Get();
	
	activity.SetState(ConvertedState);
	activity.SetDetails(ConvertedDetails);
	
	Core->ActivityManager().UpdateActivity(activity, [&](discord::Result Result)
	{
		Finished.Broadcast(static_cast<EDiscordActionResult>(Result));
	});
}
