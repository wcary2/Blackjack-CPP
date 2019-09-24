#pragma once
#include <iostream>
#include "Card.h"
#include <vector>
#include <string>
class Player
{
	bool isDealer;
	int money;
	int bet;
	int position;
	int count;
	bool busted;
	std::vector<Card> hand;
public:
	Player(int pos);
	~Player();
	void printHand();
	void printDealerHand();
	int getCount();
	bool getBusted();
	void addCard(Card card);
	void setDealer(bool dealer);
	bool getDealer();
	void setBet(int bet_);
	int getBet();
	void clearHand();
	int getPosition();
	void setMoney(int money_);
	int getMoney();
};

