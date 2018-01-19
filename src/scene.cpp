#include <iostream>
#include <cmath>
#include "gfx/canvas.h"
#include "scene.h"
#include "particle.h"

scene::scene() : m_particles() {
  m_particles.push_back(random_particle());
}

scene::scene(int number_of_particles) : m_particles() {
  while (m_particles.size() < number_of_particles) {
    auto particle = random_particle();

    bool collides_with_anything = false;
    for (const auto& other : m_particles) {
      if (particle.collides_with(other)) {
        collides_with_anything = true;
        break;
      }
    }

    if (!collides_with_anything) {
      m_particles.push_back(particle);
    }
  }
}

vec3d<double> scene::gravity_on(Particle target) {
  auto total_gravity = vec3d<double>(0, 0, 0);
  for (const auto& particle : m_particles) {
    if (particle == target) continue;
    auto distance = (particle.position() - target.position()).length();
    auto direction = (particle.position() - target.position()).unit();
    total_gravity += direction * (target.mass() + particle.mass()) / powl(distance, 2);
  }
  return total_gravity;
}

void scene::advance(double time_delta) {
  auto new_particles = std::vector<Particle>();
  for (const auto& particle : m_particles) {
    new_particles.push_back(particle.update(gravity_on(particle), time_delta));
  }

  for (auto& particle : new_particles) {
    for (auto& other : new_particles) {
      particle.collide_with(other, time_delta);
    }
  }

  m_particles = new_particles;
}

canvas scene::draw(int width, int height) const {
  auto result = canvas(width, height);
  result.clear(color::WHITE);

  for (const auto& p: m_particles) {
    p.draw(result);
  }

  return result;
}
