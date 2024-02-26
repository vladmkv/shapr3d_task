set(gtest_force_shared_crt on)

include(FetchContent)

FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG        v1.14.0
)
FetchContent_MakeAvailable(googletest)
add_library(GTest::GTest INTERFACE IMPORTED)
target_link_libraries(GTest::GTest INTERFACE gtest_main)

add_executable(tests
	Mesh_test.cpp
	MeshTriangulator_test.cpp
	ObjMeshImporter_test.cpp
	TestUtils.h
)

target_link_libraries(tests
 PRIVATE
  GTest::GTest
  geomio)

add_test(tests tests)
