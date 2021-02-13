#include "roman_number_convertor.h"

#include <gtest.h>


TEST(test_roman_number_convertor, test_one)
{
	Convertor roman;
	int v = roman.Roman_to_Arabic("I");
	EXPECT_EQ(1, v);
}

TEST(test_roman_number_convertor, test_five)
{
	Convertor roman;
	int v = roman.Roman_to_Arabic("V");
	EXPECT_EQ(5, v);
}

TEST(test_convertor, test_ten)
{
	Convertor roman;
	int v = roman.Roman_to_Arabic("X");
	EXPECT_EQ(10, v);
}

TEST(test_convertor, test_four)
{
	Convertor roman;
	int v = roman.Roman_to_Arabic("IV");
	EXPECT_EQ(4, v);
}

TEST(test_convertor, test_six)
{
	Convertor roman;
	int v = roman.Roman_to_Arabic("VI");
	EXPECT_EQ(6, v);
}
