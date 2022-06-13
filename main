#include <iostream>
#include <vector>
#include <stdlib.h>
#include <fstream>
#include <string>
#include "Term.h"
#include "Polynomial.h"
using namespace std;

void poly_menu(Polynomial poly);
void compare(Polynomial& c_poly, Polynomial& n_poly);
void write_in_text_file(Polynomial poly, string name_of_file);
Polynomial read_from_text_file(string name_of_file);
void write_in_binary_file(Polynomial poly, string name_of_file);
Polynomial read_from_binary_file(string name_of_file);

int main()
{
	while (true)
	{
		int menu_options;
		cout << "\n\t---------------\n";
		cout << "\t |1- New Polynomial\n"
			<< "\t |2- Load from text file\n"
			<< "\t |3- Load from binary file\n"
			<< "\t |4- Quit\n";
		cout << "\t |which one (1/2/3/4) ?? ";
		cin >> menu_options;
		system("CLS");// clear console
		if (menu_options == 1)
		{
			Polynomial p;
			try
			{
				poly_menu(p);
			}
			catch (char)
			{
				cerr << "\tInvalid input\n";
			}
		}
		else if (menu_options == 2)
		{
			system("CLS"); // clear console
			string name_of_file;
			cout << "\tEnter name of file : ";
			cin >> name_of_file;
			name_of_file += ".txt";
			try
			{
				Polynomial p = read_from_text_file(name_of_file);
				poly_menu(p);
			}
			catch (int)
			{
				cerr << "\tUnable to open file\n";
			}
			catch (char)
			{
				cerr << "\tInvalid input\n";
			}
		}
		else if (menu_options == 3)
		{
			system("CLS"); // clear console
			string name_of_file;
			cout << "\tEnter name of file : ";
			cin >> name_of_file;
			name_of_file += ".dat";
			try
			{
				Polynomial p = read_from_binary_file(name_of_file);
				poly_menu(p);
			}
			catch (int)
			{
				cerr << "\tUnable to open file\n";
			}
			catch (char)
			{
				cerr << "\tInvalid input\n";
			}
		}
		else if (menu_options == 4)
		{
			break;
		}
		else
		{
			cout << "\n\t Invlalid input";
		}
	}
	return 0;
}

void poly_menu(Polynomial poly)
{
	while (true)
	{
		int menu_options;
		cout << "\n\t---------------\n";
		cout << "\tCurrent Polynomial = " << poly << endl;
		cout << "\t |1- Add\n"
			<< "\t |2- Subtract\n"
			<< "\t |3- Multiply\n"
			<< "\t |4- Derivative\n"
			<< "\t |5- Find Degree\n"
			<< "\t |6- Find Value for specific x\n"
			<< "\t |7- Compare\n"
			<< "\t |8- Save to a text file\n"
			<< "\t |9- Save to a binary file\n"
			<< "\t |10- Back to Main Menu\n";
		cout << "\t |which one  ?? ";
		cin >> menu_options;
		system("CLS"); // clear console
		if (menu_options == 1)
		{
			Polynomial new_poly;
			cin >> new_poly;
			poly += new_poly;
			system("CLS"); // clear console
		}
		else if (menu_options == 2)
		{
			Polynomial new_poly;
			cin >> new_poly;
			poly -= new_poly;
			system("CLS"); // clear console
		}
		else if (menu_options == 3)
		{
			if (poly.num_of_terms() == 0)
			{
				cout << "\tPolynomial is null";
				continue;
			}
			Polynomial new_poly;
			cin >> new_poly;
			poly *= new_poly;
			system("CLS"); // clear console
		}
		else if (menu_options == 4)
		{
			if (poly.num_of_terms() == 0)
			{
				cout << "\tPolynomial is null";
				continue;
			}
			poly = ~poly;
			system("CLS"); // clear console
		}
		else if (menu_options == 5)
		{
			system("CLS"); // clear console
			try
			{
				cout << "\tf(x) = " << poly << endl;
				cout << "\tDegree of f(x): " << poly.degree_of_poly() << endl;
			}
			catch (int a)
			{
				cerr << "\tPolynomial is null\n";
			}
			
		}
		else if (menu_options == 6)
		{
			system("CLS"); // clear console
			if (poly.num_of_terms() == 0)
			{
				cout << "\tPolynomial is null";
				continue;
			}
			cout << "\tf(x) = " << poly << endl;
			float x;
			cout << "\tEnter specific x : ";
			cin >> x;
			cout << "\tf(" << x << ") = " << poly(x) << endl;
		}
		else if (menu_options == 7)
		{
			system("CLS"); // clear console
			if (poly.num_of_terms() == 0)
			{
				cout << "\tPolynomial is null";
				continue;
			}
			Polynomial n_poly;
			cin >> n_poly;
			compare(poly, n_poly);
		}
		else if (menu_options == 8)
		{
			system("CLS"); // clear console
			string name_of_file;
			cout << "\tEnter name of file : ";
			cin >> name_of_file;
			name_of_file += ".txt";
			try
			{
				write_in_text_file(poly, name_of_file);
			}
			catch (int)
			{
				cerr << "\tUnable to open text file\n";
			}
			
		}
		else if (menu_options == 9)
		{
			system("CLS"); // clear console
			string name_of_file;
			cout << "\tEnter name of file : ";
			cin >> name_of_file;
			name_of_file += ".dat";
			try
			{
				write_in_binary_file(poly, name_of_file);
			}
			catch (int)
			{
				cerr << "\tUnable to open binary file\n";
			}
		}
		else if (menu_options == 10)
		{
			break;
		}
		else
		{
			throw 'e';
		}
	}
}

