#include "ObjMeshImporter.h"
#include "TestUtils.h"

#include <gtest/gtest.h>

using namespace geomio;

TEST(ObjMeshImporterTests, ImportCube)
{
	auto meshImporter = ObjMeshImporter{};
	ASSERT_TRUE(meshImporter.load(test_utils::makeCube()));

	auto message{ meshImporter.getMessage() };
	ASSERT_TRUE(message.empty());

	auto mesh{ meshImporter.getMesh() };
	ASSERT_TRUE(mesh.vertices().size() == 8); // unique vertices in a cube
}

TEST(ObjMeshImporterTests, ImportTriangle)
{
	auto meshImporter = ObjMeshImporter{};
	ASSERT_TRUE(meshImporter.load(test_utils::makeTexturedTriangleWithNormals()));

	auto message{ meshImporter.getMessage() };
	ASSERT_TRUE(message.empty());

	auto mesh{ meshImporter.getMesh() };
	ASSERT_TRUE(mesh.vertices().size() == 3); // unique vertices in a cube
	ASSERT_TRUE(mesh.normals().size() == 3); // unique vertices in a cube
}
