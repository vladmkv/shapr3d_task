#pragma once

#include <vector>

#include "Mesh.h"

namespace geomio
{

class MeshTriangulator
{
public:
	static std::vector<Mesh::Face> triangulate(const Mesh::Face& face);
	static Mesh process(const Mesh& sourceMesh);
};

}
