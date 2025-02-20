# LearnComputeShader
## 在UE中实现ComputeShader
* 传入一个float变量InputVal，输出InputVal*Scale+Translate
* 传入一个TArray\<float\>变量InputVal，对数组中每一个元素*Scale+Translate

## 更正的错误（https://github.com/SirEnri2001/UnrealShaderTutorial\）
* 在.uproject中将ExampleComputeShader模块的"LoadingPhase"对应的值改为"PostConfigInit"，因为GlobalShader的模块要在引擎完全初始化之前加载，配置系统初始化后立即加载。
* 添加虚拟路径时AddShaderSourceDirectoryMapping的参数/MyShader改成/MyShaders，因为原来的代码有的加s了，有的没加，统一加s
* 添加第2个模块时（ShaderFunctionLibraryModule）要加宏IMPLEMENT_MODULE
* shader中\[numthreads(64, 64, 64)\]改成\[numthreads(32, 32, 1)\]，线程数乘积不能超过1024
