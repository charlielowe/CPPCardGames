#include "Deck.h"

Deck::Deck() {
	
}

// Function that loops 13 times and each time adds 4 cards to deck (1 for each suit). Manually updates card rank for picture cards
void Deck::makeDeck() {
	for (int i = 1; i <= 13; i++) {
		if (i == 1) {
			Card h("A", "H", false);
			Card d("A", "D", false);
			Card s("A", "S", false);
			Card c("A", "C", false);
			this->mCardsDeck.push_back(h);
			this->mCardsDeck.push_back(d);
			this->mCardsDeck.push_back(s);
			this->mCardsDeck.push_back(c);
		}
		else if (i == 11) {
			Card h("J", "H", false);
			Card d("J", "D", false);
			Card s("J", "S", false);
			Card c("J", "C", false);
			this->mCardsDeck.push_back(h);
			this->mCardsDeck.push_back(d);
			this->mCardsDeck.push_back(s);
			this->mCardsDeck.push_back(c);
		}
		else if (i == 12) {
			Card h("Q", "H", false);
			Card d("Q", "D", false);
			Card s("Q", "S", false);
			Card c("Q", "C", false);
			this->mCardsDeck.push_back(h);
			this->mCardsDeck.push_back(d);
			this->mCardsDeck.push_back(s);
			this->mCardsDeck.push_back(c);
		}
		else if (i == 13) {
			Card h("K", "H", false);
			Card d("K", "D", false);
			Card s("K", "S", false);
			Card c("K", "C", false);
			this->mCardsDeck.push_back(h);
			this->mCardsDeck.push_back(d);
			this->mCardsDeck.push_back(s);
			this->mCardsDeck.push_back(c);
		}
		else {
			Card h(to_string(i), "H", false);
			Card d(to_string(i), "D", false);
			Card s(to_string(i), "S", false);
			Card c(to_string(i), "C", false);
			this->mCardsDeck.push_back(h);
			this->mCardsDeck.push_back(d);
			this->mCardsDeck.push_back(s);
			this->mCardsDeck.push_back(c);
		}

		
	}
}

// Shuffles deck
void Deck::shuffleDeck() {
	srand(time(NULL)); // Sets random seed to the value of time so it's always different
	random_device rd;
	mt19937 g(rd());

	std::shuffle(this->mCardsDeck.begin(), this->mCardsDeck.end(), g);
}

// Returns deck
vector<Card> Deck::getDeck() {
	return(this->mCardsDeck);
}

// Returns card from top of deck and removes it from deck vector
Card Deck::drawCard() {
	Card drawnCard = this->mCardsDeck.back();
	this->mCardsDeck.pop_back();
	return drawnCard;
}

// Replaces the deck with new deck passed into function
void Deck::setDeck(vector<Card> deck) {
	this->mCardsDeck = deck;
}

// Adds a card to the deck
void Deck::addCard(Card card) {
	this->mCardsDeck.push_back(card);
}