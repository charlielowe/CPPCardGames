#include "Card.h"

Card::Card(string newRank, string newSuit) {
	this->rank = newRank;
	this->suit = newSuit;
	this->value = 10;
	if (rank == "K" || rank == "Q" || rank == "J") {
		this->value = 10;
	}
	else if (rank == "A") {
		this->value = 11;
	}
	else {
		this->value = stoi(rank);
	}

	this->cardID = this->rank + this->suit;
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