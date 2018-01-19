#pragma once

#include "gfx/canvas.h"
#include "math/vec3d.h"

class Particle {
  vec3d<double> m_position;
  vec3d<double> m_speed;
  double m_mass;
  double m_radius;

public:
  Particle(vec3d<double> position, vec3d<double> speed, double mass, double radius)
    : m_position(position), m_speed(speed), m_mass(mass), m_radius(radius) {};

  vec3d<double> position() const { return m_position; };
  vec3d<double> speed() const { return m_speed; };
  double mass() const { return m_mass; };
  double radius() const { return m_radius; };

  Particle update(vec3d<double> force, double time_delta) const;

  double distance_from(const Particle& other) const;
  vec3d<double> direction_to(const Particle& other) const;
  bool collides_with(const Particle& other) const;
  void collide_with(Particle& other, double time_delta);

  bool operator==(const Particle &other) const;

  void draw(canvas& c) const;
};

Particle random_particle();
