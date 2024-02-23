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

#pragma once
class SolitaireGame
{
public:
	SolitaireGame();

	void solitaireLoop(Deck& deck);
	void solitaireMain(Deck& deck);
	void useArrowKeys(int* verticalPos, int* horizontalPos, Card* firstChoice, Card* secondChoice, int* firstX, int* firstY);
	void makeTable(Deck& deck);
	void printTable(vector<vector<string>> table);
	void textColor(int color);

private:

};

