#include <func.h>
#include <string.h>
#include <stdlib.h>
#include <gtest/gtest.h>

TEST(InBounds1, InCorrect)
{
	int result = InBounds(11, 100);
	int expected = 0;
	ASSERT_EQ(expected, result);
}

TEST(InBounds2, InCorrect)
{
        int result = InBounds(0, 100);
        int expected = 0;
        ASSERT_EQ(expected, result);
}

TEST(InBounds3, InCorrect)
{
        int result = InBounds(7, 6);
        int expected = 0;
        ASSERT_EQ(expected, result);
}

TEST(InBounds, Correct)
{
        int result = InBounds(5, 100);
        int expected = 1;
        ASSERT_EQ(expected, result);
}

TEST(II_Turn1, Correct)
{
        int result = II_Turn(1);
        int expected = 0;
        ASSERT_EQ(expected, result);
}

TEST(II_Turn2, Correct)
{
        int result = II_Turn(14);
        int expected = 12;
        ASSERT_EQ(expected, result);
}

TEST(II_Turn3, Correct)
{
        int result = II_Turn(77);
        int expected = 67;
        ASSERT_EQ(expected, result);
}

TEST(II_Turn4, Correct)
{
        int result = II_Turn(11);
        int expected = 1;
        ASSERT_EQ(expected, result);
}

TEST(II_Turn, Correct)
{
        int result = II_Turn(100);
        int value = 90;
        ASSERT_LE(value, result);
}

TEST(IntToString1, Correct)
{
	char *str_res;
	char str_exp[5];
	strcpy(str_exp, "1707");
        str_res = IntToString(1707);
        ASSERT_STREQ(str_exp, str_res);
	free(str_res);
}

TEST(IntToString2, Correct)
{
        char *str_res;
        char str_exp[6];
        strcpy(str_exp, "0");
        str_res = IntToString(0);
        ASSERT_STREQ(str_exp, str_res);
        free(str_res);
}

int main(int argc, char **argv)
{
	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
