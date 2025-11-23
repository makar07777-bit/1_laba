#pragma once

#include "Shape2D.h"

class Circle : public Shape2D {
  double r;

public:
  explicit Circle(double radius = 0);

  double area() const override;
  std::string get_picture() const override;
  void input(std::istream &is) override;
  void output(std::ostream &os) const override;
};
