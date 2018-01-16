#include "progress_bar.h"

void ProgressBar::update(int new_current) {
  m_dirty = (ratio(new_current) != ratio(m_current));
  m_current = new_current;
}

void ProgressBar::print(std::ostream& out) {
  if (!m_dirty) return;
  m_dirty = false;

  int crosses = ratio()*width/100;
  int dots = width-crosses;
  
  out << "\r[";
  for (int i = 0; i < crosses; i++) out << "#";
  for (int i = 0; i < dots; i++) out << ".";
  out << "] " << ratio() << "\%" << std::flush;
}
