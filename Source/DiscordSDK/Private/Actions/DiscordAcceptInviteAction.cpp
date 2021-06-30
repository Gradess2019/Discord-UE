// Created by Stepan Trofimov, 2021


#include "Actions/DiscordAcceptInviteAction.h"

#include "DiscordObject.h"
#include "types.h"

UDiscordAcceptInviteAction* UDiscordAcceptInviteAction::AcceptInvite(const int64 UserId)
{
	UDiscordAcceptInviteAction* Node = NewObject<UDiscordAcceptInviteAction>();
	Node->UserId = UserId;
	return Node;
}

void UDiscordAcceptInviteAction::Activate()
{
	auto Core = UDiscordObject::GetCore();
	if (!Core) { return; }

	Core->ActivityManager().AcceptInvite(
		UserId,
		[&](const discord::Result Result)
		{
			Finished.Broadcast(static_cast<EDiscordActionResult>(Result));
		}
	);
}
