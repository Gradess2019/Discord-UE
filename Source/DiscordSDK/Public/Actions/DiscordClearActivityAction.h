// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "DiscordBaseAction.h"
#include "DiscordClearActivityAction.generated.h"

/**
 * 
 */
UCLASS()
class DISCORDSDK_API UDiscordClearActivityAction : public UDiscordBaseAction
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintAssignable)
	FDiscordActionPin Finished;

	UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true"))
	static UDiscordClearActivityAction* ClearActivity();

	virtual void Activate() override;
};
