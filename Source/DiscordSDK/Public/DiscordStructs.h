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
	FString LargeImageHash;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Activity")
	FString LargeText;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Activity")
	FString SmallImageHash;
	
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
		Assets.SetLargeImage(TCHAR_TO_ANSI(*LargeImageHash));
		Assets.SetLargeText(TCHAR_TO_ANSI(*LargeText));
		Assets.SetSmallImage(TCHAR_TO_ANSI(*SmallImageHash));
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
	FDiscordActivityAssets Assets;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discord|Activity")
	FDiscordActivityTimestamps Timestamps;
	
	FORCEINLINE discord::Activity* Create() const
	{
		auto Activity = new discord::Activity();
		Activity->SetName(TCHAR_TO_ANSI(*Name));
		Activity->SetState(TCHAR_TO_ANSI(*State));
		Activity->SetDetails(TCHAR_TO_ANSI(*Details));
		Activity->SetType(static_cast<discord::ActivityType>(Type.GetValue()));
		
		Assets.Init(Activity);
		Timestamps.Init(Activity);
		return Activity;
	}
};
