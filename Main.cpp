#include <iostream>
#include <vector>
#include <windows.h>
#include <conio.h>
#include "SolitaireGame.h"
#include "Card.h"
#include "Deck.h"
#include "BlackJackGame.h"

using namespace std;

void ShowConsoleCursor(bool showFlag);




Deck deck = Deck();

int main() {
    while (true) {
        string strchoice;
        bool choiceFound = false;
        cout << "Would you like to play (1)Blackjack or (2)Solitare?" << endl;
        while (choiceFound == false) {
            cin.clear();
            cin.sync();
            cout << "Enter 1 or 2: ";
            getline(cin, strchoice);
            if (strchoice != "1" && strchoice != "2") {
                cout << "Not an option." << endl;
            }
            else {
                choiceFound = true;
            }
        }
        if (stoi(strchoice) == 1) { // Blackjack
            BlackJackGame blackjack = BlackJackGame();
            system("cls");
            deck.makeDeck();
            blackjack.blackJackMain(deck);
        }
        else { // Solitaire
            SolitaireGame solitaire = SolitaireGame();
            system("cls");
            ShowConsoleCursor(false);
            deck.makeDeck();
            solitaire.makeTable(&deck);
            solitaire.solitaireMain(&deck);
            while (1) {
                solitaire.solitaireLoop(&deck);
            }
        }
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

