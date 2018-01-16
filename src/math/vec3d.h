#pragma once

#include <ostream>
#include <cmath>

template <typename T>
class vec3d {
  T m_x, m_y, m_z;

public:
  vec3d(T x, T y, T z) : m_x(x), m_y(y), m_z(z) {};
  virtual ~vec3d() {};

  T x() const { return m_x; }
  T y() const { return m_y; }
  T z() const { return m_z; }

  vec3d<T> operator*(T scale) const;
  vec3d<T> operator/(T scale) const;
  vec3d<T> operator+(const vec3d<T>& other) const;
  vec3d<T> operator-(const vec3d<T>& other) const;

  vec3d<T>& operator+=(const vec3d<T>& other);

  bool operator==(const vec3d<T>& other) const;

  vec3d<T> unit();
  T length();
};

template <typename T>
std::ostream& operator<<(std::ostream& out, const vec3d<T>& v) {
  return out << "[" << v.x() << "," << v.y() << "," << v.z() << "]";
}

template class vec3d<double>;
