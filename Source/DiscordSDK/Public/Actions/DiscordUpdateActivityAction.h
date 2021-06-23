// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "DiscordBaseAction.h"
#include "types.h"

#include "DiscordUpdateActivityAction.generated.h"

/**
 * 
 */
UCLASS()
class DISCORDSDK_API UDiscordUpdateActivityAction : public UDiscordBaseAction
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintAssignable)
	FDiscordActionPin Finished;

	UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true", WorldContext = "WorldContextObject"))
	static UDiscordUpdateActivityAction* UpdateActivity(
		const FString State,
		const FString Details
	);

	virtual void Activate() override;

private:
	UPROPERTY()
	FString State;

	UPROPERTY()
	FString Details;
	
};
