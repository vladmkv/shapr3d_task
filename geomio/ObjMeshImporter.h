#pragma once

#include <filesystem>

#include "Mesh.h"

#include <tiny_obj_loader.h>

namespace geomio
{

class ObjMeshImporter
{
public:
	bool loadFromFile(const std::filesystem::path& filePath);
	bool load(const std::string& text);	
	Mesh getMesh() const;
	std::string getMessage() const;

private:
	static std::vector<glm::vec3> readAttribute(const std::vector<tinyobj::real_t>& attrib);

	tinyobj::ObjReader reader_;
	std::string message_;
};

}
