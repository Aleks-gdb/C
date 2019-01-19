
#include <iostream> //input/output
#include <string> //use strings
#include "Prototypes.h" //access to function prototypes
using namespace std;

int main()
{
	string str;
	char ans;
	cout << "Welcome!\n";
	menu();
	getline(cin, str);
	ans = str[0];
	switch (ans)
	{
	case 'L':
	case 'l': menuLearn(); break;//switch to learn mode

	case 'G':
	case 'g': menuGame(); break;//switch to game mode

	case 'E':
	case 'e': cout << "You chose to exit the game.\n";
		system("pause"); break; //exit

	default: //validating user input
		cout << "Bad choice! Try again:\n";
		main(); break;
	}
	return 0;
}

#pragma once
//Prototypes.h is the header file for function prototypes

void menu(); //This function will output the menu.
double genRand(); // This function will generate a random value to be used in the calculation.
double addition(double, double); //This function will add two values.
double subtraction(double, double); //This function will subtract the second argument from the first one.
double multiplication(double, double); // This function will multiply two values.
double dDivision(double, double);//This function will divide the first argument by the second one.
int intDiv(double, double);// This function will determine the integer division of the first argument by the second one.
int module(double, double);// This function will calculate the remainder of the integer division of the first argument by the second one.
double power(double, double);// This function will raise the first argument to the power given in the second argument.
double sine(double); // This function will calculate the sine of an angle.
double cosine(double); // This function will calculate the cosine of an angle.
					   //void outs(string, double); // This function will output the value described in the string.
void menuLearn(); //Prints the menu for Learn Mode and performs all the operations
void menuGame(); //Prints the menu for Game Mode and performs all the operations
void introductory(); //Function for the Introductory Level in Game Mode
void intermediate(); //Function for the Intermediate Level in Game Mode
void advanced(); //Function for the Advanced Level in Game Mode
int main(); //Main

//Functions.cpp 
#include <stdlib.h> //use random number generator
#include <math.h> //use sine and cosine
#include <string> //use strings
#include <iostream> //input/output
#include "Prototypes.h"

using namespace std;

void menu()
{
	cout << "Please choose an option:"
		<< "\nLearn Mode"
		<< "\nGame Mode"
		<< "\nExit" << endl << endl;
}

