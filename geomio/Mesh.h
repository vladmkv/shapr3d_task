#pragma once

#include <glm/vec2.hpp>
#include <glm/vec3.hpp>

#include <vector>

namespace geomio
{

class Mesh
{
public:
	using Indices = std::vector<size_t>;
	struct Face
	{
		Indices vertexIndices;
		Indices normalIndices;
	};

	Mesh(std::vector<glm::vec3> vertices, std::vector<glm::vec3> normals, std::vector<Face> faces);

	const std::vector<glm::vec3>& vertices() const;

private:
	std::vector<glm::vec3> vertices_;
	std::vector<glm::vec3> normals_;
	std::vector<Face> faces_;
};

}
