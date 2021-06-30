// Created by Stepan Trofimov, 2021

#pragma once
#include "CoreMinimal.h"
#include "Engine/EngineTypes.h"
#include "TimerManager.h"
#include "DiscordEnums.h"
#include "DiscordStructs.h"
#include "DiscordSDK/Native/core.h"
#include "DiscordObject.generated.h"

class UWorld;
class UDiscordUser;

DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(
	FActivityInvite,
	EDiscordActivityActionType, Type,
	UDiscordUser*, User,
	FDiscordActivity, Activity
);

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(
	FActivityJoin,
	FString, JoinSecret
);

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(
	FActivitySpectate,
	FString, SpectateSecret
);

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(
	FActivityJoinRequest,
	UDiscordUser*, User
);

/**
 * A "bridge" between UE4 and discord for interaction with Discord app
 */
UCLASS(Blueprintable, BlueprintType)
class DISCORDSDK_API UDiscordObject : public UObject
{
	GENERATED_BODY()

public:
	/**
	 * @brief Initialize discord object
	 * @param ActivityManager Manager data that will be used in discord
	 * @param AppId Application id at https://discord.com/developers/applications
	 */
	UFUNCTION(
		BlueprintNativeEvent,
		BlueprintCallable,
		Category = "Discord|Core"
	)
	void Init(
		const FDiscordActivityManagerData& ActivityManager,
		const int64 AppId
	);

protected:
	/**
	 * @brief Initialize core discord object
	 * @param AppId Application id at https://discord.com/developers/applications
	 */
	UFUNCTION()
	void InitCore(
		int64 AppId
	);

	/**
	 * @brief Initialize discord user manager
	 */
	UFUNCTION()
	void InitUserManager();

	/**
	 * @brief Initialize discord activity manager
	 * @param ActivityManager Manager data that will be used in discord
	 * @return action result, like "ok", "failed", etc.
	 */
	UFUNCTION(
		BlueprintCallable,
		Category = "Discord|Core"
	)
	EDiscordActionResult InitActivityManager(
		const FDiscordActivityManagerData& ActivityManager
	);

	/**
	 * @brief Initialize timer for calling RunCallbacks() in Discord
	 * @param World World to get timer manager
	 */
	UFUNCTION()
	void InitTimer(
		UWorld* World
	);

public:
	/**
	 * @brief Used for calling RunCallbacks() in Discord
	 */
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Discord|Core")
	void Update();

	// TODO: How can we avoid Singleton pattern here?
	/**
	 * @brief Return discord core object to interact with
	 * @return discord core object
	 */
	static discord::Core* GetCore();

	virtual void BeginDestroy() override;


	/**
	 * @brief Fires when the user receives a join or spectate invite
	 */
	UPROPERTY(BlueprintAssignable, Category = "Discord|Core")
	FActivityInvite OnActivityInvite;

	/**
	 * @brief Fires when a user accepts a game chat invite or receives confirmation from Asking to Join
	 */
	UPROPERTY(BlueprintAssignable, Category = "Discord|Core")
	FActivityJoin OnActivityJoin;

	/**
	 * @brief Fires when a user accepts a spectate chat invite or clicks the Spectate button on a user's profile
	 */
	UPROPERTY(BlueprintAssignable, Category = "Discord|Core")
	FActivitySpectate OnActivitySpectate;

	/**
	 * @brief Fires when a user asks to join the current user's game
	 */
	UPROPERTY(BlueprintAssignable, Category = "Discord|Core")
	FActivityJoinRequest OnActivityJoinRequest;

protected:
	/**
	 * @brief Fires when the user receives a join or spectate invite
	 * @param Type whether this invite is to join or spectate
	 * @param User the user sending the invite
	 * @param Activity the inviting user's current activity
	 */
	void OnActivityInviteCallback(
		discord::ActivityActionType Type,
		discord::User const& User,
		discord::Activity const& Activity
	);

	/**
	 * @brief Fires when a user accepts a game chat invite or receives confirmation from Asking to Join
	 * @param JoinSecret the secret to join the user's game
	 */
	void OnActivityJoinCallback(
		char const* JoinSecret
	);

	/**
	 * @brief Fires when a user accepts a spectate chat invite or clicks the Spectate button on a user's profile
	 * @param SpectateSecret the secret to join the user's game as a spectator
	 */
	void OnActivitySpectateCallback(
		char const* SpectateSecret
	);

	/**
	 * @brief Fires when a user asks to join the current user's game
	 * @param User the user asking to join
	 */
	void OnActivityJoinRequestCallback(
		discord::User const& User
	);


	/**
	 * @brief Timer handler for calling Update()
	 */
	UPROPERTY(BlueprintReadWrite, Category = "Discord|Core")
	FTimerHandle UpdateTimer;

	/**
	 * @brief Current discord core object
	 */
	static discord::Core* Core;
};
