#include <iostream>
#include <vector>
#include <windows.h>
#include <conio.h>
#include "SolitaireGame.h"
#include "Card.h"
#include "Deck.h"
#include "BlackJackGame.h"

#pragma comment(lib, "winmm.lib")
using namespace std;

void ShowConsoleCursor(bool showFlag);


int main() {
    while (true) { // Game loop
        Deck deck = Deck(); // Create new deck
        system("cls");
        // Ask player which game they would like to play
        string strchoice; 
        bool choiceFound = false;
        cout << "Would you like to play (1)Blackjack or (2)Solitare?" << endl;
        while (choiceFound == false) { // Loop to handle if user enters something other than the options provided
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
            ShowConsoleCursor(true);
            deck.makeDeck();
            deck.shuffleDeck();
            blackjack.blackJackMain(deck);
        }
        else { // Solitaire
            SolitaireGame solitaire = SolitaireGame();
            system("cls");
            ShowConsoleCursor(false);

            // Create and shuffle the deck
            deck.makeDeck(); 
            deck.shuffleDeck();

            cout << "\n\n\n" << endl;
            
            vector<Card> cardDeck = deck.getDeck(); // Make a copy of the deck

            // Set picture cards to have different values to use them for comparrison when putting one card on top of another, since the card values have to be ascending 
            for (Card& card : cardDeck) {
                if (card.getRank() == "J") {
                    card.setValue(11);
                }
                else if (card.getRank() == "Q") {
                    card.setValue(12);
                }
                else if (card.getRank() == "K") {
                    card.setValue(13);
                }
                else if (card.getRank() == "A") {
                    card.setValue(1);
                }
            }
            deck.setDeck(cardDeck); // Replace original deck with the now modified copy
         
            solitaire.solitaireMain(deck);
            while (solitaire.hasQuit == false) { // Loop to run the game until the user quits
                solitaire.solitaireLoop(deck);

            }
        }
    }
    
    return 0;
}

// Toggle if cursor is shown or not
void ShowConsoleCursor(bool showFlag) { 
    HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);

    CONSOLE_CURSOR_INFO     cursorInfo;

    GetConsoleCursorInfo(out, &cursorInfo);
    cursorInfo.bVisible = showFlag;
    SetConsoleCursorInfo(out, &cursorInfo);
}
