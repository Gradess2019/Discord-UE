// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "DiscordBaseAction.h"
#include "Interfaces/IHttpRequest.h"
#include "Interfaces/IHttpResponse.h"
#include "DiscordGetUserAvatarAction.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FDiscordUserAvatarPin, UTexture2D*, Avatar);

class IImageWrapper;
class UDiscordUser;

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
	static UDiscordGetUserAvatarAction* GetUserAvatar(
		UDiscordUser* User,
		const int32 Size = 256
	);

	virtual void Activate() override;

	void OnResponse(
		FHttpRequestPtr Request,
		FHttpResponsePtr Response,
		bool bConnectedSuccessfully
	);

protected:
	TSharedPtr<IImageWrapper> GetImageWrapper() const;

	UFUNCTION()
	UTexture2D* CreateTexture() const;

	UFUNCTION()
	void FillTexture(UTexture2D* Texture, const TArray<uint8>& Data) const;

	UPROPERTY()
	UDiscordUser* User;

	UPROPERTY()
	int32 Size;
};
