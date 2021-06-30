// Created by Stepan Trofimov, 2021


#include "Libraries/DiscordFunctionLibrary.h"
#include "DiscordObject.h"
#include "Wrappers/DiscordUser.h"

int64 UDiscordFunctionLibrary::StringToInt64(const FString& String)
{
	return FCString::Strtoi64(*String, nullptr, 10);
}

FString UDiscordFunctionLibrary::Int64ToString(const int64& Number)
{
	return FString::Printf(TEXT("%lld"), Number);
}

int64 UDiscordFunctionLibrary::TextToInt64(const FText& Text)
{
	return StringToInt64(Text.ToString());
}

FText UDiscordFunctionLibrary::Int64ToText(const int64& Number)
{
	return FText::AsNumber(Number);
}

UDiscordUser* UDiscordFunctionLibrary::GetCurrentUser(EDiscordActionResult& OutResult)
{
	auto Core = UDiscordObject::GetCore();
	if (!Core) { return nullptr; }

	discord::User* User = new discord::User();
	OutResult = static_cast<EDiscordActionResult>(Core->UserManager().GetCurrentUser(User));
	
	if (!User) { return nullptr; }

	auto DiscordUser = NewObject<UDiscordUser>();
	DiscordUser->Init(User);

	return DiscordUser;
}

int64 UDiscordFunctionLibrary::GetUnixTimestamp(const FDateTime& DateTime)
{
	return DateTime.ToUnixTimestamp();
}
