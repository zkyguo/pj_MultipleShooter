// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class pj_MultipleShooter : ModuleRules
{
	public pj_MultipleShooter(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "HeadMountedDisplay","OnlineSubSystemSteam", "OnlineSubSystem", "MultiplayerSessions" });
	}
}
