#pragma once

#include "Mesh.h"

#include <istream>

namespace geomio
{

template<typename T>
bool read(std::istream& stream, T& val)
{
	auto* buf = reinterpret_cast<char*>(&val);
	stream.read(buf, sizeof(T));
	return stream.good();
}

template<typename T,
	std::enable_if_t<std::is_arithmetic_v<T>, bool> = true>
bool write(std::ostream& stream, T val)
{
	const auto* buf = reinterpret_cast<char*>(&val);
	stream.write(buf, sizeof(T));
	return stream.good();
}

// https://devblogs.microsoft.com/oldnewthing/20190619-00/?p=102599
template<typename C, typename T = typename C::value_type>
bool write(std::ostream& stream, C container)
{
	for (const auto& v : container)
	{
		if(!write(stream, v))
		{
			return false;
		}
	}
	return true;
}

class StlMeshExporter
{
public:
	static void save(const Mesh& mesh, std::ostream& stream);
	void saveToFile(const Mesh& mesh);
	void saveToBuffer(const Mesh& mesh);
};

}
