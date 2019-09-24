#pragma once
#include <string>


class Card
{
	std::string value;
	int numValue;
public:
	Card(int rank_, int suit_);
	void printCard();
	int getCardNum();
	~Card();
};


