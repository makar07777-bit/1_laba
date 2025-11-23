#include "ShapeType.h"

std::string type_to_string(ShapeType type) {
  switch (type) {
  case ShapeType::Circle:
    return "Circle";
  case ShapeType::Rectangle:
    return "Rectangle";
  case ShapeType::Square:
    return "Square";
  case ShapeType::Sphere:
    return "Sphere";
  case ShapeType::Cube:
    return "Cube";
  case ShapeType::Parallelepiped:
    return "Parallelepiped";
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
  else if (str == "Sphere" || str == "sphere")
    return ShapeType::Sphere;
  else if (str == "Cube" || str == "cube")
    return ShapeType::Cube;
  else if (str == "Parallelepiped" || str == "parallelepiped" || str == "Box" ||
           str == "box" || str == "RectangularParallelepiped" ||
           str == "rectangularparallelepiped")
    return ShapeType::Parallelepiped;
  else
    return ShapeType::Unknown;
}
