#include "BlackJackGame.h"

using namespace std;

BlackJackGame::BlackJackGame() {

};

void BlackJackGame::blackJackMain(Deck& deck) {

    // Creates vectors for different hands
    vector<Card> playerHand;
    vector<Card> playerHand2;
    vector<Card> dealerHand;

    // Initializes variables
    int playerTotal = 0;
    int playerTotal2 = 0;
    int dealerTotal = 0;
    bool hasSplit = false;
    bool quit = false;
    bool firstHandAlive = true;
    bool secondHandAlive = false;
	
    drawCard(dealerHand, dealerTotal, deck); // Draw a card for dealer

    // Draws 2 cards for the player
    Card tempCard1 = drawCard(playerHand, playerTotal, deck);
    Card tempCard2 = drawCard(playerHand, playerTotal, deck);

    // If cards have the same rank, offer player to split deck
    if (tempCard1.getRank() == tempCard2.getRank()) {

        // Printing hands
        calculateTotal(dealerTotal,dealerHand);
        cout << "Dealer Hand: Total = " << dealerTotal << endl;
        makeAscii(dealerHand);
        cout << endl;
        cout << endl;
        calculateTotal(playerTotal, playerHand);
        cout << "Player Hand: Total = " << playerTotal << endl;
        makeAscii(playerHand);
        cout << endl;
        cout << endl;

        // Ask player if they want to split
        cout << "You drew 2 of the same card, would you like to split your hand?" << endl;
        bool choiceFound = false;
        string playerChoice;
        while (!choiceFound) {
            cout << "Press 1 if you want to split, and 2 if you don't." << endl;
            getline(cin, playerChoice);
            if (playerChoice == "1") {
                cout << "You have split your hand in 2." << endl;

                // Remove card from first hand and adds it to second hand
                playerHand.pop_back();
                playerHand2.push_back(tempCard2);

                choiceFound = true;
                hasSplit = true;
                secondHandAlive = true;
            }
            else if (playerChoice == "2") {
                cout << "You will continue with 1 hand." << endl;
                choiceFound = true;
            }
            else {
                cout << "That wasn't an option." << endl;
            }
        }
        system("cls");
        
    }
    bool firstHandHeld = false;

    // Main game loop
    while (!quit) { 

        // If first hand hasn't gone over 21
        if (firstHandAlive) {
            calculateTotal(playerTotal, playerHand); // Calculate total of first hand
        }

        // If the player has split their hand, and the second deck hasn't gone over 21, calculate total of the second hand
        if (hasSplit && secondHandAlive) {
            calculateTotal(playerTotal2, playerHand2);
        }

        calculateTotal(dealerTotal, dealerHand); // Calculate dealer's total

        // If player has gone over 21 and the first hand is still alive
        if (playerTotal > 21 && firstHandAlive) {

            // If deck has been split, say first hand is bust
            if (hasSplit) {
                cout << "Your new total for your first hand is " << playerTotal << endl;
                cout << "Your first hand is bust!" << endl;
                firstHandAlive = false;

                // If second hand is also over 21, end game
                if (!secondHandAlive) {
                    quit = true;
                }
            }
            
            // If deck hasn't been split, tell player they are bust and end game
            else {
                cout << "Your new total is " << playerTotal << endl;
                cout << "BUST! You lose!" << endl;
                quit = true;
            }
        }

        // If first deck isn't bust but second deck is, tell player second deck is bust
        else if (hasSplit && playerTotal2 > 21 && secondHandAlive) {
            cout << "Your new total for your second hand is " << playerTotal2 << endl;
            cout << "Your second deck is bust!" << endl;
            cout << "You lose your second hand!!" << endl;
            secondHandAlive = false;
            
        }

        // If first deck isn't bust but has been held, and second deck has gone bust
        else if (hasSplit && !secondHandAlive && firstHandHeld) {

            // If player's first hand total is above dealer's total, tell player first hand has been won
            if (playerTotal > dealerTotal && firstHandAlive) {
                cout << "Dealer Hand: Total = " << dealerTotal << endl;
                makeAscii(dealerHand);
                cout << endl;
                cout << endl;
                cout << "Player Hand: Total = " << playerTotal << endl;
                makeAscii(playerHand);
                cout << endl;
                cout << endl;
                cout << "Your first hand's score is higher than the dealers." << endl;
                cout << "You win your first hand!!" << endl;

            }

            // If player's first hand total is less than or equal to dealer's total
            else if (playerTotal <= dealerTotal && firstHandAlive) {

                // Print ascii
                cout << "Dealer Hand: Total = " << dealerTotal << endl;
                makeAscii(dealerHand);
                cout << endl;
                cout << endl;
                cout << "Player Hand: Total = " << playerTotal << endl;
                makeAscii(playerHand);
                cout << endl;
                cout << endl;

                // If dealer is bust, win both hands
                if (dealerTotal > 21) {
                    cout << "The dealer went bust." << endl;
                    cout << "You win both hands!!" << endl;
                }

                // If not, player loses first hand
                else {
                    cout << "Your first hand's score is lower than or equal to the dealers." << endl;
                    cout << "You lose your first hand!!" << endl;
                }
                
            }

            quit = true; // End the game
        }
        else {
            
            // Calculate totals and print ascii for hands
            cout << "Dealer Hand: Total = " << dealerTotal << endl;
            makeAscii(dealerHand);
            cout << endl;
            cout << endl;
            cout << "Player Hand: Total = " << playerTotal << endl;
            makeAscii(playerHand);
            cout << endl;
            cout << endl;

            // If player has split and both hands are still in the game, also print second hand
            if (hasSplit && secondHandAlive) { 
                cout << "Player Hand 2: Total = " << playerTotal2 << endl;
                makeAscii(playerHand2);
                cout << endl;
                cout << endl;
                
                // If first hand is alive and hasn't been held, ask the user if they want to draw or hold for it
                if (firstHandAlive && !firstHandHeld) {
                    cout << "Would you like to draw or hold for your first hand?" << endl;
                    string choice = makeChoice();

                    // If player chooses to draw for first hand
                    if (stoi(choice) == 1) {
                        system("cls");
                        cout << "You drew a " << drawCard(playerHand, playerTotal, deck).getID() << endl;

                        // Calculate totals and make ascii again
                        calculateTotal(playerTotal, playerHand);
                        cout << "Dealer Hand: Total = " << dealerTotal << endl;
                        makeAscii(dealerHand);
                        cout << endl;
                        cout << endl;
                        cout << "Player Hand: Total = " << playerTotal << endl;
                        makeAscii(playerHand);
                        cout << endl;
                        cout << endl;
                        cout << "Player Hand 2: Total = " << playerTotal2 << endl;
                        makeAscii(playerHand2);
                        cout << endl;
                        cout << endl;
                    }

                    // If player chooses to hold first hand
                    else if (stoi(choice) == 2) {
                        system("cls");

                        // Print ascii
                        cout << "You hold your first hand at a total of " << playerTotal << endl;
                        cout << "Dealer Hand: Total = " << dealerTotal << endl;
                        makeAscii(dealerHand);
                        cout << endl;
                        cout << endl;
                        cout << "Player Hand: Total = " << playerTotal << endl;
                        makeAscii(playerHand);
                        cout << endl;
                        cout << endl;
                        cout << "Player Hand 2: Total = " << playerTotal2 << endl;
                        makeAscii(playerHand2);
                        cout << endl;
                        cout << endl;
                        firstHandHeld = true;
                    }
                }
                
                // Ask the player if they'd like to hold or draw for their second hand
                cout << "Would you like to draw or hold for your second hand?" << endl;
                string choice2 = makeChoice();

                // Player chose draw
                if (stoi(choice2) == 1) {
                    system("cls");
                    cout << "You drew a " << drawCard(playerHand2, playerTotal2, deck).getID() << endl;

                    // If dealer's total is less than 17, they draw a card
                    if (dealerTotal <= 16) {
                        drawCard(dealerHand, dealerTotal, deck);
                        calculateTotal(dealerTotal, dealerHand);
                    }
                }

                // Player chose hold
                else if (stoi(choice2) == 2) {
                    system("cls");
                    cout << "You hold your second hand at a total of " << playerTotal2 << endl;
                    if (firstHandHeld) {

                        // If dealer's total is less than 17, they draw a card
                        if (dealerTotal <= 16) {
                            drawCard(dealerHand, dealerTotal, deck);
                            calculateTotal(dealerTotal, dealerHand);
                        }

                        // Print ascii
                        cout << "Dealer Hand: Total = " << dealerTotal << endl;
                        makeAscii(dealerHand);
                        cout << endl;
                        cout << endl;
                        cout << "Player Hand 1: Total = " << playerTotal << endl;
                        makeAscii(playerHand);
                        cout << endl;
                        cout << endl;
                        cout << "Player Hand 2: Total = " << playerTotal2 << endl;
                        makeAscii(playerHand2);
                        cout << endl;
                        cout << endl;

                        // If dealer isn't bust
                        if (dealerTotal <= 21) {

                            // Check if player's first hand score is higher or lower than dealer's, or if it's bust
                            if (playerTotal > dealerTotal && firstHandAlive) {
                                cout << "Your first hand's score is higher than the dealers." << endl;
                                cout << "You win your first hand!!" << endl;

                            }
                            else if(playerTotal <= dealerTotal && firstHandAlive){
                                cout << "Your first hand's score is lower than or equal to the dealers." << endl;
                                cout << "You lose your first hand!!" << endl;
                            }
                            else {
                                cout << "Your first hand went bust!" << endl;
                                cout << "You lose your first hand!!" << endl;
                            }

                            // Check if second hand is higher or lower than dealer's
                            if (playerTotal2 > dealerTotal) {
                                cout << "Your second hand's score is higher than the dealers." << endl;
                                cout << "You win your second hand!!" << endl;

                            }
                            else {
                                cout << "Your second hand's score is lower than or equal to the dealers." << endl;
                                cout << "You lose your second hand!!" << endl;
                            }
                        }
                        else {
                            cout << "The dealer went bust." << endl;
                            cout << "You win both hands!!" << endl;
                           
                        }
                        quit = true;
                    }
                    
                }
            }

            // If player hasn't split or if they have but the second hand is bust
            else {
                
                // Ask if the player wants to draw or hold
                cout << "Would you like to draw or hold?" << endl;
                string choice = makeChoice();

                // Draw
                if (stoi(choice) == 1) {
                    system("cls");
                    cout << "You drew a " << drawCard(playerHand, playerTotal, deck).getID() << endl;
                    if (dealerTotal <= 16) {
                        drawCard(dealerHand, dealerTotal, deck);
                        calculateTotal(dealerTotal, dealerHand);
                    }
                }

                // Hold
                else if (stoi(choice) == 2) {
                    if (dealerTotal <= 16) {
                        drawCard(dealerHand, dealerTotal, deck);
                        calculateTotal(dealerTotal, dealerHand);
                    }
                    system("cls");

                    // Print ascii
                    cout << "Dealer Hand: Total = " << dealerTotal << endl;

                    makeAscii(dealerHand);
                    cout << endl;
                    cout << endl;
                    cout << "Player Hand: Total = " << playerTotal << endl;
                    makeAscii(playerHand);

                    // If dealer isn't bust
                    if (dealerTotal <= 21) {

                        // Check if player's total is higher or lower than dealers
                        if (playerTotal > dealerTotal) {
                            cout << "Your score is higher than the dealers." << endl;
                            cout << "You win!!" << endl;
                            quit = true;
                        }
                        else {
                            cout << "Your score is lower than or equal to the dealers." << endl;
                            cout << "You lose!" << endl;
                            quit = true;
                        }
                    }
                    else {
                        cout << "The dealer went bust." << endl;
                        cout << "You win!!" << endl;
                        quit = true;
                    }
                }

            }
        }
        
    }
    
    // Wait for player to press a key, then clear the console
    cout << "Press a key to continue.";
    _getch();
    system("cls");
}

