#pragma once
#pragma comment(lib, "dxgi")
#pragma comment(lib, "d3d11")


#include <dxgi.h>
#include <d3dcommon.h>
#include <d3d11.h>
#include <DirectXMath.h>
#include <DirectXPackedVector.h>

#include "stdafx.h"

using namespace DirectX;

class D3D
{
public:
  D3D();
  ~D3D();
  
  bool Initialize(int, int, bool, HWND, bool, float, float);
  ID3D11Device* GetDevice();
  ID3D11DeviceContext* GetDeviceContext();
  void GetWorldMatrix(XMMATRIX &);
  void GetProjectionMatrix(XMMATRIX&);
  void GetOrthoMatrix(XMMATRIX&);
  void GetVideocardInfo(char*, int&);
  void BeginScene(float, float, float, float);
  void EndScene();
  void Shutdown();
private:
  bool m_vsync_enabled;
  int m_videocardMemory;
  char m_videocardInfo[128];
  IDXGISwapChain* m_swapChain;
  ID3D11Device* m_device;
  ID3D11DeviceContext* m_deviceContext;
  ID3D11RenderTargetView* m_rtView;
  ID3D11Texture2D* m_depthStencilBuffer;
  ID3D11DepthStencilState* m_depthStencilState;
  ID3D11DepthStencilView* m_depthStencilView;
  ID3D11RasterizerState* m_rasterState;
  XMMATRIX m_projection_matrix;
  XMMATRIX m_world_matrix;
  XMMATRIX m_ortho_matrix;
};

