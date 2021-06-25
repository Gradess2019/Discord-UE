// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "DiscordBaseAction.h"
#include "types.h"
#include "Wrappers/DiscordUser.h"
#include "DiscordGetUserAction.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FDiscordUserActionPin, EDiscordActionResult, Result, UDiscordUser*, User);

/**
 * 
 */
UCLASS()
class DISCORDSDK_API UDiscordGetUserAction : public UDiscordBaseAction
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintAssignable)
	FDiscordUserActionPin Finished;

	UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true"))
	static UDiscordGetUserAction* GetUser(const int64 UserId);

	virtual void Activate() override;

protected:
	discord::UserId UserId;
};
