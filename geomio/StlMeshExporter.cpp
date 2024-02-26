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
	constexpr std::array<char, 80> header{0};
	stream.write(header.data(), header.size());

	// Number of triangles
	const auto triangleCount{ static_cast<uint32_t>(mesh.faces().size()) };
	stream.write(reinterpret_cast<const char*>(&triangleCount), sizeof(triangleCount));

	for(const auto& face: mesh.faces())
	{
		// Triangle normal
		const auto normal = mesh.faceNormal(face);
		std::array normalCoordinates{ normal.x, normal.y, normal.z };
		stream.write(reinterpret_cast<const char*>(normalCoordinates.data()), sizeof(float) * std::size(normalCoordinates));

		// Triangle vertices
		assert(face.vertexIndices.size() == 3);
		auto buf = dynamic_cast<std::ostringstream&>(stream).str();
		for(std::size_t i = 0; i < face.vertexIndices.size(); ++i)
		{
			const auto vertex = mesh.vertex(face, i);
			std::array vertexCoordinates{ vertex.x, vertex.y, vertex.z };
			stream.write(reinterpret_cast<const char*>(vertexCoordinates.data()), sizeof(float) * std::size(vertexCoordinates));
			buf = dynamic_cast<std::ostringstream&>(stream).str();
		}

		// Attribute byte count, must be 0
		stream.write("\0\0", 2);
	}
}

}
