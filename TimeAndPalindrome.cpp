/*
Purpose: Using and practicing the switch statement.
Input: User's choice of what operation to perform.
Process: Create a menu for the user to select from, create methods to use in the menu.
Output: Time in words or palindrome check.
*/

#include <iostream> //input/output
#include <string> //use strings
using namespace std;
int p, c, hours, minutes; //declaring variables
int f = 0; //declaring and initializing variable
string a, m; //declaring a string
void palindrome(int p); 
void time(int hours, int minutes); //declaring methods

void menu() //creates an interactive menu
{
	int answer;

	cout << "Use the menu to continue:\n"
		<< "1- Time\n"
		<< "2- Palindrome\n"
		<< "3- Exit\n\n";
	cin >> answer;
	
	switch (answer)
	{
	case 1: //print time
		cout << "Please enter time in 24 hour format: ";
		cin >> hours >> minutes;
		if (hours > 24 || minutes > 59) //validate time 
		{
			cout << "Incorrect format, try again.\n";
			menu();
		}
		else
		{
			time(hours, minutes);
		}
		break;

	case 2: //check for palindrome
		cout << "Please enter a five digit number: ";
		cin >> p;
		c = p;
		while (c > 0)
		{
			c = c / 10;
			f++;
		}

		if (f != 5) //validate user input
		{
			cout << "It was not a five digit number, try again.\n";
			f = 0;
			menu();
		}
		else
		{
			f = 0;
			palindrome(p);
		}
		f = 0;
		break;

	case 3: //exit
		system("pause");
	    break;

	default: //validating user input
		cout << "Bad choice! Try again:\n";
		menu();
	}
	
}

void palindrome(int p) //check for palindrome and print the statement
{
	int num, digit, rev = 0;

     num = p;

     do
     {
         digit = p % 10;
         rev = (rev * 10) + digit;
         p = p / 10;
     } while (p != 0);

	 if (num == rev)
		 cout << "The number is a palindrome.\n\n";
	 else
		 cout << "The number is not a palindrome.\n\n";
	 
	 menu();

}

void time(int hours, int minutes) //prints time
{
	switch (hours)
	{
	case 1:
	case 13: cout << "One"; break;
	case 2:
	case 14: cout << "Two"; break;
	case 3:
	case 15: cout << "Three"; break;
	case 4:
	case 16: cout << "Four"; break;
	case 5:
	case 17: cout << "Five"; break;
	case 6:
	case 18: cout << "Six"; break;
	case 7:
	case 19: cout << "Seven"; break;
	case 8:
	case 20: cout << "Eight"; break;
	case 9:
	case 21: cout << "Nine"; break;
	case 10:
	case 22: cout << "Ten"; break;
	case 11:
	case 23: cout << "Eleven"; break;
	case 12: if (minutes == 00) cout << "Noon\n"; else cout << "Twelve"; ; //includes special case, noon
	}
	switch (minutes)
	{
	case 1: cout << " one"; break;
	case 2: cout << " two"; break;
	case 3: cout << " three"; break;
	case 4: cout << " four"; break;
	case 5: cout << " five"; break;
	case 6: cout << " six"; break;
	case 7: cout << " seven"; break;
	case 8: cout << " eight"; break;
	case 9: cout << " nine"; break;
	case 10: cout << " ten"; break;
	case 11: cout << " eleven"; break;
	case 12: cout << " twelve"; break;
	case 13: cout << " thirteen"; break;
	case 14: cout << " fourteen"; break;
	case 15: cout << " fifthteen"; break;
	case 16: cout << " sixteen"; break;
	case 17: cout << " seventeen"; break;
	case 18: cout << " eighteen"; break;
	case 19: cout << " nineteen"; break;
	case 20: cout << " twenty"; break;
	case 21: cout << " twenty one"; break;
	case 22: cout << " twenty two"; break;
	case 23: cout << " twenty three"; break;
	case 24: cout << " twenty four"; break;
	case 25: cout << " twenty five"; break;
	case 26: cout << " twenty six"; break;
	case 27: cout << " twenty seven"; break;
	case 28: cout << " twenty eight"; break;
	case 29: cout << " twenty nine"; break;
	case 30: cout << " thirty"; break;
	case 31: cout << " thirty one"; break;
	case 32: cout << " thirty two"; break;
	case 33: cout << " thirty three"; break;
	case 34: cout << " thirty four"; break;
	case 35: cout << " thirty five"; break;
	case 36: cout << " thirty six"; break;
	case 37: cout << " thirty seven"; break;
	case 38: cout << " thirty eight"; break;
	case 39: cout << " thirty nine"; break;
	case 40: cout << " forty"; break;
	case 41: cout << " forty one"; break;
	case 42: cout << " forty two"; break;
	case 43: cout << " forty three"; break;
	case 44: cout << " forty four"; break;
	case 45: cout << " forty five"; break;
	case 46: cout << " forty six"; break;
	case 47: cout << " forty seven"; break;
	case 48: cout << " forty eight"; break;
	case 49: cout << " forty nine"; break;
	case 50: cout << " fifty"; break;
	case 51: cout << " fifty one"; break;
	case 52: cout << " fifty two"; break;
	case 53: cout << " fifty three"; break;
	case 54: cout << " fifty four"; break;
	case 55: cout << " fifty five"; break;
	case 56: cout << " fifty six"; break;
	case 57: cout << " fifty seven"; break;
	case 58: cout << " fifty eight"; break;
	case 59: cout << " fifty nine"; break;
	}
	if (hours < 12 && hours > 0 && minutes <= 59) //check if its morning
		cout << " AM\n";
	if (hours > 12 && hours < 24 || (hours == 12 && minutes > 0)) //check if its afternoon
		cout << " PM\n";
	if (minutes == 00 && (hours == 0 || hours == 24)) //special case, midnight
		cout << "Midnight\n";
       if ((hours == 24 || hours == 0) && minutes > 0 && minutes <= 59)
		cout << " past midnight\n\n";
	menu();
}
int main() //main method 
{
	menu(); //uses the menu to interact with the user
	return 0; 
}
