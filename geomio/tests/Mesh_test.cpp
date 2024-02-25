#include "Mesh.h"

#include <gtest/gtest.h>

TEST(MeshTests, DummyTest)
{
    auto mesh = geomio::Mesh{{}, {}, {}};
	ASSERT_TRUE(true);
}
