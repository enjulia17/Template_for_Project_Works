#ifndef INCLUDE_COMPLEX_MULTIPLICATION_H_
#define INCLUDE_COMPLEX_MULTIPLICATION_H_

#include <iostream>

using namespace std;

class Complex
{
private:
	int re, im;

public:
	void set(int x, int y);
	void input();
	int output_re();
	int output_im();
	void multiplication(Complex z);
};

#endif  // INCLUDE_COMPLEX_MULTIPLICATION_H_
