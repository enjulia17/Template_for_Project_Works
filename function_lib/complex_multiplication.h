#ifndef INCLUDE_REMAINDER_H_
#define INCLUDE_REMAINDER_H_

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

#endif  // INCLUDE_REMAINDER_H_