#include "roman_number_convertor.h"
#include <fstream>

int main()
{
	Convertor res;
	string roman;
	int n = 6;
	for (int i = 0; i < n; i++)
	{
		cout << "Input Roman number from 1 to 39: ";
		cin >> roman;
		cout << roman << endl;
		cout << "Arabic number is " << res.Roman_to_Arabic(roman) << endl;
	}
	

	Convertor roman_1, roman_2, roman_3, roman_4, roman_5, roman_6;
	roman_1.Roman_to_Arabic("I");
	roman_2.Roman_to_Arabic("II");
	roman_3.Roman_to_Arabic("III");
	roman_4.Roman_to_Arabic("V");
	roman_5.Roman_to_Arabic("VII");
	roman_6.Roman_to_Arabic("VIII");
	char a = 'I';
	char b = 'II';
	char c = 'III';
	char d = 'V';
	char e = 'VII';
	char f = 'VIII';
	ifstream input("input.txt");
	ofstream output("output.txt");

	char words;
	while (!input.eof())
	{
		input >> words;
		if (words == a)
		{
			words = roman_1.Roman_to_Arabic("I");
		}
		else if (words == b)
		{
			words = roman_2.Roman_to_Arabic("II");
		}
		else if (words == c)
		{
			words = roman_3.Roman_to_Arabic("III");
		}
		else if (words == d)
		{
			words = roman_4.Roman_to_Arabic("V");
		}
		else if (words == e)
		{
			words = roman_5.Roman_to_Arabic("VII");
		}
		else if (words == f)
		{
			words = roman_6.Roman_to_Arabic("VIII");
		}
	
		output << words;
	}
	
	system("pause");
	return 0;
}
	


	