// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "CoreMinimal.h"

#include "DiscordEnums.h"
#include "DiscordStructs.h"
#include "DiscordSDK/Native/core.h"
#include "DiscordObject.generated.h"

class UDiscordUser;

DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FActivityInvite, EDiscordActivityActionType, Type, UDiscordUser*, User, FDiscordActivity, Activity);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FActivityJoin, FString, JoinSecret);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FActivitySpectate, FString, SpectateSecret);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FActivityJoinRequest, UDiscordUser*, User);

/**
 * 
 */
UCLASS(Blueprintable, BlueprintType)
class DISCORDSDK_API UDiscordObject : public UObject
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Discord|Core")
	void Init(
		const FDiscordActivityManagerData& ActivityManager
	);

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Discord|Core")
	void Update();

	// TODO: How can we avoid Singleton pattern here?
	static discord::Core* GetCore();

	virtual void BeginDestroy() override;

protected:
	UFUNCTION()
	void InitCore();

	UFUNCTION()
	void InitUserManager();

	UFUNCTION(BlueprintCallable, Category = "Discord|Core")
	EDiscordActionResult InitActivityManager(const FDiscordActivityManagerData& ActivityManager);

	UFUNCTION()
	void InitTimer(UWorld* World);

public:
	UPROPERTY(BlueprintAssignable, Category = "Discord|Core")
	FActivityInvite OnActivityInvite;
	
	UPROPERTY(BlueprintAssignable, Category = "Discord|Core")
	FActivityJoin OnActivityJoin;
	
	UPROPERTY(BlueprintAssignable, Category = "Discord|Core")
	FActivitySpectate OnActivitySpectate;
	
	UPROPERTY(BlueprintAssignable, Category = "Discord|Core")
	FActivityJoinRequest OnActivityJoinRequest;
	
protected:
	void OnActivityInviteCallback(
		discord::ActivityActionType Type,
		discord::User const& User,
		discord::Activity const& Activity
	);

	void OnActivityJoinCallback(
		char const* JoinSecret
	);
	
	void OnActivitySpectateCallback(
		char const* SpectateSecret
	);
	
	void OnActivityJoinRequestCallback(
		discord::User const& User
	);
	

	UPROPERTY(BlueprintReadWrite, Category = "Discord|Core")
	FTimerHandle UpdateTimer;

	static discord::Core* Core;
};
