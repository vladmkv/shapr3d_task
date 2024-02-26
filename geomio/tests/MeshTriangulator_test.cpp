#include "MeshTriangulator.h"

#include <gtest/gtest.h>

#include "TestUtils.h"

using namespace geomio;

TEST(MeshTriangulatorTests, TriangulateTriangle)
{
	const Mesh::Face triangle{ { 0, 1, 2 }, {} };
	const auto result{ MeshTriangulator::triangulate(triangle) };
	ASSERT_TRUE(result.size() == 1);
	ASSERT_TRUE(triangle.vertexIndices == result[0].vertexIndices);
}

TEST(MeshTriangulatorTests, TriangulateQuad)
{
	const Mesh::Face quad{ { 0, 1, 2, 3 }, {} };
	const auto triangles{ MeshTriangulator::triangulate(quad) };
	ASSERT_TRUE(triangles.size() == 2);

	const auto triangle1{Mesh::Indices{ 0, 1, 2 }};
	const auto triangle2{ Mesh::Indices{ 0, 2, 3 } };
	ASSERT_EQ(triangles[0].vertexIndices, triangle1);
	ASSERT_EQ(triangles[1].vertexIndices, triangle2);
}

TEST(MeshTriangulatorTests, TriangulateMesh)
{
	const auto cubeQuadMesh = test_utils::makeCubeMesh();
	ASSERT_EQ(cubeQuadMesh.faces().size(), 6);
	ASSERT_EQ(cubeQuadMesh.faces()[0].vertexIndices.size(), 4);

	const auto triangulatedMesh{ MeshTriangulator::process(cubeQuadMesh) };
	ASSERT_EQ(triangulatedMesh.faces().size(), 6 * 2);
	ASSERT_EQ(triangulatedMesh.vertices().size(), cubeQuadMesh.vertices().size());
	for (auto& face: triangulatedMesh.faces())
	{
		ASSERT_EQ(face.vertexIndices.size(), 3);
	}
}
