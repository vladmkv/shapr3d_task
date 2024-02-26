#pragma once

#include <glm/vec2.hpp>
#include <glm/vec3.hpp>
#include <glm/glm.hpp>

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

	const std::vector<glm::vec3>& vertices() const { return vertices_; }
	const std::vector<glm::vec3>& normals() const { return normals_; }
	const std::vector<Face>& faces() const { return faces_; }

	glm::vec3 vertex(const Face& face, size_t index) const
	{
		return vertices_[face.vertexIndices[index]];
	}

	glm::vec3 vertex(size_t faceIndex, size_t vertexIndex) const
	{
		return vertices_[faces_[faceIndex].vertexIndices[vertexIndex]];
	}

	glm::vec3 faceNormal(const Face& face) const
	{
		const glm::vec3 a{ vertex(face, 0) - vertex(face, 1) };
		const glm::vec3 b{ vertex(face, 0) - vertex(face, 2) };
		return glm::normalize(glm::cross(a, b));
	}

private:
	std::vector<glm::vec3> vertices_;
	std::vector<glm::vec3> normals_;
	std::vector<Face> faces_;
};

}
