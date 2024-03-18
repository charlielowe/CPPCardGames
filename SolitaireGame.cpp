#include "SolitaireGame.h"
#include "Card.h"
#include <stack>

using namespace std;

const int rows = 7;
const int cols = 19;

int verticalPos;
int horizontalPos;
int firstX;
int firstY;
int secondX;
int secondY;


Card placeholder = Card(" ", " ", true);
Card emtpyH = Card(" ", "H", true);
Card emtpyD = Card(" ", "D", true);
Card emtpyS = Card(" ", "S", true);
Card emtpyC = Card(" ", "C", true);
Card emtpy = Card(" ", " ", false);
Card emtpySpace = Card("S", "S", true);
Card kingSpace = Card("K", "K", true);

// Stacks for ace piles

stack<Card> acePileH;
stack<Card> acePileD;
stack<Card> acePileS;
stack<Card> acePileC;
stack<Card> deckPile;

Card arr1[cols] = { emtpyH, placeholder, placeholder, placeholder, placeholder, placeholder, placeholder, placeholder, placeholder, placeholder, placeholder, placeholder, placeholder, placeholder, placeholder, placeholder, placeholder, placeholder , placeholder };
Card arr2[cols] = { emtpyD, placeholder, placeholder, placeholder, placeholder, placeholder, placeholder, placeholder, placeholder, placeholder, placeholder, placeholder, placeholder, placeholder, placeholder, placeholder, placeholder, placeholder, placeholder };
Card arr3[cols] = { emtpyS, placeholder, placeholder, placeholder, placeholder, placeholder, placeholder, placeholder, placeholder, placeholder, placeholder, placeholder, placeholder, placeholder, placeholder, placeholder, placeholder, placeholder, placeholder };
Card arr4[cols] = { emtpyC, placeholder, placeholder, placeholder, placeholder, placeholder, placeholder, placeholder, placeholder, placeholder, placeholder, placeholder, placeholder, placeholder, placeholder, placeholder, placeholder, placeholder, placeholder };
Card arr5[cols] = { emtpySpace, placeholder, placeholder, placeholder, placeholder, placeholder, placeholder, placeholder, placeholder, placeholder, placeholder, placeholder, placeholder, placeholder, placeholder, placeholder, placeholder, placeholder, placeholder };
Card arr6[cols] = { emtpySpace, placeholder, placeholder, placeholder, placeholder, placeholder, placeholder, placeholder, placeholder, placeholder, placeholder, placeholder, placeholder, placeholder, placeholder, placeholder, placeholder, placeholder, placeholder };
Card arr7[cols] = { emtpy, placeholder, placeholder, placeholder, placeholder, placeholder, placeholder, placeholder, placeholder, placeholder, placeholder, placeholder, placeholder, placeholder, placeholder, placeholder, placeholder, placeholder, placeholder };
vector<Card*> array2D = { arr1, arr2, arr3, arr4, arr5, arr6, arr7 };

bool isFirstPass;
bool deckEmtpy = false;

Card firstChoice = emtpy;
Card secondChoice = emtpy;

SolitaireGame::SolitaireGame(){
    verticalPos = 0;
    horizontalPos = 0;
    firstX = 0;
    firstY = 0;
    secondX = 0;
    secondY = 0;
    deckEmtpy = false;
    deckPile.push(emtpySpace);
}


void SolitaireGame::solitaireMain(Deck& deck) {
    isFirstPass = true;
    makeTable(deck);
   

    // Sets ace pile's to have value of 0 so only aces can be put on them
    arr1[0].setValue(0);
    arr2[0].setValue(0);
    arr3[0].setValue(0);
    arr4[0].setValue(0);

    // Add empty ace pile cards to ace pile stacks
    emtpyH.setValue(0);
    emtpyD.setValue(0);
    emtpyS.setValue(0);
    emtpyC.setValue(0);
    acePileH.push(emtpyH);
    acePileD.push(emtpyD);
    acePileS.push(emtpyS);
    acePileC.push(emtpyC);
  
}

void SolitaireGame::solitaireLoop(Deck& deck) {
    useArrowKeys(verticalPos, horizontalPos, firstChoice, secondChoice, firstX, firstY, deck);
    makeTable(deck);

}

