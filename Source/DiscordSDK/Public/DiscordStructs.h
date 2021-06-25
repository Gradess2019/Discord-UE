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

	FORCEINLINE discord::Activity* Create() const
	{
		auto Activity = new discord::Activity();
		Activity->SetName(TCHAR_TO_ANSI(*Name));
		Activity->SetState(TCHAR_TO_ANSI(*State));
		Activity->SetDetails(TCHAR_TO_ANSI(*Details));
		Activity->SetType(static_cast<discord::ActivityType>(Type.GetValue()));

		Assets.Init(Activity);
		
		return Activity;
	}
};
