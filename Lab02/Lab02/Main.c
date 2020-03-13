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
	
		for (int j = 0; j < handSize; j++)
		{
			printf("%5s of %8s |", CardName[hand[j].value], Suit[hand[j].suit]);
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