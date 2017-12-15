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

	HINSTANCE mhAppInst;//Ӧ�ó���ʵ�����//
	HWND      mhMainWnd;//�����ھ��//
	bool      mAppPaused;//�Ƿ�����ͣ//
	bool      mMinimized;//�����Ƿ���С��//
	bool      mMaximized;//�����Ƿ����//
	bool      mResizing;//�Ƿ��ڸı��С��״̬//
	UINT      m4xMsaaQuality;//4X MSAA�����ȼ�//

	GameTimer mTimer;//��¼delta����Ϸʱ��//

	ID3D11Device* md3dDevice;//�豸//
	ID3D11DeviceContext* md3dImmediateContext;//
	IDXGISwapChain* mSwapChain;//������//
	ID3D11Texture2D* mDepthStencilBuffer;//���ģ�建������//
	ID3D11RenderTargetView* mRenderTargetView;//��ȾĿ����ͼ////
	ID3D11DepthStencilView* mDepthStencilView;//���ģ����ͼ//
	D3D11_VIEWPORT mScreenViewport;//�ӿ�//

	// Derived class should set these in derived constructor to customize starting values.
	std::wstring mMainWndCaption;//���ڱ���//
	D3D_DRIVER_TYPE md3dDriverType;//Ӳ���豸���������豸����//
	//��ʼ���ڴ�С//
	int mClientWidth;
	int mClientHeight;
	//�Ƿ�ʹ��4x���ز���//
	bool mEnable4xMsaa;
};

#endif // D3DAPP_H