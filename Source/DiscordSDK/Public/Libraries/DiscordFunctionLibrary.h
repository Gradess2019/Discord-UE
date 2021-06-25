// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ffi.h"
#include "DiscordEnums.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "DiscordFunctionLibrary.generated.h"

class UDiscordUser;

/**
 * 
 */
UCLASS()
class DISCORDSDK_API UDiscordFunctionLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Discord|Conversions")
	static int64 StringToInt64(const FString& String);

	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Discord|Conversions")
	static FString Int64ToString(const int64& Number);

	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Discord|User")
	static UDiscordUser* GetCurrentUser(EDiscordActionResult& OutResult);

	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Discord|Conversions")
	static int64 GetUnixTimestamp(const FDateTime& DateTime);
};
