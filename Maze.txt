/*
Aleks Dziewulska
Project 3

Purpose: Practice integer reference
Input: User input of the number of spaces to move left, right, up, down 
Process: Adding the spaces to coordinates
Output: Coordinates of points in the maze
*/

#include <iostream> //input/output
#include <iomanip> //manipulate output
#include <string> //use strings
using namespace std;
void MoveRight(int &posX,int &posY,int spaces);
void MoveLeft(int &posX, int &posY, int spaces);
void MoveDown(int &posX, int &posY, int spaces);
void MoveUp(int &posX, int &posY, int spaces);
void menu();
void maze();
int S;

int main()
{
	cout << "Welcome to the maze!\nGet from point S to point E without crossing the walls( | and = )" << endl << endl;
	maze(); //calls the maze function to print the maze
	menu(); //calls the menu function to interact with the user
	return 0;
}

void maze() //print the graphical representation of the maze
{
	cout << setw(4) << "0" << setw(3) << "1" << setw(3) << "2" << setw(3) << "3" << setw(3) << "4" << setw(3) << "5"
		<< setw(3) << "6" << setw(3) << "7" << setw(3) << "8" << setw(3) << "9" << setw(4) << "10" << setw(4) << "11"
		<< setw(4) << "12" << setw(4) << "13" << setw(4) << "14" << setw(4) << "15" << endl;
	cout << "   ----------------------------------------------------" << endl;
	cout << "0 |S              |           |                        |" << endl << endl 
		 << "1 |==========     |     |     |      |============|    |" << endl << endl 
		 << "2 |               |     |     |      |       |====|    |" << endl << endl 
		 << "3 |   ============|     |            |       |====|    |"  << endl << endl 
		 << "4 |                     |     |======|       |====|    |" << endl << endl 
		 << "5 |=====================|     |                        |" << endl << endl 
		 << "6 |                           |===================|    |" << endl << endl 
		 << "7 |   ==================|            |                 |" << endl << endl 
		 << "8 |                     |=====|      |=================|" << endl << endl 
		 << "9 |=====================|                              |" << endl << endl
		 << "10|                     |=========================|    |" << endl << endl 
		 << "11|E  |===========|                                    |"<< endl;
	cout << "   ----------------------------------------------------" << endl << endl;
}

void menu() //interactive menu
{
	static int X = 0;
	static int Y = 0;
	char answer;

	cout << "Please choose which way would you like to move:\n(R)ight\n(L)eft\n(U)p\n(D)own\n(Q)uit" << endl;
	cin >> answer;

	switch (answer)
		{
		case 'R':
		case 'r':
		{
			cout << "\nYou are currently at the position: (" << X << "," << Y << ")" << endl;
			cout << "Please enter the number of spaces you would like to move: ";
			cin >> S;
			MoveRight(X, Y, S);
			menu();
			break;
		}

		case 'L':
		case 'l':
		{
			cout << "\nYou are currently at the position: (" << X << "," << Y << ")" << endl;
			cout << "Please enter the number of spaces you would like to move: ";
			cin >> S;
			MoveLeft(X, Y, S);
			menu();
			break;
		}

		case 'U':
		case 'u':
		{
			cout << "\nYou are currently at the position: (" << X << "," << Y << ")" << endl;
			cout << "Please enter the number of spaces you would like to move: ";
			cin >> S;
			MoveUp(X, Y, S);
			menu();
			break;
		}

		case 'D':
		case 'd':
		{
			cout << "\nYou are currently at the position: (" << X << "," << Y << ")" << endl;
			cout << "Please enter the number of spaces you would like to move: ";
			cin >> S;
			MoveDown(X, Y, S);
			if (X == 0 && Y == 11)
				system("pause");
			else
				menu();
			break;
		}

		case 'Q':
		case 'q':

		{
			cout << "You chose to leave the maze.\n";
			system("pause");
			break;
		}

		default: //validating user input
		{
			cout << "Bad choice! Try again:\n";
			menu();
		}

		}

}

void MoveRight(int &posX, int &posY, int spaces) //move right on the x-axis
{
	posX += spaces;
	if (posX > 15)
		posX = 15;
	cout << "New position: (" << posX << "," << posY << ")" << endl << endl;
}

void MoveLeft(int &posX, int &posY, int spaces) //move left on the x-axis
{
	posX -= spaces;
	if (posX < 0)
		posX = 0;
	cout << "New position: (" << posX << "," << posY << ")" << endl << endl;
}

void MoveDown(int &posX, int &posY, int spaces) //move down on the y-axis
{
	posY += spaces;
	if (posY > 11)
		posY = 11;
	if (posX == 0 && posY == 11)
	{
		cout << "You completed the maze, congratulations!\n";
	}
	else
		cout << "New position: (" << posX << "," << posY << ")" << endl << endl;
}

void MoveUp(int &posX, int &posY, int spaces) //move up on the y-axis
{
	posY -= spaces;
	if (posY < 0)
		posY = 0;
	cout << "New position: (" << posX << "," << posY << ")" << endl << endl;
}	
