#include <stdlib.h>
#include <stdio.h>
#include "Deck.h"
#include "Poker.h"

int main(int argc, char** argv)
{
	unsigned int playerNum = 4;
	MakeDeck(deck);
	Shuffle(deck);
	PlayerHands winner;
	PlayerHands* handArray = malloc(sizeof(PlayerHands) * playerNum);
	int winNum = 1;
	int tieCounter = 0;
	if(argc >1)
	if (atoi(argv[1]) > 1 && atoi(argv[1]) < 11)
	{
		playerNum = atoi(argv[1]);
		handArray = malloc(sizeof(PlayerHands) * playerNum);
	}
	
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
			winner = handArray[k];
		else if (winner.hand == handArray[k].hand && winner.highCard < handArray[k].highCard)
			winner = handArray[k];	
	}
	
	for (int l = 0; l < playerNum; l++)
	{
		if(winner.hand == handArray[l].hand && winner.highCard == handArray[l].highCard)
			printf("\nPlayer %d wins with a %s (%s)\n", l+1, HandNames[winner.hand], CardName[winner.highCard]);
	}

	free(handArray);
	return;
}