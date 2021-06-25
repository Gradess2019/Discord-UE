// Fill out your copyright notice in the Description page of Project Settings.


#include "Wrappers/DiscordUser.h"

#include "HttpModule.h"
#include "types.h"
#include "Interfaces/IHttpResponse.h"

void UDiscordUser::Init(const discord::User* InUser)
{
	User = InUser;
}

FString UDiscordUser::GetAvatarHash()
{
	return FString(User->GetAvatar());
}

void UDiscordUser::GetAvatar()
{
	
}

bool UDiscordUser::IsBot()
{
	return User->GetBot();
}

FString UDiscordUser::GetDiscriminator()
{
	return FString(User->GetDiscriminator());
}

int64 UDiscordUser::GetId()
{
	return User->GetId();
}

FString UDiscordUser::GetUsername()
{
	return FString(User->GetUsername());
}

void UDiscordUser::BeginDestroy()
{
	delete User;
	User = nullptr;

	Super::BeginDestroy();
}
