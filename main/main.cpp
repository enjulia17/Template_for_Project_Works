#include "roman_number_convertor.h"
#include <fstream>

int main()
{
	cout << "User menu (available commands): \n" <<
		"Press 1 to convert six Roman numbers to Arabic numbers \n" << 
		"Press 2 to convert six Arabic numbers to Roman numbers \n" << 
		"Press 3 to quit \n" << 
		"Press 4 to open the user menu" << endl;

	int command;
	bool While = true;
	while (While)
	{
		cin >> command;
		if (command == 1)
		{
			Convertor res_roman;
			string roman;
			int n = 6;
			for (int i = 0; i < n; i++)
			{
				cout << "Input Roman number from I to XXXIX: ";
				cin >> roman;
				cout << "Arabic number is " << res_roman.Roman_to_Arabic(roman) << endl;
			}	
		}

		else if (command == 2)
		{
			Convertor res_arabic;
			int arabic;
			int n = 6;
			for (int i = 0; i < n; i++)
			{
				cout << "Input Arabic number from 1 to 39: ";
				cin >> arabic;
				cout << "Roman number is " << res_arabic.Arabic_to_Roman(arabic) << endl;
			}
		}

		else if (command == 3)
			break;

		else if (command == 4)
		{
			cout << "User menu (available commands): \n" <<
				"Press 1 to convert six Roman numbers to Arabic numbers \n" <<
				"Press 2 to convert six Arabic numbers to Roman numbers \n" <<
				"Press 3 to quit \n" <<
				"Press 4 to open the user menu" << endl;
		}

		else
		{
			cout << "Error: This command is not available! Try another one from the user menu." << endl;
			cout << "User menu (available commands): \n" <<
				"Press 1 to convert six Roman numbers to Arabic numbers \n" <<
				"Press 2 to convert six Arabic numbers to Roman numbers \n" <<
				"Press 3 to quit \n" <<
				"Press 4 to open the user menu" << endl;
		}
		cout << "\n" << "Choose the next command from the user menu:" << endl;
	}
		
	/*
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
	*/

	system("pause");
	return 0;
}
	


	