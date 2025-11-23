#include "Cube.h"
#include "ShapeType.h"
#include <istream>
#include <ostream>


Cube::Cube(double a) : a(a) { this->type = ShapeType::Cube; }

double Cube::area() const { return 6.0 * a * a; }

double Cube::volume() const { return a * a * a; }

std::string Cube::get_picture() const {
  std::string s;
  int ai = static_cast<int>(a);
  for (int i = 0; i < ai; ++i)
    s += '*';
  s += '\n';
  for (int i = 0; i < ai - 2; ++i) {
    s += '*';
    for (int j = 0; j < ai - 2; ++j)
      s += ' ';
    s += "*\n";
  }
  for (int i = 0; i < ai; ++i)
    s += '*';
  s += '\n';
  return s;
}

void Cube::input(std::istream &is) { is >> a; }

void Cube::output(std::ostream &os) const {
  os << type_to_string(type) << ' ' << a;
}
