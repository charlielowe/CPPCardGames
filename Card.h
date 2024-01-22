#include <string>
#pragma once

using namespace std;

class Card
{
public:
	Card(string newRank, string newSuit, bool flipped);
	string getRank();
	string getSuit();
	int getValue();
	string getID();
	void flip();
	void setValue(int newValue);

private:
	bool flipped;
	string rank;
	string suit;
	int value;
	string cardID;
};