// Function to get input for if the player wants to hold or draw
string BlackJackGame::makeChoice(){
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
    return choice;
}

// Adds values of all cards in hand to total
void BlackJackGame::calculateTotal(int& total, vector<Card>& hand) {
    total = 0;
    for (Card& card : hand) {
        total += card.getValue();
    }
}

// Draws a card from the deck
Card BlackJackGame::drawCard(vector<Card>& hand, int total, Deck& deck) {
    Card tempPlayerCard = deck.drawCard();
    tempPlayerCard.flip();

    // For each card in hand, if hand total + value of new card is over 21, check if card is ace, if it is set value of it to 1
    for (Card& card : hand) {
        if (total + tempPlayerCard.getValue() > 21) {
            if (card.getRank() == "A") {
                card.setValue(1);

                // Recalculate total
                total = 0;
                for (Card& card : hand) {
                    total += card.getValue();
                }
            }
        }
    }
    hand.push_back(tempPlayerCard); // Push card to hand
    return tempPlayerCard;
}


// Make ascii for each card in hand
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
        table.push_back(col); // Pushes each column to vector "table"
    }
    printHand(table, Hand);
    
}

// Function to print ascii 
void BlackJackGame::printHand(vector<vector<string>>& table, vector<Card>& Hand) {

    for (int i = 0; i < 5; i++) { // Loops for the amount of strings in each column
        for (int x = 0; x < Hand.size(); x++) { // For every col in table array
            cout << table[x][i] << "   ";
        }
        cout << '\n';
    }
}

