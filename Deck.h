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
	void makeDeck();
	void shuffleDeck();
	vector<Card> getDeck();
	Card drawCard();
private:
	vector<Card> cardsDeck;
};

