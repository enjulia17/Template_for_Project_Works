#pragma once
#include <iostream>
#include <string>

using namespace std;

int numDigits(int n)
{
	string s = to_string(n);
	return s.length();
}

int getDigit(int n, int i)
{
	string s = to_string(n);
	return (int)s[i] - 48;
}

class TMonomial
{
protected:
	int power;      //массив степеней
	int n;           //кол-во переменных в мономе
	double coefficient; //коэффициент
	TMonomial *next; //указатель на следующий моном
public:
	TMonomial();
	TMonomial(int _power, double _coeff);
	TMonomial(const TMonomial &A);
	~TMonomial();

	void SetPower(int _power);
	void SetN(int _n);
	void SetCoeff(double _coeff);
	void SetNext(TMonomial* _next);

	int GetPower(int i);
	int GetN() const;
	double GetCoeff() const;
	TMonomial* GetNext();

	bool ComparePowers(const TMonomial &A);

	TMonomial &operator = (const TMonomial &A);
	TMonomial operator + (TMonomial &A);
	TMonomial &operator += (const TMonomial &A);
	TMonomial operator - (TMonomial &A);
	TMonomial &operator -= (const TMonomial &A);
	TMonomial operator * (TMonomial &A);
	TMonomial &operator *= (TMonomial &A);

	bool operator == (TMonomial &A);
	bool operator < (TMonomial &A);
	bool operator > (TMonomial &A);

	friend istream& operator >> (istream &istr, TMonomial &m);
	friend ostream& operator << (ostream &ostr, TMonomial &m);
};

TMonomial::TMonomial()
{
	n = 0;
	next = NULL;
	power = 0;
	coefficient = 0;
}

TMonomial::TMonomial(int _power, double _coeff)
{
	if (_power < 0)
		throw "Error";
	else if (_power == 0)
	{
		power = 0;
		next = NULL;
		coefficient = _coeff;
		n = 0;
	}
	else
	{
		n = numDigits(_power);
		coefficient = _coeff;
		next = 0;
		power = _power;
	}
}

TMonomial::TMonomial(const TMonomial &A)
{
	n = A.n;
	coefficient = A.coefficient;
	next = A.next;
	if (n != 0) {
		power = A.power;
	}
	else
		power = 0;
}

TMonomial::~TMonomial()
{
	if (power != 0)
		power = 0;
	n = 0;
	coefficient = 0;
	next = 0;
}

void TMonomial::SetPower(int _power)
{
	power = _power;
}

void TMonomial::SetN(int _n)
{
	if (_n < 0)
		throw "Error";
	else if (_n == 0)
	{
		if (power != 0)
			power = 0;
	}
	else if (_n != n)
	{
		if (_n > n)
			power *= pow(10, _n);
		else
			power /= pow(10, _n);
	}
	n = _n;
}

void TMonomial::SetCoeff(double _coeff)
{
	coefficient = _coeff;
}

void TMonomial::SetNext(TMonomial* _next)
{
	next = _next;
}

int TMonomial::GetPower(int i)
{
	return getDigit(power, i);
}

int TMonomial::GetN() const
{
	return n;
}

double TMonomial::GetCoeff() const
{
	return coefficient;
}

TMonomial* TMonomial::GetNext()
{
	return next;
}

bool TMonomial::ComparePowers(const TMonomial &A)
{
	if (n != A.n)
		return false;
	for (int i = 0; i < n; i++)
		if (getDigit(power, i) != getDigit(A.power, i))
			return false;
	return true;
};

TMonomial &TMonomial::operator = (const TMonomial &A)
{
	coefficient = A.coefficient;
	n = A.n;
	next = A.next;
	power = A.power;
	return *this;
}

TMonomial TMonomial::operator + (TMonomial &A)
{
	TMonomial tmp(*this);
	tmp += A;
	return tmp;
}

TMonomial &TMonomial::operator+=(const TMonomial & A)
{
	if (ComparePowers(A))
		coefficient += A.coefficient;
	return *this; 
}

TMonomial TMonomial::operator - (TMonomial &A)
{
	TMonomial tmp(*this);
	tmp -= A;
	return tmp;
}

TMonomial &TMonomial::operator-=(const TMonomial & A)
{
	if (ComparePowers(A))
		coefficient -= A.coefficient;
	return *this;
}

TMonomial TMonomial::operator * (TMonomial &A)
{
	TMonomial tmp(*this);
	tmp *= A;
	return tmp;
}

TMonomial &TMonomial::operator *= (TMonomial & A)
{
	if (n != A.n)
		throw "Error";
	coefficient *= A.coefficient;
	power += A.power;
	return *this;
}

bool TMonomial::operator == (TMonomial &A)
{
	if (n != A.n)
		throw "Error";
	if (coefficient != A.coefficient)
		return false;
	if (power != A.power)
			return false;
	return true;
}

bool TMonomial::operator > (TMonomial& A)
{
	if (n != A.n)
		throw "Error";

	if (power == A.power)
	{
		if (coefficient > A.coefficient)
			return true;
		else
			return false;
	}
	else if (power > A.power)
		return true;
	else
		return false;

}

bool TMonomial::operator < (TMonomial& A)
{
	if (n != A.n)
		throw "Error";

	if (power == A.power)
	{
		if (coefficient < A.coefficient)
			return true;
		else
			return false;
	}
	else if (power < A.power)
		return true;
	else
		return false;

}

istream& operator >> (istream &istr, TMonomial &m)
{
	istr >> m.coefficient;
	for (int i = 0; i < m.n; i++)
		istr >> m.power;
	return istr;
}

ostream& operator<<(ostream &ostr, TMonomial &m)
{
	ostr << m.GetCoeff();
	for (int i = 0; i < m.GetN(); i++)
		ostr << "*" << "x" << i << "^" << getDigit(m.power, i);

	return ostr;
}