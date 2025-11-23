#include "Parallelepiped.h"
#include "ShapeType.h"
#include <istream>
#include <ostream>


Parallelepiped::Parallelepiped(double a, double b, double c)
    : a(a), b(b), c(c) {
  this->type = ShapeType::Parallelepiped;
}

double Parallelepiped::area() const { return 2.0 * (a * b + a * c + b * c); }

double Parallelepiped::volume() const { return a * b * c; }

std::string Parallelepiped::get_picture() const {
  std::string s;
  int ai = static_cast<int>(a);
  int bi = static_cast<int>(b);
  for (int i = 0; i < ai; ++i)
    s += '*';
  s += '\n';
  for (int i = 0; i < bi - 2; ++i) {
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

void Parallelepiped::input(std::istream &is) { is >> a >> b >> c; }

void Parallelepiped::output(std::ostream &os) const {
  os << type_to_string(type) << ' ' << a << ' ' << b << ' ' << c;
}
