#ifndef __PROGRESS_BAR_H__
#define __PROGRESS_BAR_H__

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

  void update(int new_current) {
    m_dirty = (ratio(new_current) != ratio(m_current));
    m_current = new_current;
  }

  void print(std::ostream& out) {
    if (!m_dirty) return;
    m_dirty = false;

    int crosses = ratio()*width/100;
    int dots = width-crosses;

    out << "\r[";
    for (int i = 0; i < crosses; i++) out << "#";
    for (int i = 0; i < dots; i++) out << ".";
    out << "] " << ratio() << "\%" << std::flush;
  }
};

#endif
