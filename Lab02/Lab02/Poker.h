#ifndef POKERH
#pragma once
#include "Deck.h"
static const unsigned int playerNum = 4;
static const unsigned int handSize = 5;

Card* Deal(Card* deck, unsigned int playerNum, unsigned int handSize);

Card* hand1[5];
Card* hand2[5];
Card* hand3[5];
Card* hand4[5];




#endif 