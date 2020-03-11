#include "Poker.h"
#include "Deck.h"


Card* Deal(Card* deck, Card* hand, int currentPlayer)
{
	for (int i = 0; i < handSize; i++)
	{
		hand[i] = deck[currentPlayer*handSize + i];
	}
}
