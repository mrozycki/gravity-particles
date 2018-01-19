#include "canvas.h"

canvas::canvas(size_t width, size_t height) : m_width(width), m_height(height) {
  m_pixels = new color*[m_width];
  for (int i = 0; i < m_width; i++) {
    m_pixels[i] = new color[height];
  }
}

canvas::~canvas() {
  for (int i = 0; i < m_width; i++) {
    delete [] m_pixels[i];
  }
  delete [] m_pixels;
}

void canvas::set_pixel(int x, int y, color c) {
  m_pixels[x][y] = c;
}

void canvas::circle(int x, int y, int r, color c) {
  if (x+r < 0 || x-r > (int)m_width || y+r < 0 || y-r > (int)m_height) return;

  for (int i = std::max(0, x-r); i <= std::min(x+r, (int)m_width-1); i++) {
    for (int j = std::max(0, y-r); j <= std::min(y+r, (int)m_height-1); j++) {
      if (powl(i-x, 2) + powl(j-y, 2) <= r*r) {
        m_pixels[i][j] = c;
      }
    }
  }
}

void canvas::dot(int x, int y, color c) {
  if (x < 0 || x >= m_width || y < 0 || y >= m_height) return;

  set_pixel(x, y, c);
}

void canvas::clear(color c) {
  for (int y = 0; y < m_height; y++) {
    for (int x = 0; x < m_width; x++) {
      m_pixels[x][y] = c;
    }
  }
}

void canvas::print_ppm(std::ostream& out) {
  out << "P1\n";
  out << m_width << " " << m_height << "\n";
  for (int y = 0; y < m_height; y++) {
    for (int x = 0; x < m_width; x++) {
      out << static_cast<int>(m_pixels[x][y]) << " ";
    }
    out << "\n";
  }
}
