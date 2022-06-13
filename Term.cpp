#include <iostream>
#include <string>
#include <math.h>
#include "Term.h"

using namespace std;

//constructor
Term::Term()
{
	c = 0;
	p = 0;
}
Term::Term(float _c, int _p)
{
	c = _c;
	p = _p;
}

//display Term
void Term::display_term()
{
	//display coefficient
	if (c == 0)
	{
		cout << 0;
	}
	else if (c == 1)
	{
		if (p == 0)
		{
			cout << "+1";
		}
		else
		{
			cout << "+" << x;
		}
	}
	else if (c == -1)
	{
		if (p == 0)
		{
			cout << "-1";
		}
		else
		{
			cout << "-" << x;
		}
	}
	else
	{
		if (c > 0)
		{
			cout << "+" << c;
		}
		else
		{
			cout << c;
		}
		if (p == 0)
		{
			cout << "";
		}
		else
		{
			cout << x;
		}
	}
	//display power
	if (p == 1 || p == 0)
	{
		cout << "";
	}
	else
	{
		cout << '^' << p;
	}
}

//Term + Term
Term Term::operator+(const Term& a)
{
	if (p == a.p)
	{
		return Term(c + a.c, p);
	}
	else
	{
		throw "You can't sum terms with diffrent powers";
	}
}

//Term + float
Term Term::operator+(float a)
{
	if (p == 0)
	{
		return Term(c + a, 0);
	}
	else
	{
		throw "You can't sum terms with diffrent powers";
	}
}

//float + Term
Term operator+(float a, const Term& b)
{
	if (b.p == 0)
	{
		return Term(a + b.c, b.p);
	}
	else
	{
		throw "You can't sum terms with diffrent powers";
	}
}

//Term - Term
Term Term::operator-(const Term& a)
{
	if (p == a.p)
	{
		return Term(c - a.c, p);
	}
	else
	{
		throw "You can't minus terms with diffrent powers";
	}
}

//Term - float
Term Term::operator-(float a)
{
	if (p == 0)
	{
		return Term(c - a, 0);
	}
	else
	{
		throw "You can't minus terms with diffrent powers";
	}
}

//float - Term
Term operator-(float a, const Term& b)
{
	if (b.p == 0)
	{
		return Term(a - b.c, b.p);
	}
	else
	{
		throw "You can't minus terms with diffrent powers";
	}
}

//Term * Term
Term Term::operator*(const Term& a)
{
	return Term(c * a.c, p + a.p);
}

//Term * float
Term Term::operator*(float a)
{
	return Term(c * a, p);
}

//float * Term
Term operator*(float a, const Term & b)
{
	return Term(a * b.c, b.p);
}

//Term / Term
Term Term::operator/(const Term & a)
{
	if (a.c == 0)
	{
		throw "Division by zero isn't defined";
	}
	else
	{
		return Term(c / a.c, p - a.p);
	}
}

//Term / float
Term Term::operator/(float a)
{
	if (a == 0)
	{
		throw "Division by zero isn't defined";
	}
	else
	{
		return Term(c / a, p);
	}
}

//float / Term
Term operator/(float a, const Term & b)
{
	if (b.c == 0)
	{
		throw "Division by zero isn't defined";
	}
	else
	{
		return Term(a / b.c, b.p * -1);
	}
}

//Term += Term
void Term::operator+=(const Term & a)
{
	if (p == a.p)
	{
		c += a.c;
	}
	else
	{
		throw "You can't sum terms with diffrent powers";
	}
}

//Term -= Term
void Term::operator-=(const Term & a)
{
	if (p == a.p)
	{
		c -= a.c;
	}
	else
	{
		throw "You can't minus terms with diffrent powers";
	}
}

//Term *= Term
void Term::operator*=(const Term & a)
{
	c *= a.c;
	p += a.p;
}

//Term /= Term
void Term::operator/=(const Term & a)
{
	if (a.c == 0)
	{
		throw "Division by zero isn't defined";
	}
	else
	{
		c /= a.c;
		p -= a.p;
	}
}

//Term = Term
void Term::operator=(const Term & a)
{
	c = a.c;
	p = a.p;
}

