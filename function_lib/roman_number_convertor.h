#ifndef INCLUDE_ROMAN_NUMBER_CONVERTOR_H_
#define INCLUDE_ROMAN_NUMBER_CONVERTOR_H_

#include <iostream>
#include <string>
#include <map>

using namespace std;

class Convertor
{ 
public:
	int arabic_num;
	string roman_num;

	int Roman_to_Arabic(string value);
	string Arabic_to_Roman(unsigned int value);
};

#endif  // INCLUDE_ROMAN_NUMBER_CONVERTOR_H_