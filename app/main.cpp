#include <iostream>

#include "MeshTriangulator.h"
#include "ObjMeshImporter.h"
#include "StlMeshExporter.h"

using namespace geomio;

bool convert(const std::filesystem::path& inputFile, const std::filesystem::path& outputFile)
{
	std::cout << "Loading: " << std::filesystem::absolute(inputFile) << '\n';

	auto importer = ObjMeshImporter{};
	if(!importer.loadFromFile(inputFile))
	{
		std::cout << "Import error: " << importer.getMessage() << '\n';
		return false;
	}

	const auto mesh{ importer.getMesh() };
	const auto triangulatedMesh{ MeshTriangulator::process(mesh) };

	StlMeshExporter::saveToFile(triangulatedMesh, outputFile);

	return true;
}

int main(int argc, char* argv[])
{
	//convert("../../geomio/tests/resources/box.obj", "_box.stl");
	//convert("../../geomio/tests/resources/alfa147.obj", "_alfa147.stl");

	if (argc != 3)
	{
		std::cout << "Usage: <exe> <input_OBJ_path> <output_STL_path>\n";
		return 0;
	}

	convert({ argv[1] }, { argv[2] });
	return 0;
}
