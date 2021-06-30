// Created by Stepan Trofimov, 2021

#pragma once

#include "CoreMinimal.h"
#include "DiscordBaseAction.h"
#include "DiscordClearActivityAction.generated.h"

/**
 * Clear current user's activity in discord
 */
UCLASS()
class DISCORDSDK_API UDiscordClearActivityAction : public UDiscordBaseAction
{
	GENERATED_BODY()

public:
	/**
	 * @brief Clear current user's activity in discord
	 * @return Action node
	 */
	UFUNCTION(
		BlueprintCallable,
		meta = (BlueprintInternalUseOnly = "true")
	)
	static UDiscordClearActivityAction* ClearActivity();

	virtual void Activate() override;
};
