// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "DiscordUser.generated.h"

namespace discord
{
	class User;
}

/**
 * 
 */
UCLASS(Blueprintable, BlueprintType)
class DISCORDSDK_API UDiscordUser : public UObject
{
	GENERATED_BODY()

public:
	void Init(const discord::User* InUser);

	UFUNCTION(BlueprintCallable, Category = "Discord|User")
	UTexture2D* GetAvatar();

	UFUNCTION(BlueprintCallable, Category = "Discord|User")
	bool IsBot();

	UFUNCTION(BlueprintCallable, Category = "Discord|User")
	FString GetDiscriminator();

	UFUNCTION(BlueprintCallable, Category = "Discord|User")
	int64 GetId();

	UFUNCTION(BlueprintCallable, Category = "Discord|User")
	FString GetUsername();

	virtual void BeginDestroy() override;
	
protected:
	const class discord::User* User;
};
