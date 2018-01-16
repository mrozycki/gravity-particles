#include "vec3d.h"

template<typename T>
vec3d<T> vec3d<T>::operator*(T scale) const {
  return vec3d(m_x * scale, m_y * scale, m_z * scale );
}

template<typename T>
vec3d<T> vec3d<T>::operator/(T scale) const {
  return vec3d(m_x / scale, m_y / scale, m_z / scale );
}

template<typename T>
vec3d<T> vec3d<T>::operator+(const vec3d<T>& other) const {
  return vec3d(m_x + other.m_x, m_y + other.m_y, m_z + other.m_z );
}

template<typename T>
vec3d<T> vec3d<T>::operator-(const vec3d<T>& other) const {
  return vec3d(m_x - other.m_x, m_y - other.m_y, m_z - other.m_z );
}

template<typename T>
vec3d<T>& vec3d<T>::operator+=(const vec3d<T>& other) {
  m_x += other.m_x;
  m_y += other.m_y;
  m_z += other.m_z;
  return *this;
}

template<typename T>
bool vec3d<T>::operator==(const vec3d<T>& other) const {
  return m_x == other.m_x && m_y == other.m_y && m_z == other.m_z;
}

template<typename T>
vec3d<T> vec3d<T>::unit() {
  return (*this)/length();
}

template<typename T>
T vec3d<T>::length() {
  return sqrt(powl(m_x, 2) + powl(m_y, 2) + powl(m_z, 2));
}
