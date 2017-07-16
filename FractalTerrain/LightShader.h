#pragma once
#include <d3d11.h>
#include <d3dcompiler.h>
#include <DirectXMath.h>
#include <fstream>
#include "stdafx.h"

class LightShader
{
public:
  LightShader();
  ~LightShader();
  bool Initialize(ID3D11Device*, HWND);
  void Shutdown();
  bool Render(ID3D11DeviceContext*, int, DirectX::XMMATRIX&, DirectX::XMMATRIX&, DirectX::XMMATRIX&, ID3D11ShaderResourceView*, DirectX::XMFLOAT3, DirectX::XMFLOAT4);
private:
  bool InitializeShader(ID3D11Device*, HWND, WCHAR*, WCHAR*);
  void ShutdownShader();
  void OutputShaderError(ID3D10Blob*, HWND, WCHAR*);
  bool SetShaderParams(ID3D11DeviceContext*, DirectX::XMMATRIX&, DirectX::XMMATRIX&, DirectX::XMMATRIX&, ID3D11ShaderResourceView*, DirectX::XMFLOAT3, DirectX::XMFLOAT4);
  void RenderShader(ID3D11DeviceContext*, int);

  ID3D11VertexShader* m_vertexShader;
  ID3D11PixelShader* m_pixelShader;
  ID3D11InputLayout* m_layout;
  ID3D11Buffer* m_matrixBuffer;
  ID3D11SamplerState* m_sampleState;
  ID3D11Buffer* m_lightBuffer;

  struct MatrixBuffer_T
  {
    DirectX::XMMATRIX world, view, projection;
  };
  struct LightBuffer_T
  {
    DirectX::XMFLOAT4 diffuse;
    DirectX::XMFLOAT3 direction;
    float padding; // make the type a multiple of 16 bytes
  };
};

