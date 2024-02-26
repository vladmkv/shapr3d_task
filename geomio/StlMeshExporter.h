#pragma once

#include "Mesh.h"

#include <tiny_obj_loader.h>

namespace geomio
{

class StlMeshExporter
{
public:
	static void save(const Mesh& mesh, std::ostream& stream);
	void saveToFile(const Mesh& mesh);
	void saveToBuffer(const Mesh& mesh);
};

}
