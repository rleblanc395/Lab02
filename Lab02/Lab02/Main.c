#include <stdlib.h>
#include <stdio.h>
#include "Deck.h"
#include "Poker.h"

int main(int argc, char** argv)
{
	MakeDeck(deck);
	Shuffle(deck);
	PlayerHands handArray[4];
	PlayerHands winner;
	int winNum = 1;
	
	printf("\n");
	printf("\n");
	for (int i = 0; i < playerNum; i++)
	{
		Deal(deck, hand, i);
		printf("Player %d\n", i + 1);
		handArray[i] = EvaluateHand(hand);
		printf("%20s :%d: %s\n", HandNames[handArray[i].hand], handArray[i].hand, CardName[handArray[i].highCard]);
		for (int j = 0; j < handSize; j++)
		{
			printf("%5s of %8s |", CardName[hand[j].value], Suit[hand[j].suit]);
		}
		
		printf("\n");
	}

	winner = handArray[0];
	for (int k = 1; k < playerNum; k++)
	{
		if (winner.hand < handArray[k].hand)
		{
			winner = handArray[k];
			winNum = k+1;
		}
		else if (winner.hand == handArray[k].hand && winner.highCard < handArray[k].highCard)
		{
			winner = handArray[k];
			winNum = k+1;
		}
		else if(winner.hand == handArray[k].hand && winner.highCard == handArray[k].highCard)
			printf("\nPlayer %d wins with a %s (%s)\n", k+1, HandNames[winner.hand], CardName[winner.highCard]);
	}
	printf("\nPlayer %d wins with a %s (%s)\n",winNum, HandNames[winner.hand], CardName[winner.highCard]);
	return;
}