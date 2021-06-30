#pragma once
#include "CoreMinimal.h"
#include "DiscordEnums.h"
#include "types.h"

#include "DiscordStructs.generated.h"

/**
 * @brief Represents discord activity assets like large image, large text, etc.
 */
USTRUCT(BlueprintType)
struct FDiscordActivityAssets
{
	GENERATED_BODY()

	/**
	 * @brief Key of large image on https://discord.com/developers/applications/<YOUR_APP_ID>/rich-presence/assets
	 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Activity")
	FString LargeImageKey;

	/**
	 * @brief Text that will be displayed on large image mouse hover
	 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Activity")
	FString LargeText;

	/**
	 * @brief Key of small image on https://discord.com/developers/applications/<YOUR_APP_ID>/rich-presence/assets
	 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Activity")
	FString SmallImageKey;

	/**
	 * @brief Text that will be displayed on small image mouse hover
	 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Activity")
	FString SmallText;

	/**
	 * @brief Creates discord assets based on this struct values
	 * @return native discord assets object
	 */
	FORCEINLINE discord::ActivityAssets* Create() const
	{
		const auto Assets = new discord::ActivityAssets();
		Init(*Assets);

		return Assets;
	}

	/**
	 * @brief Initialize discord activity assets by the struct values
	 * @param Assets discord activity assets to initialize by this struct values
	 */
	FORCEINLINE void Init(discord::ActivityAssets& Assets) const
	{
		Assets.SetLargeImage(TCHAR_TO_ANSI(*LargeImageKey));
		Assets.SetLargeText(TCHAR_TO_ANSI(*LargeText));
		Assets.SetSmallImage(TCHAR_TO_ANSI(*SmallImageKey));
		Assets.SetSmallText(TCHAR_TO_ANSI(*SmallText));
	}

	/**
	 * @brief Initialize discord activity assets by the struct values
	 * @param Activity activity to obtain discord activity assets
	 */
	FORCEINLINE void Init(discord::Activity* Activity) const
	{
		auto& Assets = Activity->GetAssets();
		Init(Assets);
	}
};

/**
 * @brief Represents discord activity timestamps like start time (elapsed) and end time (remaining) in UNIX format
 */
USTRUCT(BlueprintType)
struct FDiscordActivityTimestamps
{
	GENERATED_BODY()

	/**
	 * @brief Start time (e.g. match start time) in UNIX format
	 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Activity")
	int64 Start;

	/**
	* @brief End time (e.g. remaining time to the end of the match) in UNIX format
	*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Activity")
	int64 End;

	/**
	 * @brief Creates discord activity timestamps based on this struct values
	 * @return native discord activity timestamps object
	 */
	FORCEINLINE discord::ActivityTimestamps* Create() const
	{
		const auto Timestamps = new discord::ActivityTimestamps();
		Init(*Timestamps);

		return Timestamps;
	}

	/**
	 * @brief Initialize discord activity timestamps by the struct values
	 * @param Timestamps discord activity timestamps to initialize by the struct values
	 */
	FORCEINLINE void Init(discord::ActivityTimestamps& Timestamps) const
	{
		Timestamps.SetStart(Start);
		Timestamps.SetEnd(End);
	}

	/**
	 * @brief Initialize discord activity timestamps by the struct values
	 * @param Activity activity to obtain discord activity timestamps
	 */
	FORCEINLINE void Init(discord::Activity* Activity) const
	{
		auto& Timestamps = Activity->GetTimestamps();
		Init(Timestamps);
	}
};

/**
 * @brief Represents discord activity party object like its id, current party size and max size
 */
USTRUCT(BlueprintType)
struct FDiscordActivityParty
{
	GENERATED_BODY()

	/**
	 * @brief Id of party
	 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Activity")
	FString Id;

	/**
	 * @brief Current party size (Count of members)
	 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Activity")
	int32 CurrentSize;

	/**
	 * @brief Max party size (Max count of members)
	 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Activity")
	int32 MaxSize;

	/**
	 * @brief Creates discord activity party based on this struct values
	 * @return native discord activity party object
	 */
	FORCEINLINE discord::ActivityParty* Create() const
	{
		const auto Party = new discord::ActivityParty();
		Init(*Party);

		return Party;
	}

	/**
	 * @brief Initialize discord activity party by the struct values
	 * @param Party discord activity party to initialize by the struct values
	 */
	FORCEINLINE void Init(discord::ActivityParty& Party) const
	{
		Party.SetId(TCHAR_TO_ANSI(*Id));

		auto& Size = Party.GetSize();
		Size.SetCurrentSize(CurrentSize);
		Size.SetMaxSize(MaxSize);
	}

