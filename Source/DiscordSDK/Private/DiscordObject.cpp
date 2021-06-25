// Fill out your copyright notice in the Description page of Project Settings.


#include "DiscordObject.h"

discord::Core* UDiscordObject::Core = nullptr;

void UDiscordObject::Init_Implementation(const FDiscordActivityManagerData& ActivityManager)
{
	const auto Outer = GetOuter();
	if (!Outer) { return; }

	const auto World = Outer->GetWorld();
	if (!World || !World->IsGameWorld()) { return; }

	InitCore();
	InitUserManager();
	InitActivityManager(ActivityManager);
	InitTimer(World);
}

void UDiscordObject::InitCore()
{
	discord::Core::Create(856990392405590106, DiscordCreateFlags_Default, &UDiscordObject::Core);
}

void UDiscordObject::InitUserManager()
{
	Core->UserManager().OnCurrentUserUpdate.Connect([&]()
	{
		UE_LOG(LogTemp, Warning, TEXT("User manager initialized"));
		Core->UserManager().OnCurrentUserUpdate.DisconnectAll();
	});
}

EDiscordActionResult UDiscordObject::InitActivityManager(const FDiscordActivityManagerData& ActivityManager)
{
	discord::Result Result = discord::Result::NotFound;
	
	if (!ActivityManager.Command.IsEmpty())
	{
		Result = Core->ActivityManager().RegisterCommand(TCHAR_TO_ANSI(*ActivityManager.Command));
	} else if (ActivityManager.SteamAppId > 0)
	{
		Result = Core->ActivityManager().RegisterSteam(ActivityManager.SteamAppId);
	}

	return static_cast<EDiscordActionResult>(Result);
}

void UDiscordObject::InitTimer(UWorld* World)
{
	World->GetTimerManager().SetTimer(
		UpdateTimer,
		this,
		&UDiscordObject::Update,
		0.05f,
		true
	);
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
