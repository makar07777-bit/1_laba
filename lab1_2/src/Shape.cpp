#include "Shape.h"
#include <istream>
#include <ostream>

std::string Shape::picture() const { return get_picture(); }

std::ostream &operator<<(std::ostream &os, const Shape &s) {
  s.output(os);
  return os;
}

std::istream &operator>>(std::istream &is, Shape &s) {
  s.input(is);
  return is;
}
