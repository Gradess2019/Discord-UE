// Created by Stepan Trofimov, 2021

#pragma once

#include "CoreMinimal.h"
#include "DiscordEnums.h"
#include "Kismet/BlueprintAsyncActionBase.h"
#include "DiscordBaseAction.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(
	FDiscordActionPin,
	EDiscordActionResult, Result
);

/**
 * Base discord async action node
 */
UCLASS()
class DISCORDSDK_API UDiscordBaseAction : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

public:
	/**
	* @brief Fires when the action is completed
	*/
	UPROPERTY(
		BlueprintAssignable,
		Category = "Discord|Actions"
	)
	FDiscordActionPin Finished;
};