void SolitaireGame::useArrowKeys(int& verticalPos, int& horizontalPos, Card& firstChoice, Card& secondChoice, int& firstX, int& firstY, Deck& deck) {
    int c, ex;
    c = _getch();



    if (c && c != 224)
    {
        if (c == KEY_ENTER) { // User presses enter the first time to choose a card
            
            if (horizontalPos == 6 && verticalPos == 0) {
                if (deckEmtpy == true) {

                    while(deckPile.size() != 1){
                        deck.addCard(deckPile.top());
                        deckPile.pop();
                    }
                    array2D[5][0] = deckPile.top();
                    array2D[6][0].flip();
                    deckEmtpy = false;
                }
                else{
                    Card tempCard = deck.drawCard();
                    if (tempCard.getFlipped() != true) {
                        tempCard.flip();
                    }
                    
                    deckPile.push(tempCard);
                    array2D[5][0] = deckPile.top();
                    if (deck.getDeck().size() == 0) {
                        array2D[6][0] = kingSpace;
                        //array2D[6][0].flip();
                        deckEmtpy = true;
                    }
                }
                
            }
            else if (array2D[horizontalPos][verticalPos].getID() != "**") { // If card isn't flipped or one of the empty ace piles
              
                int y = _getch();
                if (y == KEY_ENTER) { // Player presses enter again to confrim the card

                    // firstChoice is set to card "emtpy" by default which has an ID of ** so checking to make sure the first choice hasn't already been selected, also making sure firstChoice isn't one of the ace stacks
                    if ((firstChoice).getID() == "**" && array2D[horizontalPos][verticalPos].getID() != " H" && array2D[horizontalPos][verticalPos].getID() != " D" && array2D[horizontalPos][verticalPos].getID() != " S" && array2D[horizontalPos][verticalPos].getID() != " C") { 
                        firstChoice = array2D[horizontalPos][verticalPos]; // Sets firstChoice to card currently selected
                        firstX = horizontalPos; 
                        firstY = verticalPos;
                    }

                    // if this is the players first choice and it is one of the ace stacks, tell player that isn't allowed
                    else if((firstChoice).getID() == "**" && (array2D[horizontalPos][verticalPos].getID() == " H" || array2D[horizontalPos][verticalPos].getID() == " D" || array2D[horizontalPos][verticalPos].getID() == " S" || array2D[horizontalPos][verticalPos].getID() == " C")) {
                        cout << "You can't select one of the ace stacks as your first choice! Press a key to continue..." << endl;
                        _getch();
                        system("cls");
                    }
                    else { // If first choice has already been set
                        if (horizontalPos == 5 && verticalPos == 0) {
                            cout << "You can't put a card on the deck pile! Press a key to continue..." << endl;
                            firstChoice = emtpy;
                            secondChoice = emtpy;
                            _getch();
                            system("cls");
                        }
                        else {
                            secondChoice = array2D[horizontalPos][verticalPos]; // Second choice is set to the selected card
                            secondX = horizontalPos;
                            secondY = verticalPos;

                            // If player selects one of the ace piles as their second choice, make sure move is valid ----------------------------------------------
                            if ((verticalPos == 0) && (horizontalPos == 0 || horizontalPos == 1 || horizontalPos == 2 || horizontalPos == 3)) {
                                if (array2D[firstX][firstY+1].getID() != "  ") { // If the card they chose has any cards on top of it
                                    cout << "You can't add a card to the ace stack if it has any cards on top of it!" << endl;
                                    cout << "Press a key to continue..." << endl;
                                    firstChoice = emtpy;
                                    secondChoice = emtpy;
                                    _getch();
                                    system("cls");
                            }
                            else {
                                if (firstChoice.getSuit() == secondChoice.getSuit()) {
                                    if ((firstChoice.getValue() - 1) == secondChoice.getValue()) {
                                        switch (horizontalPos) {
                                        case 0:
                                            acePileH.push(firstChoice);
                                            break;
                                        case 1:
                                            acePileD.push(firstChoice);
                                            break;
                                        case 2:
                                            acePileS.push(firstChoice);
                                            break;
                                        case 3:
                                            acePileC.push(firstChoice);
                                            break;
                                        }



                                        array2D[horizontalPos][verticalPos] = firstChoice; // Sets the card below current card to be the first choice, aka move first card below second card
                                        if (firstX == 5 && firstY == 0) {
                                            deckPile.pop();
                                            array2D[firstX][firstY] = deckPile.top();
                                            

                                        }
                                        else {
                                            if (firstY == 2) {
                                                array2D[firstX][firstY] = kingSpace; // Sets where the first card originally was to a blank card since it's been moved

                                            }
                                            else {
                                                array2D[firstX][firstY] = placeholder; // Sets where the first card originally was to a blank card since it's been moved

                                            }

                                        }


                                        if (array2D[firstX][firstY - 1].getID() == "**") { // If card below where original card was flipped, unflip it since there now isn't a card ontop of it
                                            array2D[firstX][firstY - 1].flip();
                                        }
                                        firstChoice = emtpy;
                                        secondChoice = emtpy;
                                    }
                                    else {
                                        cout << "Cards have to be added to ace stacks in ascending value!" << endl;
                                        cout << "Press a key to continue..." << endl;
                                        firstChoice = emtpy;
                                        secondChoice = emtpy;
                                        _getch();
                                        system("cls");
                                    }
                                }
                                else {
                                    cout << "Cards added to the ace stack need to have the same suit as the stack!" << endl;
                                    cout << "Press a key to continue..." << endl;
                                    firstChoice = emtpy;
                                    secondChoice = emtpy;
                                    _getch();
                                    system("cls");
                                }
                            }
                            }
                            else {
                                // If the cards are the same colour, don't move second card
                                if (firstChoice.getColour() == secondChoice.getColour()) {
                                    cout << "Cards must be alternating in colour. Press a key to continue." << endl;
                                    firstChoice = emtpy;
                                    secondChoice = emtpy;
                                    _getch();
                                    system("cls");
                                }

                                // If second choice doesn't have a value of 1 higher than first choice then don't move second card
                                else if ((firstChoice.getValue() + 1) != secondChoice.getValue()) {
                                    cout << "Cards must be ascending in value. Press a key to continue." << endl;
                                    firstChoice = emtpy;
                                    secondChoice = emtpy;
                                    _getch();
                                    system("cls");
                                }
                                else if ((array2D[secondX][secondY + 1]).getID() != "  ") {
                                    cout << "This card already has a card on top of it! Press a key to continue." << endl;
                                    firstChoice = emtpy;
                                    secondChoice = emtpy;
                                    _getch();
                                    system("cls");
                                }
                                else {
                                    array2D[horizontalPos][verticalPos + 1] = firstChoice; // Sets the card below current card to be the first choice, aka move first card below second card


                                    int i = 1;
                                    // Sets the card below current card to be the first choice, aka move first card below second card

                                    while (array2D[firstX][firstY + i].getID() != "  ") {
                                        array2D[horizontalPos][verticalPos + 1 + i] = array2D[firstX][firstY + i];
                                        array2D[firstX][firstY + i] = placeholder; // Sets where the first card originally was to a blank card since it's been moved
                                        i++;
                                    }


                                    // If a card has just been moved off an ace stack, show the card below it in the stack
                                    if ((firstY == 0) && (firstX == 0 || firstX == 1 || firstX == 2 || firstX == 3)) {
                                        switch (firstX) {
                                        case 0:
                                            acePileH.pop();
                                            array2D[firstX][firstY] = acePileH.top();
                                            break;
                                        case 1:
                                            acePileD.pop();
                                            array2D[firstX][firstY] = acePileD.top();
                                            break;
                                        case 2:
                                            acePileS.pop();
                                            array2D[firstX][firstY] = acePileS.top();
                                            break;
                                        case 3:
                                            acePileC.pop();
                                            array2D[firstX][firstY] = acePileC.top();
                                            break;
                                        }
                                    }
                                    else {
                                        if (firstX == 5 && firstY == 0) {
                                            deckPile.pop();
                                            array2D[firstX][firstY] = deckPile.top();
                                        }
                                        else {
                                            array2D[firstX][firstY] = placeholder; // Sets where the first card originally was to a blank card since it's been moved

                                        }
                                    }

                                    if (firstY != 0) { // If card below where original card was flipped, unflip it since there now isn't a card ontop of it
                                        if (array2D[firstX][firstY - 1].getID() == "**") {
                                            array2D[firstX][firstY - 1].flip();
                                        }
                                    }
                                    firstChoice = emtpy;
                                    secondChoice = emtpy;
                                }
                            }
                        }
                        

                    }
                    
                }
            }
            else {
                cout << "You cannot select that card! Press a key to continue." << endl;
                firstChoice = emtpy;
                secondChoice = emtpy;
                _getch();
                system("cls");
            }
            
        }
        else if (c == KEY_QUIT) {
            this->hasQuit = true;
            
        }
      
    }
    else
    {
        switch (ex = _getch())

        {
        case KEY_UP     /* H */:
            if (verticalPos > 0) {
                verticalPos = verticalPos - 1;
                while (array2D[horizontalPos][verticalPos].getID() == "  ") {
                    verticalPos = verticalPos - 1;
                }
                if (array2D[horizontalPos][verticalPos].getID() == "SS") {
                    verticalPos = verticalPos + 2;
                }
            }
            break;
        case KEY_DOWN   /* K */:
            if (verticalPos < 16) {
                verticalPos = verticalPos + 1;
                if (array2D[horizontalPos][verticalPos].getID() == "  " && array2D[horizontalPos][verticalPos + 1].getID() == "  ") {
                    verticalPos = verticalPos - 1;
                }
                else {
                    while (array2D[horizontalPos][verticalPos].getID() == "  " || array2D[horizontalPos][verticalPos].getID() == "SS") {
                        verticalPos = verticalPos + 1;
                    }
                }
                
                
            }
            break;
        case KEY_LEFT   /* M */:
            if (horizontalPos > 0) {
                horizontalPos = horizontalPos - 1;
                if (horizontalPos > 0) {
                    if (array2D[horizontalPos][verticalPos].getID() == "  " && array2D[horizontalPos - 1][verticalPos].getID() == "  ") {
                        horizontalPos = horizontalPos + 1;
                    }
                    else {
                        while (array2D[horizontalPos][verticalPos].getID() == "  " || array2D[horizontalPos][verticalPos].getID() == "SS") {
                            horizontalPos = horizontalPos - 1;
                        }
                    }
                }
                else {
                    if (array2D[horizontalPos][verticalPos].getID() == "  ") {
                        horizontalPos = horizontalPos + 1;

                    }
                }
                
                
            }
            break;
        case KEY_RIGHT: /* P */
            if (horizontalPos < 6) {
                horizontalPos = horizontalPos + 1;
                if (array2D[horizontalPos][verticalPos].getID() == "  " && array2D[horizontalPos + 1][verticalPos].getID() == "  ") {
                    horizontalPos = horizontalPos - 1;
                }
                else {
                    while (array2D[horizontalPos][verticalPos].getID() == "  " || array2D[horizontalPos][verticalPos].getID() == "SS") {
                        horizontalPos = horizontalPos + 1;
                    }
                }

            }
            break;
            
        default:
            
            break;
        }
    }
}

