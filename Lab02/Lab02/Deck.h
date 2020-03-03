#ifndef DECKH
#pragma once

typedef unsigned int uint;
typedef enum suit
{
	Clubs,
	Diamonds,
	Hearts,
	Spades
}Suits;

typedef enum value
{
	Ace,
	Deuce,
	Three,
	Four,
	Five,
	Six,
	Seven,
	Eight,
	Nine,
	Ten,
	Jack,
	Queen,
	King
}CardValue;

typedef struct card
{
	Suits suit;
	CardValue value;
}Card;

//Look up table for card values
static const char* CardName[] = { "Ace", "Deuce", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Jack", "Queen", "King" };
// Look up table for suits
static const char* Suit[] = { "Clubs", "Diamonds", "Hearts", "Spades" };

//Reserve memory for card deck array
Card deck[52];

// declare function to make the deck
Card* MakeDeck(Card* deck);
// declare function to shuffle the deck
Card* Shuffle(Card* deck);
// declare function to deal 5
Card* DealHand5(uint playerNum, Card* deck);
#endif // !DECKH