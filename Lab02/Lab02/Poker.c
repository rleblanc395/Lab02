#include "Poker.h"
#include "Deck.h"
#include <stdlib.h>
#include <stdio.h>


Card* Deal(Card* deck, Card* hand, int currentPlayer)
{
	for (int i = 0; i < handSize; i++)
	{
		hand[i] = deck[currentPlayer*handSize + i];
	}
}

PlayerHands EvaluateHand(Card* hand)
{
	hand = SortHand(hand);
	int isStraight = IsStraight(hand);
	int isFlush = IsFlush(hand);
	int pairs = CountPairs(hand);
	PlayerHands toScore;
	toScore.highCard = hand[handSize - 1].value;
	
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
Card* SortHand(Card* hand)
{
	Card temp;
	
	for (int i = 0; i < handSize-1; i++)
	{
		for (int j = 0; j < handSize -1 -i; j++)
		{
			if (hand[j].value > hand[j+1].value)
			{
				temp = hand[j];
				hand[j] = hand[j+1];
				hand[j+1] = temp;
			}
		}
	}
	return hand;
 }

int CountPairs(Card* hand)
{
	int pairs = 0;
	for (int i = 0; i < handSize; i++)
	{
		for (int j = i + 1; j < handSize; j++)
		{
			if (hand[i].value == hand[j].value)
				pairs++;
		}
	}
	return pairs;
}

int IsFlush(Card* hand)
{
	for (int i = 1; i < handSize; i++)
	{
		if (hand[0].suit != hand[i].suit)
			return 0;
	}
	return 1;
}

int IsStraight(Card* hand)
{
	for (int k = 0; k < handSize-1; k++)
	{
		if (hand[k].value != hand[k + 1].value - 1)
			return 0;
	}
	return 1;
}