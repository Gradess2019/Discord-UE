// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "CoreMinimal.h"
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
	UFUNCTION(BlueprintCallable, Category="Discord")
	void Start();

	UFUNCTION(BlueprintCallable, Category="Discord")
	void Stop();

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category="Discord")
	void Update();

	protected:
	discord::Core* Core;
};
