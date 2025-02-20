// ShaderFunctionLibraryModule.h
#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "ExampleComputeShaderModule.h"

#include "ShaderFunctionLibraryModule.generated.h"


class FShaderFunctionLibraryModule : public IModuleInterface {
    virtual void StartupModule() override;
    // virtual void ShutdownModule() override;
};

// 因为UCLASS中用了MinimalAPI，所以类下面的函数要加宏“模块名_API”才能让函数暴露在其他模块中
// 一般没有MinimalAPI时，宏“模块名_API”是加在class后面的，class里的函数就不用加宏了
UCLASS(meta=(ScriptName="ShaderFunctionLibrary"), MinimalAPI)
class UShaderFunctionLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
public:
	UFUNCTION(BlueprintCallable, meta=(DisplayName="Execute ExampleComputeShader"), Category="My Shader Functions")
	static SHADERFUNCTIONLIBRARY_API float ExecuteExampleComputeShader(float InputVal, float Scale, float Translate);

	// 蓝图函数库的参数如果是引用类型，前面必须加const，不加const不能正确暴露在蓝图里
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Execute ExampleComputeShader Array"), Category = "My Shader Functions")
	static SHADERFUNCTIONLIBRARY_API TArray<float> ExecuteExampleComputeShader_Array(const TArray<float>& InputVal, float Scale, float Translate);
};