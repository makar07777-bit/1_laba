#pragma once

#include "ShapeType.h"
#include <string>


class Shape {
protected:
  static constexpr double pi = 3.1415926535;
  ShapeType type{ShapeType::Unknown};

  virtual std::string get_picture() const = 0;
  virtual void input(std::istream &is) = 0;
  virtual void output(std::ostream &os) const = 0;

public:
  virtual ~Shape() = default;

  virtual std::string picture() const;

  friend std::ostream &operator<<(std::ostream &os, const Shape &s);
  friend std::istream &operator>>(std::istream &is, Shape &s);
};
