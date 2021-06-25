#pragma once
#include "CoreMinimal.h"
#include "DiscordEnums.h"
#include "types.h"

#include "DiscordStructs.generated.h"

USTRUCT(BlueprintType)
struct FDiscordActivityAssets
{
	GENERATED_BODY()
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Activity")
	FString LargeImageKey;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Activity")
	FString LargeText;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Activity")
	FString SmallImageKey;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Activity")
	FString SmallText;

	FORCEINLINE discord::ActivityAssets* Create() const
	{
		const auto Assets = new discord::ActivityAssets();
		Init(*Assets);

		return Assets;
	}

	FORCEINLINE void Init(discord::ActivityAssets& Assets) const
	{
		Assets.SetLargeImage(TCHAR_TO_ANSI(*LargeImageKey));
		Assets.SetLargeText(TCHAR_TO_ANSI(*LargeText));
		Assets.SetSmallImage(TCHAR_TO_ANSI(*SmallImageKey));
		Assets.SetSmallText(TCHAR_TO_ANSI(*SmallText));
	}

	FORCEINLINE void Init(discord::Activity* Activity) const
	{
		auto& Assets = Activity->GetAssets();
		Init(Assets);
	}
};

USTRUCT(BlueprintType)
struct FDiscordActivityTimestamps
{
	GENERATED_BODY()
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Activity")
	int64 Start;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Activity")
	int64 End;

	FORCEINLINE discord::ActivityTimestamps* Create() const
	{
		const auto Timestamps = new discord::ActivityTimestamps();
		Init(*Timestamps);

		return Timestamps;
	}
	
	FORCEINLINE void Init(discord::ActivityTimestamps& Timestamps) const
	{
		Timestamps.SetStart(Start);
		Timestamps.SetEnd(End);
	}

	FORCEINLINE void Init(discord::Activity* Activity) const
	{
		auto& Timestamps = Activity->GetTimestamps();
		Init(Timestamps);
	}
};


USTRUCT(BlueprintType)
struct FDiscordActivityParty
{
	GENERATED_BODY()
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Activity")
	FString Id;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Activity")
	int32 CurrentSize;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Activity")
	int32 MaxSize;

	FORCEINLINE discord::ActivityParty* Create() const
	{
		const auto Party = new discord::ActivityParty();
		Init(*Party);

		return Party;
	}
	
	FORCEINLINE void Init(discord::ActivityParty& Party) const
	{
		Party.SetId(TCHAR_TO_ANSI(*Id));
		
		auto& Size = Party.GetSize();
		Size.SetCurrentSize(CurrentSize);
		Size.SetMaxSize(MaxSize);
	}

	FORCEINLINE void Init(discord::Activity* Activity) const
	{
		auto& Party = Activity->GetParty();
		Init(Party);
	}
};

USTRUCT(BlueprintType)
struct FDiscordActivity
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Activity")
	FString Name;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Activity")
	FString State;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Activity")
	FString Details;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Activity")
	TEnumAsByte<EDiscordActivityType> Type;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Activity")
	bool bInstance;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Activity")
	FDiscordActivityAssets Assets;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Activity")
	FDiscordActivityTimestamps Timestamps;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Activity")
	FDiscordActivityParty Party;
	
	FORCEINLINE discord::Activity* Create() const
	{
		auto Activity = new discord::Activity();
		Activity->SetName(TCHAR_TO_ANSI(*Name));
		Activity->SetState(TCHAR_TO_ANSI(*State));
		Activity->SetDetails(TCHAR_TO_ANSI(*Details));
		Activity->SetType(static_cast<discord::ActivityType>(Type.GetValue()));
		Activity->SetInstance(bInstance);

		Assets.Init(Activity);
		Timestamps.Init(Activity);
		Party.Init(Activity);

		return Activity;
	}
};
