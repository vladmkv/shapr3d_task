cmake_minimum_required(VERSION 3.14)

project(obj2stl VERSION "1.0" LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

enable_testing()

add_subdirectory(geomio)
add_subdirectory(app)
