#include "Deck.h"

Deck::Deck() {
	srand(time(NULL));
}

void Deck::makeDeck() {
	for (int i = 1; i <= 13; i++) {
		if (i == 1) {
			Card h("A", "H", false);
			Card d("A", "D", false);
			Card s("A", "S", false);
			Card c("A", "C", false);
			this->cardsDeck.push_back(h);
			this->cardsDeck.push_back(d);
			this->cardsDeck.push_back(s);
			this->cardsDeck.push_back(c);
		}
		else if (i == 11) {
			Card h("J", "H", false);
			Card d("J", "D", false);
			Card s("J", "S", false);
			Card c("J", "C", false);
			this->cardsDeck.push_back(h);
			this->cardsDeck.push_back(d);
			this->cardsDeck.push_back(s);
			this->cardsDeck.push_back(c);
		}
		else if (i == 12) {
			Card h("Q", "H", false);
			Card d("Q", "D", false);
			Card s("Q", "S", false);
			Card c("Q", "C", false);
			this->cardsDeck.push_back(h);
			this->cardsDeck.push_back(d);
			this->cardsDeck.push_back(s);
			this->cardsDeck.push_back(c);
		}
		else if (i == 13) {
			Card h("K", "H", false);
			Card d("K", "D", false);
			Card s("K", "S", false);
			Card c("K", "C", false);
			this->cardsDeck.push_back(h);
			this->cardsDeck.push_back(d);
			this->cardsDeck.push_back(s);
			this->cardsDeck.push_back(c);
		}
		else {
			Card h(to_string(i), "H", false);
			Card d(to_string(i), "D", false);
			Card s(to_string(i), "S", false);
			Card c(to_string(i), "C", false);
			this->cardsDeck.push_back(h);
			this->cardsDeck.push_back(d);
			this->cardsDeck.push_back(s);
			this->cardsDeck.push_back(c);
		}

		
	}
}

vector<Card> Deck::getDeck() {
	return(this->cardsDeck);
}

Card Deck::drawCard() {
	int randomIndex = rand() % this->cardsDeck.size();
	Card drawnCard = this->cardsDeck[randomIndex];
	this->cardsDeck.erase(this->cardsDeck.begin() + randomIndex);
	return drawnCard;
}