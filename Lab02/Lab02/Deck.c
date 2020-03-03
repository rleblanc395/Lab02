#include "Deck.h"

Card* MakeDeck(Card* deck)
{
	int index = 0;
	//int length = 0;

	for (Suits s = Clubs; s <= Spades; s++)
	{
		for (CardValue c = Ace; c <= King; c++)
		{
			deck[index] = (Card){ s, c };
			index++;
		}
	}
}

Card* Shuffle(Card* deck)
{
	srand(time(0));
	Card tmp;

	for (int i = 51; i >= 0; i--)
	{
		int j = rand() % (i + 1);
		tmp = deck[j];
		deck[j] = deck[i];
		deck[i] = tmp;
	}
}

Card* DealHand5(uint playerNum, Card* deck)
{
	
}