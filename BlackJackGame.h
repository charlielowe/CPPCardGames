#pragma once
#include "Deck.h"
#include "Card.h"
#include <vector>
#include <iostream>
#include <conio.h>

class BlackJackGame
{
public:
	BlackJackGame();
	void blackJackMain(Deck& deck);
	void makeAscii(vector<Card>& Hand);
	void printHand(vector<vector<string>>& table, vector<Card>& Hand);
	void aceCheck(Card& tempCard, int& total);
};

