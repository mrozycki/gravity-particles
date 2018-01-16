#pragma once

#include "math/vec3d.h"

class Particle {
  vec3d<double> m_position;
  vec3d<double> m_speed;
  double m_mass;

public:
  Particle(vec3d<double> position, vec3d<double> speed, double mass)
    : m_position(position), m_speed(speed), m_mass(mass) {};

  vec3d<double> position() const { return m_position; };
  vec3d<double> speed() const { return m_speed; };
  double mass() const { return m_mass; };

  Particle update(vec3d<double> force, double time_delta);

  bool operator==(const Particle &other) const;
};

Particle random_particle();
