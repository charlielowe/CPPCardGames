#include "Card.h"
#include <vector>
#include <time.h> 

using namespace std;

#pragma once
class Deck
{
public:
	Deck();
	void makeDeck();
	vector<Card> getDeck();
	Card drawCard();
private:
	vector<Card> cardsDeck;
};

