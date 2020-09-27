// George Bennett
// gcbz9k@mail.umkc.edu
// 09/26/2020
// CS201R Program 2 - Take it or Leave It!

#include <iostream>
#include <sstream>
#include <ctime>
#include <random>
#include "CardsModule.h"
using namespace std;

int main() {
	int deckSize = 16;
	vector<int> deck(16);
	vector<int> deadCards(0);
	vector<int> liveCards(16);
	fillDeck(deck);
	shuffleDeck(deck);
	fillDeck(liveCards);

	int cardIndex = 0;
	int takenCard = 0;
	int score = 0;
	char userInput;

	while (cardIndex<16) {
		//Prepares the deck
		int newCard = deck.at(cardIndex);
		int tempSize = deadCards.size();
		cardIndex++;

		//Prints current deck
		sortDeck(liveCards);
		sortDeck(deadCards);
		cout << "Current Score: " << score << endl;
		cout << "Dead Cards: " << printCards(deadCards).str() << endl;
		cout << "Live Cards: " << printCards(liveCards).str() << endl;
		cout << "Next Card: " << newCard;

		//Prints if the card is dead or not
		if (takenCard > newCard) {
			cout << " Dead" << endl << endl << endl;
			continue;
		}
		else {
			cout << endl << endl;
		}
		

		//Prompts the user to either take it or leave it
		bool waiting = true;
		while (waiting) {
			cout << "Take it [T] or leave it [L]?: ";
			cin >> userInput;

			switch (userInput) {
			case 't':
			case 'T':
				//Removes taken card and all cards below the and adds them to the dead cards
				for (unsigned int i = 0; i < liveCards.size(); i++) {
					if (liveCards.at(i) <= newCard) {
						deadCards.push_back(liveCards.at(i));
					}
				}
				
				//Updates the card picked
				takenCard = newCard;
				score += takenCard;
				waiting = false;
				break;
			case 'l':
			case 'L':
				//Adds the left card to dead cards and removes it from the live cards
				deadCards.push_back(newCard);
				removeElement(newCard, liveCards);
				waiting = false;
				break;
			default:
				cout << "Invalid Input" << endl;
				waiting = true;
			}
		}

		//Updates the live cards by removing the new dead ones
		if (tempSize < deadCards.size()) {
			for (unsigned int i = tempSize; i < deadCards.size(); i++) {
				removeElement(deadCards.at(i), liveCards);
			}
		}
		cout << endl;
	}
	cout << "Final Score: " << score << endl;
}