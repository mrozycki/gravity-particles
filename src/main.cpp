#include <iostream>
#include <iomanip>
#include <fstream>
#include "math/vec3d.h"
#include "gfx/canvas.h"
#include "scene.h"
#include "particle.h"
#include "utils/progress_bar.h"

std::string get_filename(int frame_number) {
  std::ostringstream filenameStream;
  filenameStream << "output/frame_"
    << std::setw(4) << std::setfill('0') << frame_number
    << ".pbm";

  return filenameStream.str();
}

int main()
{
  const auto build_number = 1;
  std::cout << "Gravity Particles v" << build_number << std::endl;

  auto s = scene(1000);

  const int frames = 200;
  ProgressBar pb(frames);
  pb.print(std::cout);

  for (int i = 1; i <= frames; i++) {
    std::ofstream file(get_filename(i));
    s.draw(640, 480).print_ppm(file);
    s.advance(1);
    pb.update(i);
    pb.print(std::cout);
  }

  return 0;
}
