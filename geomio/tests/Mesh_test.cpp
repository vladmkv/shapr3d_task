#include "Mesh.h"

#include <gtest/gtest.h>

using namespace geomio;
TEST(MeshTests, CreateTriangle)
{
	const auto mesh = Mesh{
		{{0, 0, 0}, {1, 0, 0}, {0, 1, 0}},
		{{0, 0, 1}},
		{{ { 0, 1, 2 }, { 0, 0, 0 } } } };

	ASSERT_TRUE(mesh.vertices().size() == 3);
	ASSERT_TRUE(mesh.normals().size() == 1);
	ASSERT_TRUE(mesh.faces().size() == 1);
}
