// ExampleComputeShaderModule.h
#include "Modules/ModuleManager.h"


class FExampleComputeShaderModule : public IModuleInterface {
    virtual void StartupModule() override;
};


class EXAMPLECOMPUTESHADER_API FExampleComputeShaderResource : public FRenderResource // 使用EXAMPLECOMPUTESHADER_API因为我们要在别的模块访问到这个类
{
	static FExampleComputeShaderResource* GInstance; // 单例模式
public:
	FRWBufferStructured InputBuffer;  // RWStructuredBuffer<float> InputBuffer;
	FRWBufferStructured OutputBuffer; // RWStructuredBuffer<float> OutputBuffer;

	// 初始化所有buffer，override基类
	// 此函数由FRenderResource::InitResource(FRHICommandList&)调用
	virtual void InitRHI(FRHICommandListBase& RHICmdList) override;


	// 此函数由FRenderResource::ReleaseResource(FRHICommandList&)调用
	virtual void ReleaseRHI() override; // 释放所有buffer

	static FExampleComputeShaderResource* Get(); // 单例模式
private:
	FExampleComputeShaderResource() {} // 构造函数私有
};

// 加上宏“模块名称_API”才能把类暴露出去，让依赖此模块的其他模块使用
class EXAMPLECOMPUTESHADER_API FunTestClass {
public:
	void DispatchExampleComputeShader_RenderThread(FRHICommandList& RHICmdList, FExampleComputeShaderResource* Resource, float Scale, float Translate, uint32 ThreadGroupX, uint32 ThreadGroupY, uint32 ThreadGroupZ);
	void DispatchExampleComputeShader_GameThread(float InputVal, float Scale, float Translate, FExampleComputeShaderResource* Resource);
	float GetGPUReadback(FExampleComputeShaderResource* Resource, float& OutputVal);

	void DispatchExampleComputeShader_Array_GameThread(const TArray<float>& InputVal, float Scale, float Translate, FExampleComputeShaderResource* Resource);
	TArray<float>& GetGPUReadback_Array(FExampleComputeShaderResource* Resource, TArray<float>& OutputVal);
};
