#include <iostream>
#include <string>
#include <Windows.h>
#include "Card.h"
#include "Deck.h"
#include <WinUser.h>
#include "Player.h"

void drawTable(std::vector<Player> players, int currentPlayer);
void playGame(std::vector<Player> & players, Deck & deck);
void dealerAI(std::vector<Player> &, int currentPlayer, Deck &);
void getBets(std::vector<Player> &);
void dealCards(std::vector<Player> &, Deck & deck);


int main() {
	int numDecks;
	std::cout << "Enter the number of Decks: ";
	std::cin >> numDecks;
	int numPlayers;
	std::cout << "Enter the number of players: ";
	std::cin >> numPlayers;
	//create deck
	Deck deck = Deck(numDecks);
	//setup players
	std::vector<Player> players;
	
	for (int i = 0; i < numPlayers + 1; i++) {
		players.push_back(Player(i));
		players.back().addCard(deck.deal());
		players.back().addCard(deck.deal());
		//setDealer -- last player is dealer
		if (i == numPlayers) {
			players[i].setDealer(true);
		}
	}
	getBets(players);
	playGame(players, deck);
}


void playGame(std::vector<Player> & players, Deck & deck) {
	//set player values for determining turn and drawing table.
	int currentPlayer = 0;
	int numPlayers = players.size();
	drawTable(players, currentPlayer);
	//while loop where the game is essentially played. P exits loop
	
	while (!(GetKeyState('P') & 0x8000)) {

		if (players[currentPlayer].getDealer()) {
			dealerAI(players, currentPlayer, deck);
			//determines winners
			for (int i = 0; i < players.size(); i++) {
				if ((players[i].getCount() > players[currentPlayer].getCount() &&
					!players[i].getBusted())
					|| (!players[i].getBusted() && players[currentPlayer].getBusted())) {
					int money = players[i].getMoney() + (players[i].getBet() * 2);
					players[i].setMoney(money);
					players[i].setBet(0);
					players[i].clearHand();
				}
				else {
					players[i].setBet(0);
					players[i].clearHand();
				}
			}
			getBets(players);
			dealCards(players, deck);
			currentPlayer = 0;
			drawTable(players, currentPlayer);
		}
		

		//Moves to the next player | stand
		if (GetKeyState('S') & 0x8000 || players[currentPlayer].getCount() > 21) {
			currentPlayer++;
			currentPlayer %= numPlayers + 1;
			drawTable(players, currentPlayer);
			Sleep(75);
		}
		//adds card to players hand | hit
		if (GetKeyState('H') & 0x8000) {
			players[currentPlayer].addCard(deck.deal());
			drawTable(players, currentPlayer);
			Sleep(75);
		}
	}

}


/*
Draw the table, the cards of each player, and the dealer
*/
void drawTable(std::vector<Player> players, int currentPlayer) {
	std::cout << std::flush;
	system("CLS");
	for (int i = 0; i < players.size(); i++) {
		//Print the player and his position and whether it is his turn or not.
		std::cout << "P" << players[i].getPosition() << 
			" Money: " << players[i].getMoney() <<
			((currentPlayer == i) ? " Your turn! " : " ");

		if (players[i].getBusted()) {
			std::cout << " Busted! " << std::endl;
		}
		else std::cout << std::endl;

		//Prints the hands of each player. if statement determines whether to print a normal hand
		//or print the dealer hand. TODO: find a better way to do this.
		if (players[i].getDealer() && !players[currentPlayer].getDealer()) {
			players[i].printDealerHand();
		}
		else {
			players[i].printHand();
			std::cout << players[i].getCount() << std::endl << std::endl;
		}
	}
}


/*
Players the dealer according to standard rules
*/
void dealerAI(std::vector<Player> & players, int currentPlayer, Deck&  deck) {
	Player & dealer = players[currentPlayer];
	while(dealer.getCount() <= 16) {
		dealer.addCard(deck.deal());
		drawTable(players, currentPlayer);
		Sleep(75);
	}
}


void getBets(std::vector<Player> & players) {
	std::cout << std::flush;
	for (int i = 0; i < players.size() - 1; i++) {
		std::cout << "Player " << i << " enter your bet: ";
		int bet = 0;
		std::cin >> bet;
		players[i].setBet(bet);
		std::cout << std::endl << std::endl;
	}
}

void dealCards(std::vector<Player> & players, Deck & deck) {
	for (int i = 0; i < players.size(); i++) {
		players[i].addCard(deck.deal());
		players[i].addCard(deck.deal());
	}
}