#include <iostream>
#include <vector>
#include <string>
#include "Term.h"
#include "Polynomial.h"
using namespace std;

//constructor
Polynomial::Polynomial(vector <Term> p)
{
	poly = p;
	sort_poly();
	simplify_poly();
	shrink_poly();
}

//display Polynomial
void Polynomial::display_poly()
{
	for (int i = 0; i < poly.size(); i++)
	{
		poly.at(i).display_term();
		cout << ' ';
	}
}

//sort Polynomial
void Polynomial::sort_poly()
{
	//bubble sort
	for (int i = 0; i < poly.size() - 1; i++)
	{
		for (int j = 0; j < poly.size() - i - 1; j++)
		{
			if (poly.at(j).get_p() < poly.at(j + 1).get_p())
			{
				swap(poly.at(j), poly.at(j + 1));
			}
		}
	}
}

//simplify Polynomial
void Polynomial::simplify_poly()
{
	for (int i = 0; i < poly.size(); i++)
	{
		for (int j = i + 1; j < poly.size();)
		{
			if (poly.at(i).get_p() == poly.at(j).get_p())
			{
				// sum coefficient of terms that have same powers
				float c = poly.at(i).get_c() + poly.at(j).get_c();
				poly.at(i).set_c(c);
				poly.erase(poly.begin() + j); //delete jth term of poly
			}
			else
			{
				j++;
			}
		}
	}
}

// delete term with zero coefficient
void Polynomial::shrink_poly()
{
	for (int i = 0; i < poly.size(); i++)
	{
		if (poly.at(i).get_c() == 0)
		{
			poly.erase(poly.begin() + i);
		}
	}
}

//Polynomial + Polynomial
Polynomial Polynomial::operator +(const Polynomial & p)
{
	vector <Term> result = poly;
	for (int i = 0; i < p.poly.size(); i++)
	{
		result.push_back(p.poly.at(i));
	}
	return Polynomial(result);
}
//Polynomial + Term
Polynomial Polynomial::operator +(const Term & a)
{
	vector <Term> result = poly;
	result.push_back(a);
	return Polynomial(result);
}
//Term + Polynomial
Polynomial operator +(const Term & a, const Polynomial & p)
{
	vector <Term> result = p.poly;
	result.push_back(a);
	return Polynomial(result);
}
//Polynomial + float
Polynomial Polynomial::operator +(float a)
{
	Term t(a, 0);
	return (*this + t);
}
//float + Polynomial
Polynomial operator +(float a, Polynomial p)
{
	Term t(a, 0);
	return (p + t);
}

//Polynomial - Polynomial
Polynomial Polynomial::operator -(Polynomial & p)
{
	Polynomial p1 = p;
	for (int i = 0; i < p1.poly.size(); i++)
	{
		p1.poly.at(i) = p1.poly.at(i) * -1;
	}
	return (*this + p1);
}
//Polynomial - Term
Polynomial Polynomial::operator -(Term & a)
{
	Term a1 = a * -1;
	return (*this + a1);
}
//Term - Polynomial
Polynomial operator -(Term & a, Polynomial & p)
{
	Polynomial p1 = p;
	for (int i = 0; i < p1.poly.size(); i++)
	{
		p1.poly.at(i) = p1.poly.at(i) * -1;
	}
	return (a + p1);
}
//Polynomial - float
Polynomial Polynomial::operator -(float a)
{
	float a1 = a * -1;
	return (*this + a1);
}
//float - Polynomial 
Polynomial operator -(float a, Polynomial p)
{
	Term t(a, 0);
	return (t - p);
}

//Polynomial * Polynomial
Polynomial Polynomial::operator *(Polynomial & p)
{
	vector <Term> t;

	//multiply Polynomials
	for (int i = 0; i < poly.size(); i++)
	{
		for (int j = 0; j < p.poly.size(); j++)
		{
			t.push_back(poly.at(i) * p.poly.at(j));
		}
	}

	return Polynomial(t);
}
//Polynomial * Term
Polynomial Polynomial::operator *(Term & a)
{
	vector <Term> t = { a };
	Polynomial p(t);
	return (*this * p);
}
//Term * Polynomial
Polynomial operator *(Term & a, Polynomial & p)
{
	vector <Term> t = { a };
	Polynomial p1(t);
	return (p * p1);
}
//Polynomial * float
Polynomial Polynomial::operator *(float a)
{
	Term t(a, 0);
	return (*this * t);
}
//Polynomial * float
Polynomial operator *(float a, Polynomial & p)
{
	Term t(a, 0);
	return (p * t);
}

//Polynomial += Polynomial
void Polynomial::operator +=(Polynomial & p)
{
	*this = *this + p;
}

//Polynomial -= Polynomial
void Polynomial::operator -=(Polynomial & p)
{
	*this = *this - p;
}

