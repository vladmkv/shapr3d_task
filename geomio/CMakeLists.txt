add_library(geomio INTERFACE)

target_sources(geomio PUBLIC "Mesh.h")

target_include_directories(geomio INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})

add_subdirectory(third_party)

target_link_libraries(geomio INTERFACE glm)
target_link_libraries(geomio INTERFACE tinyobjloader)

add_subdirectory(tests)
