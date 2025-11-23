#include "Square.h"
#include "ShapeType.h"
#include <istream>
#include <ostream>


Square::Square(double a) : a(a) { this->type = ShapeType::Square; }

double Square::area() const { return a * a; }

std::string Square::get_picture() const {
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

void Square::input(std::istream &is) { is >> a; }

void Square::output(std::ostream &os) const {
  os << type_to_string(type) << ' ' << a;
}
