#include "Mesh.h"

namespace geomio
{
	Mesh::Mesh(std::vector<glm::vec3> vertices, std::vector<glm::vec3> normals, std::vector<glm::vec2> textureCoordinates) :
		vertices_{std::move(vertices)},
		normals_{std::move(normals)},
		textureCoordinates_{std::move(textureCoordinates)}
	{
	}

const std::vector<glm::vec3>& Mesh::vertices() const
{
	return vertices_;
}

}
