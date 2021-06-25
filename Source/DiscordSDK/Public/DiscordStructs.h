#pragma once
#include "CoreMinimal.h"
#include "DiscordEnums.h"
#include "types.h"

#include "DiscordStructs.generated.h"

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

	FORCEINLINE discord::Activity* Create() const
	{
		auto Activity = new discord::Activity();
		Activity->SetName(TCHAR_TO_ANSI(*Name));
		Activity->SetState(TCHAR_TO_ANSI(*State));
		Activity->SetDetails(TCHAR_TO_ANSI(*Details));
		Activity->SetType(static_cast<discord::ActivityType>(Type.GetValue()));
		
		return Activity;
	}
};
