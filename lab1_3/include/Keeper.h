#pragma once

#include <cstddef>
#include <iosfwd>

class Shape;

class Keeper {
  size_t capacity, size;
  Shape **shapes;

public:
  explicit Keeper(size_t capacity = 10);
  ~Keeper();

  size_t get_size() const noexcept;
  bool add(Shape *shape);
  bool remove(size_t id);
  void clear();

  Shape &operator[](size_t id);
  const Shape &operator[](size_t id) const;

  friend std::ostream &operator<<(std::ostream &os, const Keeper &keeper);
  friend std::istream &operator>>(std::istream &is, Keeper &keeper);
};
