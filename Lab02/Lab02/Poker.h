#ifndef POKERH
#pragma once
#include "Deck.h"
static const unsigned int playerNum = 4;
static const unsigned int handSize = 5;

Card* Deal(Card* deck, Card* hand, int currentPlayer);

Card* hand[5];




#endif 