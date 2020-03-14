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
	King,
	Ace
}CardValue;

typedef struct card
{
	Suits suit;
	CardValue value;
}Card;

//Look up table for card values
static const char* CardName[] = { "Deuce", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Jack", "Queen", "King", "Ace" };
// Look up table for suits
static const char* Suit[] = { "Clubs", "Diamonds", "Hearts", "Spades" };

//Reserve memory for card deck array
Card deck[52];

// declare function to make the deck
Card* MakeDeck(Card* deck);
// declare function to shuffle the deck
Card* Shuffle(Card* deck);

#endif // !DECKH