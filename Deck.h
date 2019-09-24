#pragma once
#include <vector>
#include <string>
#include <stdlib.h>
#include "Card.h"
#include <time.h>
class Deck
{
	std::vector<Card> cards;
public:
	Deck(int num);
	~Deck();
	void shuffle();
	Card deal();
};

