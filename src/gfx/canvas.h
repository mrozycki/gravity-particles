#pragma once

#include <cstddef>
#include <ostream>
#include <cmath>
#include "color.h"

class canvas {
  size_t m_width, m_height;
  color **m_pixels;
  void set_pixel(int x, int y, color c);

public:
  canvas(size_t width, size_t height);
  virtual ~canvas();

  void circle(int x, int y, int radius, color c);
  void dot(int x, int y, color c);
  void clear(color c);
  void print_ppm(std::ostream& out);
};
