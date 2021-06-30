// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintAsyncActionBase.h"
#include "DiscordEnums.h"
#include "types.h"
#include "Wrappers/DiscordUser.h"
#include "DiscordGetUserAction.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FDiscordUserActionPin, EDiscordActionResult, Result, UDiscordUser*, User);

/**
 * Get user by user's id
 */
UCLASS()
class DISCORDSDK_API UDiscordGetUserAction : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

public:
	/**
	 * @brief Get user by user's id
	 * @param UserId Target user's id
	 * @return Action Node
	 */
	UFUNCTION(
		BlueprintCallable,
		meta = (BlueprintInternalUseOnly = "true")
	)
	static UDiscordGetUserAction* GetUser(
		const int64 UserId
	);

	virtual void Activate() override;

	/**
	 * @brief Fires when action is finished
	 */
	UPROPERTY(
		BlueprintAssignable
	)
	FDiscordUserActionPin Finished;

protected:
	/**
	 * @brief Target user's id
	 */
	discord::UserId UserId;
};
