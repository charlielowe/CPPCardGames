#include <string>
#pragma once

using namespace std;

class Card
{
public:
	Card(string newRank, string newSuit);
	string getRank();
	string getSuit();
	int getValue();
	string getID();

private:
	bool flipped;
	string rank;
	string suit;
	int value;
	string cardID;
};

