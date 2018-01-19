#include <iostream>
#include <vector>
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

std::vector<std::pair<Particle*, vec3d<double>>> scene::calculate_gravity() {
  std::vector<std::pair<Particle*, vec3d<double>>> result;

  for (auto& particle : m_particles) {
    vec3d<double> total_gravity = vec3d<double>(0, 0, 0);
    for (auto& other : result) {
      auto direction = particle.direction_to(*other.first);
      auto mass_sum = particle.mass() + other.first->mass();
      auto distance = particle.distance_from(*other.first);
      auto partial_gravity = direction * mass_sum / powl(distance, 2);

      total_gravity += partial_gravity;
      other.second -= partial_gravity;
    }
    result.push_back(std::make_pair(&particle, total_gravity));
  }

  return result;
}

void scene::advance(double time_delta) {
  auto gravities = calculate_gravity();
  for (auto& particle : gravities) {
    particle.first->update(particle.second, time_delta);
  }

  for (auto& particle : m_particles) {
    for (auto& other : m_particles) {
      particle.collide_with(other, time_delta);
    }
  }
}

canvas scene::draw(int width, int height) const {
  auto result = canvas(width, height);
  result.clear(color::WHITE);

  for (const auto& p: m_particles) {
    p.draw(result);
  }

  return result;
}
