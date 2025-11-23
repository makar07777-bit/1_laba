#pragma once

#include "Shape3D.h"

class Sphere : public Shape3D {
  double r;

public:
  explicit Sphere(double radius = 0);

  double area() const override;      // surface area
  double volume() const override;    // volume

  std::string get_picture() const override; // same as circle
  void input(std::istream &is) override;
  void output(std::ostream &os) const override;
};
