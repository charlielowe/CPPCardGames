#include "Deck.h"

Deck::Deck() {
	srand(time(NULL));
}

void Deck::makeDeck() {
	for (int i = 1; i <= 13; i++) {
		if (i == 1) {
			Card h("A", "H");
			Card d("A", "D");
			Card s("A", "S");
			Card c("A", "C");
			this->cardsDeck.push_back(h);
			this->cardsDeck.push_back(d);
			this->cardsDeck.push_back(s);
			this->cardsDeck.push_back(c);
		}
		else if (i == 11) {
			Card h("J", "H");
			Card d("J", "D");
			Card s("J", "S");
			Card c("J", "C");
			this->cardsDeck.push_back(h);
			this->cardsDeck.push_back(d);
			this->cardsDeck.push_back(s);
			this->cardsDeck.push_back(c);
		}
		else if (i == 12) {
			Card h("Q", "H");
			Card d("Q", "D");
			Card s("Q", "S");
			Card c("Q", "C");
			this->cardsDeck.push_back(h);
			this->cardsDeck.push_back(d);
			this->cardsDeck.push_back(s);
			this->cardsDeck.push_back(c);
		}
		else if (i == 13) {
			Card h("K", "H");
			Card d("K", "D");
			Card s("K", "S");
			Card c("K", "C");
			this->cardsDeck.push_back(h);
			this->cardsDeck.push_back(d);
			this->cardsDeck.push_back(s);
			this->cardsDeck.push_back(c);
		}
		else {
			Card h(to_string(i), "H");
			Card d(to_string(i), "D");
			Card s(to_string(i), "S");
			Card c(to_string(i), "C");
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