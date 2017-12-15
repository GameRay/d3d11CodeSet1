//***************************************************************************************
// d3dApp.h by Frank Luna (C) 2011 All Rights Reserved.
//
// Simple Direct3D demo application class.  
// Make sure you link: d3d11.lib d3dx11d.lib D3DCompiler.lib D3DX11EffectsD.lib 
//                     dxerr.lib dxgi.lib dxguid.lib.
// Link d3dx11.lib and D3DX11Effects.lib for release mode builds instead
//   of d3dx11d.lib and D3DX11EffectsD.lib.
//***************************************************************************************

#ifndef D3DAPP_H
#define D3DAPP_H

#include "d3dUtil.h"
#include "GameTimer.h"
#include <string>

class D3DApp
{
public:
	D3DApp(HINSTANCE hInstance);
	virtual ~D3DApp();
	
	HINSTANCE AppInst()const;
	HWND      MainWnd()const;
	float     AspectRatio()const;
	
	int Run();
 
	// Framework methods.  Derived client class overrides these methods to 
	// implement specific application requirements.

	virtual bool Init();
	virtual void OnResize(); 
	virtual void UpdateScene(float dt)=0;
	virtual void DrawScene()=0; 
	virtual LRESULT MsgProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam);

	// Convenience overrides for handling mouse input.
	virtual void OnMouseDown(WPARAM btnState, int x, int y){ }
	virtual void OnMouseUp(WPARAM btnState, int x, int y)  { }
	virtual void OnMouseMove(WPARAM btnState, int x, int y){ }

protected:
	bool InitMainWindow();
	bool InitDirect3D();

	void CalculateFrameStats();

protected:

	HINSTANCE mhAppInst;//应用程序实例句柄//
	HWND      mhMainWnd;//主窗口句柄//
	bool      mAppPaused;//是否处于暂停//
	bool      mMinimized;//程序是否最小化//
	bool      mMaximized;//程序是否最大化//
	bool      mResizing;//是否处在改变大小的状态//
	UINT      m4xMsaaQuality;//4X MSAA质量等级//

	GameTimer mTimer;//记录delta和游戏时间//

	ID3D11Device* md3dDevice;//设备//
	ID3D11DeviceContext* md3dImmediateContext;//
	IDXGISwapChain* mSwapChain;//交换连//
	ID3D11Texture2D* mDepthStencilBuffer;//深度模板缓存纹理//
	ID3D11RenderTargetView* mRenderTargetView;//渲染目标视图////
	ID3D11DepthStencilView* mDepthStencilView;//深度模板视图//
	D3D11_VIEWPORT mScreenViewport;//视口//

	// Derived class should set these in derived constructor to customize starting values.
	std::wstring mMainWndCaption;//窗口标题//
	D3D_DRIVER_TYPE md3dDriverType;//硬件设备还是引用设备类型//
	//初始窗口大小//
	int mClientWidth;
	int mClientHeight;
	//是否使用4x多重采样//
	bool mEnable4xMsaa;
};

#endif // D3DAPP_H