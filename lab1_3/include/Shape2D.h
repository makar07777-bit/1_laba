#pragma once

#include "Shape.h"

class Shape2D : public Shape {
public:
  virtual double area() const = 0;
};
