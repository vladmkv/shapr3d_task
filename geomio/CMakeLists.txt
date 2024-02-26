add_library(geomio
	Mesh.h Mesh.cpp
	MeshImporter.h
	MeshTriangulator.h MeshTriangulator.cpp
	ObjMeshImporter.h ObjMeshImporter.cpp
	StlMeshExporter.h StlMeshExporter.cpp)

target_include_directories(geomio PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

add_subdirectory(third_party)

target_link_libraries(geomio PUBLIC glm)
target_link_libraries(geomio PUBLIC tinyobjloader)

add_subdirectory(tests)
