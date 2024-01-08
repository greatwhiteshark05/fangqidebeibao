// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class rider : ModuleRules
{
	public rider(ReadOnlyTargetRules Target) : base(Target)
	{
		PrivateDependencyModuleNames.AddRange(new string[] { "UMGEditor", "UMGEditor","UMG", "InputDevice", "InputDevice", "InputDevice" });
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "EnhancedInput","ProceduralMeshComponent"});
	}
}
