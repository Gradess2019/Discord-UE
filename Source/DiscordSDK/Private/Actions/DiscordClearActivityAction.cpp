// Created by Stepan Trofimov, 2021


#include "Actions/DiscordClearActivityAction.h"

#include "DiscordObject.h"
#include "types.h"

UDiscordClearActivityAction* UDiscordClearActivityAction::ClearActivity()
{
	UDiscordClearActivityAction* Node = NewObject<UDiscordClearActivityAction>();
	return Node;
}

void UDiscordClearActivityAction::Activate()
{
	auto Core = UDiscordObject::GetCore();
	if (!Core) { return; }

	Core->ActivityManager().ClearActivity([&](discord::Result Result)
	{
		Finished.Broadcast(static_cast<EDiscordActionResult>(Result));
	});
}
