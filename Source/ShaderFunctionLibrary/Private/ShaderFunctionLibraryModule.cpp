// ShaderFunctionLibraryModule.cpp
#include "ShaderFunctionLibraryModule.h"

IMPLEMENT_MODULE(FShaderFunctionLibraryModule, ShaderFunctionLibrary)

void FShaderFunctionLibraryModule::StartupModule()
{ }

SHADERFUNCTIONLIBRARY_API float UShaderFunctionLibrary::ExecuteExampleComputeShader(float InputVal, float Scale, float Translate)
{
	FunTestClass f;
	float OutputVal;
	f.DispatchExampleComputeShader_GameThread(InputVal, Scale, Translate, FExampleComputeShaderResource::Get());
	return f.GetGPUReadback(FExampleComputeShaderResource::Get(), OutputVal);
}

SHADERFUNCTIONLIBRARY_API TArray<float> UShaderFunctionLibrary::ExecuteExampleComputeShader_Array(const TArray<float>& InputVal, float Scale, float Translate)
{
	FunTestClass f;
	TArray<float> OutputVal;
	OutputVal.AddUninitialized(InputVal.Num());//给OutputVal分配和InputVal一样大小的空间
	f.DispatchExampleComputeShader_Array_GameThread(InputVal, Scale, Translate, FExampleComputeShaderResource::Get());
	return f.GetGPUReadback_Array(FExampleComputeShaderResource::Get(), OutputVal);
}
