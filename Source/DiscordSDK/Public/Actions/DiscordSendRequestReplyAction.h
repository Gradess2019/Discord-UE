// Created by Stepan Trofimov, 2021

#pragma once

#include "CoreMinimal.h"
#include "DiscordBaseAction.h"
#include "DiscordStructs.h"
#include "DiscordSendRequestReplyAction.generated.h"

/**
 * Send request reply in discord, like yes or no
 */
UCLASS()
class DISCORDSDK_API UDiscordSendRequestReplyAction : public UDiscordBaseAction
{
	GENERATED_BODY()

public:
	/**
	 * @brief Send request reply in discord
	 * @param UserId the user id of the person who asked to join
	 * @param Reply No, Yes, or Ignore
	 * @return action node
	 */
	UFUNCTION(
		BlueprintCallable,
		Category = "Discord|Actions",
		meta = (BlueprintInternalUseOnly = "true")
	)
	static UDiscordSendRequestReplyAction* SendRequestReply(
		const int64 UserId,
		const EDiscordActivityJoinRequestReply Reply
	);

	virtual void Activate() override;

private:
	/**
	 * @brief the user id of the person who asked to join
	 */
	UPROPERTY()
	int64 UserId;

	/**
	 * @brief No, Yes, or Ignore
	 */
	UPROPERTY()
	TEnumAsByte<EDiscordActivityJoinRequestReply> Reply;
};
