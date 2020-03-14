#ifndef POKERH
#pragma once
#include "Deck.h"

static const unsigned int playerNum = 4;
static const unsigned int handSize = 5;

typedef enum pokerHand
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
	PokerHand hand;
	int highCard;
}PlayerHands;

static const char* HandNames[] = { "Nothing", "Pair", "Two Pair", "Three of a Kind", "Straight", "Flush",
									"Full House", "Four of a Kind", "Straight Flush", "Royal Flush" };
Card hand[5];

int CountPairs(Card* hand);
int IsFlush(Card* hand);
int IsStraight(Card* hand);

Card* SortHand(Card* hand);
Card* Deal(Card* deck, Card* hand, int currentPlayer);

PlayerHands EvaluateHand(Card* hand);






#endif 