#include "Sphere.h"
#include "ShapeType.h"
#include <cmath>
#include <ostream>
#include <istream>

Sphere::Sphere(double radius) : r(radius) { this->type = ShapeType::Sphere; }

double Sphere::area() const { return 4.0 * pi * r * r; }

double Sphere::volume() const { return (4.0 / 3.0) * pi * r * r * r; }

std::string Sphere::get_picture() const {
  // reuse circle-like ASCII art by radius
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

      if (distance_sq >= radius_sq - radius && distance_sq <= radius_sq + radius) {
        line += '*';
      } else {
        line += ' ';
      }
    }
    result += line + '\n';
  }

  return result;
}

void Sphere::input(std::istream &is) { is >> r; }

void Sphere::output(std::ostream &os) const {
  os << type_to_string(type) << ' ' << r;
}
