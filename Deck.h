#include "Card.h"
#include <vector>
#include <time.h>
#include <iterator>
#include <random>
#include <algorithm>

using namespace std;

#pragma once
class Deck
{
public:
	Deck();
	void makeDeck(); // Fills deck with 52 cards
	void shuffleDeck(); // Shuffles deck
	vector<Card> getDeck(); // Returns deck vector
	Card drawCard(); // Returns top card in deck and removes it from deck
	void setDeck(vector<Card> deck);
	void addCard(Card card);
private:
	vector<Card> mCardsDeck; // Vector containing all cards
};

