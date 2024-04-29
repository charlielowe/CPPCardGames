#include "Card.h"

Card::Card(string newRank, string newSuit, bool mFlipped) {
	this->mRank = newRank;
	this->mSuit = newSuit;
	this->mFlipped = mFlipped;
	
	// Sets the value of the picture cards
	if (mRank == "K" || mRank == "Q" || mRank == "J" || mRank == " " || mRank == "E" || mRank == "S") {
		this->mValue = 10;
	}
	else if (mRank == "A") {
		this->mValue = 11;
	}
	else {
		this->mValue = stoi(mRank);
	}

	// Sets the card ID depending on if card is flipped
	if (mFlipped == true) {
		this->mCardID = this->mRank + this->mSuit;
	}
	else {
		this->mCardID = "**";
	}

	if (mSuit == "H" || mSuit == "D") {
		this->mColour = "red";
	}
	else if(mSuit == "S" || mSuit == "C") {
		this->mColour = "black";
	}
	else {
		this->mColour = "white";
	}
	
}

// Swaps mFlipped bool to opposite of what it currently is, updates card ID
void Card::flip() {
	this->mFlipped = !(this->mFlipped);
	if (this->mFlipped) {
		this->mCardID = this->mRank + this->mSuit;
	}
	else {
		this->mCardID = "**";
	}
}


// Getters and setters

string Card::getRank() {
	return this->mRank;
}

string Card::getSuit() {
	return this->mSuit;
}

int Card::getValue() {
	return this->mValue;
}

string Card::getID() {
	return this->mCardID;
}

void Card::setValue(int newValue) {
	this->mValue = newValue;
}

string Card::getColour() {
	return this->mColour;
}

bool Card::getFlipped() {
	return this->mFlipped;
}