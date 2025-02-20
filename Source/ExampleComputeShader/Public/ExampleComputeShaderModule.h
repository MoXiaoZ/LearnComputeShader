// ExampleComputeShaderModule.h
#include "Modules/ModuleManager.h"


class FExampleComputeShaderModule : public IModuleInterface {
    virtual void StartupModule() override;
};


class EXAMPLECOMPUTESHADER_API FExampleComputeShaderResource : public FRenderResource // ʹ��EXAMPLECOMPUTESHADER_API��Ϊ����Ҫ�ڱ��ģ����ʵ������
{
	static FExampleComputeShaderResource* GInstance; // ����ģʽ
public:
	FRWBufferStructured InputBuffer;  // RWStructuredBuffer<float> InputBuffer;
	FRWBufferStructured OutputBuffer; // RWStructuredBuffer<float> OutputBuffer;

	// ��ʼ������buffer��override����
	// �˺�����FRenderResource::InitResource(FRHICommandList&)����
	virtual void InitRHI(FRHICommandListBase& RHICmdList) override;


	// �˺�����FRenderResource::ReleaseResource(FRHICommandList&)����
	virtual void ReleaseRHI() override; // �ͷ�����buffer

	static FExampleComputeShaderResource* Get(); // ����ģʽ
private:
	FExampleComputeShaderResource() {} // ���캯��˽��
};

// ���Ϻꡰģ������_API�����ܰ��౩¶��ȥ����������ģ�������ģ��ʹ��
class EXAMPLECOMPUTESHADER_API FunTestClass {
public:
	void DispatchExampleComputeShader_RenderThread(FRHICommandList& RHICmdList, FExampleComputeShaderResource* Resource, float Scale, float Translate, uint32 ThreadGroupX, uint32 ThreadGroupY, uint32 ThreadGroupZ);
	void DispatchExampleComputeShader_GameThread(float InputVal, float Scale, float Translate, FExampleComputeShaderResource* Resource);
	float GetGPUReadback(FExampleComputeShaderResource* Resource, float& OutputVal);

	void DispatchExampleComputeShader_Array_GameThread(const TArray<float>& InputVal, float Scale, float Translate, FExampleComputeShaderResource* Resource);
	TArray<float>& GetGPUReadback_Array(FExampleComputeShaderResource* Resource, TArray<float>& OutputVal);
};
