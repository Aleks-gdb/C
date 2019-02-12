//testDriver.cpp runs the program from the main()
#include "Prototypes.h"
int main()
{
	char ans, ans1;
	int real, imag, real2, imag2;
	Complex Cnum;
	Complex Cnum2;
	Complex Result;
	cout << "Welcome!" << endl;
		cout << "Please choose the operation:"
			<< "\na. Add"
			<< "\nb. Subtract"
			<< "\nc. Multiply"
			<< "\nd. Divide"	
			<< "\ne. Compare"
			<< "\nf. Exit"
			<< endl;
		cin >> ans;
		switch (ans)
		{
		case 'a':
		case 'A':
			for (;;) {
				cout << "\nPlease enter the first number"
					<< "\nReal number: ";
				if (cin >> real) {
					break;
				}
				else {
					cout << "Please enter a valid integer" << endl;
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
				}
			}
			for (;;) {
				cout << "\nImaginary number: ";
				if (cin >> imag) {
					break;
				}
				else {
					cout << "Please enter a valid integer" << endl;
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
				}
			}
			for (;;) {
				cout << "\nPlease enter the second number"
					<< "\nReal number: ";
				if (cin >> real2) {
					break;
				}
				else {
					cout << "Please enter a valid integer" << endl;
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
				}
			}
			for (;;) {
				cout << "\nImaginary number: ";
				if (cin >> imag2) {
					break;
				}
				else {
					cout << "Please enter a valid integer" << endl;
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
				}
			}
			Cnum.setReal(real);
			Cnum.setImag(imag);
			Cnum2.setReal(real2);
			Cnum2.setImag(imag2);
			Result = Cnum.add(Cnum2);
			Result.print();

		    cout << "\nWould you like to continue with another operation?(y/n)\n";
		    cin >> ans1;
			ans1 = toupper(ans1);
			while (ans1 != 'Y' && ans1 != 'N')
				{
					cout << "\nPlease choose. (y/n) ";
					cin >> ans1;
					ans1 = toupper(ans1);
				}
			if (ans1 == 'Y')
				main();
			else
				system("pause");
			break;
			
		case 'b':
		case 'B': for (;;) {
			cout << "\nPlease enter the first number"
				<< "\nReal number: ";
			if (cin >> real) {
				break;
			}
			else {
				cout << "Please enter a valid integer" << endl;
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
			}
		}
		for (;;) {
					  cout << "\nImaginary number: ";
					  if (cin >> imag) {
						  break;
					  }
					  else {
						  cout << "Please enter a valid integer" << endl;
						  cin.clear();
						  cin.ignore(numeric_limits<streamsize>::max(), '\n');
					  }
				  }
				  for (;;) {
					  cout << "\nPlease enter the second number to subtract from the second one"
						  << "\nReal number: ";
					  if (cin >> real2) {
						  break;
					  }
					  else {
						  cout << "Please enter a valid integer" << endl;
						  cin.clear();
						  cin.ignore(numeric_limits<streamsize>::max(), '\n');
					  }
				  }
				  for (;;) {
					  cout << "\nImaginary number: ";
					  if (cin >> imag2) {
						  break;
					  }
					  else {
						  cout << "Please enter a valid integer" << endl;
						  cin.clear();
						  cin.ignore(numeric_limits<streamsize>::max(), '\n');
					  }
				  }
				  Cnum.setReal(real);
				  Cnum.setImag(imag);
				  Cnum2.setReal(real2);
				  Cnum2.setImag(imag2);
				  Result.sub(Cnum, Cnum2);
				  Result.print();

				  cout << "\nWould you like to continue with another operation?(y/n)\n";
				  cin >> ans1;
				  ans1 = toupper(ans1);
				  while (ans1 != 'Y' && ans1 != 'N')
				  {
					  cout << "\nPlease choose. (y/n) ";
					  cin >> ans1;
					  ans1 = toupper(ans1);
				  }
				  if (ans1 == 'Y')
					  main();
				  else
					  system("pause");
				  break;

		case 'c':
		case 'C': for (;;) {
			cout << "\nPlease enter the first number"
				<< "\nReal number: ";
			if (cin >> real) {
				break;
			}
			else {
				cout << "Please enter a valid integer" << endl;
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
			}
		}
				  for (;;) {
					  cout << "\nImaginary number: ";
					  if (cin >> imag) {
						  break;
					  }
					  else {
						  cout << "Please enter a valid integer" << endl;
						  cin.clear();
						  cin.ignore(numeric_limits<streamsize>::max(), '\n');
					  }
				  }
				  for (;;) {
					  cout << "\nPlease enter the second number"
						  << "\nReal number: ";
					  if (cin >> real2) {
						  break;
					  }
					  else {
						  cout << "Please enter a valid integer" << endl;
						  cin.clear();
						  cin.ignore(numeric_limits<streamsize>::max(), '\n');
					  }
				  }
				  for (;;) {
					  cout << "\nImaginary number: ";
					  if (cin >> imag2) {
						  break;
					  }
					  else {
						  cout << "Please enter a valid integer" << endl;
						  cin.clear();
						  cin.ignore(numeric_limits<streamsize>::max(), '\n');
					  }
				  }
				  Cnum.setReal(real);
				  Cnum.setImag(imag);
				  Cnum2.setReal(real2);
				  Cnum2.setImag(imag2);
				  Result = Cnum.mul(Cnum2);
				  Result.print();
				  cout << "\nWould you like to continue with another operation?(y/n)\n";
				  cin >> ans1;
				  ans1 = toupper(ans1);
				  while (ans1 != 'Y' && ans1 != 'N')
				  {
					  cout << "\nPlease choose. (y/n) ";
					  cin >> ans1;
					  ans1 = toupper(ans1);
				  }
				  if (ans1 == 'Y')
					  main();
				  else
					  system("pause");
				  break;

		case 'd':
		case 'D': for (;;) {
			cout << "\nPlease enter the first number"
				<< "\nReal number: ";
			if (cin >> real) {
				break;
			}
			else {
				cout << "Please enter a valid integer" << endl;
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
			}
		}
				  for (;;) {
					  cout << "\nImaginary number: ";
					  if (cin >> imag) {
						  break;
					  }
					  else {
						  cout << "Please enter a valid integer" << endl;
						  cin.clear();
						  cin.ignore(numeric_limits<streamsize>::max(), '\n');
					  }
				  }
				  for (;;) {
					  cout << "\nPlease enter the second number to subtract from the second one"
						  << "\nReal number: ";
					  if (cin >> real2) {
						  break;
					  }
					  else {
						  cout << "Please enter a valid integer" << endl;
						  cin.clear();
						  cin.ignore(numeric_limits<streamsize>::max(), '\n');
					  }
				  }
				  for (;;) {
					  cout << "\nImaginary number: ";
					  if (cin >> imag2) {
						  break;
					  }
					  else {
						  cout << "Please enter a valid integer" << endl;
						  cin.clear();
						  cin.ignore(numeric_limits<streamsize>::max(), '\n');
					  }
				  }
				  Cnum.setReal(real);
				  Cnum.setImag(imag);
				  Cnum2.setReal(real2);
				  Cnum2.setImag(imag2);
				  Result.div(Cnum, Cnum2);
				  Result.print();

				  cout << "\nWould you like to continue with another operation?(y/n)\n";
				  cin >> ans1;
				  ans1 = toupper(ans1);
				  while (ans1 != 'Y' && ans1 != 'N')
				  {
					  cout << "\nPlease choose. (y/n) ";
					  cin >> ans1;
					  ans1 = toupper(ans1);
				  }
				  if (ans1 == 'Y')
					  main();
				  else
					  system("pause");
				  break;
		case 'e':
		case 'E': for (;;) {
			cout << "\nPlease enter the first number"
				<< "\nReal number: ";
			if (cin >> real) {
				break;
			}
			else {
				cout << "Please enter a valid integer" << endl;
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
			}
		}
				  for (;;) {
					  cout << "\nImaginary number: ";
					  if (cin >> imag) {
						  break;
					  }
					  else {
						  cout << "Please enter a valid integer" << endl;
						  cin.clear();
						  cin.ignore(numeric_limits<streamsize>::max(), '\n');
					  }
				  }
				  for (;;) {
					  cout << "\nPlease enter the second number"
						  << "\nReal number: ";
					  if (cin >> real2) {
						  break;
					  }
					  else {
						  cout << "Please enter a valid integer" << endl;
						  cin.clear();
						  cin.ignore(numeric_limits<streamsize>::max(), '\n');
					  }
				  }
				  for (;;) {
					  cout << "\nImaginary number: ";
					  if (cin >> imag2) {
						  break;
					  }
					  else {
						  cout << "Please enter a valid integer" << endl;
						  cin.clear();
						  cin.ignore(numeric_limits<streamsize>::max(), '\n');
					  }
				  }
				  Cnum.setReal(real);
				  Cnum.setImag(imag);
				  Cnum2.setReal(real2);
				  Cnum2.setImag(imag2);
				  if (Cnum.equal(Cnum2) == true)
					  cout << "The complex numbers are equal.";
				  else
					  cout << "The complex numbers are not equal.";
				  cout << "\nWould you like to continue with another operation?(y/n)\n";
				  cin >> ans1;
				  ans1 = toupper(ans1);
				  while (ans1 != 'Y' && ans1 != 'N')
				  {
					  cout << "\nPlease choose. (y/n) ";
					  cin >> ans1;
					  ans1 = toupper(ans1);
				  }
				  if (ans1 == 'Y')
					  main();
				  else
					  system("pause");
				  break;

		case 'f':
		case 'F': system("pause"); break;

		default: cout << "Oops! Wrong entry, try again.\n";  main(); break;
		}
	return 0;
}

