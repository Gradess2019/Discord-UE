// Copyright Epic Games, Inc. All Rights Reserved.

using System.IO;
using UnrealBuildTool;

public class DiscordSDK : ModuleRules
{
	public DiscordSDK(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = ModuleRules.PCHUsageMode.UseExplicitOrSharedPCHs;
		
		PublicDefinitions.Add("_CRT_SECURE_NO_WARNINGS");
		
		PublicIncludePaths.AddRange(
			new string[]
			{
				Path.Combine(ModuleDirectory, "Native")
			}
		);
		
		var discordLibrary = Path.Combine(PluginDirectory, "Source", "ThirdParty", "Discord", "Win64", "discord_game_sdk.dll.lib");
		PublicAdditionalLibraries.AddRange(
			new string[]
			{
				discordLibrary
			}
		); 
		
		RuntimeDependencies.Add(Path.Combine(PluginDirectory, "Source", "ThirdParty", "Discord", "Win64", "discord_game_sdk.dll"));

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
				"HTTP",
				"ImageWrapper",
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