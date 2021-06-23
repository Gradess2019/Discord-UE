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
	UDiscordObject();

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category="Discord")
	void Update();

	static discord::Core* GetCore();
	
protected:
	UPROPERTY(BlueprintReadWrite, Category = "Discord")
	FTimerHandle UpdateTimer;
	
	static discord::Core* Core;
};
