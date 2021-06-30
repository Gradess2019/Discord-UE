// Created by Stepan Trofimov, 2021

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintAsyncActionBase.h"
#include "Interfaces/IHttpRequest.h"
#include "DiscordGetUserAvatarAction.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(
	FDiscordUserAvatarPin,
	UTexture2D*, Avatar
);

class IImageWrapper;
class UDiscordUser;

/**
 * Get discord user avatar image
 */
UCLASS()
class DISCORDSDK_API UDiscordGetUserAvatarAction : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

public:
	/**
	 * @brief Get user avatar image
	 * @param User User to get the avatar
	 * @param Size Preferred size of avatar
	 * @return Action node
	 */
	UFUNCTION(
		BlueprintCallable,
		meta = (BlueprintInternalUseOnly = "true")
	)
	static UDiscordGetUserAvatarAction* GetUserAvatar(
		UDiscordUser* User,
		const int32 Size = 256
	);

	virtual void Activate() override;

	/**
	 * @brief Response callback
	 * @param Request Original Http request that started things
	 * @param Response Response received from the server if a successful connection was established
	 * @param bConnectedSuccessfully Indicates whether or not the request was able to connect successfully
	 */
	void OnResponse(
		FHttpRequestPtr Request,
		FHttpResponsePtr Response,
		bool bConnectedSuccessfully
	);

	/**
	* @brief Fires when an action is finished
	*/
	UPROPERTY(
		BlueprintAssignable,
		Category = "Discord|Action"
	)
	FDiscordUserAvatarPin Finished;

protected:
	/**
	 * @brief Get image wrapper interface
	 * @return Image wrapper
	 */
	TSharedPtr<IImageWrapper> GetImageWrapper() const;

	/**
	 * @brief Create empty Texture2D
	 * @return Empty Texture2D
	 */
	UFUNCTION()
	UTexture2D* CreateTexture() const;

	/**
	 * @brief Fill empty texture with passed data
	 * @param Texture Texture to fill
	 * @param Data Data to use
	 */
	UFUNCTION()
	void FillTexture(
		UTexture2D* Texture,
		const TArray<uint8>& Data
	) const;

	/**
	 * @brief User to use for obtaining avatar
	 */
	UPROPERTY()
	UDiscordUser* User;

	/**
	 * @brief Preferred size of the image
	 */
	UPROPERTY()
	int32 Size;
};
