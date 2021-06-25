// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "DiscordFunctionLibrary.generated.h"

/**
 * 
 */
UCLASS()
class DISCORDSDK_API UDiscordFunctionLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Discord")
	static int64 StringToInt64(const FString& String);

	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Discord")
	static FString Int64ToString(const int64& Number);

};
