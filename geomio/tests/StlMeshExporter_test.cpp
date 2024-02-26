#include "StlMeshExporter.h"
#include "TestUtils.h"

#include <algorithm>
#include <array>

#include <gtest/gtest.h>

using namespace geomio;

void verifyBytesContain(std::vector<char>::iterator& it, glm::vec3 vec)
{
	std::array<float, 3> coordinates{};
	const auto byteCount = sizeof(float) * 3;
	std::copy_n(it, byteCount, reinterpret_cast<char*>(coordinates.data()));
	ASSERT_EQ(coordinates[0], vec.x);
	ASSERT_EQ(coordinates[1], vec.y);
	ASSERT_EQ(coordinates[2], vec.z);
	it += byteCount;
}

TEST(StlMeshExporterTests, TriangleExport)
{
	std::ostringstream stream{};
	const auto mesh = test_utils::makeTriangleMesh();

	StlMeshExporter::save(mesh, stream);
	const auto str{ stream.str() };
	ASSERT_FALSE(str.empty());

	std::vector<char> byteVec{};
	std::copy_n(str.data(), str.size(), std::back_inserter(byteVec));

	// Header
	const size_t headerSize{ 80 };
	ASSERT_TRUE(std::all_of(byteVec.begin(), byteVec.begin() + headerSize, [](auto byteVal) { return byteVal == 0; }));

	// Number of triangles
	auto it{ byteVec.begin() + headerSize };
	const auto triangleCount{ *reinterpret_cast<uint32_t*>(&(*it)) };
	ASSERT_TRUE(triangleCount == 1);

	// Normal vector
	it += sizeof(uint32_t);
	const auto& meshNormal{ mesh.faceNormal(mesh.faces()[0]) };
	verifyBytesContain(it, meshNormal);

	// Vertices
	for(int i = 0; i < 3; ++i)
	{
		verifyBytesContain(it, mesh.vertex(0, i));
	}

	// Attribute byte count -- must be 0
	const auto byteCount{ *reinterpret_cast<uint16_t*>(&(*it)) };
	ASSERT_TRUE(byteCount == 0);
}
