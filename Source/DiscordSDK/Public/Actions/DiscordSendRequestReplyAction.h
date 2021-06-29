// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "DiscordBaseAction.h"
#include "DiscordStructs.h"
#include "DiscordSendRequestReplyAction.generated.h"

/**
 * 
 */
UCLASS()
class DISCORDSDK_API UDiscordSendRequestReplyAction : public UDiscordBaseAction
{
	GENERATED_BODY()

public:
	UPROPERTY(
		BlueprintAssignable,
		Category = "Discord|Actions"
	)
	FDiscordActionPin Finished;

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
	UPROPERTY()
	int64 UserId;

	UPROPERTY()
	TEnumAsByte<EDiscordActivityJoinRequestReply> Reply;
};
