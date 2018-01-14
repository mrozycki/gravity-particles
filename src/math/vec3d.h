#ifndef __VEC3D_H__
#define __VEC3D_H__

#include <ostream>
#include <cmath>

template <typename T>
class vec3d {
  T _x, _y, _z;

public:
  vec3d(T x, T y, T z) : _x(x), _y(y), _z(z) {};
  virtual ~vec3d() {};

  T x() const { return this->_x; }
  T y() const { return this->_y; }
  T z() const { return this->_z; }

  vec3d<T> operator*(T scale) const { return vec3d(_x * scale, _y * scale, _z * scale ); }
  vec3d<T> operator/(T scale) const { return vec3d(_x / scale, _y / scale, _z / scale ); }
  vec3d<T> operator+(const vec3d<T>& other) const { return vec3d(_x + other._x, _y + other._y, _z + other._z ); }
  vec3d<T>& operator+=(const vec3d<T>& other) { _x += other._x; _y += other._y; _z += other._z; return *this; }
  vec3d<T> operator-(const vec3d<T>& other) const { return vec3d(_x - other._x, _y - other._y, _z - other._z ); }
  bool operator==(const vec3d<T>& other) const { return _x == other._x && _y == other._y && _z == other._z; }

  vec3d<T> unit() { return (*this)/length(); }
  T length() { return sqrt(powl(_x, 2) + powl(_y, 2) + powl(_z, 2)); }
};

template <typename T>
std::ostream& operator<<(std::ostream& out, const vec3d<T>& v) {
  return out << "[" << v.x() << "," << v.y() << "," << v.z() << "]";
}

#endif
