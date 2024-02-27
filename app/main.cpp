#include <iostream>

#include "MeshTriangulator.h"
#include "ObjMeshImporter.h"
#include "StlMeshExporter.h"

using namespace geomio;

int main()
{
	const std::filesystem::path filePath{"../../geomio/tests/resources/box.obj"};
	std::cout << "Loading: " << absolute(filePath) << '\n';

	auto importer = ObjMeshImporter{};
	if(!importer.loadFromFile(filePath))
	{
		std::cout << "Import error: " << importer.getMessage() << '\n';
		return 0;
	}

	const auto mesh{ importer.getMesh() };
	const auto triangulatedMesh{ MeshTriangulator::process(mesh) };

	StlMeshExporter::saveToFile(triangulatedMesh, { "box.stl" });

	return 0;
}
