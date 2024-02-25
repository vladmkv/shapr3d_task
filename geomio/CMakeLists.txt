add_library(geomio
	Mesh.h Mesh.cpp
	MeshImporter.h
	ObjMeshImporter.h ObjMeshImporter.cpp)

target_include_directories(geomio PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

add_subdirectory(third_party)

target_link_libraries(geomio PUBLIC glm)
target_link_libraries(geomio PUBLIC tinyobjloader)

add_subdirectory(tests)
