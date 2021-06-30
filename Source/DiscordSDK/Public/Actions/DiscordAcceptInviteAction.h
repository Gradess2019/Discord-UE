// Created by Stepan Trofimov, 2021

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
		Category = "Discord|Actions",
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
