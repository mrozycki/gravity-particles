#include <cmath>
#include "gfx/canvas.h"
#include "scene.h"
#include "particle.h"

scene::scene() : m_particles() {
  m_particles.push_back(random_particle());
}

scene::scene(int number_of_particles) : m_particles() {
  for (int i = 0; i < number_of_particles; i++) {
    m_particles.push_back(random_particle());
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
  for (auto& particle : m_particles) {
    new_particles.push_back(particle.update(gravity_on(particle), time_delta));
  }

  m_particles = new_particles;
}

canvas scene::draw(int width, int height) const {
  auto result = canvas(width, height);
  result.clear(color::WHITE);

  for (const auto& p: m_particles) {
    if (p.position().x() < -width/2 || p.position().x() >= width/2
      || p.position().y() < -height/2 || p.position().y() >= height/2) continue;

    result.set_pixel(p.position().x() + width/2, p.position().y() + height/2, color::BLACK);
  }

  return result;
}
