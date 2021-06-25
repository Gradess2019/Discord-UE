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

	Core->UserManager().OnCurrentUserUpdate.Connect([&]()
	{
		UE_LOG(LogTemp, Log, TEXT("User manager initialized"));
		Core->UserManager().OnCurrentUserUpdate.DisconnectAll();
	});
}

discord::Core* UDiscordObject::GetCore() { return Core; }

void UDiscordObject::BeginDestroy()
{
	delete Core;
	Core = nullptr;

	Super::BeginDestroy();
}

void UDiscordObject::Update_Implementation()
{
	if (!Core) { return; }
	Core->RunCallbacks();
}
