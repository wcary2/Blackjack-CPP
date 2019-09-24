#include "Deck.h"
#include <iostream>

/*TODO:
 * REDO SHUFFLE: make the shuffle algorithm move every card
*/

/*sets up the deck based on the number of decks passed*/
Deck::Deck(int num)
{
	for (int i = 0; i < num; i++) {
		for (int suit = 0; suit < 4; suit++) {
			for (int rank = 0; rank < 13; rank++) {
				cards.push_back(Card(rank, suit));
			}
		}
	}
	shuffle();
	for (std::vector<Card>::iterator it = cards.begin(); it != cards.end(); it++) {
		it->printCard();
	}
}

//bad shuffle algorithm should be fixed to move all the cards to a different position
/*Shuffles the cards currently in the deck*/
void Deck::shuffle() {
	int numCards = cards.size();
	for (int i = 0; i < numCards; i++) {
		srand(time(NULL));
		int cardToShuffle = rand() % (numCards - i); //random card
		Card temp = cards[cards.size() - 1 - i];
		cards[cards.size() - 1 - i] = cards[cardToShuffle];
		cards[cardToShuffle] = temp;
	}
}

Card Deck::deal() {
	Card temp = cards.back();
	cards.pop_back();
	return temp;
}

Deck::~Deck()
{

}
