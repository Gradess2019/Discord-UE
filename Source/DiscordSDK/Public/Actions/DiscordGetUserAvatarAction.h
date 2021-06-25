// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "DiscordBaseAction.h"
#include "types.h"
#include "DiscordGetUserAvatarAction.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FDiscordUserAvatarPin, UTexture2D*, Avatar);

/**
 * 
 */
UCLASS()
class DISCORDSDK_API UDiscordGetUserAvatarAction : public UDiscordBaseAction
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintAssignable)
	FDiscordUserAvatarPin Finished;

	UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true"))
	static UDiscordGetUserAvatarAction* GetUserAvatar(const int64 UserId);

	virtual void Activate() override;
};
