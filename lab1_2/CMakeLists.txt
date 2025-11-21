cmake_minimum_required(VERSION 3.16)
project(lab1 CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(main
	main.cpp
	src/ShapeType.cpp
	src/Shape.cpp
	src/Circle.cpp
	src/Rectangle.cpp
	src/Square.cpp
	src/Keeper.cpp
)

target_include_directories(main PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)