//Polynomial *= Polynomial
void Polynomial::operator *=(Polynomial & p)
{
	*this = *this * p;
}

//Polynomial > Polynomial
bool Polynomial::operator >(Polynomial & p)
{
	int size;
	if (poly.size() >= p.poly.size())
	{
		size = p.poly.size();
	}
	else
	{
		size = poly.size();
	}

	for (int i = 0; i < size; i++)
	{
		if (poly.at(i).get_p() > p.poly.at(i).get_p())
		{
			return true;
		}
		else if (poly.at(i).get_p() == p.poly.at(i).get_p())
		{
			if (poly.at(i).get_c() > p.poly.at(i).get_c())
				return true;
			else if ((poly.at(i).get_c() == p.poly.at(i).get_c()) && (i != size - 1))
				continue;
			else
				return false;
		}
		else
		{
			return false;
		}
	}
}
//Polynomial > Term
bool Polynomial::operator >(Term & a)
{
	vector <Term> t = { a };
	Polynomial p(t);
	return (*this > p);
}
//Term > Polynomial
bool operator >(Term & a, Polynomial & p)
{
	vector <Term> t = { a };
	Polynomial p2(t);
	return (p2 > p);
}
//Polynomial > float
bool Polynomial::operator >(float a)
{
	Term t(a, 0);
	return (*this > t);
}
// float > Polynomial
bool operator >(float a, Polynomial & p)
{
	Term t(a, 0);
	return (t > p);
}

//Polynomial < Polynomial
bool Polynomial::operator <(Polynomial & p)
{
	int size;
	if (poly.size() >= p.poly.size())
	{
		size = p.poly.size();
	}
	else
	{
		size = poly.size();
	}

	for (int i = 0; i < size; i++)
	{
		if (poly.at(i).get_p() < p.poly.at(i).get_p())
		{
			return true;
		}
		else if (poly.at(i).get_p() == p.poly.at(i).get_p())
		{
			if (poly.at(i).get_c() < p.poly.at(i).get_c())
				return true;
			else if ((poly.at(i).get_c() == p.poly.at(i).get_c()) && (i != size - 1))
				continue;
			else
				return false;
		}
		else
		{
			return false;
		}
	}
}
//Polynomial < Term
bool Polynomial::operator <(Term & a)
{
	vector <Term> t = { a };
	Polynomial p(t);
	return (*this < p);
}
//Term < Polynomial
bool operator <(Term & a, Polynomial & p)
{
	vector <Term> t = { a };
	Polynomial p2(t);
	return (p2 < p);
}
//Polynomial < float
bool Polynomial::operator <(float a)
{
	Term t(a, 0);
	return (*this < t);
}
// float < Polynomial
bool operator <(float a, Polynomial & p)
{
	Term t(a, 0);
	return (t < p);
}

//Polynomial >= Polynomial
bool Polynomial::operator >=(Polynomial & p)
{
	int size;
	if (poly.size() >= p.poly.size())
	{
		size = p.poly.size();
	}
	else
	{
		size = poly.size();
	}

	for (int i = 0; i < size; i++)
	{
		if (poly.at(i).get_p() > p.poly.at(i).get_p())
		{
			return true;
		}
		else if (poly.at(i).get_p() == p.poly.at(i).get_p())
		{
			if (poly.at(i).get_c() > p.poly.at(i).get_c())
				return true;
			else if ((i == size - 1) && (poly.at(i).get_c() == p.poly.at(i).get_c()))
				return true;
			else if ((i != size - 1) && (poly.at(i).get_c() == p.poly.at(i).get_c()))
				continue;
			else
				return false;
		}
		else
		{
			return false;
		}
	}
}
//Polynomial >= Term
bool Polynomial::operator >=(Term & a)
{
	vector <Term> t = { a };
	Polynomial p(t);
	return (*this >= p);
}
//Term >= Polynomial
bool operator >=(Term & a, Polynomial & p)
{
	vector <Term> t = { a };
	Polynomial p1(t);
	return (p1 >= p);
}
//Polynomial >= float
bool Polynomial::operator >=(float a)
{
	Term t(a, 0);
	return (*this >= t);
}
//float >= Polynomial
bool operator >=(float a, Polynomial & p)
{
	Term t(a, 0);
	return (t >= p);
}