void compare(Polynomial& c_poly, Polynomial& n_poly)
{
	system("CLS"); // clear console
	cout << "\tCurrent Polynomial = " << c_poly << endl;
	cout << "\tOther Polynomial = " << n_poly << endl;
	cout << "\tComparing Current_Polynomial with Other_Polynomial:\n\n";
	cout << "\tCurrent_Polynomial > Other_Polynomial: " << ((c_poly > n_poly) ? "true" : "false") << endl;
	cout << "\tCurrent_Polynomial >= Other_Polynomial: " << ((c_poly >= n_poly) ? "true" : "false") << endl;
	cout << "\tCurrent_Polynomial < Other_Polynomial: " << ((c_poly < n_poly) ? "true" : "false") << endl;
	cout << "\tCurrent_Polynomial <= Other_Polynomial: " << ((c_poly <= n_poly) ? "true" : "false") << endl;
	cout << "\tCurrent_Polynomial == Other_Polynomial: " << ((c_poly == n_poly) ? "true" : "false") << endl;
}

void write_in_text_file(Polynomial poly, string name_of_file)
{
	ofstream fout;
	fout.open(name_of_file, ios::app);
	if (fout.is_open())
	{
		for (int i = 0; i < poly.num_of_terms(); i++)
		{
			//print each term in a line with this format : x^2 ==>  1 2   1:coefficient 2:power
			//poly[i+1] return ith term of poly
			fout << poly[i + 1].get_c() << ' ' << poly[i + 1].get_p() << '\n';
		}
		fout.close();
	}
	else
	{
		throw -1;
	}
}

Polynomial read_from_text_file(string name_of_file)
{
	ifstream fin;
	vector <Term> t;
	fin.open(name_of_file, ios::in);
	if (fin.is_open())
	{
		while (!fin.eof())
		{
			float c, p;
			fin >> c >> p;
			t.push_back(Term(c, p));
		}
		fin.close();
		t.pop_back(); // last term read to times so we must delete one of them (ifstream bug)
		return Polynomial(t);
	}
	else
	{
		throw -1;
	}
}

void write_in_binary_file(Polynomial poly, string name_of_file)
{
	ofstream fout;
	fout.open(name_of_file, ios::app | ios::binary);

	if (fout.is_open())
	{
		for (int i = 0; i < poly.num_of_terms(); i++)
		{
			float c = poly[i + 1].get_c();
			int p = poly[i + 1].get_p();
			char space = ' ';
			char endline = '\n';
			fout.write((char*)& c, sizeof(c));
			fout.write((char*)& space, sizeof(space));
			fout.write((char*)& p, sizeof(p));
			fout.write((char*)& endline, sizeof(endline));
		}
		fout.close();
	}
	else
	{
		throw -1;
	}
}

Polynomial read_from_binary_file(string name_of_file)
{
	ifstream fin;
	fin.open(name_of_file, ios::binary);

	vector <Term> t;
	if (fin.is_open())
	{
		while (!fin.eof())
		{
			float c;
			int p;
			char space;
			char endline;
			fin.read((char*)& c, sizeof(c));
			fin.read((char*)& space, sizeof(space));
			fin.read((char*)& p, sizeof(p));
			fin.read((char*)& endline, sizeof(endline));
			t.push_back(Term(c, p));
		}
		fin.close();
		t.pop_back(); // last term read to times so we must delete one of them (ifstream bug)
		return Polynomial(t);
	}
	else
	{
		throw -1;
	}
}
