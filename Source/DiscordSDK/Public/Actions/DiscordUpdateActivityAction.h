// Created by Stepan Trofimov, 2021

#pragma once

#include "CoreMinimal.h"
#include "DiscordBaseAction.h"
#include "DiscordStructs.h"
#include "types.h"

#include "DiscordUpdateActivityAction.generated.h"

/**
 * Updates current user activity in discord, like a game, state, etc.
 */
UCLASS()
class DISCORDSDK_API UDiscordUpdateActivityAction : public UDiscordBaseAction
{
	GENERATED_BODY()

public:
	/**
	 * @brief Updates current user activity
	 * @param Activity activity to set
	 * @return action node
	 */
	UFUNCTION(
		BlueprintCallable,
		meta = (BlueprintInternalUseOnly = "true")
	)
	static UDiscordUpdateActivityAction* UpdateActivity(const FDiscordActivity& Activity);

	virtual void Activate() override;

private:
	/**
	 * @brief Activity to use while update
	 */
	UPROPERTY()
	FDiscordActivity Activity;
};
