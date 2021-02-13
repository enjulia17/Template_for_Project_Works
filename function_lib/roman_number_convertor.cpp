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
			result += roman_num[value[i]] - temporary*2;
		}

		temporary = roman_num[value[i]]; //���������� ������
	}

	return result;

}
 

