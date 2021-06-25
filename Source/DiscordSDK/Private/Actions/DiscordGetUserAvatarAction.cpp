// Fill out your copyright notice in the Description page of Project Settings.


#include "Actions/DiscordGetUserAvatarAction.h"
#include "DiscordObject.h"
#include "HttpModule.h"
#include "types.h"
#include "Misc/Base64.h"
#include "Interfaces/IHttpResponse.h"

UDiscordGetUserAvatarAction* UDiscordGetUserAvatarAction::GetUserAvatar(const int64 UserId)
{
	auto Node = NewObject<UDiscordGetUserAvatarAction>();
	return Node;
}

void UDiscordGetUserAvatarAction::Activate()
{
	auto Core = UDiscordObject::GetCore();
	if (!Core) { return; }

	auto HttpRequest = FHttpModule::Get().CreateRequest();
	HttpRequest->SetVerb("GET");
	HttpRequest->SetHeader(TEXT("Content-Type"), TEXT("image/jpeg"));
	HttpRequest->SetURL(FString(
		"https://cdn.discordapp.com/avatars/330221327464005634/f2fd0423b40e4e1e8c055a32ff28b25f.jpg?size=256")
	);
	
	HttpRequest->OnProcessRequestComplete().BindLambda(
		[&](FHttpRequestPtr Request, FHttpResponsePtr Response, bool bConnectedSuccessfully)
		{
			UTexture2D* Tex2D = UTexture2D::CreateTransient(256, 256, EPixelFormat::PF_FloatRGB);

			auto Size = Response.Get()->GetContentLength();
			const TArray<uint8>* SrcData = &Response->GetContent();
			auto ContentType = Response->GetContentType();
			auto Result = FBase64::Encode(*SrcData);

			// auto Result = BytesToString(SrcData->GetData(), Size);
			UE_LOG(LogTemp, Warning, TEXT("%s"), *Result)
			// Fill in the base mip for the texture we created
			uint8* MipData = (uint8*)Tex2D->PlatformData->Mips[0].BulkData.Lock(LOCK_READ_WRITE);
			FMemory::Memcpy(MipData, SrcData, Size);
			Tex2D->PlatformData->Mips[0].BulkData.Unlock();

			Tex2D->PlatformData->SetNumSlices(1);
			Tex2D->NeverStream = true;
			Tex2D->Rename(TEXT("UserAvatar"));
			Tex2D->CompressionSettings = TC_Default;

			// Update the remote texture data
			Tex2D->UpdateResource();
			Finished.Broadcast(Tex2D);
			// UE_LOG(LogTemp, Warning, TEXT("HTTP Request %d, %d, %d"), Request->GetContentLength(), Response->GetContentLength(), bConnectedSuccessfully);
		});

	HttpRequest->ProcessRequest();
}
