#ifndef __CANVAS_H__
#define __CANVAS_H__

#include <cstddef>
#include <ostream>
#include "color.h"

class canvas {
  size_t width, height;
  color **pixels;

public:
  canvas() {}
  canvas(size_t width, size_t height) {
    this->width = width;
    this->height = height;
    this->pixels = new color*[width];
    for (int i = 0; i < width; i++) {
      this->pixels[i] = new color[height];
    }
  }

  virtual ~canvas() {
    for (int i = 0; i < width; i++) {
      delete [] this->pixels[i];
    }
    delete [] pixels;
  }

  void set_pixel(int x, int y, color c) {
    this->pixels[x][y] = c;
  }

  void clear(color c) {
    for (int y = 0; y < this->height; y++) {
      for (int x = 0; x < this->width; x++) {
        this->pixels[x][y] = c;
      }
    }
  }

  void print_ppm(std::ostream& out) {
    out << "P1\n";
    out << this->width << " " << this->height << "\n";
    for (int y = 0; y < this->height; y++) {
      for (int x = 0; x < this->width; x++) {
        out << static_cast<int>(this->pixels[x][y]) << " ";
      }
      out << "\n";
    }
  }
};

#endif
