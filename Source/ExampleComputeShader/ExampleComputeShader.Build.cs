// ExampleComputeShader.Build.cs
using UnrealBuildTool;

public class ExampleComputeShader : ModuleRules
{
	public ExampleComputeShader(ReadOnlyTargetRules Target) : base(Target)
	{
        //LoadingPhase = ModuleLoadingPhase.PostConfigInit;

        PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;
	
		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "RHI", "RenderCore" });

    }
}