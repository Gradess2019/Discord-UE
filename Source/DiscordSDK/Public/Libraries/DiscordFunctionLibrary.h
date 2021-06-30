// Created by Stepan Trofimov, 2021

#pragma once

#include "CoreMinimal.h"
#include "ffi.h"
#include "DiscordEnums.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "DiscordFunctionLibrary.generated.h"

class UDiscordUser;

UCLASS()
class DISCORDSDK_API UDiscordFunctionLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

	/**
	 * @brief Convert FString to int64
	 * @param String string to convert
	 * @return result int64
	 */
	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Discord|Conversions")
	static int64 StringToInt64(const FString& String);

	/**
	 * @brief Convert int64 to FString
	 * @param Number number to convert
	 * @return result string
	 */
	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Discord|Conversions")
	static FString Int64ToString(const int64& Number);

	/**
	 * @brief Convert FText to int64
	 * @param Text text to convert
	 * @return result int64
	 */
	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Discord|Conversions")
	static int64 TextToInt64(const FText& Text);

	/**
	 * @brief Convert int64 to FText
	 * @param Number number to convert
	 * @return result text
	 */
	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Discord|Conversions")
	static FText Int64ToText(const int64& Number);

	/**
	 * @brief Return current discord user
	 * @param OutResult action result
	 * @return current discord user
	 */
	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Discord|User")
	static UDiscordUser* GetCurrentUser(EDiscordActionResult& OutResult);

	/**
	 * @brief Convert DateTime to UNIX timestamp
	 * @param DateTime DateTime to convert
	 * @return result UNIX time
	 */
	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Discord|Conversions")
	static int64 GetUnixTimestamp(const FDateTime& DateTime);
};
