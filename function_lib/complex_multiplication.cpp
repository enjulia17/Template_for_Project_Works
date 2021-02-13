#include "complex_multiplication.h"

void Complex::set(int x, int y)
{
	re = x;
	im = y;
}

void Complex::input()
{
	cout << "Input real part: ";
	cin >> re;
	cout << "Input imagnary part: ";
	cin >> im;
}

int Complex::output_re()
{
	cout << "real part = " << re << endl;
	return re;
}

int Complex::output_im()
{
	cout << "imaginary part = " << im << endl;
	return im;
}

void Complex::multiplication(Complex z)
{
	re = re * z.re;
	im = im * z.im;
}
