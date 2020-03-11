#include <stdlib.h>
#include <stdio.h>
#include "Deck.h"
#include "Poker.h"

int main(int argc, char** argv)
{
	MakeDeck(deck);
	Shuffle(deck);
	for (int i = 0; i < playerNum; i++)
	{
		Deal(deck, hand, i);

		printf("Player %d\n", i + 1);
	
		for (int i = 0; i < handSize; i++)
		{
			printf("%5s of %8s |", CardName[deck[i].value], Suit[deck[i].suit]);
		}
		printf("\n");
	}
	/*
	for(plyerNum)
	{
	MakeHand()
	PrintHand()
	ScoreHand()
	Messages
	}
	*/
	
	return;
}