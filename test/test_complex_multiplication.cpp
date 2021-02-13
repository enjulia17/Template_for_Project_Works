#include "complex_multiplication.h"

#include <gtest.h>


TEST(test_lib, simple_test_1)
{
	Complex num_1, num_2;
	num_1.set(1, 3);
	num_2.set(2, 5);
	num_2.multiplication(num_1);
	int v = num_2.output_re();
	EXPECT_EQ(2, v);
}

TEST(test_lib, simple_test_2)
{
	Complex num_1, num_2;
	num_1.set(1, 3);
	num_2.set(2, 5);
	num_2.multiplication(num_1);
	int v = num_2.output_im();
	EXPECT_EQ(15, v);
}