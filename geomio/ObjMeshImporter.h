#pragma once

#include "Mesh.h"

#include <tiny_obj_loader.h>

namespace geomio
{

class ObjMeshImporter
{
public:
	bool load(const std::string& text);
	Mesh getMesh() const;
	std::string getMessage() const;

private:	
	tinyobj::ObjReader reader_;
	std::string message_;
};

}
