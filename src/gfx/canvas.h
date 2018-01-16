#pragma once

#include <cstddef>
#include <ostream>
#include "color.h"

class canvas {
  size_t m_width, m_height;
  color **m_pixels;

public:
  canvas(size_t width, size_t height);
  virtual ~canvas();

  void set_pixel(int x, int y, color c);
  void clear(color c);
  void print_ppm(std::ostream& out);
};
