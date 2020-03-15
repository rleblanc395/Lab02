/************************************************************
*  File:       Poker.c
*  Project:    Lab 2
*  Author:     Ryan LeBlanc
*  Version:    1.0
*  Date:       14 Mar 2020
*  Course:     CMPE1700
*  Instructor: AJ Armstrong
*  Description: Implementation of methods for dealing and 
*  scoring a poker hand. See Poker.h for declarations.
* *********************************************************/
#include "Poker.h"
#include "Deck.h"
#include <stdlib.h>
#include <stdio.h>

/*********************************************************************
 * Function:    Deal
 * Arguments:   Card* deck - pointer to a Card array( the deck)
 *				Card* hand - pointer to a Card array (the hand to populate)
 *				int currentPlayer - the player whose hand is being dealt
 * Returns:     Card* hand - pointer to a Card array (populated hand)
 * Description: deals a hand from the deck based on player number
 * ******************************************************************/
Card* Deal(Card* deck, Card* hand, int currentPlayer)
{
	// for every card in the hand
	for (int i = 0; i < handSize; i++)
	{
		// place a card, that hasn't been used, into the hand array
		hand[i] = deck[currentPlayer*handSize + i];
	}
}

/*********************************************************************
 * Function:    EvaluateHand
 * Arguments:   Card* deck - pointer to a Card array(hand)
 * Returns:     PlayerHands toScore - the diagnostics of the hand
 * Description: takes a 5 card hand and returns the hand type, and high card
 * ******************************************************************/
PlayerHands EvaluateHand(Card* hand)
{
	hand = SortHand(hand); // sort the hand highes to lowest
	int isStraight = IsStraight(hand); // check if the hand is straight
	int isFlush = IsFlush(hand); // check if the hand is flush
	int pairs = CountPairs(hand); // the number of pairs in the hand
	PlayerHands toScore; // the structure that will be returned
	// set the high card to the highest card value in the hand
	toScore.highCard = hand[handSize - 1].value; 
	
	// check for hand type and stop when the highest value hand is found
	if (isFlush && isStraight)
	{
		if (toScore.highCard == Ace)
			toScore.hand = royalFlush;
		else
			toScore.hand = straightFlush;
	}
	else if (pairs == 6)
		toScore.hand = fourOfAKind;
	else if (pairs == 4)
		toScore.hand = fullHouse;
	else if (isFlush)
		toScore.hand = flush;
	else if (isStraight)
		toScore.hand = straight;
	else if (pairs == 3)
		toScore.hand = threeOfAKind;
	else if (pairs == 2)
		toScore.hand = twoPair;
	else if (pairs == 1)
		toScore.hand = pair;
	else
		toScore.hand = nothing;
	return toScore;
}

/*********************************************************************
 * Function:    SortHand
 * Arguments:   Card* hand - pointer to a Card* array to sort
 * Returns:     Card* hand - a sorted hand
 * Description: bubble sorts the hand of cards
 * ******************************************************************/
Card* SortHand(Card* hand)
{
	Card temp;
	// cycle through card pairs
	for (int i = 0; i < handSize-1; i++)
	{
		for (int j = 0; j < handSize -1 -i; j++)
		{
			// check if prior card is larger than later
			if (hand[j].value > hand[j+1].value)
			{
				//swaps cards
				temp = hand[j];
				hand[j] = hand[j+1];
				hand[j+1] = temp;
			}
		}
	}
	//send the new hand back
	return hand;
 }

/*********************************************************************
 * Function:    CountPairss
 * Arguments:   Card* hand - pointer to a Card array(hand)
 * Returns:     int pairs - number of pairs in a hand
 * Description: creates a deck of 52 cards
 * ******************************************************************/
int CountPairs(Card* hand)
{
	int pairs = 0; // number of pairs
	// filter through card combinations
	for (int i = 0; i < handSize; i++)
	{
		for (int j = i + 1; j < handSize; j++)
		{
			// add 1 to pair if the cards are a pair
			if (hand[i].value == hand[j].value)
				pairs++;
		}
	}
	return pairs;
}

/*********************************************************************
 * Function:    IsFlush
 * Arguments:   Card* hand - pointer to a Card array(hand)
 * Returns:     0 - if not a flush
 *				1 - if is a flush
 * Description: checks if a hand contains a flush
 * ******************************************************************/
int IsFlush(Card* hand)
{
	// cycle through the hand
	for (int i = 1; i < handSize; i++)
	{
		// if the suits don't match, return false
		if (hand[0].suit != hand[i].suit)
			return 0;
	}
	// return true
	return 1;
}

/*********************************************************************
 * Function:    IsStraight
 * Arguments:   Card* hand - pointer to a Card array(hand)
 * Returns:     0 - not straight
 *				1 - is straight
 * Description: checks if the hand contains a straight
 * ******************************************************************/
int IsStraight(Card* hand)
{
	// cycle through pre sorted cards in the hand
	for (int k = 0; k < handSize-1; k++)
	{
		// if the cards are not increasing by 1, return false
		if (hand[k].value != hand[k + 1].value - 1)
			return 0; 
	}
	return 1; // return true
}