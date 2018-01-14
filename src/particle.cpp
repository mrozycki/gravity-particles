#include "particle.h"
#include "math/vec3d.h"

Particle random_particle() {
  auto position = vec3d<double>(rand()%320-320, rand()%320-240, rand()%256);
  auto speed = vec3d<double>(rand(), rand(), rand()).unit();
  return Particle(position, speed, 1);
}

Particle Particle::update(vec3d<double> force, double time_delta) {
  auto acceleration = force / mass();
  auto new_velocity = speed() + acceleration * time_delta;
  auto new_position = position() + new_velocity * time_delta;

  return Particle(new_position, new_velocity, mass());
}