void SolitaireGame::makeTable(Deck& deck){

    
    if (isFirstPass) {
        
        Card tempCard = deck.drawCard();
        tempCard.flip();
        arr1[2] = tempCard;
        tempCard = deck.drawCard();
        tempCard.flip();
        arr2[2] = deck.drawCard();
        arr2[3] = tempCard;
        tempCard = deck.drawCard();
        tempCard.flip();
        arr3[2] = deck.drawCard();
        arr3[3] = deck.drawCard();
        arr3[4] = tempCard;
        tempCard = deck.drawCard();
        tempCard.flip();
        arr4[2] = deck.drawCard();
        arr4[3] = deck.drawCard();
        arr4[4] = deck.drawCard();
        arr4[5] = tempCard;
        tempCard = deck.drawCard();
        tempCard.flip();
        arr5[2] = deck.drawCard();
        arr5[3] = deck.drawCard();
        arr5[4] = deck.drawCard();
        arr5[5] = deck.drawCard();
        arr5[6] = tempCard;
        tempCard = deck.drawCard();
        tempCard.flip();
        deckPile.push(tempCard);
        arr6[0] = deckPile.top();
        tempCard = deck.drawCard();
        tempCard.flip();
        arr6[2] = deck.drawCard();
        arr6[3] = deck.drawCard();
        arr6[4] = deck.drawCard();
        arr6[5] = deck.drawCard();
        arr6[5] = deck.drawCard();
        arr6[6] = deck.drawCard();
        arr6[7] = tempCard;
        tempCard = deck.drawCard();
        tempCard.flip();
        arr7[2] = deck.drawCard();
        arr7[3] = deck.drawCard();
        arr7[4] = deck.drawCard();
        arr7[5] = deck.drawCard();
        arr7[5] = deck.drawCard();
        arr7[6] = deck.drawCard();
        arr7[7] = deck.drawCard();
        arr7[8] = tempCard;
        isFirstPass = false;
    }

    array2D = { arr1, arr2, arr3, arr4, arr5, arr6, arr7 };

    // Define some sample cards (replace with your ASCII art)
    vector<string> col1;
    vector<string> col2;
    vector<string> col3;
    vector<string> col4;
    vector<string> col5;
    vector<string> col6;
    vector<string> col7;

    // Create a vector of cards
    vector<vector<string>> table = { col1, col2, col3, col4, col5, col6, col7 };
    
    for (int i = 0; i < rows; i++) {
        for (int x = 0; x < cols; x++) {
            if (array2D[i][x].getID() == "SS") {
                table[i].push_back("           ");
                table[i].push_back("           ");
                table[i].push_back("           ");
                table[i].push_back("           ");
                table[i].push_back("           ");
            }
            else if(array2D[i][x].getID() != "  " && array2D[i][x+1].getID() == "  ") {
                table[i].push_back("  _______  ");
                if (array2D[i][x].getID().substr(0,2) == "10") {
                    if (&(array2D[horizontalPos][verticalPos]) == &(array2D[i][x])) {
                        table[i].push_back(" |" + array2D[i][x].getID() + "O   | ");
                    }
                    else {
                        table[i].push_back(" |" + array2D[i][x].getID() + "    | ");
                    }
                    
                }
                else {
                    if (&(array2D[horizontalPos][verticalPos]) == &(array2D[i][x])) {
                        table[i].push_back(" |" + array2D[i][x].getID() + "O    | ");
                    }
                    else {
                        table[i].push_back(" |" + array2D[i][x].getID() + "     | ");
                    }
                }
                table[i].push_back(" |       | ");
                table[i].push_back(" |       | ");
                table[i].push_back(" |_______| ");
            }
            else if(array2D[i][x].getID() != "  " && array2D[i][x+1].getID() != "  ") {
                table[i].push_back("  _______  ");
                if ((array2D[i][x].getID()).substr(0, 2) == "10") {
                    if (&(array2D[horizontalPos][verticalPos]) == &(array2D[i][x])) {
                        table[i].push_back(" |" + array2D[i][x].getID() + "O   | ");
                    }
                    else {
                        table[i].push_back(" |" + array2D[i][x].getID() + "    | ");
                    }

                }
                else {
                    if (&(array2D[horizontalPos][verticalPos]) == &(array2D[i][x])) {
                        table[i].push_back(" |" + array2D[i][x].getID() + "O    | ");
                    }
                    else {
                        table[i].push_back(" |" + array2D[i][x].getID() + "     | ");
                    }
                }
            }
            else {
                table[i].push_back("           ");
            }
        }
        while(table[i].size() > 38) {
            table[i].pop_back();
        }
        while (table[i].size() < 38) {
            table[i].push_back("           ");
        }
    }

    //currentCard = &table[horizontalPos];
    //currentArea = verticalPos;

    // Print cards horizontally

    setCursorPosition(0, 0);
    printTable(table);
}