void menuLearn()
{
	string str, str1, s;
	char ans, ans1, ans2, an;
	cout << "You are now in the learn mode\n\n"
		<< "Please select an operation:"
		<< "\nAdd"
		<< "\nSubtract"
		<< "\nMultiply"
		<< "\nPower"
		<< "\nSine"
		<< "\nCosine"
		<< "\nReturn to the main menu\n";
	getline(cin, str);
	ans = str[0];
	ans1 = str[1];
	switch (ans)
	{
	case 'A':
	case 'a': cout << "Do you want your number(s) to be:"
		<< "\nEntered manually"
		<< "\nGenerated randomly by the computer"
		<< "\nSelect a different operation\n";
		getline(cin, str1);
		ans2 = str1[0];
		switch (ans2)
		{
		case 'E':
		case 'e':
			do
			{
				cout << "\nEnter two numbers separated by a space:\n";
				double o; double t;
				cin >> o;
				cin >> t;
				cin.ignore();
				double r = addition(o, t);
				cout << "\n" << o << " + " << t << " = " << r << endl
					<< "Would you like to repeat this operation with different numbers?(y/n)\n";
				getline(cin, s);
				an = s[0];
			} while (an == 'Y' || an == 'y');
			switch (an)
			{
			case 'n':
			case 'N': menuLearn();  break;

			default: cout << "Oops! You did not enter y/n.\n";
				menuLearn();  break;
			} break;
		case 'G':
		case 'g':
			do
			{
				double o = genRand();
				double t = genRand();
				double r = addition(o, t);
				cout << "\n" << o << " + " << t << " = " << r << endl
					<< "Would you like to repeat this operation with different numbers?(y/n)\n";
				getline(cin, s);
				an = s[0];
			} while (an == 'Y' || an == 'y');
			switch (an)
			{
			case 'n':
			case 'N': menuLearn();  break;

			default: cout << "Oops! You did not enter y/n.\n\n";
				menuLearn(); break;
			} break;
		case 'S':
		case 's': menuLearn(); break;
		default:
			cout << "You did not select an option from the menu.\n\n";
			menuLearn();
		} break;

	case 'S':
	case 's': if (ans1 == 'u' || ans1 == 'U') //case for subtract
	{
		cout << "Do you want your number(s) to be:"
			<< "\nEntered manually"
			<< "\nGenerated randomly by the computer"
			<< "\nSelect a different operation\n";
		getline(cin, str1);
		ans2 = str1[0];
		switch (ans2)
		{
		case 'E':
		case 'e':
			do
			{
				cout << "\nEnter two numbers separated by a space:\n";
				double o; double t;
				cin >> o;
				cin >> t;
				cin.ignore();
				double r = subtraction(o, t);
				cout << "\n" << o << " - " << t << " = " << r << endl
					<< "Would you like to repeat this operation with different numbers?(y/n)\n";
				getline(cin, s);
				an = s[0];
			} while (an == 'Y' || an == 'y');
			switch (an)
			{
			case 'n':
			case 'N': menuLearn();  break;

			default: cout << "Oops! You did not enter y/n.\n";
				menuLearn();  break;
			} break;
		case 'G':
		case 'g':
			do
			{
				double o = genRand();
				double t = genRand();
				double r = subtraction(o, t);
				cout << "\n" << o << " - " << t << " = " << r << endl
					<< "Would you like to repeat this operation with different numbers?(y/n)\n";
				getline(cin, s);
				an = s[0];
			} while (an == 'Y' || an == 'y');
			switch (an)
			{
			case 'n':
			case 'N': menuLearn();  break;

			default: cout << "Oops! You did not enter y/n.\n\n";
				menuLearn();  break;
			} break;
		case 'S':
		case 's': menuLearn();  break;
		default:
			cout << "You did not select an option from the menu.\n\n";
			menuLearn();  break;
		} break;
	}
			  if (ans1 == 'i' || ans1 == 'I') //case for sine
			  {
				  cout << "Do you want your number(s) to be:"
					  << "\nEntered manually"
					  << "\nGenerated randomly by the computer"
					  << "\nSelect a different operation\n";
				  getline(cin, str1);
				  ans2 = str1[0];
				  switch (ans2)
				  {
				  case 'E':
				  case 'e':
					  do
					  {
						  cout << "\nEnter the angle in radians:\n";
						  double angle;
						  cin >> angle;
						  cin.ignore();
						  double r = sine(angle);
						  cout << "\nsin(" << angle << ") " << "= " << r << endl
							  << "Would you like to repeat this operation with a different number?(y/n)\n";
						  getline(cin, s);
						  an = s[0];
					  } while (an == 'Y' || an == 'y');
					  switch (an)
					  {
					  case 'n':
					  case 'N': menuLearn();  break;

					  default: cout << "Oops! You did not enter y/n.\n";
						  menuLearn();  break;
					  } break;
				  case 'G':
				  case 'g':
					  do
					  {
						  double angle = genRand();
						  double r = sine(angle);
						  cout << "\nsin(" << angle << ") " << "= " << r << endl
							  << "Would you like to repeat this operation with different numbers?(y/n)\n";
						  getline(cin, s);
						  an = s[0];
					  } while (an == 'Y' || an == 'y');
					  switch (an)
					  {
					  case 'n':
					  case 'N': menuLearn();  break;

					  default: cout << "Oops! You did not enter y/n.\n\n";
						  menuLearn();  break;
					  } break;
				  case 'S':
				  case 's': menuLearn();  break;
				  default:
					  cout << "You did not select an option from the menu.\n\n";
					  menuLearn();  break;
				  } break;
			  }

			  cout << "\nYour answer was unclear, please try again.\n\n";
			  menuLearn(); break;

	case 'M':
	case 'm':cout << "Do you want your number(s) to be:"
		<< "\nEntered manually"
		<< "\nGenerated randomly by the computer"
		<< "\nSelect a different operation\n";
		getline(cin, str1);
		ans2 = str1[0];
		switch (ans2)
		{
		case 'E':
		case 'e':
			do
			{
				cout << "\nEnter two numbers separated by a space:\n";
				double o; double t;
				cin >> o;
				cin >> t;
				cin.ignore();
				double r = multiplication(o, t);
				cout << "\n" << o << " * " << t << " = " << r << endl
					<< "Would you like to repeat this operation with different numbers?(y/n)\n";
				getline(cin, s);
				an = s[0];
			} while (an == 'Y' || an == 'y');
			switch (an)
			{
			case 'n':
			case 'N': menuLearn();  break;

			default: cout << "Oops! You did not enter y/n.\n";
				menuLearn();  break;
			} break;
		case 'G':
		case 'g':
			do
			{
				double o = genRand();
				double t = genRand();
				double r = multiplication(o, t);
				cout << "\n" << o << " * " << t << " = " << r << endl
					<< "Would you like to repeat this operation with different numbers?(y/n)\n";
				getline(cin, s);
				an = s[0];
			} while (an == 'Y' || an == 'y');
			switch (an)
			{
			case 'n':
			case 'N': menuLearn();  break;

			default: cout << "Oops! You did not enter y/n.\n\n";
				menuLearn();  break;
			} break;
		case 'S':
		case 's': menuLearn();  break;
		default:
			cout << "You did not select an option from the menu.\n\n";
			menuLearn();
		} break;

	case 'P':
	case 'p': cout << "Do you want your number(s) to be:"
		<< "\nEntered manually"
		<< "\nGenerated randomly by the computer"
		<< "\nSelect a different operation\n";
		getline(cin, str1);
		ans2 = str1[0];
		switch (ans2)
		{
		case 'E':
		case 'e':
			do
			{
				cout << "\nEnter two numbers separated by a space(base exponent):\n";
				double b; double e;
				cin >> b;
				cin >> e;
				cin.ignore();
				double r = power(b, e);
				cout << "\n" << b << "^" << e << " = " << r << endl
					<< "Would you like to repeat this operation with different numbers?(y/n)\n";
				getline(cin, s);
				an = s[0];
			} while (an == 'Y' || an == 'y');
			switch (an)
			{
			case 'n':
			case 'N': menuLearn();  break;

			default: cout << "Oops! You did not enter y/n.\n";
				menuLearn();  break;
			} break;
		case 'G':
		case 'g':
			do
			{
				double b = genRand();
				double e = genRand();
				double r = power(b, e);
				cout << "\n" << b << "^" << e << " = " << r << endl
					<< "Would you like to repeat this operation with different numbers?(y/n)\n";
				getline(cin, s);
				an = s[0];
			} while (an == 'Y' || an == 'y');
			switch (an)
			{
			case 'n':
			case 'N': menuLearn();  break;

			default: cout << "Oops! You did not enter y/n.\n\n";
				menuLearn();  break;
			}break;
		case 'S':
		case 's': menuLearn();  break;
		default:
			cout << "You did not select an option from the menu.\n\n";
			menuLearn();  break;
		} break;

	case 'C':
	case 'c': cout << "Do you want your number(s) to be:"
		<< "\nEntered manually"
		<< "\nGenerated randomly by the computer"
		<< "\nSelect a different operation\n";
		getline(cin, str1);
		ans2 = str1[0];
		switch (ans2)
		{
		case 'E':
		case 'e':
			do
			{
				cout << "\nEnter the angle in radians:\n";
				double angle;
				cin >> angle;
				cin.ignore();
				double r = cosine(angle);
				cout << "\ncos(" << angle << ") " << "= " << r << endl
					<< "Would you like to repeat this operation with a different number?(y/n)\n";
				getline(cin, s);
				an = s[0];
			} while (an == 'Y' || an == 'y');
			switch (an)
			{
			case 'n':
			case 'N': menuLearn();  break;

			default: cout << "Oops! You did not enter y/n.\n";
				menuLearn();  break;
			} break;
		case 'G':
		case 'g':
			do
			{
				double angle = genRand();
				double r = cosine(angle);
				cout << "\ncos(" << angle << ") " << "= " << r << endl
					<< "Would you like to repeat this operation with different numbers?(y/n)\n";
				getline(cin, s);
				an = s[0];
			} while (an == 'Y' || an == 'y');
			switch (an)
			{
			case 'n':
			case 'N': menuLearn();  break;

			default: cout << "Oops! You did not enter y/n.\n\n";
				menuLearn();  break;
			} break;
		case 'S':
		case 's': menuLearn();  break;
		default:
			cout << "You did not select an option from the menu.\n\n";
			menuLearn();  break;
		} break;
	case 'R':
	case 'r': main(); break;

	default: cout << "Oops! Wrong choice, try again:\n";
		menuLearn();  break;
	}
}

