// Fill out your copyright notice in the Description page of Project Settings.


#include "DiscordObject.h"

void UDiscordObject::Start()
{
	auto result = discord::Core::Create(856990392405590106, DiscordCreateFlags_Default, &Core);
	discord::Activity activity{};
	activity.SetState("Тестируем");
	activity.SetDetails("Кушаем чай и пьём конфеты, никакого суецыда");
	Core->ActivityManager().UpdateActivity(activity, [](discord::Result result)
	{
		UE_LOG(LogTemp, Warning, TEXT("UPDATE ACTIVITY %d"), result)
	});
}

void UDiscordObject::Stop()
{
	Core->ActivityManager().ClearActivity([&](discord::Result result)
	{
		UE_LOG(LogTemp, Warning, TEXT("CLEAR ACTIVITY %d"), result)
		delete Core;
		Core = nullptr;
	});
}

void UDiscordObject::Update_Implementation()
{
	if (!Core) { return; }
	Core->RunCallbacks();
}
