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
	int currentCard = 0;
	int score = 0;
	char userInput;

	while (cardIndex<16) {
		//Flips over a new card
		int newCard = deck.at(cardIndex);

		//Prints current deck
		cout << "Current Score: " << score << endl;
		cout << "Dead Cards: " << printCards(deadCards).str() << endl;
		cout << "Live Cards: " << printCards(liveCards).str() << endl;
		cout << "Next Card: " << newCard;

		//Skips the new card if is less than the current card
		if (currentCard > newCard) {
			//Adds the card to dead cards and removes it from live cards
			cout << " Dead" << endl << endl << endl;

			deadCards.push_back(newCard);
			removeElement(newCard, liveCards);
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
				//Adds the card to the score and to the last knowledge
				currentCard = newCard;
				score += currentCard;
				removeElement(currentCard, liveCards);
				waiting = false;
				break;
			case 'l':
			case 'L':
				//Adds the card to dead cards and removes it from the live cards
				deadCards.push_back(newCard);
				removeElement(newCard, liveCards);
				waiting = false;
				break;
			default:
				cout << "Invalid Input" << endl;
				waiting = true;
			}
		}
		//Switches to new card for next round
		cardIndex++;
		cout << endl;
	}
	cout << "Final Score: " << score << endl;
}