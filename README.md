![Build status](https://github.com/vladmkv/shapr3d_task/actions/workflows/cmake-multi-platform.yml/badge.svg)

# OBJ to STL converter

Features:
- Cross-platform C++17 code
- Unit-tests covering core functionality based on gtest
- CMake build system

Implemented so far:
- Import from OBJ
- Mesh storage
- Shell face triangulation
- Calculate face normals from face plane
- Export to STL

TODO:
- Advanced triangulation

Third-party components:
- tinyobjloader for OBJ file parsing
- glm for geometry classes
- gtest

## Build instructions
CMake and C++ compiler are required. Tested with g++, clang and msvc.

Clone the repository including submodules: `$ git clone --recurse-submodules https://github.com/vladmkv/shapr3d_task.git`

Configure CMake project:
```
cd shapr3d_task
mkdir build
cd build
cmake -S .. -B.
```

Build CMake project: `cmake --build .`

Run CTest unit-tests: `ctest`

## Usage
```
cd build/app/Debug
app.exe ../../../geomio/tests/resources/box.obj box.stl
```
