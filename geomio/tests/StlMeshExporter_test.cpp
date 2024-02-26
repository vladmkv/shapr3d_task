#include "StlMeshExporter.h"
#include "TestUtils.h"

#include <algorithm>
#include <array>
#include <cstdint>

#include <gtest/gtest.h>

using namespace geomio;

namespace export_test
{

void verifyVec3(std::istream& stream, glm::vec3 vec)
{
	float x, y, z;
	ASSERT_TRUE(read(stream, x));
	ASSERT_TRUE(read(stream, y));
	ASSERT_TRUE(read(stream, z));
	ASSERT_EQ(x, vec.x);
	ASSERT_EQ(y, vec.y);
	ASSERT_EQ(z, vec.z);
}

TEST(StlMeshExporterTests, TriangleExport)
{
	std::stringstream stream{};
	const auto mesh = test_utils::makeTriangleMesh();

	StlMeshExporter::save(mesh, stream);
	stream.seekg(0);

	// Header
	const size_t headerSize{ 80 };
	char b;

	for (auto i = 0; i < headerSize; ++i)
	{
		ASSERT_TRUE(read(stream, b));
		ASSERT_EQ(b, 0);
	}

	// Number of triangles
	int32_t triangleCount;
	ASSERT_TRUE(read(stream, triangleCount));
	ASSERT_TRUE(triangleCount == 1);

	// Normal vector
	const auto& faceNormal{ mesh.faceNormal(mesh.faces()[0]) };
	verifyVec3(stream, faceNormal);

	// Vertices
	for(int i = 0; i < 3; ++i)
	{
		const auto& vertex{ mesh.vertex(0, i)};
		verifyVec3(stream, vertex);
	}

	// Attribute byte count -- must be 0
	uint16_t byteCount;
	read(stream, byteCount);
	ASSERT_TRUE(byteCount == 0);
}

TEST(StlMeshExporterTests, StreamIoTest)
{
	std::stringstream stream{};
	const std::array<float, 3> a{ 1.0, 2.0, 3.0 };

	ASSERT_TRUE(write(stream, a));

	stream.seekg(0);

	verifyVec3(stream, { 1.0, 2.0, 3.0 });
}

}