#include <iostream>
#include <windows.h>
#include <conio.h>
#include <vector>
#include "Deck.h"
#include <queue>

using namespace std;

#define KEY_UP    72
#define KEY_LEFT  75
#define KEY_RIGHT 77
#define KEY_DOWN  80
#define KEY_ENTER 13
#define KEY_QUIT 8

#pragma once
class SolitaireGame
{
public:
	SolitaireGame();
	bool hasQuit = false;
	void solitaireLoop(Deck& deck); // Main code that repeatedly loops while the game is going
	void solitaireMain(Deck& deck); // Function that runs once at the start of the game to initialize everything
	void handleUserInput(int& verticalPos, int& horizontalPos, Card& firstChoice, Card& secondChoice, int& firstX, int& firstY, Deck& deck); // Function that checks what key was pressed. Handles arrow key controls
	void makeTable(Deck& deck); // Creates a 2d vector called table and fills it with ASCII art for all of the cards
	void printTable(vector<vector<string>> table); // Prints card ASCII art and changes colours
	void setTextColour(int color); // Function to change the text colour
	void setCursorPosition(int x, int y); // Function to set cursor position
	void resetChoices();
private:

};

