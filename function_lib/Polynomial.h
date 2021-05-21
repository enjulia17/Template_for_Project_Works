#pragma once

#include <iostream>
#include "Monomial.h"

using namespace std;

class TPolynomial
{
protected:
	TMonomial *start;
	int n;          //размерность монома
	int k;          //количество мономов
public:
	TPolynomial();
	TPolynomial(int _n);
	TPolynomial(const TPolynomial &A);
	~TPolynomial();

	int GetN();
	int GetSize();
	TMonomial* GetStart();
	TPolynomial operator-(TPolynomial &A);
	TPolynomial operator+(TPolynomial &A);
	TPolynomial& operator=(const TPolynomial &A);
	bool operator==(const TPolynomial &A);
	bool operator!=(const TPolynomial &A);
	TPolynomial operator*(TPolynomial &A);
	TPolynomial& operator+=(const TMonomial &m);
	TPolynomial& operator-=(const TMonomial &m);
	friend std::ostream& operator<<(std::ostream &ostr, TPolynomial& Tm);
};

TPolynomial::TPolynomial()
{
	n = 0;
	k = 0;
	start = NULL;
}

TPolynomial::TPolynomial(int _n)
{
	if (_n <= 0)
		throw "Error";
	n = _n;
	k = 0;
	start = NULL;
}

TPolynomial::TPolynomial(const TPolynomial &A)
{
	n = A.n;
	k = A.k;
	if (A.start == NULL)
		start = NULL;
	else
	{
		start = new TMonomial(*A.start);
		for (TMonomial* i = A.start->GetNext(); i != NULL; i = i->GetNext())
		{
			start->SetNext(new TMonomial(*i));
		}
	}
}

TPolynomial::~TPolynomial()
{
	if (start == NULL)
		return;
	TMonomial* next_elem;
	for (TMonomial* i = start; i != NULL; )
	{
		next_elem = i->GetNext();
		i->~TMonomial();
		i = next_elem;
	}
}

int TPolynomial::GetN()
{
	return n;
}

int TPolynomial::GetSize()
{
	return k;
}

TMonomial* TPolynomial::GetStart()
{
	return start;
}

TPolynomial& TPolynomial::operator=(const TPolynomial &A)
{
	if (*this != A)
	{
		if (start != NULL)
		{
			TMonomial* next_elem;
			for (TMonomial* i = start; i != NULL; )
			{
				next_elem = i->GetNext();
				i->~TMonomial();
				i = next_elem;
			}
		}

		start = new TMonomial(*A.start);
		TMonomial* source_elem = start;
		for (TMonomial* i = A.start->GetNext(); i != NULL; i = i->GetNext())
		{
			source_elem->SetNext(new TMonomial(*i));
			source_elem = source_elem->GetNext();
		}

		n = A.n;
		k = A.k;
	}
	return *this;
}

TPolynomial &TPolynomial::operator+=(const TMonomial &m)
{
	if (m.GetCoeff() == 0)
		return *this;
	if (start == NULL)
	{
		start = new TMonomial(m);
		start->SetCoeff(start->GetCoeff());
		k++;
	}
	else
	{
		TMonomial* last_elem = NULL;
		for (TMonomial *ptr = start; ptr != NULL; ptr = ptr->GetNext())
		{
			if (ptr->ComparePowers(m))
			{
				*ptr += m;
				break;
			}
			else if (ptr->GetNext() == NULL)
			{
				last_elem = ptr;
			}
		}

		if (last_elem != NULL)
		{
			last_elem->SetNext(new TMonomial(m));
			last_elem->SetCoeff(last_elem->GetCoeff());
			k++;
		}
	}
	return *this;
}


TPolynomial &TPolynomial::operator-=(const TMonomial &m)
{
	//if (n != m.GetN())
		//throw "Error";
	if (m.GetCoeff() == 0)
		return *this;
	if (start == NULL)
	{
		start = new TMonomial(m);
		start->SetCoeff(start->GetCoeff() * (-1));
		k++;
	}
	else
	{
		TMonomial* last_elem = NULL;
		for (TMonomial *ptr = start; ptr != NULL; ptr = ptr->GetNext())
		{
			if (ptr->ComparePowers(m))
			{
				*ptr -= m;
				break;
			}
			else if (ptr->GetNext() == NULL)
			{
				last_elem = ptr;
			}
		}

		if (last_elem != NULL)
		{
			last_elem->SetNext(new TMonomial(m));
			last_elem->SetCoeff(last_elem->GetCoeff() * (-1));
			k++;
		}
	}
	return *this;
}

bool TPolynomial::operator==(const TPolynomial &A)
{
	if (this->n != A.n)
		throw "Error";
	if (this->k != A.k)
		return false;
	for (TMonomial* source_ptr = start; source_ptr != NULL; source_ptr = source_ptr->GetNext())
		for (TMonomial* p_ptr = start; p_ptr != NULL; p_ptr = p_ptr->GetNext())
		{
			if (*source_ptr == *p_ptr)
			{
				break;
			}
			else if (p_ptr->GetNext() == NULL)
			{
				return false;
			}
		}
	return true;
}

bool TPolynomial::operator!=(const TPolynomial &A)
{
	return !(*this == A);
}

TPolynomial TPolynomial::operator*(TPolynomial &A)
{
	if (n != A.n)
		throw "Error";
	TPolynomial tmp(n);

	for (TMonomial* source_ptr = start; source_ptr != NULL; source_ptr = source_ptr->GetNext())
		for (TMonomial* p_ptr = A.start; p_ptr != NULL; p_ptr = p_ptr->GetNext())
		{
			tmp += (*source_ptr) * (*p_ptr);
		}
	return tmp;
}

TPolynomial TPolynomial::operator+(TPolynomial &A)
{
	TPolynomial tmp(A);

	for (TMonomial* p_ptr = start; p_ptr != NULL; p_ptr = p_ptr->GetNext())
	{
		tmp += *p_ptr;
	}

	return tmp;
}

TPolynomial TPolynomial::operator-(TPolynomial &A)
{
	TPolynomial tmp(A);

	for (TMonomial* p_ptr = start; p_ptr != NULL; p_ptr = p_ptr->GetNext())
	{
		tmp -= *p_ptr;
	}

	return tmp;
}

ostream& operator<<(ostream &ostr, TPolynomial& Tm)
{
	if (Tm.start == NULL)
		ostr << "Empty";
	else
	{
		for (TMonomial* ptr = Tm.start; ptr != NULL; ptr = ptr->GetNext())
		{
			ostr << *ptr;
			if (ptr->GetNext() != NULL)
				ostr << "+";
		}
	}
	return ostr;
}