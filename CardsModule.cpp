// George Bennett
// gcbz9k@mail.umkc.edu
// 09/26/2020
// CS201R Program 2 - Take it or Leave It!

#include <iostream>
#include <sstream>
#include <iomanip>
#include <vector>
#include <ctime>
#include <random>
using namespace std;

//Fills the card deck with size integers representing the cards
void fillDeck(vector<int>& deck, int size=16) {
	for (int i = 1; i <= size; i++) {
		deck.at(i - 1) = i;
	}
	return;
}


//Shuffles each card using a random index
void shuffleDeck(vector<int>& deck) {
	srand(time(NULL));
	for (int i = 0; i < 16; i++) {
		int swap = ((rand() % 15) + 1);
		int temp = deck.at(swap);
		deck.at(swap) = deck.at(i);
		deck.at(i) = temp;
	}
	return;
}


//Prints a line of cards with width 3
ostringstream printCards(const vector<int>& deck) {
	ostringstream cardStream;
	for (unsigned int i = 0; i < deck.size(); i++) {
		cardStream << setw(3) << deck.at(i);
	}
	return cardStream;
}

//Sorts a list of cards in ascending order using insertion sort
void sortDeck(vector<int>& deck) {
	for (unsigned int i = 0; i < deck.size(); i++) {
		unsigned int j = i;
		while (j > 0 && deck.at(j) < deck.at(j-1)) {
			int temp = deck.at(j);
			deck.at(j) = deck.at(j-1);
			deck.at(j-1) = temp;
			--j;
		}
	}
	return;
}


//Removes an element at an index, returns error if index out of range
void removeElement(int element, vector<int>& deck) {
	bool found = false;
	for (unsigned int j = 0; j < deck.size(); j++) {
		if (deck.at(j) == element) {
			found = true;
			for (unsigned int i = j; i < deck.size() - 1; i++) {
				deck.at(i) = deck.at(i + 1);
			}
			deck.resize(deck.size() - 1);
			return;
		}
	}
	if (!found) {
		cout << "Cannot find element" << endl;
		return;
	}
	return;
}
