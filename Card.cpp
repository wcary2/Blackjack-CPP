#include "Card.h"
#include <string>
#include <iostream>
Card::Card(int rank_, int suit_)
{
	std::string suit[]{ "c", "s", "h", "d" };
	std::string rank[]{ "A", "2", "3", "4", "5", "6", "7", "8", "9", "T", "J", "Q", "K" };
	value = rank[rank_] + suit[suit_];
	numValue = (rank_  >= 9) ? 10 : rank_ + 1; //Sets max card value to 10
}

Card::~Card()
{

}

void Card::printCard() {
	std::cout << value << " ";
}

int Card::getCardNum() {
	return numValue;
}
