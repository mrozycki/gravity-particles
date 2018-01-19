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
vec3d<T> vec3d<T>::cross(const vec3d<T>& other) const {
  return vec3d(
    m_y * other.m_z + m_z * other.m_y,
    -(m_x * other.m_z + m_z * other.m_x),
    m_x * other.m_y + m_y * other.m_x
  );
}

template<typename T>
T vec3d<T>::dot(const vec3d<T>& other) const {
  return m_x * other.m_x + m_y * other.m_y + m_z * other.m_z;
}

template<typename T>
vec3d<T> vec3d<T>::unit() const {
  return (*this)/length();
}

template<typename T>
T vec3d<T>::length() const {
  return sqrt(powl(m_x, 2) + powl(m_y, 2) + powl(m_z, 2));
}

template<typename T>
vec3d<T> vec3d<T>::rebase(vec3d<T> new_x, vec3d<T> new_y, vec3d<T> new_z) const {
  return vec3d<T>(dot(new_x), dot(new_y), dot(new_z));
}
