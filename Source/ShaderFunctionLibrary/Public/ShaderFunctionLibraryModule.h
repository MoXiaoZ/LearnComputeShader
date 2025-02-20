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

// ��ΪUCLASS������MinimalAPI������������ĺ���Ҫ�Ӻꡰģ����_API�������ú�����¶������ģ����
// һ��û��MinimalAPIʱ���ꡰģ����_API���Ǽ���class����ģ�class��ĺ����Ͳ��üӺ���
UCLASS(meta=(ScriptName="ShaderFunctionLibrary"), MinimalAPI)
class UShaderFunctionLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
public:
	UFUNCTION(BlueprintCallable, meta=(DisplayName="Execute ExampleComputeShader"), Category="My Shader Functions")
	static SHADERFUNCTIONLIBRARY_API float ExecuteExampleComputeShader(float InputVal, float Scale, float Translate);

	// ��ͼ������Ĳ���������������ͣ�ǰ������const������const������ȷ��¶����ͼ��
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Execute ExampleComputeShader Array"), Category = "My Shader Functions")
	static SHADERFUNCTIONLIBRARY_API TArray<float> ExecuteExampleComputeShader_Array(const TArray<float>& InputVal, float Scale, float Translate);
};