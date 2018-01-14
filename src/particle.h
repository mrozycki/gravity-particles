#ifndef __PARTICLE_H__
#define __PARTICLE_H__

#include "math/vec3d.h"

class Particle {
  vec3d<double> _position;
  vec3d<double> _speed;
  double _mass;

public:
  Particle(vec3d<double> position, vec3d<double> speed, double mass)
    : _position(position), _speed(speed), _mass(mass) {};

  vec3d<double> position() const { return this->_position; };
  vec3d<double> speed() const { return this->_speed; };
  double mass() const { return this->_mass; };
  Particle update(vec3d<double> force, double time_delta);

  bool operator==(const Particle &other) const {
    return _position == other._position && _speed == other._speed && _mass == other._mass;
  }
};

Particle random_particle();

#endif
