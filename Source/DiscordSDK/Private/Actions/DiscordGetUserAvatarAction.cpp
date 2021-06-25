// Fill out your copyright notice in the Description page of Project Settings.


#include "Actions/DiscordGetUserAvatarAction.h"
#include "DiscordObject.h"
#include "HttpModule.h"
#include "IImageWrapper.h"
#include "IImageWrapperModule.h"
#include "Interfaces/IHttpResponse.h"
#include "Wrappers/DiscordUser.h"

UDiscordGetUserAvatarAction* UDiscordGetUserAvatarAction::GetUserAvatar(UDiscordUser* User, const int32 Size)
{
	const auto Node = NewObject<UDiscordGetUserAvatarAction>();
	Node->User = User;
	Node->Size = Size;
	return Node;
}

void UDiscordGetUserAvatarAction::Activate()
{
	auto Core = UDiscordObject::GetCore();
	if (!Core) { return; }

	const auto UserId = User->GetId();
	const auto Hash = User->GetAvatarHash();
	const auto URL = FString::Format(
		TEXT("https://cdn.discordapp.com/avatars/{0}/{1}.jpg?size={2}"),
		{UserId, Hash, Size}
	);

	auto HttpRequest = FHttpModule::Get().CreateRequest();
	HttpRequest->SetVerb("GET");
	HttpRequest->SetHeader(TEXT("Content-Type"), TEXT("image/jpeg"));
	HttpRequest->SetURL(URL);
	HttpRequest->OnProcessRequestComplete().BindUObject(this, &UDiscordGetUserAvatarAction::OnResponse);
	HttpRequest->ProcessRequest();
}

void UDiscordGetUserAvatarAction::OnResponse(
	FHttpRequestPtr Request,
	FHttpResponsePtr Response,
	bool bConnectedSuccessfully
)
{
	auto ImageWrapper = GetImageWrapper();

	const auto ImageDataArray = Response->GetContent();
	const auto bValidImageType = ImageWrapper->SetCompressed(ImageDataArray.GetData(), ImageDataArray.Num());
	if (!(ImageWrapper.IsValid() || bValidImageType)) { return; }

	auto UncompressedBGRA = TArray<uint8>();
	const bool bSuccess = ImageWrapper->GetRaw(ERGBFormat::BGRA, 8, UncompressedBGRA);
	if (!bSuccess) { return; }

	const auto Texture = CreateTexture();
	FillTexture(Texture, UncompressedBGRA);

	Finished.Broadcast(Texture);
}

TSharedPtr<IImageWrapper> UDiscordGetUserAvatarAction::GetImageWrapper() const
{
	auto& ImageWrapperModule = FModuleManager::LoadModuleChecked<IImageWrapperModule>(FName("ImageWrapper"));
	return ImageWrapperModule.CreateImageWrapper(EImageFormat::JPEG);
}

UTexture2D* UDiscordGetUserAvatarAction::CreateTexture() const
{
	auto Texture = UTexture2D::CreateTransient(Size, Size, PF_B8G8R8A8);
	Texture->MipGenSettings = TextureMipGenSettings::TMGS_NoMipmaps;
	return Texture;
}

void UDiscordGetUserAvatarAction::FillTexture(UTexture2D* Texture, const TArray<uint8>& Data) const
{
	const auto TextureData = Texture->PlatformData->Mips[0].BulkData.Lock(LOCK_READ_WRITE);
	FMemory::Memcpy(TextureData, Data.GetData(), Data.Num());
	Texture->PlatformData->Mips[0].BulkData.Unlock();

	Texture->UpdateResource();
}
