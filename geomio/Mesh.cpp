#include "Mesh.h"

namespace geomio
{

Mesh::Mesh(std::vector<glm::vec3> vertices, std::vector<glm::vec3> normals, std::vector<Face> faces) :
	vertices_{std::move(vertices)},
	normals_{std::move(normals)},
	faces_{std::move(faces)}
{
}

const std::vector<glm::vec3>& Mesh::vertices() const
{
	return vertices_;
}

}
