#include "Card.h"

Card::Card(string newRank, string newSuit, bool flipped) {
	this->rank = newRank;
	this->suit = newSuit;
	this->flipped = flipped;
	
	// Sets the value of the picture cards
	if (rank == "K" || rank == "Q" || rank == "J" || rank == " " || rank == "E" || rank == "S") {
		this->value = 10;
	}
	else if (rank == "A") {
		this->value = 11;
	}
	else {
		this->value = stoi(rank);
	}

	// Sets the card ID depending on if card is flipped
	if (flipped == true) {
		this->cardID = this->rank + this->suit;
	}
	else {
		this->cardID = "**";
	}

	if (suit == "H" || suit == "D") {
		this->colour = "red";
	}
	else {
		this->colour = "black";
	}
	
}

// Swaps flipped bool to opposite of what it current is, updates card ID
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

string Card::getColour() {
	return this->colour;
}

bool Card::getFlipped() {
	return this->flipped;
}