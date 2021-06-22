// Copyright Epic Games, Inc. All Rights Reserved.

using System.IO;
using UnrealBuildTool;

public class DiscordSDK : ModuleRules
{
	public DiscordSDK(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = ModuleRules.PCHUsageMode.UseExplicitOrSharedPCHs;

		var nativeDirectory = Path.Combine(PluginDirectory, "Source", "Native");
		PublicIncludePaths.AddRange(
			new string[]
			{
				nativeDirectory
			}
		);
		
		var discordLibrary = Path.Combine(PluginDirectory, "Binaries", "Win64", "discord_game_sdk.dll.lib");
		PublicAdditionalLibraries.AddRange(
			new string[]
			{
				discordLibrary
			}
		);

		PrivateIncludePaths.AddRange(
			new string[]
			{
				// ... add other private include paths required here ...
			}
		);


		PublicDependencyModuleNames.AddRange(
			new string[]
			{
				"Core",
				// ... add other public dependencies that you statically link with here ...
			}
		);


		PrivateDependencyModuleNames.AddRange(
			new string[]
			{
				"CoreUObject",
				"Engine",
				"Slate",
				"SlateCore",
				// ... add private dependencies that you statically link with here ...	
			}
		);


		DynamicallyLoadedModuleNames.AddRange(
			new string[]
			{
				// ... add any modules that your module loads dynamically here ...
			}
		);
	}
}