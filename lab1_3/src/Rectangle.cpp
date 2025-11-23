#include "Rectangle.h"
#include "ShapeType.h"
#include <istream>
#include <ostream>


Rectangle::Rectangle(double a, double b) : a(a), b(b) {
  this->type = ShapeType::Rectangle;
}

double Rectangle::area() const { return a * b; }

std::string Rectangle::get_picture() const {
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

void Rectangle::input(std::istream &is) { is >> a >> b; }

void Rectangle::output(std::ostream &os) const {
  os << type_to_string(type) << ' ' << a << ' ' << b;
}