//Polynomial <= Polynomial
bool Polynomial::operator <=(Polynomial & p)
{
	int size;
	if (poly.size() >= p.poly.size())
	{
		size = p.poly.size();
	}
	else
	{
		size = poly.size();
	}

	for (int i = 0; i < size; i++)
	{
		if (poly.at(i).get_p() < p.poly.at(i).get_p())
		{
			return true;
		}
		else if (poly.at(i).get_p() == p.poly.at(i).get_p())
		{
			if (poly.at(i).get_c() < p.poly.at(i).get_c())
				return true;
			else if ((i == size - 1) && (poly.at(i).get_c() == p.poly.at(i).get_c()))
				return true;
			else if ((i != size - 1) && (poly.at(i).get_c() == p.poly.at(i).get_c()))
				continue;
			else
				return false;
		}
		else
		{
			return false;
		}
	}
}
//Polynomial <= Term
bool Polynomial::operator <=(Term & a)
{
	vector <Term> t = { a };
	Polynomial p(t);
	return (*this <= p);
}
//Term <= Polynomial
bool operator <=(Term & a, Polynomial & p)
{
	vector <Term> t = { a };
	Polynomial p1(t);
	return (p1 <= p);
}
//Polynomial <= float
bool Polynomial::operator <=(float a)
{
	Term t(a, 0);
	return (*this <= t);
}
//float <= Polynomial
bool operator <=(float a, Polynomial & p)
{
	Term t(a, 0);
	return (t <= p);
}

//Polynomial == Polynomial
bool Polynomial::operator ==(Polynomial & p)
{
	if (poly.size() != p.poly.size())
		return false;

	int size = poly.size();

	for (int i = 0; i < size; i++)
	{
		if (poly.at(i).get_p() == p.poly.at(i).get_p())
		{
			if ((i == size - 1) && (poly.at(i).get_c() == p.poly.at(i).get_c()))
				return true;
			else if ((i != size - 1) && (poly.at(i).get_c() == p.poly.at(i).get_c()))
				continue;
			else
				return false;
		}
		else
			return false;
	}
}
//Polynomial == Term
bool Polynomial::operator ==(Term & a)
{
	vector <Term> t = { a };
	Polynomial p(t);
	return (*this == p);
}
//Term == Polynomial
bool operator ==(Term & a, Polynomial & p)
{
	return (p == a);
}
//Polynomial == float
bool Polynomial::operator ==(float a)
{
	Term t(a, 0);
	return (*this == t);
}
//float == Polynomial
bool operator ==(float a, Polynomial & p)
{
	return (p == a);
}

//Polynomial != Polynomial
bool Polynomial::operator !=(Polynomial & p)
{
	return !(*this == p);
}
//Polynomial != Term
bool Polynomial::operator !=(Term & a)
{
	return !(*this == a);
}
//Term != Polynomial
bool operator !=(Term & a, Polynomial & p)
{
	return !(a == p);
}
//Polynomial != float
bool Polynomial::operator !=(float a)
{
	return !(*this == a);
}
//float != Polynomial
bool operator !=(float a, Polynomial & p)
{
	return !(a == p);
}

//derivative
Polynomial Polynomial::operator~()
{
	vector <Term> t;
	for (int i = 0; i < poly.size(); i++)
	{
		t.push_back(~poly.at(i));
	}

	return Polynomial(t);
}

// ++p
Polynomial& Polynomial::operator++()
{
	*this = *this + 1;
	sort_poly();
	simplify_poly();
	return *this;
}
// p++
Polynomial Polynomial::operator++(int)
{
	Polynomial result(poly);
	*this = *this + 1;
	sort_poly();
	simplify_poly();
	return result;
}

// --p
Polynomial& Polynomial::operator--()
{
	*this = *this - 1;
	sort_poly();
	simplify_poly();
	return *this;
}
// p--
Polynomial Polynomial::operator--(int)
{
	Polynomial result(poly);
	*this = *this - 1;
	sort_poly();
	simplify_poly();
	return result;
}

//Algebraic quantification
float Polynomial::operator()(float a)
{
	float sum = 0;
	for (int i = 0; i < poly.size(); i++)
	{
		sum += poly.at(i)(a);
	}
	return sum;
}

// find a term in polynomial
Term Polynomial::operator[](int i)
{
	if ((i - 1 >= poly.size()) && (i - 1 < 0))
		throw "Number is bigger than Polynomial size or smaller than 1";
	return poly.at(i - 1);
}

//cout << p
std::ostream & operator<<(std::ostream & out, const Polynomial & a)
{
	for (int i = 0; i < a.poly.size(); i++)
	{
		out << a.poly.at(i);
		out << ' ';
	}
	return out;
}

//cin >> p
std::istream& operator>>(std::istream & in, Polynomial & a)
{
	int size_of_poly;
	cout << "How many terms do yo want to insert: ";
	cin >> size_of_poly;
	vector <Term> t(size_of_poly);
	for (int i = 0; i < size_of_poly; i++)
	{
		cout << "#" << i + 1 << "th\n";
		in >> t.at(i);
	}

	a.poly = t;
	a.sort_poly();
	a.simplify_poly();
	return in;
}

//Number of Term in Polynomial
int Polynomial::num_of_terms()
{
	return poly.size();
}

//degree of Polynomial
int Polynomial::degree_of_poly()
{
	if (num_of_terms() == 0)
		throw - 1;
	sort_poly();
	return poly.at(0).get_p();
}
