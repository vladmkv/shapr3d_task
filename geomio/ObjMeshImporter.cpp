#include "Mesh.h"
#include "ObjMeshImporter.h"

#include <tiny_obj_loader.h>

#include <cassert>
#include <filesystem>


namespace geomio
{

bool ObjMeshImporter::loadFromFile(const std::filesystem::path& filePath)
{
	tinyobj::ObjReaderConfig reader_config{};
	reader_config.triangulate = false;
	reader_config.vertex_color = false;

	return reader_.ParseFromFile(filePath.string(), reader_config) ? reader_.Valid() : false;
}

bool ObjMeshImporter::load(const std::string& text)
{
	tinyobj::ObjReaderConfig reader_config{};
	reader_config.triangulate = false;
	reader_config.vertex_color = false;

	return reader_.ParseFromString(text, {}, reader_config) ? reader_.Valid() : false;
}

std::vector<glm::vec3> ObjMeshImporter::readAttribute(const std::vector<tinyobj::real_t>& attrib)
{
	std::vector<glm::vec3> vertices{};

	for	(size_t i = 0; i < attrib.size() / 3; ++i)
	{
		auto x = attrib[3 * i + 0];
		auto y = attrib[3 * i + 1];
		auto z = attrib[3 * i + 2];
		vertices.emplace_back(x, y, z);
	}

	return vertices;
}

// Original sample code: https://github.com/tinyobjloader/tinyobjloader/tree/release#example-code-new-object-oriented-api
Mesh ObjMeshImporter::getMesh() const
{
	auto& attrib = reader_.GetAttrib();
	auto& shapes = reader_.GetShapes();
	
	auto vertices{ readAttribute(attrib.vertices) };
	auto normals{ readAttribute(attrib.normals) };
	
	std::vector<Mesh::Face> faces;
	for (const auto& shape : shapes)
	{
		size_t index_offset = 0;
		for (size_t f = 0; f < shape.mesh.num_face_vertices.size(); f++) {
			Mesh::Face face;
			// Loop over vertices in the face.
			auto fv = static_cast<size_t>(shape.mesh.num_face_vertices[f]);
			for (size_t v = 0; v < fv; v++) {
				face.vertexIndices.push_back(shape.mesh.indices[index_offset + v].vertex_index);
				face.normalIndices.push_back(shape.mesh.indices[index_offset + v].normal_index);
			}
			index_offset += fv;
			faces.push_back(std::move(face));
		}
	}

	return Mesh{std::move(vertices), std::move(normals), std::move(faces)};
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
