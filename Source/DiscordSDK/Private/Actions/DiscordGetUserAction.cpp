// Fill out your copyright notice in the Description page of Project Settings.


#include "Actions/DiscordGetUserAction.h"
#include "Wrappers/DiscordUser.h"
#include "DiscordObject.h"
#include "types.h"

UDiscordGetUserAction* UDiscordGetUserAction::GetUser(const int64 UserId)
{
	const auto Node = NewObject<UDiscordGetUserAction>();
	Node->UserId = UserId;
	return Node;
}

void UDiscordGetUserAction::Activate()
{
	auto Core = UDiscordObject::GetCore();
	if (!Core) { return; }

	Core->UserManager().GetUser(UserId, [&](discord::Result Result, const discord::User& User)
	{
		auto DiscordUser = NewObject<UDiscordUser>();
		DiscordUser->Init(&User);
		Finished.Broadcast(static_cast<EDiscordActionResult>(Result), DiscordUser);
	});
}
