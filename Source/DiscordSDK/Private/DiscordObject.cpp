// Created by Stepan Trofimov, 2021


#include "DiscordObject.h"
#include "Engine/World.h"
#include "Wrappers/DiscordUser.h"
#include "GenericPlatform/GenericPlatformMisc.h"

discord::Core* UDiscordObject::Core = nullptr;

void UDiscordObject::Init_Implementation(
	const FDiscordActivityManagerData& ActivityManager,
	const int64 AppId,
	const int32 DiscordInstanceId
)
{
	const auto Outer = GetOuter();
	if (!Outer) { return; }

	const auto World = Outer->GetWorld();
	if (!World || !World->IsGameWorld()) { return; }

	FPlatformMisc::SetEnvironmentVar(ANSI_TO_TCHAR("DISCORD_INSTANCE_ID"), *FString::FromInt(DiscordInstanceId));
	InitCore(AppId);
	InitUserManager();
	InitActivityManager(ActivityManager);
	InitTimer(World);
}

void UDiscordObject::InitCore(int64 AppId)
{
	discord::Core::Create(AppId, DiscordCreateFlags_Default, &UDiscordObject::Core);
}

void UDiscordObject::InitUserManager()
{
	Core->UserManager().OnCurrentUserUpdate.Connect([&]()
	{
		UE_LOG(LogTemp, Warning, TEXT("User manager initialized"));
		Core->UserManager().OnCurrentUserUpdate.DisconnectAll();
	});
}

EDiscordActionResult UDiscordObject::InitActivityManager(
	const FDiscordActivityManagerData& ActivityManager
)
{
	discord::Result Result = discord::Result::NotFound;

	if (!ActivityManager.Command.IsEmpty())
	{
		Result = Core->ActivityManager().RegisterCommand(TCHAR_TO_ANSI(*ActivityManager.Command));
	}
	else if (ActivityManager.SteamAppId > 0)
	{
		Result = Core->ActivityManager().RegisterSteam(ActivityManager.SteamAppId);
	}

	const auto OnActivityInviteCallback = std::bind(
		&UDiscordObject::OnActivityInviteCallback,
		this,
		std::placeholders::_1,
		std::placeholders::_2,
		std::placeholders::_3
	);

	const auto OnActivityJoinCallback = std::bind(
		&UDiscordObject::OnActivityJoinCallback,
		this,
		std::placeholders::_1
	);

	const auto OnActivitySpectateCallback = std::bind(
		&UDiscordObject::OnActivitySpectateCallback,
		this,
		std::placeholders::_1
	);
	
	const auto OnActivityJoinRequestCallback = std::bind(
		&UDiscordObject::OnActivityJoinRequestCallback,
		this,
		std::placeholders::_1
	);

	Core->ActivityManager().OnActivityInvite.Connect(OnActivityInviteCallback);
	Core->ActivityManager().OnActivityJoin.Connect(OnActivityJoinCallback);
	Core->ActivityManager().OnActivitySpectate.Connect(OnActivitySpectateCallback);
	Core->ActivityManager().OnActivityJoinRequest.Connect(OnActivityJoinRequestCallback);

	return static_cast<EDiscordActionResult>(Result);
}

void UDiscordObject::InitTimer(
	UWorld* World
)
{
	World->GetTimerManager().SetTimer(
		UpdateTimer,
		this,
		&UDiscordObject::Update,
		0.05f,
		true
	);
}

void UDiscordObject::Update_Implementation()
{
	if (!Core) { return; }
	Core->RunCallbacks();
}

discord::Core* UDiscordObject::GetCore() { return Core; }

void UDiscordObject::BeginDestroy()
{
	delete Core;
	Core = nullptr;

	Super::BeginDestroy();
}

void UDiscordObject::OnActivityInviteCallback(
	discord::ActivityActionType Type,
	discord::User const& User,
	discord::Activity const& Activity
)
{
	const auto DiscordType = static_cast<EDiscordActivityActionType>(Type);

	auto DiscordUser = NewObject<UDiscordUser>();
	DiscordUser->Init(&User);

	OnActivityInvite.Broadcast(DiscordType, DiscordUser, FDiscordActivity());
}

void UDiscordObject::OnActivityJoinCallback(
	char const* JoinSecret
)
{
	OnActivityJoin.Broadcast(FString(JoinSecret));
}

void UDiscordObject::OnActivitySpectateCallback(
	char const* SpectateSecret
)
{
	OnActivitySpectate.Broadcast(FString(SpectateSecret));
}

void UDiscordObject::OnActivityJoinRequestCallback(
	discord::User const& User
)
{
	auto DiscordUser = NewObject<UDiscordUser>();
	DiscordUser->Init(&User);
	
	OnActivityJoinRequest.Broadcast(DiscordUser);
}
