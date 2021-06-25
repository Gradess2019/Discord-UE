// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "DiscordBaseAction.h"
#include "DiscordAcceptInviteAction.generated.h"

/**
 * 
 */
UCLASS()
class DISCORDSDK_API UDiscordAcceptInviteAction : public UDiscordBaseAction
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintAssignable)
	FDiscordActionPin Finished;

	UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true"))
	static UDiscordAcceptInviteAction* AcceptInvite(const int64 UserId);

	virtual void Activate() override;

protected:
	UPROPERTY()
	int64 UserId;
};
