/**
Terrain processing
*/
#pragma once

#include "D3D.h"
#include "Input.h"
#include "ShaderManager.h"
#include "Timer.h"
#include "UI.h"
#include "Camera.h"
#include "Position.h"
#include "Terrain.h"

class Zone
{
public:
  Zone();
  ~Zone();

  bool Initialize(D3D*, HWND, int, int, float);
  void Shutdown();
  bool Frame(D3D*, Input*, ShaderManager*, float, int);
private:
  void HandleMovementInput(Input*, float);
  bool Render(D3D*, ShaderManager*);

  UI* m_ui;
  Camera* m_cam;
  Position* m_pos;
  Terrain* m_terrain;
  bool m_displayUI;
};

