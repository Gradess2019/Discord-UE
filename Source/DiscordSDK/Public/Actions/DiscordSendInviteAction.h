// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "DiscordBaseAction.h"
#include "DiscordStructs.h"
#include "DiscordSendInviteAction.generated.h"

/**
 * 
 */
UCLASS()
class DISCORDSDK_API UDiscordSendInviteAction : public UDiscordBaseAction
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintAssignable)
	FDiscordActionPin Finished;

	UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true"))
	static UDiscordSendInviteAction* SendInvite(const FDiscordSendInviteData& Data);

	virtual void Activate() override;

protected:
	UPROPERTY()
	FDiscordSendInviteData Data;
};