void menuGame()
{
	char ans, ans1;
	int score;
	string str;
	cout << "You are now in the game mode\n\n"
		<< "Please select the level:"
		<< "\na. Introductory"
		<< "\nb. Intermediate"
		<< "\nc. Advanced"
		<< "\nd. Return to the main menu\n";
	cin >> ans;
	cin.ignore();
	switch (ans)
	{
	case 'a':
	case 'A': introductory(); break;

	case 'b':
	case 'B': intermediate(); break;

	case 'c':
	case 'C': advanced(); break;

	case 'd':
	case 'D': main(); break;

	default: cout << "Oops! Your selection was not an option in the menu.\n";
		menuGame(); break;
	}
}

double addition(double o, double t)
{
	double r;
	r = o + t;
	return r;
}

double subtraction(double o, double t)
{
	double r;
	r = o - t;
	return r;
}

double multiplication(double o, double t)
{
	double r;
	r = o * t;
	return r;
}

double dDivision(double o, double t)
{
	double r;
	r = o / t;
	return r;
}

int intDiv(double o, double t)
{
	int r;
	r = o / t;
	return r;
}

int module(double o, double t)
{
	int r;
	r = (int)o % (int)t;
	return r;
}

double power(double base, double exponent)
{
	double r;
	r = pow(base, exponent);
	return r;
}
/*
void getVal(double* v)
{

}
*/
double genRand()
{
	double r;
	r = rand() % 100 + 1;
	return r;
}

double sine(double a)
{
	double r;
	r = sin(a); //a is in radians
	return r;
}

double cosine(double a)
{
	double r;
	r = cos(a); //a is in radians
	return r;
}

