#include "ShapeType.h"

std::string type_to_string(ShapeType type) {
  switch (type) {
  case ShapeType::Circle:
    return "Circle";
  case ShapeType::Rectangle:
    return "Rectangle";
  case ShapeType::Square:
    return "Square";
  default:
    return "Unknown";
  }
}

ShapeType string_to_type(const std::string &str) {
  if (str == "Circle" || str == "circle")
    return ShapeType::Circle;
  else if (str == "Rectangle" || str == "rectangle")
    return ShapeType::Rectangle;
  else if (str == "Square" || str == "square")
    return ShapeType::Square;
  else
    return ShapeType::Unknown;
}
