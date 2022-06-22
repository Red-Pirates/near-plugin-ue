// Fill out your copyright notice in the Description page of Project Settings.

using UnrealBuildTool;

public class Near : ModuleRules
{
	public Near(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;
	
		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "NearPlugin", "ApplicationCore"});

		PrivateDependencyModuleNames.AddRange(new string[] {  });
	}
}
