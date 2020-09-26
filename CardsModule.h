#pragma once
#ifndef CardsModule
#define CardsModule

#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

//Deck Initialization
void fillDeck(vector<int>& deck, int size=16);

//Deck Manipulation
void shuffleDeck(vector<int>& deck);
void sortDeck(vector<int>& deck);
void removeElement(int index, vector<int>& deck);

//Card Output
ostringstream printCards(const vector<int>& deck);

#endif