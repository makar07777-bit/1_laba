#include "Keeper.h"
#include "Circle.h"
#include "Rectangle.h"
#include "Shape.h"
#include "Shape2D.h"
#include "ShapeType.h"
#include "Square.h"


#include <iostream>
#include <limits>

Keeper::Keeper(size_t capacity)
    : capacity(capacity), size(0), shapes(new Shape *[capacity]) {}

Keeper::~Keeper() {
  for (size_t i = 0; i < size; ++i)
    delete shapes[i];
  delete[] shapes;
}

size_t Keeper::get_size() const noexcept { return size; }

bool Keeper::add(Shape *shape) {
  if (size == capacity)
    return false;
  shapes[size++] = shape;
  return true;
}

bool Keeper::remove(size_t id) {
  if (id >= size)
    return false;
  delete shapes[id];
  for (size_t i = id; i + 1 < size; ++i)
    shapes[i] = shapes[i + 1];
  shapes[size - 1] = nullptr;
  --size;
  return true;
}

void Keeper::clear() {
  for (size_t i = 0; i < size; ++i) {
    delete shapes[i];
    shapes[i] = nullptr;
  }
  size = 0;
}

Shape &Keeper::operator[](size_t id) { return *shapes[id]; }
const Shape &Keeper::operator[](size_t id) const { return *shapes[id]; }

std::ostream &operator<<(std::ostream &os, const Keeper &keeper) {
  for (size_t i = 0; i < keeper.size; ++i)
    os << *keeper.shapes[i] << '\n';
  return os;
}

std::istream &operator>>(std::istream &is, Keeper &keeper) {
  std::string type;
  while (is >> type) {
    Shape *shape = nullptr;
    switch (string_to_type(type)) {
    case ShapeType::Circle:
      shape = new Circle();
      break;
    case ShapeType::Rectangle:
      shape = new Rectangle();
      break;
    case ShapeType::Square:
      shape = new Square();
      break;
    default:
      is.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      continue;
    }

    if (shape) {
      is >> *shape;
      keeper.add(shape);
    }
  }
  return is;
}
