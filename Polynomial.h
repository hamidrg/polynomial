#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H

class Polynomial
{
private:
	std::vector <Term> poly;
public:
	Polynomial() {}
	Polynomial(std::vector <Term> p);
	void display_poly();
	void sort_poly();
	void simplify_poly();
	void shrink_poly(); // delete term with zero coefficient

	//Polynomial + Polynomial
	Polynomial operator +(const Polynomial& p);
	//Polynomial + Term
	Polynomial operator +(const Term& a);
	//Term + Polynomial
	friend Polynomial operator +(const Term& a, const Polynomial& p);
	//Polynomial + float
	Polynomial operator +(float a);
	//float + Polynomial 
	friend Polynomial operator +(float a, Polynomial p);

	//Polynomial - Polynomial
	Polynomial operator -(Polynomial& p);
	//Polynomial - Term
	Polynomial operator -(Term& a);
	//Term - Polynomial
	friend Polynomial operator -(Term& a, Polynomial& p);
	//Polynomial - float
	Polynomial operator -(float a);
	//float - Polynomial 
	friend Polynomial operator -(float a, Polynomial p);

	//Polynomial * Polynomial
	Polynomial operator *(Polynomial& p);
	//Polynomial * Term
	Polynomial operator *(Term& a);
	//Term * Polynomial
	friend Polynomial operator *(Term& a, Polynomial& p);
	//Polynomial * float
	Polynomial operator *(float a);
	//Polynomial * float
	friend Polynomial operator *(float a, Polynomial& p);

	//Polynomial += Polynomial
	void operator +=(Polynomial& p);

	//Polynomial -= Polynomial
	void operator -=(Polynomial& p);

	//Polynomial *= Polynomial
	void operator *=(Polynomial& p);

	//Polynomial = Polynomial was defined

	//Polynomial > Polynomial
	bool operator >(Polynomial& p);
	//Polynomial > Term
	bool operator >(Term& a);
	//Term > Polynomial
	friend bool operator >(Term& a, Polynomial& p);
	//Polynomial > float
	bool operator >(float a);
	// float > Polynomial
	friend bool operator >(float a, Polynomial& p);

	//Polynomial < Polynomial
	bool operator <(Polynomial& p);
	//Polynomial < Term
	bool operator <(Term& a);
	//Term < Polynomial
	friend bool operator <(Term& a, Polynomial& p);
	//Polynomial < float
	bool operator <(float a);
	// float < Polynomial
	friend bool operator <(float a, Polynomial& p);

	//Polynomial >= Polynomial
	bool operator >=(Polynomial& p);
	//Polynomial >= Term
	bool operator >=(Term& a);
	//Term >= Polynomial
	friend bool operator >=(Term& a, Polynomial& p);
	//Polynomial >= float
	bool operator >=(float a);
	//float >= Polynomial
	friend bool operator >=(float a, Polynomial& p);

	//Polynomial <= Polynomial
	bool operator <=(Polynomial& p);
	//Polynomial <= Term
	bool operator <=(Term& a);
	//Term <= Polynomial
	friend bool operator <=(Term& a, Polynomial& p);
	//Polynomial <= float
	bool operator <=(float a);
	//float <= Polynomial
	friend bool operator <=(float a, Polynomial& p);

	//Polynomial == Polynomial
	bool operator ==(Polynomial& p);
	//Polynomial == Term
	bool operator ==(Term& a);
	//Term == Polynomial
	friend bool operator ==(Term& a, Polynomial& p);
	//Polynomial == float
	bool operator ==(float a);
	//float == Polynomial
	friend bool operator ==(float a, Polynomial& p);

	//Polynomial != Polynomial
	bool operator !=(Polynomial& p);
	//Polynomial != Term
	bool operator !=(Term& a);
	//Term != Polynomial
	friend bool operator !=(Term& a, Polynomial& p);
	//Polynomial != float
	bool operator !=(float a);
	//float != Polynomial
	friend bool operator !=(float a, Polynomial& p);

	//derivative
	Polynomial operator~();

	// ++p
	Polynomial& operator++();
	// p++
	Polynomial operator++(int);
	// --p
	Polynomial& operator--();
	// p--
	Polynomial operator--(int);

	//Algebraic quantification
	float operator()(float a);

	// find ith term in polynomial
	Term operator[](int i);

	//cout << p
	friend std::ostream& operator<<(std::ostream& out, const Polynomial& a);
	//cin >> p
	friend std::istream& operator>>(std::istream& in, Polynomial& a);

	//Number of Term in Polynomial
	int num_of_terms();

	//degree of Polynomial
	int degree_of_poly();
};

Polynomial operator +(const Term& a, const Polynomial& p);
Polynomial operator +(float a, Polynomial p);
Polynomial operator -(Term& a, Polynomial& p);
Polynomial operator -(float a, Polynomial p);
Polynomial operator *(Term& a, Polynomial& p);
Polynomial operator *(float a, Polynomial& p);
bool operator >(Term& a, Polynomial& p);
bool operator >(float a, Polynomial& p);
bool operator <(Term& a, Polynomial& p);
bool operator <(float a, Polynomial& p);
bool operator >=(Term& a, Polynomial& p);
bool operator >=(float a, Polynomial& p);
bool operator <=(Term& a, Polynomial& p);
bool operator <=(float a, Polynomial& p);
bool operator ==(Term& a, Polynomial& p);
bool operator ==(float a, Polynomial& p);
bool operator !=(Term& a, Polynomial& p);
bool operator !=(float a, Polynomial& p);
std::ostream& operator<<(std::ostream& out, const Polynomial& a);
std::istream& operator>>(std::istream& in, Polynomial& a);
#endif