//Term > Term
bool Term::operator>(const Term & a)
{
	if (p > a.p)
	{
		return true;
	}
	else if (p == a.p)
	{
		if (c > a.c)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	else
	{
		return false;
	}
}

//Term > float
bool Term::operator>(float a)
{
	if (p == 0)
	{
		if (c > a)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	else
	{
		return false;
	}
}

//float > Term
bool operator>(float a, const Term & b)
{
	if (b.p == 0)
	{
		if (a > b.c)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	else
	{
		return false;
	}
}

//Term >= Term
bool Term::operator>=(const Term & a)
{
	if (p > a.p)
	{
		return true;
	}
	else if (p == a.p)
	{
		if (c >= a.c)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	else
	{
		return false;
	}
}

//Term >= float
bool Term::operator>=(float a)
{
	if (p == 0)
	{
		if (c >= a)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	else
	{
		return false;
	}
}

//float >= Term
bool operator>=(float a, const Term & b)
{
	if (b.p == 0)
	{
		if (a >= b.c)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	else
	{
		return false;
	}
}

//Term < Term
bool Term::operator<(const Term & a)
{
	if (p < a.p)
	{
		return true;
	}
	else if (p == a.p)
	{
		if (c < a.c)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	else
	{
		return false;
	}
}

//Term < float
bool Term::operator<(float a)
{
	if (p == 0)
	{
		if (c < a)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	else
	{
		return false;
	}
}

//float < Term
bool operator<(float a, const Term & b)
{
	if (b.p == 0)
	{
		if (a < b.c)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	else
	{
		return false;
	}
}

//Term <= Term
bool Term::operator<=(const Term & a)
{
	if (p < a.p)
	{
		return true;
	}
	else if (p == a.p)
	{
		if (c <= a.c)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	else
	{
		return false;
	}
}

//Term <= float
bool Term::operator<=(float a)
{
	if (p == 0)
	{
		if (c <= a)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	else
	{
		return false;
	}
}

//float <= Term
bool operator<=(float a, const Term & b)
{
	if (b.p == 0)
	{
		if (a <= b.c)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	else
	{
		return false;
	}
}

//Term == Term
bool Term::operator==(const Term & a)
{
	if (p == a.p)
	{
		if (c == a.c)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	else
	{
		return false;
	}
}

//Term == float
bool Term::operator==(float a)
{
	if (p == 0)
	{
		if (c == a)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	else
	{
		return false;
	}
}

//float == Term
bool operator==(float a, const Term & b)
{
	if (b.p == 0)
	{
		if (a == b.c)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	else
	{
		return false;
	}
}

//Term != Term
bool Term::operator!=(const Term & a)
{
	if (p != a.p)
	{
		return true;
	}
	else
	{
		if (c != a.c)
		{
			return true;
		}
		else
		{
			return false; // two terms are equal
		}
	}
}

//Term != float
bool Term::operator!=(float a)
{
	if (p != 0)
	{
		return true;
	}
	else
	{
		if (c != a)
		{
			return true;
		}
		else
		{
			return false; // term and float are equal
		}
	}
}

//float != Term
bool operator!=(float a, const Term & b)
{
	if (b.p != 0)
	{
		return true;
	}
	else
	{
		if (b.c != a)
		{
			return true;
		}
		else
		{
			return false; // term and float are equal
		}
	}
}

//++Term
Term& Term::operator++()
{
	if (p == 0)
	{
		c++;
		return *this;
	}
	else
	{
		throw "You can't sum terms with diffrent powers";
	}
}

//Term++
Term Term::operator++(int)
{
	if (p == 0)
	{
		c++;
		return Term(c, p);
	}
	else
	{
		throw "You can't sum terms with diffrent powers";
	}
}

//--Term
Term& Term::operator--()
{
	if (p == 0)
	{
		c--;
		return *this;
	}
	else
	{
		throw "You can't minus terms with diffrent powers";
	}
}

//Term--
Term Term::operator--(int)
{
	if (p == 0)
	{
		c--;
		return Term(c, p);
	}
	else
	{
		throw "You can't minus terms with diffrent powers";
	}
}

//derivative
Term Term::operator~()
{
	if (p == 0)
		return Term(0, 0);

	return Term(c * p, p - 1);
}

//Algebraic quantification : 3x^4  === x=1 ===> result=3
float Term::operator()(float a)
{
	return (c * pow(a, p));
}

//cout << Term
ostream& operator<<(ostream & out, const Term & a)
{
	//display coefficient
	if (a.c == 0)
	{
		out << 0;
	}
	else if (a.c == 1)
	{
		if (a.p == 0)
		{
			out << "+1";
		}
		else
		{
			out << '+' << a.x;
		}
	}
	else if (a.c == -1)
	{
		if (a.p == 0)
		{
			out << "-1";
		}
		else
		{
			out << '-' << a.x;
		}
	}
	else
	{
		if (a.c > 0)
		{
			out << '+' << a.c;
		}
		else
		{
			cout << a.c;
		}
		if (a.p == 0)
		{
			out << "";
		}
		else
		{
			out << a.x;
		}
	}
	//display power
	if (a.p == 1 || a.p == 0)
	{
		out << "";
	}
	else
	{
		out << '^' << a.p;
	}
	return out;
}

//cin >> Term
istream& operator>>(istream & in, Term & a)
{
	float _c; // coefficient
	int _p; // power
	bool pow_is_zero = false;

	string term;
	cout << "Enter Term : ";
	in >> term;

	int x_pos = term.find('x'); // find coefficient position

	string c;
	if (x_pos == -1) // if there is no 'x' in the term then x_pos is -1
	{
		c = term.substr(0, term.size()); // extract coefficient
		_c = stof(c); // convert string to float
		_p = 0;
		pow_is_zero = true;
	}
	else if (x_pos == 0) // if x position is 0 then coefficient is 1
	{
		_c = 1;
	}
	else
	{
		c = term.substr(0, x_pos);
		if (c == "-") // if substr is "-" then coefficient is -1
		{
			_c = -1;
		}
		else if (c == "+")
		{
			_c = 1;
		}
		else
		{
			_c = stof(c); // convert string to float
		}
	}

	if (!pow_is_zero) // if power is not zero then find it
	{
		// check whether power exist or not
		bool check_pow_exist = false;
		for (int i = 0; i < term.size(); i++)
		{
			if (term.at(i) == '^')
			{
				check_pow_exist = true;
			}
		}
		if (check_pow_exist == false)
		{
			_p = 1;
		}
		else // find power
		{
			int pow_pos = term.find('^'); // find power position
			string p = term.substr(pow_pos + 1, term.size()); // extract power
			_p = stof(p); // convert string to float
		}
	}

	a.set_c(_c);
	a.set_p(_p);
	return in;

}
