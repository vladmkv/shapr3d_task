#pragma once

#include "ObjMeshImporter.h"

#include <sstream>
#include <string>

namespace test_utils
{

using namespace geomio;

inline std::string makeCube()
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

inline std::string makeTexturedTriangleWithNormals()
{
	std::stringstream objStream;
	objStream <<
		"v 0.000000 0.000000 0.000000\n"
		"v 2.000000 0.000000 0.000000\n"
		"v 2.000000 2.000000 0.000000\n"
		"vn 0.000000 0.000000 1.000000\n"
		"vn 0.000000 0.000000 1.000000\n"
		"vn 0.000000 0.000000 1.000000\n"
		"vt 0.0 0.0 [0]\n"
		"vt 0.0 1.0 [0]\n"
		"vt 1.0 1.0 [0]\n"
		"f 1/1/1 2/2/3 3/3/3\n";

	return objStream.str();
}

inline Mesh makeCubeMesh()
{
	auto meshImporter = ObjMeshImporter{};
	meshImporter.load(makeCube());
	return meshImporter.getMesh();
}

inline Mesh makeTriangleMesh()
{
	return {
	{{0, 0, 0}, {1, 0, 0}, {0, 1, 0}},
	{{0, 0, 1}},
	{{ { 0, 1, 2 }, { 0, 0, 0 } } }
	};
}

};