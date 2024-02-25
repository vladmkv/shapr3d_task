#include "ObjMeshImporter.h"

#include <tiny_obj_loader.h>

#include <cassert>


namespace geomio
{

bool ObjMeshImporter::load(const std::string& text)
{
	tinyobj::ObjReaderConfig reader_config{};
	reader_config.triangulate = false;
	reader_config.vertex_color = false;

	return reader_.ParseFromString(text, {}, reader_config) ? reader_.Valid() : false;
}

// Original sample code: https://github.com/tinyobjloader/tinyobjloader/tree/release#example-code-new-object-oriented-api
Mesh ObjMeshImporter::getMesh() const
{
	auto& attrib = reader_.GetAttrib();
	auto& shapes = reader_.GetShapes();
	
	assert(shapes.size() == 1);

	std::vector<glm::vec3> vertices{};
	std::vector<glm::vec3> normals{};
	std::vector<glm::vec2> textureCoordinates{};

	// Loop over shapes
	for (size_t s = 0; s < shapes.size(); s++) {
		// Loop over faces(polygon)
		size_t index_offset = 0;
		for (size_t f = 0; f < shapes[s].mesh.num_face_vertices.size(); f++) {
			auto fv = static_cast<size_t>(shapes[s].mesh.num_face_vertices[f]);

			// Loop over vertices in the face.
			for (size_t v = 0; v < fv; v++) {
				// access to vertex
				tinyobj::index_t idx = shapes[s].mesh.indices[index_offset + v];
				tinyobj::real_t vx = attrib.vertices[3 * static_cast<size_t>(idx.vertex_index) + 0];
				tinyobj::real_t vy = attrib.vertices[3 * static_cast<size_t>(idx.vertex_index) + 1];
				tinyobj::real_t vz = attrib.vertices[3 * static_cast<size_t>(idx.vertex_index) + 2];
				vertices.emplace_back(vx, vy, vz);

				// Check if `normal_index` is zero or positive. negative = no normal data
				if (idx.normal_index >= 0) {
					tinyobj::real_t nx = attrib.normals[3 * static_cast<size_t>(idx.normal_index) + 0];
					tinyobj::real_t ny = attrib.normals[3 * static_cast<size_t>(idx.normal_index) + 1];
					tinyobj::real_t nz = attrib.normals[3 * static_cast<size_t>(idx.normal_index) + 2];
					normals.emplace_back(nx, ny, nz);
				}
				else
				{
					normals.emplace_back();
				}

				// Check if `texcoord_index` is zero or positive. negative = no texcoord data
				if (idx.texcoord_index >= 0) {
					tinyobj::real_t tx = attrib.texcoords[2 * static_cast<size_t>(idx.texcoord_index) + 0];
					tinyobj::real_t ty = attrib.texcoords[2 * static_cast<size_t>(idx.texcoord_index) + 1];
					textureCoordinates.emplace_back(tx, ty);
				}
				else
				{
					textureCoordinates.emplace_back();
				}
			}
			index_offset += fv;
		}
	}

	assert(vertices.size() == normals.size());
	assert(vertices.size() == textureCoordinates.size());

	return Mesh{vertices, normals, textureCoordinates};
}

std::string ObjMeshImporter::getMessage() const
{
	if (!reader_.Error().empty())
	{
		return reader_.Error();
	}
	if (!reader_.Warning().empty())
	{
		return reader_.Warning();
	}
	return {};
}

}
