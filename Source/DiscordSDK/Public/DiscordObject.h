// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "CoreMinimal.h"

#include "DiscordStructs.h"
#include "DiscordSDK/Native/core.h"
#include "DiscordObject.generated.h"

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
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Discord|Core")
	void Update();


	// TODO: How can we avoid Singleton pattern here?
	static discord::Core* GetCore();

	virtual void BeginDestroy() override;

protected:
	UPROPERTY(BlueprintReadWrite, Category = "Discord|Core")
	FTimerHandle UpdateTimer;

	static discord::Core* Core;
};
