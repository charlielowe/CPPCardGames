#include "Card.h"

Card::Card(string newRank, string newSuit, bool flipped) {
	this->rank = newRank;
	this->suit = newSuit;
	this->flipped = flipped;
	
	if (rank == "K" || rank == "Q" || rank == "J" || rank == " " || rank == "E" || rank == "S") {
		this->value = 10;
	}
	else if (rank == "A") {
		this->value = 11;
	}
	else {
		this->value = stoi(rank);
	}
	if (flipped == true) {
		this->cardID = this->rank + this->suit;
	}
	else {
		this->cardID = "**";
	}

	
}

void Card::flip() {
	this->flipped = !(this->flipped);
	if (this->flipped) {
		this->cardID = this->rank + this->suit;
	}
	else {
		this->cardID = "**";
	}
	
}

string Card::getRank() {
	return this->rank;
}

string Card::getSuit() {
	return this->suit;
}

int Card::getValue() {
	return this->value;
}

string Card::getID() {
	return this->cardID;
}

void Card::setValue(int newValue) {
	this->value = newValue;
}