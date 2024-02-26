#include "StlMeshExporter.h"

#include <array>
#include <fstream>
#include <ostream>
#include <sstream>

#include "Mesh.h"

namespace geomio
{

void StlMeshExporter::saveToFile(const Mesh& mesh)
{
	std::ofstream fileStream;
	fileStream.open("file.bin", std::ios::binary | std::ios::out);
	save(mesh, fileStream);
}

void StlMeshExporter::saveToBuffer(const Mesh& mesh)
{
	std::ostringstream bufferStream;
	save(mesh, bufferStream);
}

void StlMeshExporter::save(const Mesh& mesh, std::ostream& stream)
{
	// Header
	write(stream, std::array<char, 80>{});

	// Number of triangles
	const auto triangleCount{ static_cast<uint32_t>(mesh.faces().size()) };
	write(stream, triangleCount);

	for(const auto& face: mesh.faces())
	{
		// Triangle normal
		const auto normal = mesh.faceNormal(face);
		const std::array<float, 3> normalCoordinates{ normal.x, normal.y, normal.z };
		write(stream, normalCoordinates);

		// Triangle vertices
		assert(face.vertexIndices.size() == 3);
		for(std::size_t i = 0; i < face.vertexIndices.size(); ++i)
		{
			const auto vertex = mesh.vertex(face, i);
			const std::array<float, 3> vertexCoordinates{ vertex.x, vertex.y, vertex.z };
			write(stream, vertexCoordinates);
		}

		// Attribute byte count, must be 0;
		write(stream, std::array<char, 2>{});
	}
}

}
