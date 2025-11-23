#pragma once

#include "Shape3D.h"

class Parallelepiped : public Shape3D {
  double a, b, c;

public:
  Parallelepiped(double a = 0, double b = 0, double c = 0);

  double area() const override;   // surface area: 2(ab+ac+bc)
  double volume() const override; // volume: abc

  std::string get_picture() const override; // same as rectangle (a x b)
  void input(std::istream &is) override;
  void output(std::ostream &os) const override;
};
