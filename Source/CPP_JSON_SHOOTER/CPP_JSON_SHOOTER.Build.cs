// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class CPP_JSON_SHOOTER : ModuleRules
{
	public CPP_JSON_SHOOTER(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] {
			"Core",
			"CoreUObject",
			"Engine",
			"InputCore",
			"EnhancedInput",
			"AIModule",
			"StateTreeModule",
			"GameplayStateTreeModule",
			"UMG",
			"Slate",
			"HTTP", 
			"Json", 
			"JsonUtilities"
        });

		PrivateDependencyModuleNames.AddRange(new string[] { });

		PublicIncludePaths.AddRange(new string[] {
			"CPP_JSON_SHOOTER",
			"CPP_JSON_SHOOTER/Variant_Horror",
			"CPP_JSON_SHOOTER/Variant_Horror/UI",
			"CPP_JSON_SHOOTER/Variant_Shooter",
			"CPP_JSON_SHOOTER/Variant_Shooter/AI",
			"CPP_JSON_SHOOTER/Variant_Shooter/UI",
			"CPP_JSON_SHOOTER/Variant_Shooter/Weapons"
		});

		// Uncomment if you are using Slate UI
		// PrivateDependencyModuleNames.AddRange(new string[] { "Slate", "SlateCore" });

		// Uncomment if you are using online features
		// PrivateDependencyModuleNames.Add("OnlineSubsystem");

		// To include OnlineSubsystemSteam, add it to the plugins section in your uproject file with the Enabled attribute set to true
	}
}
