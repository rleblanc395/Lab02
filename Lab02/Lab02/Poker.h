#ifndef POKERH
#pragma once
#include "Deck.h"

/************************************************************
*  File:       Poker.h
*  Project:    Lab 2
*  Author:     Ryan LeBlanc
*  Version:    1.0
*  Date:       14 Mar 2020
*  Course:     CMPE1700
*  Instructor: AJ Armstrong
*  Description: Declaration of an enum of poker hand types,
*  a structure that stores a single hand and its high card,
*  and a series of methods that evaluate hands as if playing
*  poker. See Poker.c for implementation
* *********************************************************/

static const unsigned int handSize = 5; // hand size in poker

typedef enum pokerHand // ranking of poker hands
{
	nothing,
	pair,
	twoPair,
	threeOfAKind,
	straight,
	flush,
	fullHouse,
	fourOfAKind,
	straightFlush,
	royalFlush,
}PokerHand;

typedef struct hands
{
	PokerHand hand; // the poker hand
	int highCard;	// the highest card value in said hand
}PlayerHands;

// LookUp table for poker hands
static const char* HandNames[] = { "Nothing", "Pair", "Two Pair", 
									"Three of a Kind", "Straight", "Flush",
									"Full House", "Four of a Kind", 
									"Straight Flush", "Royal Flush" };
Card hand[5]; // reserve memory for hand Card array

// declare funtion to count the number of pairs in a hand
int CountPairs(Card* hand); 
// declare funtion to check if a hand is a flush
int IsFlush(Card* hand); 
// declare funtion to check if a hand is a straight
int IsStraight(Card* hand); 

// declare funtion to sort a set of cards from highest to lowest
Card* SortHand(Card* hand); 
// declare funtion to create a 5 card hand from the 'top' of the deck
Card* Deal(Card* deck, Card* hand, int currentPlayer);

// declare funtion to return the diagnostics of a hand(hand type & high card)
PlayerHands EvaluateHand(Card* hand);


#endif 