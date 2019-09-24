#include "Player.h"

/*TODO: */

Player::Player(int pos)
{
	busted = false;
	isDealer = false;
	money = 500;
	position = pos;
	count = 0;
}


Player::~Player()
{
}

/*prints hand*/
void Player::printHand()
{
	for (std::vector<Card>::iterator it = hand.begin(); it != hand.end(); it++) {
		it->printCard();
	}
}

/*prints the dealers hand hiding the second card*/
void Player::printDealerHand()
{
	hand[0].printCard();
	std::cout << "## ";
}

int Player::getCount()
{
	return count;
}

void Player::addCard(Card card)
{
	hand.push_back(card);
	count += hand.back().getCardNum();
	if (count > 21) {
		busted = true;
	}
}

bool Player::getBusted() {
	return busted;
}

void Player::setDealer(bool dealer) {
	isDealer = dealer;
}

bool Player::getDealer() {
	return isDealer;
}

int Player::getPosition() {
	return position;
}


void Player::setBet(int bet_) {
	bet = bet_;
	money -= bet;
}

int Player::getBet() {
	return bet;
}

void Player::clearHand() {
	count = 0;
	busted = false;
	hand.clear();
}

void Player::setMoney(int money_) {
	money = money_;
}

int Player::getMoney() {
	return money;
}