#include "Polynomial.h"

#include <gtest.h>

TEST(TMonomial, can_create_default_monomial)
{
	ASSERT_NO_THROW(TMonomial A);
}

TEST(TMonomial, can_create_monomial)
{
	ASSERT_NO_THROW(TMonomial A(4));
}

TEST(TMonomial, throws_when_create_monomial_with_negative_size)
{
	ASSERT_ANY_THROW(TMonomial A(-4));
}

TEST(TMonomial, can_set_and_get_power)
{
	int a[3] = { 1,2,3 };
	TMonomial A(3);
	ASSERT_NO_THROW(A.SetPower(a));
	ASSERT_EQ(1, A.GetPower()[0]);
	ASSERT_EQ(2, A.GetPower()[1]);
	ASSERT_EQ(3, A.GetPower()[2]);
}

TEST(TMonomial, can_set_and_get_size)
{
	TMonomial A(3);
	ASSERT_NO_THROW(A.SetN(5));
	ASSERT_EQ(5, A.GetN());
}

TEST(TMonomial, can_sum_monomials_with_equal_size)
{
	int a[3] = { 1,2,3 };
	TMonomial A(3, a, 3.1);
	TMonomial B(3, a, 0.5);
	ASSERT_NO_THROW(A + B);
	TMonomial C(3);
	C = A + B;
	ASSERT_EQ(3.6, C.GetCoeff());
}

TEST(TMonomial, can_subtract_monomials_with_equal_size)
{
	int a[3] = { 1,2,3 };
	TMonomial A(3, a, 3.1);
	TMonomial B(3, a, 0.5);
	ASSERT_NO_THROW(A - B);
	TMonomial C(3);
	C = A - B;
	ASSERT_EQ(2.6, C.GetCoeff());
}

TEST(TMonomial, can_multiply_monomials_with_equal_size)
{
	int a[3] = { 1,2,3 };
	int a2[3] = { 3,2,1 };
	TMonomial A(3, a, 3.1);
	TMonomial B(3, a2, 0.5);
	ASSERT_NO_THROW(A * B);
	TMonomial C(3);
	C = A * B;
	ASSERT_EQ(3.1*0.5, C.GetCoeff());
	for (int i = 0; i < 3; i++)
		ASSERT_EQ(C.GetPower()[i], 4);
}

TEST(TMonomial, can_equivalence_equal_monomials)
{
	int a[3] = { 1,2,3 };
	TMonomial A(3, a, 3.1);
	TMonomial B(3, a, 3.1);
	ASSERT_TRUE(A == B);
}

TEST(TPolynomial, can_create_polynomial)
{
	ASSERT_NO_THROW(TPolynomial A);
}

TEST(TPolynomial, can_create_polynomial_with_positive_n)
{
	ASSERT_NO_THROW(TPolynomial A(4));
}

TEST(TPolynomial, throws_when_create_polynomial_with_negative_n)
{
	ASSERT_ANY_THROW(TPolynomial A(-4));
}

TEST(TPolynomial, can_create_copy_polynomial)
{
	TPolynomial A(3);
	ASSERT_NO_THROW(TPolynomial B(A));
	TPolynomial C(A);
	ASSERT_EQ(C.GetSize(), 0);
	ASSERT_EQ(C.GetN(), 3);
	if (C.GetStart() != NULL)
		ASSERT_TRUE(false);
}

TEST(TPolynomial, can_sum_polynomials_with_equal_n)
{
	TPolynomial P1(2);
	TPolynomial P2(2);
	ASSERT_NO_THROW(P1 + P2);
}

TEST(TPolynomial, can_subtract_polynomials_with_equal_n)
{
	TPolynomial P1(2);
	TPolynomial P2(2);
	ASSERT_NO_THROW(P1 - P2);
}
