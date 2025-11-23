#pragma once

#include "Shape2D.h"

class Shape3D : public Shape2D {
public:
  virtual double volume() const = 0;
};
