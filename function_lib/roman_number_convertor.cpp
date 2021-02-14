#include "roman_number_convertor.h"

int Convertor::Roman_to_Arabic(string value)
{
	map<char, int> roman_num; //����� ������������ ������� ����� � ��������� ������� (��������� ������ � � ������������ � ��� �����)
	roman_num['I'] = 1;
	roman_num['V'] = 5;
	roman_num['X'] = 10;

	int result = 0;
	int temporary = 0;

	for (int i = 0; i < value.length(); i++)
	{
		//���� ������ �� ������
		if (roman_num[value[i]] == 0)
		{
			cout << "Invalid format";
			cin.ignore();
			return -1;
		}

		//���� ��������� �������� ������ ��� ����� ���������� (�����������)
		if (roman_num[value[i]] <= temporary)
		{
			result += roman_num[value[i]];
		}

		//���� ������� ������� ������������
		else
		{
			result += roman_num[value[i]] - temporary * 2;
		}

		temporary = roman_num[value[i]]; //���������� ������
	}

	return result;
}

string Convertor::Arabic_to_Roman(unsigned int value)
{
	struct roman_num_str 
	{ 
		unsigned int value; 
		char const* numeral; 
	};
	const struct roman_num_str roman_num[] =
	{
		{ 10, "X" },{ 9, "IX" },
		{ 5, "V" },{ 4, "IV" },
		{ 1, "I" },
		{ 0, NULL }
	};

	string result;
	for (const roman_num_str* temporary = roman_num; temporary->value > 0; ++temporary)
	{
		while (value >= temporary->value)
		{
			result += temporary->numeral;
			value -= temporary->value;
		}
	}
	return result;
}


	
 

