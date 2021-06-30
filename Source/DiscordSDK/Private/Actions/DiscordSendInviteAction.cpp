// Created by Stepan Trofimov, 2021


#include "Actions/DiscordSendInviteAction.h"

#include "DiscordObject.h"
#include "types.h"

UDiscordSendInviteAction* UDiscordSendInviteAction::SendInvite(
	const FDiscordSendInviteData& Data
)
{
	UDiscordSendInviteAction* Node = NewObject<UDiscordSendInviteAction>();
	Node->Data = Data;
	return Node;
}

void UDiscordSendInviteAction::Activate()
{
	auto Core = UDiscordObject::GetCore();
	if (!Core) { return; }

	Core->ActivityManager().SendInvite(
		Data.UserId,
		static_cast<discord::ActivityActionType>(Data.Type.GetValue()),
		TCHAR_TO_ANSI(*Data.Content),
		[&](const discord::Result Result)
		{
			Finished.Broadcast(static_cast<EDiscordActionResult>(Result));
		}
	);
}
