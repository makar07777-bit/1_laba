#pragma once

#include <string>

enum class ShapeType : unsigned char { Unknown, Circle, Rectangle, Square };

std::string type_to_string(ShapeType type);
ShapeType string_to_type(const std::string &str);
