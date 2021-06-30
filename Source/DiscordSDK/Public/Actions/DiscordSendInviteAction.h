// Created by Stepan Trofimov, 2021

#pragma once

#include "CoreMinimal.h"
#include "DiscordBaseAction.h"
#include "DiscordStructs.h"
#include "DiscordSendInviteAction.generated.h"

/**
 * Send a game invite to a given user. If you do not have a valid activity with all the required fields, this call will error
 */
UCLASS()
class DISCORDSDK_API UDiscordSendInviteAction : public UDiscordBaseAction
{
	GENERATED_BODY()

public:
	/**
	 * @brief Send a game invite to a given user
	 * @param Data User id, type and message
	 * @return Action node
	 */
	UFUNCTION(
		BlueprintCallable,
		Category = "Discord|Actions",
		meta = (BlueprintInternalUseOnly = "true")
	)
	static UDiscordSendInviteAction* SendInvite(
		const FDiscordSendInviteData& Data
	);

	virtual void Activate() override;

protected:
	/**
	 * @brief User id, type and message
	 */
	UPROPERTY()
	FDiscordSendInviteData Data;
};
