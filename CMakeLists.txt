cmake_minimum_required(VERSION 3.0.2)
project(stack_simulator)

add_compile_options(-std=c++11)

find_package(SFML 2.5 COMPONENTS system window graphics REQUIRED)

include_directories(include)

set(sfml_libraries
  sfml-graphics
  sfml-window
  sfml-system
)

set(dependencies
  src/cellstack.cpp
  src/cell.cpp
  src/button.cpp
)

install(
  DIRECTORY font
  DESTINATION pepe
)

add_executable(main src/main.cpp ${dependencies})
target_link_libraries(main ${sfml_libraries})