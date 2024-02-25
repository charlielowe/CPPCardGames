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
	void blackJackMain(Deck& deck); // Function that contains all main game logic
	void makeAscii(vector<Card>& Hand); // Function to create ascii art for cards
	void printHand(vector<vector<string>>& table, vector<Card>& Hand); // Prints card ascii
	Card drawCard(vector<Card>& hand, int total, Deck& deck); // Draws a card from the deck
	void calculateTotal(int& total, vector<Card>& hand); // Calculates the hand total
	string makeChoice(); // Asking the player if they want to hold or draw
};

