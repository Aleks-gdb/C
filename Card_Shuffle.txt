#include "Prototypes.h"

int main()
{
	DeckOfCards Deck; //declares a new DeckOfCards object
	Card card; //declares a new Card object

	//output the deck before shuffle
	for (int c = 0; c < 52; c++)
	{
		card = Deck.dealCard(); //use card as a temporary object to output the cards
		cout << setw(20) << left << card.toString();
	}
	cout << endl << endl;
	Deck.shuffle(); //shuffle the deck
	for (int s = 0; s < 52; s++)
	{
		card = Deck.dealCard(); //card is a temporary object to output the cards
		cout << setw(20) << left << card.toString();
	}
	
	Card Hand[5]; //an array to store the cards of the poker hand
	cout << "\n\nA poker hand:\n";
	for (int i = 0; i < 5; i++)
	{
		Hand[i] = Deck.dealCard(); //stores randomly shuffled cards in Hand
		cout << Hand[i].toString() << endl; //outputs the content of Hand, the poker hand
	}
	
	//check if the poker hand contains a pair or two pairs
	for (int i = 0; i < 5; i++)
	{
		for (int j = i + 1; j < 5; j++)
		{
			for (int k = j + 1; k < 5; k++)
			{
				for (int l = k + 1; l < 5; l++)
				{
					if (Hand[i].getFace() == Hand[j].getFace() && Hand[k].getFace() == Hand[l].getFace() && i != j != k != l)
					{
						cout << "You got two pairs!\n";
						break;
					}
				}
			}

			if (Hand[i].getFace() == Hand[j].getFace() && i != j)
			{
				cout << "You got a pair!\n";
				break;
			}
		}
	}

	//check if the hand contains three of a kind
	for (int i = 0; i < 5; i++)
	{
		for (int j = i + 1; j < 5; j++)
		{
			for (int k = j + 1; k < 5; k++)
			{
					if (Hand[i].getFace() == Hand[j].getFace() && Hand[i].getFace() == Hand[k].getFace() && i != j != k)
					{
						cout << "You got three of a kind!\n";
						break;
					}
			}
		}
	}

	//check for a four of a kind in the poker hand
	for (int i = 0; i < 5; i++)
	{
		for (int j = i + 1; j < 5; j++)
		{
			for (int k = j + 1; k < 5; k++)
			{
				for (int l = k + 1; l < 5; l++)
				{
					if (Hand[i].getFace() == Hand[j].getFace() && Hand[i].getFace() == Hand[k].getFace() && 
						Hand[i].getFace() == Hand[l].getFace() && i != j != k != l)
					{
						cout << "You got four of a kind!\n";
						break;
					}
				}
			}
		}
	}

	//check for a flush
	for (int i = 0; i < 5; i++)
	{
		for (int j = i + 1; j < 5; j++)
		{
			for (int k = j + 1; k < 5; k++)
			{
				for (int l = k + 1; l < 5; l++)
				{
					for (int m = l + 1; m < 5; m++)
					{
						if (Hand[i].getSuit() == Hand[j].getSuit() && Hand[i].getSuit() == Hand[k].getSuit() &&
							Hand[i].getSuit() == Hand[l].getSuit() && Hand[i].getSuit() == Hand[m].getSuit())
						{
							cout << "You got a flush!\n";
							break;
						}
					}
				}
			}
		}
	}

	//check for a straight
	int straight = 0;
	for (int i = 0; i < 5; i++)
	{
		for (int j = i + 1; i < 5; i++)
		{
			if (Hand[i].getFace() > Hand[j].getFace()) //comparing the values to sort them in order
			{
				Card temp = Hand[i];
				Hand[i] = Hand[j];
				Hand[j] = temp;
			}
			if (Hand[i].getFace() == (Hand[j].getFace() -1)) //checking for face values that differ by 1 
				straight++;
			if (straight == 4)
				cout << "You got a straight!\n";
		}
	}
	system("pause");
	return 0;
}

//Prototypes.h
#pragma once
#include <time.h>
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;
class Card
{
public:
	enum FaceType { ACE, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, JACK, QUEEN, KING };
	enum SuitType { SPADES, HEARTS, DIAMONDS, CLUBS };
	static string FaceArray[];
	static string SuitArray[];
private:
	int Face;
	int Suit;
public:
	Card();
	Card(int f, int s) //overloaded constructor for Card
	{
		Face = f;
		Suit = s;
	}
	string toString();
	int getFace() { return Face; } //returns the face of the card as an int
	int getSuit() { return Suit; } //returns the suit of the card as an int
};

class DeckOfCards
{
	Card Deck[52]; //Deck[] of 52 Card objects
	int currentCard; //next card to deal
	int Cards; //keep track of cards 
public:
	DeckOfCards();
	void shuffle();
	Card dealCard();
	bool moreCards();
};

//ClassDefinitions.cpp
#include "Prototypes.h"

string Card::FaceArray[] = {"Ace", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Jack", "Queen", "King"};
string Card::SuitArray[] = {"Spades", "Hearts", "Diamonds", "Clubs"};
//default constructor for Card
Card::Card() 
{

}

//convert Card to a string
string Card::toString() 
{
	return (FaceArray[Face] + " of " + SuitArray[Suit]);
}

//constructor for DeckOfCards
DeckOfCards::DeckOfCards() 
{
	currentCard = 0;
	for (int i = 0; i < 52; i++)
	{
		int f = i % 13;
		int s = i / 13;
		Deck[i] = Card(f, s);
	}
}

//shuffle the cards
void DeckOfCards::shuffle()
{
	int value[52];
	bool check;
	int j, r;
	srand(time(NULL));
	for (int i = 0; i < 52; i++)
	{
		//check for repeated values that are randomly generated
		do
		{
			j = rand() % 52; //randomly generates a number
			check = true;
			for (int c = 0; c < i; c++)
			{
				if (j == value[c]) //if number is already used
				{
					check = false;
					break; //stop checking the other values
				}
			}
		} while (!check);
		value[i] = j; //stores all the original randomly generated values in the array
	}
	
	//perform the shuffle
	for(int a = 0; a < 52; a++)
	{
		r = value[a];
		Card temp = Deck[a];
		if (Deck[a].getFace() != Deck[r].getFace() && Deck[a].getSuit() != Deck[r].getSuit()) //checks to make sure card will not repeat
		{
			Deck[a] = Deck[r];
			Deck[r] = temp;
		}
	}
}

//output the next card
Card DeckOfCards::dealCard()
{
	if (currentCard < 52)
	{
		currentCard++;
		if (currentCard == 52) //once the deck is printed
			currentCard = 0; //set the current to 0 again
	}
	return Deck[currentCard];
}

//check for more cards available to deal from the deck
bool DeckOfCards::moreCards()
{
	if (currentCard == 52)
		return false;
	else
		return true;
}
