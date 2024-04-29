#include <string>
#pragma once

using namespace std;

class Card
{
public:
	Card(string newRank, string newSuit, bool flipped);
	
	// Getters and setters
	string getRank();
	string getSuit();
	int getValue();
	string getID();
	string getColour();
	void setValue(int newValue);
	bool getFlipped();
	void flip(); // Flips the card
	

private:
	bool mFlipped;
	string mRank;
	string mSuit;
	int mValue;
	string mCardID;
	string mColour;
};

