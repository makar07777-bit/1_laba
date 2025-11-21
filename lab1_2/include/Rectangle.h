#pragma once

#include "Shape2D.h"

class Rectangle : public Shape2D {
  double a, b;

public:
  Rectangle(double a = 0, double b = 0);

  double area() const override;
  std::string get_picture() const override;
  void input(std::istream &is) override;
  void output(std::ostream &os) const override;
};
