// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "DiscordBaseAction.h"
#include "DiscordAcceptInviteAction.generated.h"

/**
 * Accepts a game invitation from a given userId
 */
UCLASS()
class DISCORDSDK_API UDiscordAcceptInviteAction : public UDiscordBaseAction
{
	GENERATED_BODY()

public:
	/**
	 * @brief Accepts a game invitation from a given userId
	 * @param UserId Sender's user id
	 * @return Action node
	 */
	UFUNCTION(
		BlueprintCallable,
		meta = (BlueprintInternalUseOnly = "true")
	)
	static UDiscordAcceptInviteAction* AcceptInvite(const int64 UserId);

	virtual void Activate() override;

protected:
	/**
	 * @brief Sender's user id
	 */
	UPROPERTY()
	int64 UserId;
};