void introductory()
{
	int score; char ans, ans1; string str;
	cout << "You are in the introductory level.\nPlease select an operation:"
		<< "\nAdd"
		<< "\nSubtract"
		<< "\nMultiply"
		<< "\nDivide"
		<< "\nReturn to previous menu\n";
	getline(cin, str);
	ans1 = str[0];
	switch (ans1)
	{
	case 'a':
	case 'A':
		score = 0;
		for (int i = 0; i < 10; i++)
		{
			int o = rand() % 10;
			int t = rand() % 10;
			int a;
			cout << "\nAdd:\n" << o << " + " << t << " = ";
			cin >> a;
			cin.ignore();
			int r = addition(o, t);
			if (a == r)
			{
				score++;
				cout << "\nGood job!          Your score is " << score << "/10\n";
			}
			else
			{
				cout << "\nOops! Your answer is incorrect.\nThe correct answer is " << r << " because:\n" << r << " - " << o << " = " << t << " and " << r << " - " << t << " = " << o
					<< "\nYour score is " << score << "/10\n";
			}
		}
		if (score > 8)
		{
			cout << "\nYour final score is " << score << "/10!\nWould you like to:\na. Advance to a higher level\nb. Play this level again\nc. Exit this mode\n";
			cin >> ans;
			cin.ignore();
			switch (ans)
			{
			case 'a':
			case 'A': intermediate(); break;

			case 'b':
			case 'B': introductory(); break;

			case 'c':
			case 'C': main(); break;

			default: cout << "Oops! Your answer did not match any of the choices. You are returned back to introductory level.\n";
				introductory(); break;
			}
		}
		else
		{
			cout << "\nYour final score is " << score << "/10\nWould you like to:\na. Play this level again\nb. Exit this mode\n";
			cin >> ans;
			cin.ignore();
			switch (ans)
			{
			case 'a':
			case 'A': introductory(); break;

			case 'b':
			case 'B': main(); break;

			default: cout << "Oops! Your answer did not match any of the choices. You are returned back to introductory level.\n";
				introductory(); break;
			}
		}
		break;

	case 's':
	case 'S':
		score = 0;
		for (int i = 0; i < 10; i++)
		{
			int o = rand() % 10;
			int t = rand() % 10;
			int a;
			cout << "\nSubtract:\n" << o << " - " << t << " = ";
			cin >> a;
			cin.ignore();
			int r = subtraction(o, t);
			if (a == r)
			{
				score++;
				cout << "\nGood job!          Your score is " << score << "/10\n";
			}
			else
			{
				cout << "\nOops! Your answer is incorrect.\nThe correct answer is " << r << " because:\n" << r << " + " << o << " = " << t << " and " << r << " + " << t << " = " << o
					<< "\nYour score is " << score << "/10\n";
			}
		}
		if (score > 8)
		{
			cout << "\nYour final score is " << score << "/10!\nWould you like to:\na. Advance to a higher level\nb. Play this level again\nc. Exit this mode\n";
			cin >> ans;
			cin.ignore();
			switch (ans)
			{
			case 'a':
			case 'A': intermediate(); break;

			case 'b':
			case 'B': introductory(); break;

			case 'c':
			case 'C': main(); break;

			default: cout << "Oops! Your answer did not match any of the choices. You are returned back to introductory level.\n";
				introductory(); break;
			}
		}
		else
		{
			cout << "\nYour final score is " << score << "/10\nWould you like to:\na. Play this level again\nb. Exit this mode\n";
			cin >> ans;
			cin.ignore();
			switch (ans)
			{
			case 'a':
			case 'A': introductory(); break;

			case 'b':
			case 'B': main(); break;

			default: cout << "Oops! Your answer did not match any of the choices. You are returned back to introductory level.\n";
				introductory(); break;
			}
		}
		break;

	case 'm':
	case 'M': score = 0;
		for (int i = 0; i < 10; i++)
		{
			int o = rand() % 10;
			int t = rand() % 10;
			int a;
			cout << "\nMultiply:\n" << o << " * " << t << " = ";
			cin >> a;
			cin.ignore();
			int r = multiplication(o, t);
			if (a == r)
			{
				score++;
				cout << "\nGood job!          Your score is " << score << "/10\n";
			}
			else
			{
				cout << "\nOops! Your answer is incorrect.\nThe correct answer is " << r << " because:\n" << r << " / " << o << " = " << t << " and " << r << " / " << t << " = " << o
					<< "\nYour score is " << score << "/10\n";
			}
		}
		if (score > 8)
		{
			cout << "\nYour final score is " << score << "/10!\nWould you like to:\na. Advance to a higher level\nb. Play this level again\nc. Exit this mode\n";
			cin >> ans;
			cin.ignore();
			switch (ans)
			{
			case 'a':
			case 'A': intermediate(); break;

			case 'b':
			case 'B': introductory(); break;

			case 'c':
			case 'C': main(); break;

			default: cout << "Oops! Your answer did not match any of the choices. You are returned back to introductory level.\n";
				introductory(); break;
			}
		}
		else
		{
			cout << "\nYour final score is " << score << "/10\nWould you like to:\na. Play this level again\nb. Exit this mode\n";
			cin >> ans;
			cin.ignore();
			switch (ans)
			{
			case 'a':
			case 'A': introductory(); break;

			case 'b':
			case 'B': main(); break;

			default: cout << "Oops! Your answer did not match any of the choices. You are returned back to introductory level.\n";
				introductory(); break;
			}
		}
		break;

	case 'd':
	case 'D': score = 0;
		for (int i = 0; i < 10; i++)
		{
			int o = rand() % 10;
			int t = rand() % 10;
			int a;
			cout << "\nDivide:\n" << o << " / " << t << " = ";
			cin >> a;
			cin.ignore();
			int r = intDiv(o, t);
			if (a == r)
			{
				score++;
				cout << "\nGood job!          Your score is " << score << "/10\n";
			}
			else
			{
				cout << "\nOops! Your answer is incorrect.\nThe correct answer is " << r << " because:\n" << r << " * " << o << " = " << t << " and " << r << " * " << t << " = " << o
					<< "\nYour score is " << score << "/10\n";
			}
		}
		if (score > 8)
		{
			cout << "\nYour final score is " << score << "/10!\nWould you like to:\na. Advance to a higher level\nb. Play this level again\nc. Exit this mode\n";
			cin >> ans;
			cin.ignore();
			switch (ans)
			{
			case 'a':
			case 'A': intermediate(); break;

			case 'b':
			case 'B': introductory(); break;

			case 'c':
			case 'C': main(); break;

			default: cout << "Oops! Your answer did not match any of the choices. You are returned back to introductory level.\n";
				introductory(); break;
			}
		}
		else
		{
			cout << "\nYour final score is " << score << "/10\nWould you like to:\na. Play this level again\nb. Exit this mode\n";
			cin >> ans;
			cin.ignore();
			switch (ans)
			{
			case 'a':
			case 'A': introductory(); break;

			case 'b':
			case 'B': main(); break;

			default: cout << "Oops! Your answer did not match any of the choices. You are returned back to introductory level.\n";
				introductory(); break;
			}
		}
		break;

	case 'r':
	case 'R': menuGame(); break;

	default: cout << "The operation you selected was not on the list, try again.\n\n";
		menuGame(); break;
	}
}

