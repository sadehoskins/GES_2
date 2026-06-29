// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class GES_2 : ModuleRules
{
    public GES_2(ReadOnlyTargetRules Target) : base(Target)
    {
        PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

        PublicDependencyModuleNames.AddRange(new string[] {
            "Core", "CoreUObject", "Engine", "InputCore", "EnhancedInput", "GameplayTags"
        });

        PrivateDependencyModuleNames.AddRange(new string[] { });
    }
}