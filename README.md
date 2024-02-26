![Build status](https://github.com/vladmkv/shapr3d_task/actions/workflows/cmake-multi-platform.yml/badge.svg)

# OBJ to STL converter

Features:
- Cross-platform C++17 code
- Unit-tests based on gtest
- CMake build system

Implemented so far:
- Mesh storage
- Shell face triangulation
- Import from OBJ string

TODO:
- Calculate triangle normals
- Export to STL
- Read OBJ from disk
- Advanced triangulation

Third-party components:
- tinyobjloader for OBJ file parsing
- glm for geometry classes
- gtest
