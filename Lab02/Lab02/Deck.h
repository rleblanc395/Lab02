#ifndef DECKH
#pragma once

/************************************************************
*  File:       Deck.h
*  Project:    Lab 2
*  Author:     Ryan LeBlanc
*  Version:    1.0
*  Date:       14 Mar 2020
*  Course:     CMPE1700
*  Instructor: AJ Armstrong
*  Description: Declaration of an enum of card types and values,
*  a structre that stores a card's type and value, and a series
*  of methods used to create a generic deck of 52 cards
*  See deck.c for implementation
* *********************************************************/

typedef enum suit // the suits of playing cards
{
	Clubs,
	Diamonds,
	Hearts,
	Spades
}Suits;

typedef enum value // the values of playing cards
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
	Suits suit; // suit of the card
	CardValue value; // value of the card
}Card;

//Look up table for card values
static const char* CardName[] = { "Deuce", "Three", "Four", 
								  "Five", "Six", "Seven", "Eight", "Nine", 
								  "Ten", "Jack", "Queen", "King", "Ace" };
// Look up table for suits
static const char* Suit[] = { "Clubs", "Diamonds", "Hearts", "Spades" };

//Reserve memory for card deck array
Card deck[52];

// declare function to make the deck
Card* MakeDeck(Card* deck);
// declare function to shuffle the deck
Card* Shuffle(Card* deck);

#endif // !DECKH