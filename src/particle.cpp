#include <cmath>
#include <iostream>
#include "particle.h"
#include "math/vec3d.h"
#include "gfx/color.h"

template <typename T>
void debug(std::string name, T value) {
  std::cout << name << ": " << value << std::endl;
}

void Particle::update(vec3d<double> force, double time_delta) {
  auto acceleration = force / mass();
  m_speed += acceleration * time_delta;
  m_position += m_speed * time_delta;
}

bool Particle::operator==(const Particle &other) const {
  return m_position == other.m_position
      && m_speed == other.m_speed
      && m_mass == other.m_mass;
}

double Particle::distance_from(const Particle& other) const {
  return (other.m_position - m_position).length();
}

vec3d<double> Particle::direction_to(const Particle& other) const {
  return (other.m_position - m_position).unit();
}

bool Particle::collides_with(const Particle& other) const {
  if (this == &other) return false;
  return distance_from(other) < m_radius + other.m_radius;
}

void Particle::collide_with(Particle& other, double time_delta) {
  if (!collides_with(other)) return;

  auto new_x = direction_to(other);
  auto x1 = m_position.dot(new_x), x2 = other.m_position.dot(new_x);
  auto v1 = m_speed.dot(new_x), v2 = other.m_speed.dot(new_x);
  if (v1-v2 < 0) return;

  auto backoff = m_radius + other.m_radius - (x2-x1);
  auto backoff_time = backoff/(v1-v2);
  auto nx1 = x1-v1*backoff_time + (time_delta-backoff_time)*v2;
  auto nx2 = x2-v2*backoff_time + (time_delta-backoff_time)*v1;

  m_position = m_position + (nx1-x1)*new_x;
  other.m_position = other.m_position + (nx1-x1)*new_x;
  m_speed = m_speed + (0.9*v2-v1)*new_x;
  other.m_speed = other.m_speed + (0.9*v1-v2)*new_x;
}

void Particle::draw(canvas& c) const {
  c.dot(m_position.x(), m_position.y(), color::BLACK);
}

Particle random_particle() {
  constexpr int width = 320;
  constexpr int height = 200;
  auto position = vec3d<double>(rand()%width, rand()%height, rand()%((width+height)/2));
  auto speed = vec3d<double>(rand()%200-100, rand()%200-100, rand()%200-100).unit();
  return Particle(position, speed, 1, 0.5);
}
