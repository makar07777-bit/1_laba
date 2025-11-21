#pragma once

#include "Shape2D.h"

class Square : public Shape2D {
  double a;

public:
  explicit Square(double a = 0);

  double area() const override;
  std::string get_picture() const override;
  void input(std::istream &is) override;
  void output(std::ostream &os) const override;
};
