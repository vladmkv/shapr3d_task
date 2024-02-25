#pragma once

#include <glm/vec2.hpp>
#include <glm/vec3.hpp>

#include <vector>

namespace geomio
{

class Mesh
{
	using Face = std::vector<size_t>; // vertex indices

public:
	Mesh(std::vector<glm::vec3> vertices, std::vector<glm::vec3> normals, std::vector<glm::vec2> textureCoordinates);

	const std::vector<glm::vec3>& vertices() const;

private:
	std::vector<glm::vec3> vertices_;
	std::vector<glm::vec3> normals_;
	std::vector<glm::vec2> textureCoordinates_;
	std::vector<Face> faces_;
};

}