void intermediate()
{
	char operation[] = { '+', '-', '*', '/' };
	int score; char ans, ans1, ans2; string str;
	cout << "You are in the intermediate level.\nWould you like to: "
		<< "\na. Choose the operation"
		<< "\nb. Have the computer choose the operation randomly\n";
	getline(cin, str);
	ans = str[0];

	switch (ans)
	{
	case 'a':
	case 'A':
		cout << "\nAdd"
			<< "\nSubtract"
			<< "\nMultiply"
			<< "\nDivide"
			<< "\nReturn to game mode\n";
		getline(cin, str);
		ans1 = str[0];
		switch (ans1)
		{
		case 'a':
		case 'A':
			score = 0;
			for (int i = 0; i < 10; i++)
			{
				int o = rand() % 89 + 10;
				int t = rand() % 89 + 10;
				int a;
				cout << "\nAdd:\n" << o << " + " << t << " = ";
				cin >> a;
				cin.ignore();
				int r = addition(o, t);
				if (a == r)
				{
					score++;
					cout << "\nGood job!          Your score is " << score << "/10\n";
				}
				else
				{
					cout << "\nOops! Your answer is incorrect.\nThe correct answer is " << r << " because:\n" << r << " - " << o << " = " << t << " and " << r << " - " << t << " = " << o
						<< "\nYour score is " << score << "/10\n";
				}
			}
			if (score > 8)
			{
				cout << "\nYour final score is " << score << "/10!\nWould you like to:\na. Advance to a higher level\nb. Play this level again\nc. Exit this mode\n";
				cin >> ans2;
				cin.ignore();
				switch (ans2)
				{
				case 'a':
				case 'A': advanced(); break;

				case 'b':
				case 'B': intermediate(); break;

				case 'c':
				case 'C': main(); break;

				default: cout << "Oops! Your answer did not match any of the choices. You are returned back to intermediate level.\n";
					intermediate(); break;
				}
			}
			else
			{
				cout << "\nYour final score is " << score << "/10\nWould you like to:\na. Play this level again\nb. Exit this mode\n";
				cin >> ans2;
				cin.ignore();
				switch (ans2)
				{
				case 'a':
				case 'A': intermediate(); break;

				case 'b':
				case 'B': main(); break;

				default: cout << "Oops! Your answer did not match any of the choices. You are returned back to intermediate level.\n";
					intermediate(); break;
				}
			}
			break;

		case 's':
		case 'S':
			score = 0;
			for (int i = 0; i < 10; i++)
			{
				int o = rand() % 89 + 10;
				int t = rand() % 89 + 10;
				int a;
				cout << "\nSubtract:\n" << o << " - " << t << " = ";
				cin >> a;
				cin.ignore();
				int r = subtraction(o, t);
				if (a == r)
				{
					score++;
					cout << "\nGood job!          Your score is " << score << "/10\n";
				}
				else
				{
					cout << "\nOops! Your answer is incorrect.\nThe correct answer is " << r << " because:\n" << r << " + " << o << " = " << t << " and " << r << " + " << t << " = " << o
						<< "\nYour score is " << score << "/10\n";
				}
			}
			if (score > 8)
			{
				cout << "\nYour final score is " << score << "/10!\nWould you like to:\na. Advance to a higher level\nb. Play this level again\nc. Exit this mode\n";
				cin >> ans2;
				cin.ignore();
				switch (ans2)
				{
				case 'a':
				case 'A': advanced(); break;

				case 'b':
				case 'B': intermediate(); break;

				case 'c':
				case 'C': main(); break;

				default: cout << "Oops! Your answer did not match any of the choices. You are returned back to intermediate level.\n";
					intermediate(); break;
				}
			}
			else
			{
				cout << "\nYour final score is " << score << "/10\nWould you like to:\na. Play this level again\nb. Exit this mode\n";
				cin >> ans2;
				cin.ignore();
				switch (ans2)
				{
				case 'a':
				case 'A': intermediate(); break;

				case 'b':
				case 'B': main(); break;

				default: cout << "Oops! Your answer did not match any of the choices. You are returned back to intermediate level.\n";
					intermediate(); break;
				}
			}
			break;

		case 'm':
		case 'M': score = 0;
			for (int i = 0; i < 10; i++)
			{
				int o = rand() % 89 + 10;
				int t = rand() % 89 + 10;
				int a;
				cout << "\nMultiply:\n" << o << " * " << t << " = ";
				cin >> a;
				cin.ignore();
				int r = multiplication(o, t);
				if (a == r)
				{
					score++;
					cout << "\nGood job!          Your score is " << score << "/10\n";
				}
				else
				{
					cout << "\nOops! Your answer is incorrect.\nThe correct answer is " << r << " because:\n" << r << " / " << o << " = " << t << " and " << r << " / " << t << " = " << o
						<< "\nYour score is " << score << "/10\n";
				}
			}
			if (score > 8)
			{
				cout << "\nYour final score is " << score << "/10!\nWould you like to:\na. Advance to a higher level\nb. Play this level again\nc. Exit this mode\n";
				cin >> ans2;
				cin.ignore();
				switch (ans2)
				{
				case 'a':
				case 'A': advanced(); break;

				case 'b':
				case 'B': intermediate(); break;

				case 'c':
				case 'C': main(); break;

				default: cout << "Oops! Your answer did not match any of the choices. You are returned back to intermediate level.\n";
					intermediate(); break;
				}
			}
			else
			{
				cout << "\nYour final score is " << score << "/10\nWould you like to:\na. Play this level again\nb. Exit this mode\n";
				cin >> ans2;
				cin.ignore();
				switch (ans2)
				{
				case 'a':
				case 'A': intermediate(); break;

				case 'b':
				case 'B': main(); break;

				default: cout << "Oops! Your answer did not match any of the choices. You are returned back to intermediate level.\n";
					intermediate(); break;
				}
			}
			break;

		case 'd':
		case 'D': score = 0;
			for (int i = 0; i < 10; i++)
			{
				int o = rand() % 89 + 10;
				int t = rand() % 89 + 10;
				int a;
				cout << "\nDivide:\n" << o << " / " << t << " = ";
				cin >> a;
				cin.ignore();
				int r = intDiv(o, t);
				if (a == r)
				{
					score++;
					cout << "\nGood job!          Your score is " << score << "/10\n";
				}
				else
				{
					cout << "\nOops! Your answer is incorrect.\nThe correct answer is " << r << " because:\n" << r << " * " << o << " = " << t << " and " << r << " * " << t << " = " << o
						<< "\nYour score is " << score << "/10\n";
				}
			}
			if (score > 8)
			{
				cout << "\nYour final score is " << score << "/10!\nWould you like to:\na. Advance to a higher level\nb. Play this level again\nc. Exit this mode\n";
				cin >> ans2;
				cin.ignore();
				switch (ans2)
				{
				case 'a':
				case 'A': advanced(); break;

				case 'b':
				case 'B': intermediate(); break;

				case 'c':
				case 'C': main(); break;

				default: cout << "Oops! Your answer did not match any of the choices. You are returned back to intermediate level.\n";
					intermediate(); break;
				}
			}
			else
			{
				cout << "\nYour final score is " << score << "/10\nWould you like to:\na. Play this level again\nb. Exit this mode\n";
				cin >> ans2;
				cin.ignore();
				switch (ans2)
				{
				case 'a':
				case 'A': intermediate(); break;

				case 'b':
				case 'B': main(); break;

				default: cout << "Oops! Your answer did not match any of the choices. You are returned back to intermediate level.\n";
					intermediate(); break;
				}
			}
			break;

		case 'r':
		case 'R': menuGame(); break;

		default: cout << "The operation you selected was not on the list, try again.\n\n";
			menuGame(); break;
		} break;

	case 'b':
	case 'B':
		int ran;
		ran = rand() % 4;
		score = 0;
		if (ran == 0)
		{
			for (int i = 0; i < 10; i++)
			{
				int o = rand() % 89 + 10;
				int t = rand() % 89 + 10;
				int a;
				cout << "\nAdd:\n" << o << " + " << t << " = ";
				cin >> a;
				cin.ignore();
				int r = addition(o, t);
				if (a == r)
				{
					score++;
					cout << "\nGood job!          Your score is " << score << "/10\n";
				}
				else
				{
					cout << "\nOops! Your answer is incorrect.\nThe correct answer is " << r << " because:\n" << r << " - " << o << " = " << t << " and " << r << " - " << t << " = " << o
						<< "\nYour score is " << score << "/10\n";
				}
			}
			if (score > 8)
			{
				cout << "\nYour final score is " << score << "/10!\nWould you like to:\na. Advance to a higher level\nb. Play this level again\nc. Exit this mode\n";
				cin >> ans2;
				cin.ignore();
				switch (ans2)
				{
				case 'a':
				case 'A': advanced(); break;

				case 'b':
				case 'B': intermediate(); break;

				case 'c':
				case 'C': main(); break;

				default: cout << "Oops! Your answer did not match any of the choices. You are returned back to intermediate level.\n";
					intermediate(); break;
				}
			}
			else
			{
				cout << "\nYour final score is " << score << "/10\nWould you like to:\na. Play this level again\nb. Exit this mode\n";
				cin >> ans2;
				cin.ignore();
				switch (ans2)
				{
				case 'a':
				case 'A': intermediate(); break;

				case 'b':
				case 'B': main(); break;

				default: cout << "Oops! Your answer did not match any of the choices. You are returned back to intermediate level.\n";
					intermediate(); break;
				}
			}
			break;
		}
		if (ran == 1)
		{
			for (int i = 0; i < 10; i++)
			{
				int o = rand() % 89 + 10;
				int t = rand() % 89 + 10;
				int a;
				cout << "\nSubtract:\n" << o << " - " << t << " = ";
				cin >> a;
				cin.ignore();
				int r = subtraction(o, t);
				if (a == r)
				{
					score++;
					cout << "\nGood job!          Your score is " << score << "/10\n";
				}
				else
				{
					cout << "\nOops! Your answer is incorrect.\nThe correct answer is " << r << " because:\n" << r << " + " << o << " = " << t << " and " << r << " + " << t << " = " << o
						<< "\nYour score is " << score << "/10\n";
				}
			}
			if (score > 8)
			{
				cout << "\nYour final score is " << score << "/10!\nWould you like to:\na. Advance to a higher level\nb. Play this level again\nc. Exit this mode\n";
				cin >> ans2;
				cin.ignore();
				switch (ans2)
				{
				case 'a':
				case 'A': advanced(); break;

				case 'b':
				case 'B': intermediate(); break;

				case 'c':
				case 'C': main(); break;

				default: cout << "Oops! Your answer did not match any of the choices. You are returned back to intermediate level.\n";
					intermediate(); break;
				}
			}
			else
			{
				cout << "\nYour final score is " << score << "/10\nWould you like to:\na. Play this level again\nb. Exit this mode\n";
				cin >> ans2;
				cin.ignore();
				switch (ans2)
				{
				case 'a':
				case 'A': intermediate(); break;

				case 'b':
				case 'B': main(); break;

				default: cout << "Oops! Your answer did not match any of the choices. You are returned back to intermediate level.\n";
					intermediate(); break;
				}
			}
			break;
		}
		if (ran == 2)
		{
			for (int i = 0; i < 10; i++)
			{
				int o = rand() % 89 + 10;
				int t = rand() % 89 + 10;
				int a;
				cout << "\nMultiply:\n" << o << " * " << t << " = ";
				cin >> a;
				cin.ignore();
				int r = multiplication(o, t);
				if (a == r)
				{
					score++;
					cout << "\nGood job!          Your score is " << score << "/10\n";
				}
				else
				{
					cout << "\nOops! Your answer is incorrect.\nThe correct answer is " << r << " because:\n" << r << " / " << o << " = " << t << " and " << r << " / " << t << " = " << o
						<< "\nYour score is " << score << "/10\n";
				}
			}
			if (score > 8)
			{
				cout << "\nYour final score is " << score << "/10!\nWould you like to:\na. Advance to a higher level\nb. Play this level again\nc. Exit this mode\n";
				cin >> ans2;
				cin.ignore();
				switch (ans2)
				{
				case 'a':
				case 'A': advanced(); break;

				case 'b':
				case 'B': intermediate(); break;

				case 'c':
				case 'C': main(); break;

				default: cout << "Oops! Your answer did not match any of the choices. You are returned back to intermediate level.\n";
					intermediate(); break;
				}
			}
			else
			{
				cout << "\nYour final score is " << score << "/10\nWould you like to:\na. Play this level again\nb. Exit this mode\n";
				cin >> ans2;
				cin.ignore();
				switch (ans2)
				{
				case 'a':
				case 'A': intermediate(); break;

				case 'b':
				case 'B': main(); break;

				default: cout << "Oops! Your answer did not match any of the choices. You are returned back to intermediate level.\n";
					intermediate(); break;
				}
			}
			break;
		}

		if (ran == 3)
		{
			for (int i = 0; i < 10; i++)
			{
				int o = rand() % 89 + 10;
				int t = rand() % 89 + 10;
				int a;
				cout << "\nDivide:\n" << o << " / " << t << " = ";
				cin >> a;
				cin.ignore();
				int r = intDiv(o, t);
				if (a == r)
				{
					score++;
					cout << "\nGood job!          Your score is " << score << "/10\n";
				}
				else
				{
					cout << "\nOops! Your answer is incorrect.\nThe correct answer is " << r << " because:\n" << r << " * " << o << " = " << t << " and " << r << " * " << t << " = " << o
						<< "\nYour score is " << score << "/10\n";
				}
			}
			if (score > 8)
			{
				cout << "\nYour final score is " << score << "/10!\nWould you like to:\na. Advance to a higher level\nb. Play this level again\nc. Exit this mode\n";
				cin >> ans2;
				cin.ignore();
				switch (ans2)
				{
				case 'a':
				case 'A': advanced(); break;

				case 'b':
				case 'B': intermediate(); break;

				case 'c':
				case 'C': main(); break;

				default: cout << "Oops! Your answer did not match any of the choices. You are returned back to intermediate level.\n";
					intermediate(); break;
				}
			}
			else
			{
				cout << "\nYour final score is " << score << "/10\nWould you like to:\na. Play this level again\nb. Exit this mode\n";
				cin >> ans2;
				cin.ignore();
				switch (ans2)
				{
				case 'a':
				case 'A': intermediate(); break;

				case 'b':
				case 'B': main(); break;

				default: cout << "Oops! Your answer did not match any of the choices. You are returned back to intermediate level.\n";
					intermediate(); break;
				}
			}
			break;
		} break;
	case 'r':
	case 'R': menuGame(); break;

	default: cout << "The operation you selected was not on the list, try again.\n\n";
		menuGame(); break;
	}
}

