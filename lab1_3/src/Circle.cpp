#include "Circle.h"
#include "ShapeType.h"
#include <istream>
#include <ostream>


Circle::Circle(double radius) : r(radius) { this->type = ShapeType::Circle; }

double Circle::area() const { return pi * r * r; }

std::string Circle::get_picture() const {
  int radius = static_cast<int>(r);
  if (radius <= 0)
    return "";

  int size = 2 * radius + 1;
  std::string result;

  for (int y = 0; y < size; y++) {
    std::string line;
    for (int x = 0; x < size; x++) {
      int dx = x - radius;
      int dy = (y - radius) * 2;

      int distance_sq = dx * dx + dy * dy;
      int radius_sq = radius * radius;

      if (distance_sq >= radius_sq - radius &&
          distance_sq <= radius_sq + radius) {
        line += '*';
      } else {
        line += ' ';
      }
    }
    result += line + '\n';
  }

  return result;
}

void Circle::input(std::istream &is) { is >> r; }

void Circle::output(std::ostream &os) const {
  os << type_to_string(type) << ' ' << r;
}
