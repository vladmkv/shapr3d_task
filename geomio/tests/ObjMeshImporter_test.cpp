#include "ObjMeshImporter.h"

#include <gtest/gtest.h>

using namespace geomio;

std::string makeCube()
{
	std::stringstream objStream;
	objStream << 
		"v 0.000000 2.000000 2.000000\n"
		"v 0.000000 0.000000 2.000000\n"
		"v 2.000000 0.000000 2.000000\n"
		"v 2.000000 2.000000 2.000000\n"
		"v 0.000000 2.000000 0.000000\n"
		"v 0.000000 0.000000 0.000000\n"
		"v 2.000000 0.000000 0.000000\n"
		"v 2.000000 2.000000 0.000000\n"
		"# 8 vertices\n"
		"\n"
		"f 1 2 3 4\n"
		"f 8 7 6 5\n"
		"f 4 3 7 8\n"
		"f 5 1 4 8\n"
		"f 5 6 2 1\n"
		"f 2 6 7 3\n"
		"# 6 elements";

	return objStream.str();
}

TEST(ObjMeshImporterTests, ImportCube)
{
	auto meshImporter = ObjMeshImporter{};
	ASSERT_TRUE(meshImporter.load(makeCube()));

	auto message{ meshImporter.getMessage() };
	ASSERT_TRUE(message.empty());

	auto mesh{ meshImporter.getMesh() };
	ASSERT_TRUE(mesh.vertices().size() == 24); // 6 faces * 4 vertices
}