void advanced()
{
	string str; char ans, ans2; int score;
	cout << "You are in the advanced level.\nWould you like to:"
		<< "\nBegin"
		<< "\nExit to the main menu\n";
	getline(cin, str);
	ans = str[0];
	switch (ans)
	{
	case 'b':
	case 'B':
		int ran;
		ran = rand() % 4;
		score = 0;
		if (ran == 0)
		{
			for (int i = 0; i < 10; i++)
			{
				int o = rand() % 100;
				int t = rand() % 100;
				int a;
				cout << "\nAdd:\n" << o << " + " << t << " = ";
				cin >> a;
				cin.ignore();
				int r = addition(o, t);
				if (a == r)
				{
					score++;
					cout << "\nGood job!          Your score is " << score << "/10\n";
				}
				else
				{
					cout << "\nOops! Your answer is incorrect.\nThe correct answer is " << r << " because:\n" << r << " - " << o << " = " << t << " and " << r << " - " << t << " = " << o
						<< "\nYour score is " << score << "/10\n";
				}
			}
			if (score > 8)
			{
				cout << "\nYour final score is " << score << "/10!\nWould you like to:\na. Play this level again\nb. Exit this mode\n";
				cin >> ans2;
				cin.ignore();
				switch (ans2)
				{
				case 'a':
				case 'A': advanced(); break;

				case 'b':
				case 'B': main(); break;

				default: cout << "Oops! Your answer did not match any of the choices. You are returned back to advanced level.\n";
					advanced(); break;
				}
			}
			else
			{
				cout << "\nYour final score is " << score << "/10\nWould you like to:\na. Play this level again\nb. Exit this mode\n";
				cin >> ans2;
				cin.ignore();
				switch (ans2)
				{
				case 'a':
				case 'A': advanced(); break;

				case 'b':
				case 'B': main(); break;

				default: cout << "Oops! Your answer did not match any of the choices. You are returned back to advanced level.\n";
					advanced(); break;
				}
			}
		}
		if (ran == 1)
		{
			for (int i = 0; i < 10; i++)
			{
				int o = rand() % 100;
				int t = rand() % 100;
				int a;
				cout << "\nSubtract:\n" << o << " - " << t << " = ";
				cin >> a;
				cin.ignore();
				int r = subtraction(o, t);
				if (a == r)
				{
					score++;
					cout << "\nGood job!          Your score is " << score << "/10\n";
				}
				else
				{
					cout << "\nOops! Your answer is incorrect.\nThe correct answer is " << r << " because:\n" << r << " + " << o << " = " << t << " and " << r << " + " << t << " = " << o
						<< "\nYour score is " << score << "/10\n";
				}
			}
			if (score > 8)
			{
				cout << "\nYour final score is " << score << "/10!\nWould you like to:\na. Play this level again\nb. Exit this mode\n";
				cin >> ans2;
				cin.ignore();
				switch (ans2)
				{
				case 'a':
				case 'A': advanced(); break;

				case 'b':
				case 'B': main(); break;

				default: cout << "Oops! Your answer did not match any of the choices. You are returned back to advanced level.\n";
					advanced(); break;
				}
			}
			else
			{
				cout << "\nYour final score is " << score << "/10\nWould you like to:\na. Play this level again\nb. Exit this mode\n";
				cin >> ans2;
				cin.ignore();
				switch (ans2)
				{
				case 'a':
				case 'A': advanced(); break;

				case 'b':
				case 'B': main(); break;

				default: cout << "Oops! Your answer did not match any of the choices. You are returned back to advanced level.\n";
					advanced(); break;
				}
			}
		}
		if (ran == 2)
		{
			for (int i = 0; i < 10; i++)
			{
				int o = rand() % 100;
				int t = rand() % 100;
				int a;
				cout << "\nMultiply:\n" << o << " * " << t << " = ";
				cin >> a;
				cin.ignore();
				int r = multiplication(o, t);
				if (a == r)
				{
					score++;
					cout << "\nGood job!          Your score is " << score << "/10\n";
				}
				else
				{
					cout << "\nOops! Your answer is incorrect.\nThe correct answer is " << r << " because:\n" << r << " / " << o << " = " << t << " and " << r << " / " << t << " = " << o
						<< "\nYour score is " << score << "/10\n";
				}
			}
			if (score > 8)
			{
				cout << "\nYour final score is " << score << "/10!\nWould you like to:\na. Advance to a higher level\nb. Play this level again\nc. Exit this mode\n";
				cin >> ans2;
				cin.ignore();
				switch (ans2)
				{
				case 'a':
				case 'A': advanced(); break;

				case 'b':
				case 'B': advanced(); break;

				case 'c':
				case 'C': main(); break;

				default: cout << "Oops! Your answer did not match any of the choices. You are returned back to advanced level.\n";
					advanced(); break;
				}
			}
			else
			{
				cout << "\nYour final score is " << score << "/10\nWould you like to:\na. Play this level again\nb. Exit this mode\n";
				cin >> ans2;
				cin.ignore();
				switch (ans2)
				{
				case 'a':
				case 'A': advanced(); break;

				case 'b':
				case 'B': main(); break;

				default: cout << "Oops! Your answer did not match any of the choices. You are returned back to advanced level.\n";
					advanced(); break;
				}
			}
		}

		if (ran == 3)
		{
			for (int i = 0; i < 10; i++)
			{
				int o = rand() % 100;
				int t = rand() % 100;
				int a;
				cout << "\nDivide:\n" << o << " / " << t << " = ";
				cin >> a;
				cin.ignore();
				int r = intDiv(o, t);
				if (a == r)
				{
					score++;
					cout << "\nGood job!          Your score is " << score << "/10\n";
				}
				else
				{
					cout << "\nOops! Your answer is incorrect.\nThe correct answer is " << r << " because:\n" << r << " * " << o << " = " << t << " and " << r << " * " << t << " = " << o
						<< "\nYour score is " << score << "/10\n";
				}
			}
			if (score > 8)
			{
				cout << "\nYour final score is " << score << "/10!\nWould you like to:\na. Play this level again\nb. Exit this mode\n";
				cin >> ans2;
				cin.ignore();
				switch (ans2)
				{
				case 'a':
				case 'A': advanced(); break;

				case 'b':
				case 'B': main(); break;

				default: cout << "Oops! Your answer did not match any of the choices. You are returned back to advanced level.\n";
					advanced(); break;
				}
			}
			else
			{
				cout << "\nYour final score is " << score << "/10\nWould you like to:\na. Play this level again\nb. Exit this mode\n";
				cin >> ans2;
				cin.ignore();
				switch (ans2)
				{
				case 'a':
				case 'A': advanced(); break;

				case 'b':
				case 'B': main(); break;

				default: cout << "Oops! Your answer did not match any of the choices. You are returned back to advanced level.\n";
					advanced(); break;
				}
			}
		}break;
	case 'e':
	case 'E': menuGame(); break;

	default: cout << "Your choice was not on the list.\n";
		menuGame(); break;
	}
}
