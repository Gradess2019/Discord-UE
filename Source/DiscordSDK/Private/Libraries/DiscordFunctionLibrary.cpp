// Fill out your copyright notice in the Description page of Project Settings.


#include "Libraries/DiscordFunctionLibrary.h"

int64 UDiscordFunctionLibrary::StringToInt64(const FString& String)
{
	return FCString::Strtoi64(*String, nullptr, 10);
}

FString UDiscordFunctionLibrary::Int64ToString(const int64& Number)
{
	return FString::Printf(TEXT("%lld"), Number);
}
