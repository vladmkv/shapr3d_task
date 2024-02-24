add_library(geomio INTERFACE)

target_sources(geomio PUBLIC "Mesh.h")

target_include_directories(geomio INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})

add_subdirectory(tests)