	/**
	 * @brief Initialize discord activity party by the struct values
	 * @param Activity activity to obtain discord activity party object
	 */
	FORCEINLINE void Init(discord::Activity* Activity) const
	{
		auto& Party = Activity->GetParty();
		Init(Party);
	}
};

/**
 * @brief Represents secret passwords for joining and spectating the player's game
 */
USTRUCT(BlueprintType)
struct FDiscordActivitySecrets
{
	GENERATED_BODY()

	/**
	 * @brief Unique hash for the given match context
	 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Activity")
	FString Match;

	/**
	 * @brief Unique hash for chat invites and Ask to Join
	 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Activity")
	FString Join;

	/**
	 * @brief Unique hash for Spectate button
	 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Activity")
	FString Spectate;

	/**
	 * @brief Creates discord activity secrets based on this struct values
	 * @return native discord activity secrets object
	 */
	FORCEINLINE discord::ActivitySecrets* Create() const
	{
		const auto Secrets = new discord::ActivitySecrets();
		Init(*Secrets);

		return Secrets;
	}

	/**
	 * @brief Initialize discord activity secrets by the struct values
	 * @param Secrets discord activity secrets to initialize by the struct values
	 */
	FORCEINLINE void Init(discord::ActivitySecrets& Secrets) const
	{
		Secrets.SetMatch(TCHAR_TO_ANSI(*Match));
		Secrets.SetJoin(TCHAR_TO_ANSI(*Join));
		Secrets.SetSpectate(TCHAR_TO_ANSI(*Spectate));
	}

	/**
	 * @brief Initialize discord activity secrets by the struct values
	 * @param Activity activity to obtain discord activity secrets object
	 */
	FORCEINLINE void Init(discord::Activity* Activity) const
	{
		auto& Secrets = Activity->GetSecrets();
		Init(Secrets);
	}
};

/**
 * @brief Represents discord activity (Rich Presence) like Name of the game, details, images, etc.
 */
USTRUCT(BlueprintType)
struct FDiscordActivity
{
	GENERATED_BODY()

	/**
	 * @brief Name of the application - this is a read-only field
	 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Activity")
	FString Name;

	/**
	 * @brief The player's current party status
	 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Activity")
	FString State;

	/**
	 * @brief What the player is currently doing
	 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Activity")
	FString Details;

	/**
	 * @brief Helps create elapsed/remaining timestamps on a player's profile
	 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Activity")
	FDiscordActivityTimestamps Timestamps;

	/**
	 * @brief Assets to display on the player's profile
	 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Activity")
	FDiscordActivityAssets Assets;

	/**
	 * @brief Information about the player's party
	 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Activity")
	FDiscordActivityParty Party;

	/**
	 * @brief Secret passwords for joining and spectating the player's game
	 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Activity")
	FDiscordActivitySecrets Secrets;

	/**
	 * @brief Whether this activity is an instanced context, like a match
	 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Activity")
	bool bInstance;
	
	/**
	 * @brief Type of the activity, like playing, streaming, listening, etc.
	 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Activity")
	TEnumAsByte<EDiscordActivityType> Type;

	/**
	 * @brief Create discord activty objects based on the struct values
	 * @return Created discord activity object
	 */
	FORCEINLINE discord::Activity* Create() const
	{
		auto Activity = new discord::Activity();
		Activity->SetName(TCHAR_TO_ANSI(*Name));
		Activity->SetState(TCHAR_TO_ANSI(*State));
		Activity->SetDetails(TCHAR_TO_ANSI(*Details));
		Activity->SetType(static_cast<discord::ActivityType>(Type.GetValue()));
		Activity->SetInstance(bInstance);

		Timestamps.Init(Activity);
		Assets.Init(Activity);
		Party.Init(Activity);
		Secrets.Init(Activity);

		return Activity;
	}
};

/**
 * @brief Represents discord activity manager data like registering command to launch your game
 */
USTRUCT(BlueprintType)
struct FDiscordActivityManagerData
{
	GENERATED_BODY()

	/**
	 * @brief The command to register, like "game.exe --full-screen --no-hax"
	 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Discord|Activity")
	FString Command;

	/**
	 * @brief Your game's Steam app id for the protocol "steam://run-game-id/<id>"
	 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Discord|Activity", meta=(MakeStructureDefaultValue = "-1"))
	int64 SteamAppId;
};

/**
 * @brief Represents invitation data like user id, activity action type and message
 */
USTRUCT(BlueprintType)
struct FDiscordSendInviteData
{
	GENERATED_BODY()

	/**
	 * @brief The id of the user to invite
	 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Discord|Activity")
	int64 UserId;

	/**
	 * @brief Marks the invite as an invitation to join or spectate
	 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Discord|Activity")
	TEnumAsByte<EDiscordActivityActionType> Type;

	/**
	 * @brief A message to send along with the invite
	 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Discord|Activity")
	FString Content;
};
