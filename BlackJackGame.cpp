#include "BlackJackGame.h"
using namespace std;


BlackJackGame::BlackJackGame() {

};

void BlackJackGame::blackJackMain(Deck& deck) {

    vector<Card> playerHand;
    vector<Card> dealerHand;
    int playerTotal;
    int dealerTotal;

    bool quit = false;
	// Get given 2 cards
	// If values of both are over 21, bust
	// Choose to draw a new card or hold
	// If new card, check if over 21 again
	// If hold, reveal dealers cards
	// If players total is higher than dealers total, player wins. Else, dealer wins

	// Draw first 2 cards
    cout << endl;
    dealerHand.push_back(deck.drawCard());
    dealerHand.push_back(deck.drawCard());
    Card tempPlayerCard = deck.drawCard();
    tempPlayerCard.flip();
	playerHand.push_back(tempPlayerCard);
    tempPlayerCard = deck.drawCard();
    tempPlayerCard.flip();
	playerHand.push_back(tempPlayerCard);

    while (!quit) {
        
        playerTotal = 0;
        dealerTotal = 0;
        for (Card& card : playerHand) {
            playerTotal += card.getValue();
        }
        for (Card& card : dealerHand) {
            dealerTotal += card.getValue();
        }
        if (playerTotal > 21) {
            cout << "Your new total is " << playerTotal << endl;
            cout << "BUST! You lose!" << endl;
            quit = true;
        }
        else {
            cout << "Dealer Hand: " << endl;
            makeAscii(dealerHand);
            cout << endl;
            cout << endl;
            cout << "Player Hand: Total = " << playerTotal << endl;
            makeAscii(playerHand);
            cout << endl;
            cout << "Would you like to draw or hold?" << endl;
            bool choiceFound = false;
            string choice;
            while (choiceFound != true) {
                cin.clear();
                cin.sync();
                cout << "Enter 1 to draw or 2 to hold: ";
                getline(cin, choice);
                if (choice != "1" && choice != "2") {
                    cout << "Not an option." << endl;
                }
                else {
                    choiceFound = true;
                }
            }
            if (stoi(choice) == 1) {
                tempPlayerCard = deck.drawCard();
                tempPlayerCard.flip();
                if (tempPlayerCard.getRank() == "A") {
                    string aceChoice;
                    bool aceChoiceFound = false;
                    while (!aceChoiceFound) {
                        cin.clear();
                        cin.sync();
                        cout << "You drew an Ace, would you like the value to be 1 or 11? ";
                        getline(cin, aceChoice);
                        if ((aceChoice) == "1") {
                            tempPlayerCard.setValue(1);
                            aceChoiceFound = true;
                            system("cls");
                        }
                        else if ((aceChoice) == "11") {
                            tempPlayerCard.setValue(11);
                            aceChoiceFound = true;
                            system("cls");
                        }
                        else {
                            cout << "That wasn't an option." << endl;
                        }
                    }
                    
                }
                else {
                    system("cls");
                    cout << "You drew a " << tempPlayerCard.getID() << endl;
                }
                playerHand.push_back(tempPlayerCard);
            }
            else {
                system("cls");
                cout << "Your card total is: " << playerTotal << endl;
            }
            if (dealerTotal < 16) {
                dealerHand.push_back(deck.drawCard());
            }
            if (stoi(choice) == 2) {
                cout << "The dealer's total is: " << dealerTotal << endl;
                cout << "Dealer Hand: " << endl;
                for (Card& card : dealerHand) {
                    card.flip();
                }
                makeAscii(dealerHand);
                cout << endl;
                cout << endl;
                cout << "Player Hand: Total = " << playerTotal << endl;
                makeAscii(playerHand);
                if (dealerTotal <= 21) {
                    if (playerTotal > dealerTotal) {
                        cout << "You win!!" << endl;
                        quit = true;
                    }
                    else {
                        cout << "You lose!" << endl;
                        quit = true;
                    }
                }
                else {
                    cout << "You win!!" << endl;
                    quit = true;
                }
            }
        }
        

    }
    
    cout << "Press a key to continue.";
    _getch();
    system("cls");
}

void BlackJackGame::makeAscii(vector<Card>& Hand){


    // Create a vector of cards
    vector<vector<string>> table;

    for (Card& card : Hand) {
        vector<string> col;
        col.push_back("  _______  ");
        if ((card.getID()).substr(0, 2) == "10") {
            col.push_back(" |" + card.getID() + "    | ");
        }
        else {
            col.push_back(" |" + card.getID() + "     | ");
        }
        col.push_back(" |       | ");
        col.push_back(" |       | ");
        col.push_back(" |_______| ");
        table.push_back(col);
    }
    printHand(table, Hand);
    
}

void BlackJackGame::printHand(vector<vector<string>>& table, vector<Card>& Hand) {

    for (int i = 0; i < 5; i++) { // Loops for the ammount of strings inside cards[0] (which is card1) 
        for (int x = 0; x < Hand.size(); x++) { // For every col in table array
            // Adjust spacing between cards as needed
            cout << table[x][i] << "   ";

        }
        cout << '\n';
    }
}