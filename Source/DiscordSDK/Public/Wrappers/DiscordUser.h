// Created by Stepan Trofimov, 2021

#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "DiscordUser.generated.h"

namespace discord
{
	class User;
}

/**
 * Represents discord user. Users can spawn across the entire platform,
 * be members of guilds, participate in text and voice chat, and much more.
 */
UCLASS(Blueprintable, BlueprintType)
class DISCORDSDK_API UDiscordUser : public UObject
{
	GENERATED_BODY()

public:
	/**
	 * @brief Initialize unreal discord user
	 * @param InUser native discord user
	 */
	void Init(const discord::User* InUser);

	/**
	 * @brief the user's avatar hash
	 * @return avatar hash
	 */
	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Discord|User")
	FString GetAvatarHash();

	/**
	 * @brief Whether current user is a bot or not
	 * @return bot or not
	 */
	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Discord|User")
	bool IsBot();

	/**
	 * @brief the user's 4-digit discord-tag, like #1234
	 * @return user's discriminator
	 */
	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Discord|User")
	FString GetDiscriminator();

	/**
	 * @brief the user's id
	 * @return the user's id
	 */
	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Discord|User")
	int64 GetId();

	/**
	 * @brief the user's username, not unique across the platform
	 * @return the user's username
	 */
	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Discord|User")
	FString GetUsername();

	virtual void BeginDestroy() override;
	
protected:
	/**
	 * @brief Native discord object
	 */
	const discord::User* User;
};
