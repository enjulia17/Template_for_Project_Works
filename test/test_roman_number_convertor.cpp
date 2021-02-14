#include "roman_number_convertor.h"

#include <gtest.h>


TEST(test_roman_number_to_arabic_number, test_one)
{
	Convertor roman;
	int v = roman.Roman_to_Arabic("I");
	EXPECT_EQ(1, v);
}

TEST(test_roman_number_to_arabic_number, test_five)
{
	Convertor roman;
	int v = roman.Roman_to_Arabic("V");
	EXPECT_EQ(5, v);
}

TEST(test_roman_number_to_arabic_number, test_ten)
{
	Convertor roman;
	int v = roman.Roman_to_Arabic("X");
	EXPECT_EQ(10, v);
}

TEST(test_roman_number_to_arabic_number, test_four)
{
	Convertor roman;
	int v = roman.Roman_to_Arabic("IV");
	EXPECT_EQ(4, v);
}

TEST(test_roman_number_to_arabic_number, test_six)
{
	Convertor roman;
	int v = roman.Roman_to_Arabic("VI");
	EXPECT_EQ(6, v);
}

TEST(test_roman_number_to_arabic_number, test_thirty_nine)
{
	Convertor roman;
	int v = roman.Roman_to_Arabic("XXXIX");
	EXPECT_EQ(39, v);
}

TEST(test_arabic_number_to_roman_number, test_one)
{
	Convertor arabic;
	string v = arabic.Arabic_to_Roman(1);
	EXPECT_EQ("I", v);
}

TEST(test_arabic_number_to_roman_number, test_five)
{
	Convertor arabic;
	string v = arabic.Arabic_to_Roman(5);
	EXPECT_EQ("V", v);
}

TEST(test_arabic_number_to_roman_number, test_ten)
{
	Convertor arabic;
	string v = arabic.Arabic_to_Roman(10);
	EXPECT_EQ("X", v);
}

TEST(test_arabic_number_to_roman_number, test_four)
{
	Convertor arabic;
	string v = arabic.Arabic_to_Roman(4);
	EXPECT_EQ("IV", v);
}

TEST(test_arabic_number_to_roman_number, test_six)
{
	Convertor arabic;
	string v = arabic.Arabic_to_Roman(6);
	EXPECT_EQ("VI", v);
}

TEST(test_arabic_number_to_roman_number, test_twenty_five)
{
	Convertor arabic;
	string v = arabic.Arabic_to_Roman(25);
	EXPECT_EQ("XXV", v);
}