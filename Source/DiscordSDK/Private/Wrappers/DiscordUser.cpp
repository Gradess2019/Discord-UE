// Fill out your copyright notice in the Description page of Project Settings.


#include "Wrappers/DiscordUser.h"
#include "types.h"

void UDiscordUser::Init(const discord::User* InUser)
{
	User = InUser;
}

UTexture2D* UDiscordUser::GetAvatar()
{
	unimplemented();
	return nullptr;
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
