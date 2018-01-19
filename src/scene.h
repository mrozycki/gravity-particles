#pragma once

#include <ostream>
#include <vector>
#include "particle.h"
#include "gfx/color.h"

class scene {
  std::vector<Particle> m_particles;

public:
  scene();
  scene(int);
  virtual ~scene() {};

  void advance(double time_delta);
  std::vector<Particle> particles() const { return m_particles; }
  std::vector<std::pair<Particle*, vec3d<double>>> calculate_gravity();

  canvas draw(int width, int height) const;
};
