// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include "CoreMinimal.h"
#include "Modules/ModuleManager.h"

class FDiscordSDKModule : public IModuleInterface
{
public:

	/** IModuleInterface implementation */
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;
};
