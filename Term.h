#ifndef TERM_H
#define TERM_H

class Term
{
private:
	float c; // coefficient
	char x = 'x'; // variable
	int p; // power

public:
	Term();
	Term(float _c, int _p);
	void display_term();

	Term operator+(const Term& a);
	Term operator+(float a);
	friend Term operator+(float a, const Term& b);

	Term operator-(const Term& a);
	Term operator-(float a);
	friend Term operator-(float a, const Term& b);

	Term operator*(const Term& a);
	Term operator*(float a);
	friend Term operator*(float a, const Term& b);

	Term operator/(const Term& a);
	Term operator/(float a);
	friend Term operator/(float a, const Term& b);

	void operator+=(const Term& a);

	void operator-=(const Term& a);

	void operator*=(const Term& a);

	void operator/=(const Term& a);

	void operator=(const Term& a);

	bool operator>(const Term& a);
	bool operator>(float a);
	friend bool operator>(float a, const Term& b);

	bool operator>=(const Term& a);
	bool operator>=(float a);
	friend bool operator>=(float a, const Term& b);

	bool operator<(const Term& a);
	bool operator<(float a);
	friend bool operator<(float a, const Term& b);

	bool operator<=(const Term& a);
	bool operator<=(float a);
	friend bool operator<=(float a, const Term& b);

	bool operator==(const Term& a);
	bool operator==(float a);
	friend bool operator==(float a, const Term& b);

	bool operator!=(const Term& a);
	bool operator!=(float a);
	friend bool operator!=(float a, const Term& b);

	Term& operator++(); // ++a
	Term operator++(int); // a++

	Term& operator--(); // --a
	Term operator--(int); // a--

	Term operator~(); // derivative

	float operator()(float a);

	friend std::ostream& operator<<(std::ostream& out, const Term& a);
	friend std::istream& operator>>(std::istream& in, Term& a);

	//setter
	void set_c(float _c) { c = _c; }
	void set_p(int _p) { p = _p; }
	//getter
	float get_c() { return c; }
	char get_x() { return x; }
	int get_p() { return p; }
};

Term operator+(float a, const Term& b);
Term operator-(float a, const Term& b);
Term operator*(float a, const Term& b);
Term operator/(float a, const Term& b);
bool operator>(float a, const Term& b);
bool operator>=(float a, const Term& b);
bool operator<(float a, const Term& b);
bool operator<=(float a, const Term& b);
bool operator==(float a, const Term& b);
bool operator!=(float a, const Term& b);
std::ostream& operator<<(std::ostream& out, const Term& a);
std::istream& operator>>(std::istream& in, Term& a);
#endif
