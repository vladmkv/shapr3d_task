#include "MeshTriangulator.h"

#include <iterator>

namespace geomio
{

std::vector<Mesh::Face> MeshTriangulator::triangulate(const Mesh::Face& face)
{
	assert(face.vertexIndices.size() >= 3);

	if (face.vertexIndices.size() == 3)
	{
		return{ face };
	}

	std::vector<Mesh::Face> triangles;

	// Create triangle shell
	for(std::size_t i = 1; i < face.vertexIndices.size() - 1; ++i)
	{
		Mesh::Face triangle{ {face.vertexIndices[0], face.vertexIndices[i], face.vertexIndices[i + 1]}, {} };
		triangles.push_back(std::move(triangle));
	}

	return triangles;
}

Mesh MeshTriangulator::process(const Mesh& sourceMesh)
{
	std::vector<Mesh::Face> triangles;

	for(const auto& face: sourceMesh.faces())
	{
		auto faceTriangles{ triangulate(face) };
		std::move(faceTriangles.begin(), faceTriangles.end(), std::back_inserter(triangles));
	}

	return { sourceMesh.vertices(), sourceMesh.normals(), std::move(triangles) };
} 

}
