// Created by Stepan Trofimov, 2021.


#include "Actions/DiscordUpdateActivityAction.h"

#include "DiscordObject.h"
#include "types.h"

UDiscordUpdateActivityAction* UDiscordUpdateActivityAction::UpdateActivity(
	const FDiscordActivity& Activity
)
{
	UDiscordUpdateActivityAction* Node = NewObject<UDiscordUpdateActivityAction>();
	Node->Activity = Activity;
	return Node;
}

void UDiscordUpdateActivityAction::Activate()
{
	auto Core = UDiscordObject::GetCore();
	if (!Core) { return; }

	const auto NewActivity = Activity.Create();

	Core->ActivityManager().UpdateActivity(*NewActivity, [&](discord::Result Result)
	{
		Finished.Broadcast(static_cast<EDiscordActionResult>(Result));
	});
}
