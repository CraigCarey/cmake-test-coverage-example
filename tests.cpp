#include <gtest/gtest.h>

#include "lib_under_test.hpp"

TEST(GreaterTest, AisGreater)
{
	EXPECT_EQ(3, totally_covered(3, 1, 2));
};

TEST(GreaterTest, BisGreater)
{
	EXPECT_EQ(3, totally_covered(1, 3, 2));
};

TEST(GreaterTest, CisGreater)
{
	EXPECT_EQ(3, totally_covered(1, 2, 3));
};

TEST(PartialTest, AOnly)
{
	EXPECT_EQ(3, partially_covered(3, 2, 1));
};

TEST(PartialTest, BOnly)
{
	EXPECT_EQ(3, partially_covered(1, 3, 2));
};

// Uncomment for improved coverage
// TEST(PartialTest, COnly)
//{
//    EXPECT_EQ(3, partially_covered(1, 2, 3));
//};

int main(int argc, char** argv)
{
	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
