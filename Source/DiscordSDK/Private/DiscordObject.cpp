// Fill out your copyright notice in the Description page of Project Settings.


#include "DiscordObject.h"

discord::Core* UDiscordObject::Core = nullptr;

UDiscordObject::UDiscordObject()
{
	const auto Outer = GetOuter();
	if (!Outer) { return; }

	const auto World = Outer->GetWorld();
	if (!World || !World->IsGameWorld()) { return; }

	discord::Core::Create(856990392405590106, DiscordCreateFlags_Default, &UDiscordObject::Core);
	World->GetTimerManager().SetTimer(
		UpdateTimer,
		this,
		&UDiscordObject::Update,
		0.05f,
		true
	);
}

discord::Core* UDiscordObject::GetCore()
{
	return Core;
}

void UDiscordObject::Update_Implementation()
{
	if (!Core) { return; }
	Core->RunCallbacks();
}
