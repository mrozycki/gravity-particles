#ifndef __SCENE_H__
#define __SCENE_H__

#include <ostream>
#include <vector>
#include "particle.h"
#include "gfx/color.h"

class scene {
  std::vector<Particle> particles;

public:
  scene();
  scene(int);
  virtual ~scene() {};

  void advance(double time_delta);
  std::vector<Particle> get_particles() const { return particles; }
  vec3d<double> gravity_on(Particle particle);

  canvas draw(int width, int height) const;
};

#endif
