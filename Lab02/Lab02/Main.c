/************************************************************
 *  File:       Main.c
 *  Project:    Lab 2
 *  Author:     Ryan LeBlanc
 *  Version:    1.0
 *  Date:       14 Mar 2020
 *  Course:     CMPE1700
 *  Instructor: AJ Armstrong
 *  Description: Main implementation file for command-line
 *  program to deal and score poker hands. Accepts
 *  the following arguments:  (1)  Player number(1-10)
 *  (2a) Line to generate data for, or (2b) information of
 *  interest for file, (3) line number for 2b information.
 *  The first arguement is optional; the game default to 4 
 *  players.
 * *********************************************************/
#include <stdlib.h>
#include <stdio.h>
#include "Deck.h"
#include "Poker.h"

 /*********************************************************************
  * Function: main
  * Arguments:int argc - number of arguments (1 implicit arg always present)
  *           char** argv - Array of strings containing com. line arguments
  * API:      arg 1 - (optional) Player number
  * Returns:  int - Program success status
  * Description: Parses command-line arguments and passes output to
  *              console. Creates and evaluates a series of poker hands,
  *				 prints them into the console, and evaluates a winner.
  * ******************************************************************/
int main(int argc, char** argv)
{
	unsigned int playerNum = 4; // default player number
	PlayerHands winner;			// will store the winner's hand for printing
	// allocates memory for an array of player hands with a size of 4 hands
	PlayerHands* handArray = malloc(sizeof(PlayerHands) * playerNum);

	// SetUp
	MakeDeck(deck); // creates the initial deck of cards
	Shuffle(deck);  // shuffles our card deck
	if(argc >1)		// check if we have a first arguement
	//check if the first arguement is acceptable
	if (atoi(argv[1]) > 1 && atoi(argv[1]) < 11)
	{
		// allocates the memory size of the hand array to a size
		// specified by the arguement
		playerNum = atoi(argv[1]);
		handArray = malloc(sizeof(PlayerHands) * playerNum);
	}
	
	// generate specified number of hands
	for (int i = 0; i < playerNum; i++)
	{
		Deal(deck, hand, i); // generate a pointer to the point in the
			//deck of a hand	
		handArray[i] = EvaluateHand(hand); //places the new hand in an array
		printf("Player %d\n", i + 1);// prints the player number
		//prints the hand type and high card for ease of reading
		printf("%20s : %s\n", HandNames[handArray[i].hand], 
			 CardName[handArray[i].highCard]);
		// print the hand of cards
		for (int j = 0; j < handSize; j++)
		{
			printf("%5s of %8s |", CardName[hand[j].value], 
				Suit[hand[j].suit]);
		}
		printf("\n"); // new line for fomatting
	}

	winner = handArray[0]; // sets our initial winning hand
	// sort to find the winning hand
	for (int k = 1; k < playerNum; k++)
	{
		//sets a hand to win if the hand type would win
		if (winner.hand < handArray[k].hand) 
			winner = handArray[k];
		// sets a hand to win if the hand types match 
		// and the second hand has the high card
		else if (winner.hand == handArray[k].hand && 
			winner.highCard < handArray[k].highCard)
			winner = handArray[k];	
	}
	
	// prints each player with a winning hand as the winner
	for (int l = 0; l < playerNum; l++)
	{
		if(winner.hand == handArray[l].hand && 
			winner.highCard == handArray[l].highCard)
			printf("\nPlayer %d wins with a %s (%s)\n", l+1, 
				HandNames[winner.hand], CardName[winner.highCard]);
	}
	// frees the memory used by the array of hands
	free(handArray);
	return EXIT_SUCCESS;
}