/************************************************************
*  File:       Deck.c
*  Project:    Lab 2
*  Author:     Ryan LeBlanc
*  Version:    1.0
*  Date:       14 Mar 2020
*  Course:     CMPE1700
*  Instructor: AJ Armstrong
*  Description: Implementation of methods for creating and 
*  shuffling a deck of 52 cards (no jokers)
*  See deck.h for declaration
* *********************************************************/
#include <time.h>
#include <stdlib.h>
#include "Deck.h"

/*********************************************************************
 * Function:    MakeDeck
 * Arguments:   Card* deck - pointer to a deck array
 * Returns:     Card* deck - a fully populated array cards
 * Description: creates a deck of 52 cards
 * ******************************************************************/
Card* MakeDeck(Card* deck)
{
	int index = 0; // the index of the Card array being altered
	// create a card of every value for every suit
	for (Suits s = Clubs; s <= Spades; s++)
	{
		for (CardValue c = Deuce; c <= Ace; c++)
		{
			// load them into the deck array
			deck[index] = (Card){ s, c };
			index++;
		}
	}
}

/*********************************************************************
 * Function:    Shuffle
 * Arguments:   Card* deck - pointer to a deck array
 * Returns:     Card* deck - withits cards in randomized positions
 * Description: randomizes the positions of Cards in a 52 card array
 * ******************************************************************/
Card* Shuffle(Card* deck)
{
	srand(time(0)); // seed the random num generator
	Card tmp; // placeholder card for swapping
	// Fisher yates shuffle
	for (int i = 51; i >= 0; i--)
	{
		int j = rand() % (i + 1); // find a random card
		//swap cards
		tmp = deck[j];
		deck[j] = deck[i];
		deck[i] = tmp;
	}
}

