#pragma once

#include "Mesh.h"

#include <filesystem>

namespace geomio
{

class IMeshImporter
{
public:
	virtual Mesh import(std::filesystem::path file) = 0;
};

}