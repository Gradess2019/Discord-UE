// Fill out your copyright notice in the Description page of Project Settings.


#include "Actions/DiscordSendRequestReplyAction.h"

#include "DiscordObject.h"
#include "types.h"

UDiscordSendRequestReplyAction* UDiscordSendRequestReplyAction::SendRequestReply(
	const int64 UserId,
	const EDiscordActivityJoinRequestReply Reply
)
{
	UDiscordSendRequestReplyAction* Node = NewObject<UDiscordSendRequestReplyAction>();
	Node->UserId = UserId;
	Node->Reply = Reply;
	return Node;
}

void UDiscordSendRequestReplyAction::Activate()
{
	auto Core = UDiscordObject::GetCore();
	if (!Core) { return; }

	const auto UserReply = static_cast<discord::ActivityJoinRequestReply>(Reply.GetValue());
	Core->ActivityManager().SendRequestReply(UserId, UserReply, [&](discord::Result Result)
	{
		Finished.Broadcast(static_cast<EDiscordActionResult>(Result));
	});
}
