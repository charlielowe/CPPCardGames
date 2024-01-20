#include <iostream>
#include <vector>
#include <windows.h>
#include <conio.h>
#include "SolitaireGame.h"
#include "Card.h"
#include "Deck.h"

using namespace std;


void ShowConsoleCursor(bool showFlag);

SolitaireGame solitaire = SolitaireGame();

Deck deck = Deck();

int main() {

    ShowConsoleCursor(false);
    deck.makeDeck();
    solitaire.makeTable(&deck);   

    while (1) {
        solitaire.solitaireLoop(&deck);
    }

    return 0;
}

void ShowConsoleCursor(bool showFlag) {
    HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);

    CONSOLE_CURSOR_INFO     cursorInfo;

    GetConsoleCursorInfo(out, &cursorInfo);
    cursorInfo.bVisible = showFlag; // set the cursor visibility
    SetConsoleCursorInfo(out, &cursorInfo);
}

