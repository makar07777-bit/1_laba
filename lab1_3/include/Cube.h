#pragma once

#include "Shape3D.h"

class Cube : public Shape3D {
  double a;

public:
  explicit Cube(double a = 0);

  double area() const override;   // surface area
  double volume() const override; // volume

  std::string get_picture() const override; // same as square
  void input(std::istream &is) override;
  void output(std::ostream &os) const override;
};
