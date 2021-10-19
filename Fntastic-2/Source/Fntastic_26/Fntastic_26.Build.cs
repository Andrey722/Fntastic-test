// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class Fntastic_26 : ModuleRules
{
	public Fntastic_26(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "HeadMountedDisplay", "AIModule" });
	}
}
