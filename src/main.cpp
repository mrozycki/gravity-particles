#include <iostream>
#include <iomanip>
#include <fstream>
#include <chrono>
#include "math/vec3d.h"
#include "gfx/canvas.h"
#include "scene.h"
#include "particle.h"
#include "utils/progress_bar.h"

using std::cout;
using std::endl;
namespace chrono = std::chrono;

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
  cout << "Gravity Particles v" << build_number << endl;

  auto start_time = chrono::steady_clock::now();

  cout << "> Generating random scene...";
  auto s = scene(5000);
  cout << " DONE" << endl;

  const int frames = 100;
  cout << "> Generating " << frames << " frames of simulation..." << endl;
  ProgressBar pb(frames);
  pb.print(cout);

  for (int i = 1; i <= frames; i++) {
    s.advance(1);
    pb.update(i);
    pb.print(cout);

    std::ofstream file(get_filename(i));
    s.draw(320, 200).print_ppm(file);
  }
  cout << endl << "\tDONE" << endl;

  auto end_time = chrono::steady_clock::now();
  auto elapsed = chrono::duration_cast<chrono::seconds>(end_time-start_time);
  cout << "Took " << elapsed.count() << "s" << endl;

  return 0;
}