void SolitaireGame::printTable(vector<vector<string>> table) {
    cout << "Press enter to select your first card, then enter again to confirm it or any other key to cancel." << endl;
    cout << "firstChoice: " << firstChoice.getID() << " | secondChoice: " << secondChoice.getID() << endl;
   
    string isO, isO10, suit, suit10;
    for (int i = 0; i < 38; i++) { // Loops for the ammount of strings inside cards[0] (which is card1) 
        for (int x = 0; x < rows; x++) { // For every col in table array
            // Adjust spacing between cards as needed
            isO = table[x][i].substr(4, 1);
            isO10 = table[x][i].substr(5, 1);
            suit = table[x][i].substr(3, 1);
            suit10 = table[x][i].substr(4, 1);
            if (isO == "O" || isO10 == "O") {
                textColor(10);
                replace(table[x][i].begin(), table[x][i].end(), 'O', ' ');
            }
            else{
                textColor(15);
            }
            if ((suit == "H" || suit == "D" || suit10 == "H" || suit10 == "D") && isO != "O" && isO10 != "O") {
                textColor(15);
                cout << table[x][i].substr(0, 2);
                textColor(12);
                cout << table[x][i].substr(2, 3);
                textColor(15);
                cout << table[x][i].substr(5, 7) << "   ";

            }
            else if((suit == "S" || suit == "C" || suit10 == "S" || suit10 == "C") && isO != "O" && isO10 != "O") {
                textColor(15);
                cout << table[x][i].substr(0, 2);
                textColor(9);
                cout << table[x][i].substr(2, 3);
                textColor(15);
                cout << table[x][i].substr(5, 7) << "   ";
            }
            else {
                cout << table[x][i] << "   ";
            }
            
            textColor(15);
        }
        cout << '\n';
    }
}

void SolitaireGame::textColor(int color) {
    static int __BACKGROUND;

    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO csbiInfo;


    GetConsoleScreenBufferInfo(h, &csbiInfo);

    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),
        color + (__BACKGROUND << 4));
}

void SolitaireGame::setCursorPosition(int x, int y)
{
    static const HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    std::cout.flush();
    COORD coord = { (SHORT)x, (SHORT)y };
    SetConsoleCursorPosition(hOut, coord);
}