#include <stdio.h>
#include "complex_multiplication.h"

int main() 
{
	Complex num_1;
	num_1.set(2, 4);
	cout << "Number 1st:\n";
	num_1.output_re();
	num_1.output_im();
	Complex num_2;
	num_2.input();
	cout << "Number 2nd:\n";
	num_2.output_re();
	num_2.output_im();
	num_1.multiplication(num_2);
	cout << "The result of multiplication:\n";
	num_1.output_re();
	num_1.output_im();
	system("pause");
    return 0;
}