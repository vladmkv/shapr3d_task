#include "Mesh.h"

#include <gtest/gtest.h>

#include "TestUtils.h"

using namespace geomio;
TEST(MeshTests, CreateTriangle)
{
	const auto mesh{ test_utils::makeTriangleMesh() };
	ASSERT_TRUE(mesh.vertices().size() == 3);
	ASSERT_TRUE(mesh.vertex(0, 0) == glm::vec3(0, 0, 0));
	ASSERT_TRUE(mesh.vertex(0, 1) == glm::vec3(1, 0, 0));
	ASSERT_TRUE(mesh.vertex(0, 2) == glm::vec3(0, 1, 0));
	ASSERT_TRUE(mesh.normals().size() == 1);
	ASSERT_TRUE(mesh.faces().size() == 1);
	ASSERT_TRUE(mesh.faceNormal(mesh.faces()[0]) == glm::vec3(0, 0, 1));
}
