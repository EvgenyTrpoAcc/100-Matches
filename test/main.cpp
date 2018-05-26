#define CTEST_MAIN

#include <func.h>
#include <gtest/gtest.h>

TEST(CheckCorrect, Correct)
{
	ASSERT_EQ(78, II_Turn(86));
	ASSERT_EQ(0, II_Turn(1));
	ASSERT_EQ(12, II_Turn(14));
	ASSERT_EQ(67, II_Turn(77));
	ASSERT_TRUE(InBounds(5, 100));
	ASSERT_STRNE("1707", IntToString(1707));
	ASSERT_STRNE("0", IntToString(0));
}

TEST(CheckCorrect, Incorrect)
{
	ASSERT_FALSE(InBounds(11, 100));
	ASSERT_FALSE(InBounds(0, 100));
	ASSERT_FALSE(InBounds(7, 6));
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

