#pragma once

#include <iostream>

class ProgressBar {
private:
  int m_max;
  int m_current;
  bool m_dirty;
  const int width = 60;

  int ratio(int value) { return value*100/m_max; }
  int ratio() { return ratio(m_current); }

public:
  ProgressBar(int max) : m_max(max), m_current(0), m_dirty(true) {}
  virtual ~ProgressBar() = default;

  void update(int new_current);
  void print(std::ostream& out);
};
