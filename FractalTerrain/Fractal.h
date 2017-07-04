#pragma once
#include "stdafx.h"
#include <stdlib.h>
#include <time.h>
#include <math.h>

// determine how the range of generated random numbers is reduced at each iteration
// a high value results in smooth terrain

class Fractal
{
public:
  Fractal();
  ~Fractal();
  bool Initialize(int, int, int, float);
  bool Generate();
  float& operator()(int, int);
  float operator()(int, int) const;
  void Release();
private:
  void GenerateFractal();
  void GenerateFractalRecursive(float, int, int, int, int);
  void ClampTerrainHeight(float&, const float&, const float&);

  int m_width;
  int m_maxHeight;
  float m_roughness;
  float* m_fractalMap;
};
