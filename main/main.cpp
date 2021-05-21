#include <iostream>
#include <locale.h>

#include "Polynomial.h"

using namespace std;

int main()
{
	TMonomial A(123, 5);
	TMonomial B(1234, 2);
	cout << "Monom A = " << A << endl;
	cout << "Monom B = " << B << endl;

	TPolynomial P(3);
	P += A;
	P += B;
	cout << "\nPolynom P = A + B = " << P << endl;

	TPolynomial P2(P);
	cout << "Polynom P2(P) = " << P2 << endl;

	TPolynomial P3(3);
	P3 = P + P2;
	cout << "\nPolynom P3 = P + P2 = " << P3 << endl;

	return 0;
}