#pragma once
//Prototypes.h
#include <iostream>
#include <cctype>
using namespace std;
class Complex
{
private:
	int real;
	int imag;
public:
	Complex();
	Complex(int r, int i);
	void setReal(int r);
	void setImag(int i);
	int getReal();
	int getImag();
	void print();
	bool isReal();
	bool isImaginary();
	Complex add(Complex a);
	void sub(Complex c1, Complex c2);
	Complex mul(Complex a);
	void div(Complex c1, Complex c2);
	bool equal(Complex a);
};


//Complex.cpp contains the class Complex 
#include "Prototypes.h" //Use function prototypes

//Constructor, initializes real and imaginary to 0
Complex::Complex()
{
	real = 0;
	imag = 0;
}
//Overloaded constructor, sets values of real and imaginary to r and i
Complex::Complex(int r, int i)
{
	real = r;
	imag = i;
}
//Set real number to r
void Complex::setReal(int r)
{
	real = r;
}
//Set imag number to i
void Complex::setImag(int i)
{
	imag = i;
}
//Return back the real number
int Complex::getReal()
{
	return real;
}
//Return back the imag number
int Complex::getImag()
{
	return imag;
}
//Print the real and imag numbers
void Complex::print()
{
	cout << "(" << real << ", " << imag << "i)";
}
//Check for imaginary number being equal to zero
bool Complex::isReal()
{
	if (imag == 0)
		return true;
	else
		return false;
}
//Check for real number being equal to zero
bool Complex::isImaginary()
{
	if (real == 0)
		return true;
	else
		return false;
}
//Add two Complex objects(implicit and explicit) and return a new Complex objet
Complex Complex::add(Complex a)
{
	Complex result;
	result.real = a.real + this->real;
	result.imag = a.imag + this->imag;
	return result;
}
//Subtract Complex object c2 from Complex object c1
void Complex::sub(Complex c1, Complex c2)
{
	this->imag = c1.imag - c2.imag;
	this->real = c1.real - c2.real;
}
//Mulitply two Complex objects(implicit and explicit) and return a new Complex objet
Complex Complex::mul(Complex a)
{
	Complex result;
	result.real = (a.real * this->real) - (a.imag * this->imag);
	result.imag = (a.real * this->imag) + (a.imag * this->real);
	return result;
}
//Divide c1/c2
void Complex::div(Complex c1, Complex c2)
{
	if (c1.real == c2.real && c1.imag == c2.imag)
	{
		this->real = 1;
		this->imag = 0;
	}
	else
	{
		this->real = ((c1.real * c2.real) + (c1.imag * c2.imag)) / ((c2.real * c2.real) + (c2.imag * c2.imag));
		this->imag = ((c2.real * c1.imag) - (c1.real * c2.imag)) / ((c2.real * c2.real) + (c2.imag * c2.imag));
	}
}
//Check if the objects are equal
bool Complex::equal(Complex a)
{
	if (a.real == this->real && a.imag == this->imag)
		return true;
	else
		return false;
}
