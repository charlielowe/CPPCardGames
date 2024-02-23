#include "SolitaireGame.h"
#include "Card.h"

using namespace std;

const int rows = 7;
const int cols = 17;

int verticalPos = 0;
int horizontalPos = 0;
int firstX = 0;
int firstY = 0;


Card placeholder = Card(" ", " ", true);
Card emtpyH = Card(" ", "H", true);
Card emtpyD = Card(" ", "D", true);
Card emtpyS = Card(" ", "S", true);
Card emtpyC = Card(" ", "C", true);
Card emtpy = Card(" ", " ", false);
Card emtpySpace = Card("S", "S", true);

Card arr1[cols] = { emtpyH, placeholder, placeholder, placeholder, placeholder, placeholder, placeholder, placeholder, placeholder, placeholder, placeholder, placeholder, placeholder, placeholder, placeholder, placeholder, placeholder};
Card arr2[cols] = { emtpyD, placeholder, placeholder, placeholder, placeholder, placeholder, placeholder, placeholder, placeholder, placeholder, placeholder, placeholder, placeholder, placeholder, placeholder, placeholder, placeholder };
Card arr3[cols] = { emtpyS, placeholder, placeholder, placeholder, placeholder, placeholder, placeholder, placeholder, placeholder, placeholder, placeholder, placeholder, placeholder, placeholder, placeholder, placeholder, placeholder };
Card arr4[cols] = { emtpyC, placeholder, placeholder, placeholder, placeholder, placeholder, placeholder, placeholder, placeholder, placeholder, placeholder, placeholder, placeholder, placeholder, placeholder, placeholder, placeholder };
Card arr5[cols] = { emtpySpace, placeholder, placeholder, placeholder, placeholder, placeholder, placeholder, placeholder, placeholder, placeholder, placeholder, placeholder, placeholder, placeholder, placeholder, placeholder, placeholder };
Card arr6[cols] = { emtpySpace, placeholder, placeholder, placeholder, placeholder, placeholder, placeholder, placeholder, placeholder, placeholder, placeholder, placeholder, placeholder, placeholder, placeholder, placeholder, placeholder };
Card arr7[cols] = { emtpy, placeholder, placeholder, placeholder, placeholder, placeholder, placeholder, placeholder, placeholder, placeholder, placeholder, placeholder, placeholder, placeholder, placeholder, placeholder, placeholder };
vector<Card*> array2D = { arr1, arr2, arr3, arr4, arr5, arr6, arr7 };

bool isFirstPass = true;

Card firstChoice = emtpy;
Card secondChoice = emtpy;

SolitaireGame::SolitaireGame(){
}

void SolitaireGame::solitaireMain(Deck& deck) {
    if (firstChoice.getID() != "**") {
        cout << "First Choice: " << firstChoice.getID() << endl;
    }
    else {
        cout << "Press enter to select your first card, then enter again to confirm it or any other key to cancel." << endl;
    }
    if (secondChoice.getID() != "**") {
        cout << "Second Choice: " << secondChoice.getID() << endl;
    }
    else if (secondChoice.getID() == "**" && firstChoice.getID() != "**") {
        cout << "Press enter to select your second card, then enter again to confirm it or any other key to cancel." << endl;
    }
}

void SolitaireGame::solitaireLoop(Deck& deck) {
    useArrowKeys(&verticalPos, &horizontalPos, &firstChoice, &secondChoice, &firstX, &firstY);
    system("cls");
    makeTable(deck);
    
    if (firstChoice.getID() != "**") {
        cout << "First Choice: " << firstChoice.getID() << endl;
    }
    else {
        cout << "Press enter to select your first card, then enter again to confirm it or any other key to cancel." << endl;
    }
    if (secondChoice.getID() == "**" && firstChoice.getID() != "**") {
        cout << "Press enter to select your second card, then enter again to confirm it or any other key to cancel." << endl;
    }
}

void SolitaireGame::useArrowKeys(int* verticalPos, int* horizontalPos, Card* firstChoice, Card* secondChoice, int* firstX, int* firstY) {
    int c, ex;
    c = _getch();


    if (c && c != 224)
    {
        if (c == KEY_ENTER) {
            if (array2D[*horizontalPos][*verticalPos].getID() != "**") {
                cout << array2D[*horizontalPos][*verticalPos].getID() << endl;
                int y = _getch();
                if (y == KEY_ENTER) {
                    if ((*firstChoice).getID() == "**") {
                        *firstChoice = array2D[*horizontalPos][*verticalPos];
                        *firstX = *horizontalPos;
                        *firstY = *verticalPos;
                    }
                    else {
                        *secondChoice = array2D[*horizontalPos][*verticalPos];
                        array2D[*horizontalPos][*verticalPos + 1] = *firstChoice;
                        array2D[*firstX][*firstY] = placeholder;
                        if (array2D[*firstX][*firstY - 1].getID() == "**") {
                            array2D[*firstX][*firstY - 1].flip();
                        }
                        *firstChoice = emtpy;
                        *secondChoice = emtpy;
                    }
                    
                }
            }
            else {
                cout << "You cannot select a card that isn't flipped! Press a key to continue" << endl;
                _getch();
            }
            
        }
      
    }
    else
    {
        switch (ex = _getch())

        {
        case KEY_UP     /* H */:
            if (*verticalPos > 0) {
                *verticalPos = *verticalPos - 1;
                while (array2D[*horizontalPos][*verticalPos].getID() == "  ") {
                    *verticalPos = *verticalPos - 1;
                }
                if (array2D[*horizontalPos][*verticalPos].getID() == "SS") {
                    *verticalPos = *verticalPos + 2;
                }
            }
            break;
        case KEY_DOWN   /* K */:
            if (*verticalPos < 16) {
                *verticalPos = *verticalPos + 1;
                if (array2D[*horizontalPos][*verticalPos].getID() == "  " && array2D[*horizontalPos][*verticalPos + 1].getID() == "  ") {
                    *verticalPos = *verticalPos - 1;
                }
                else {
                    while (array2D[*horizontalPos][*verticalPos].getID() == "  " || array2D[*horizontalPos][*verticalPos].getID() == "SS") {
                        *verticalPos = *verticalPos + 1;
                    }
                }
                
                
            }
            break;
        case KEY_LEFT   /* M */:
            if (*horizontalPos > 0) {
                *horizontalPos = *horizontalPos - 1;
                if (*horizontalPos > 0) {
                    if (array2D[*horizontalPos][*verticalPos].getID() == "  " && array2D[*horizontalPos - 1][*verticalPos].getID() == "  ") {
                        *horizontalPos = *horizontalPos + 1;
                    }
                    else {
                        while (array2D[*horizontalPos][*verticalPos].getID() == "  " || array2D[*horizontalPos][*verticalPos].getID() == "SS") {
                            *horizontalPos = *horizontalPos - 1;
                        }
                    }
                }
                else {
                    if (array2D[*horizontalPos][*verticalPos].getID() == "  ") {
                        *horizontalPos = *horizontalPos + 1;

                    }
                }
                
                
            }
            break;
        case KEY_RIGHT: /* P */
            if (*horizontalPos < 6) {
                *horizontalPos = *horizontalPos + 1;
                if (array2D[*horizontalPos][*verticalPos].getID() == "  " && array2D[*horizontalPos + 1][*verticalPos].getID() == "  ") {
                    *horizontalPos = *horizontalPos - 1;
                }
                else {
                    while (array2D[*horizontalPos][*verticalPos].getID() == "  " || array2D[*horizontalPos][*verticalPos].getID() == "SS") {
                        *horizontalPos = *horizontalPos + 1;
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

    Card tempCard = deck.drawCard();
    tempCard.flip();
    if (isFirstPass) {
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
        arr6[0] = tempCard;
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
    printTable(table);
}

void SolitaireGame::printTable(vector<vector<string>> table) {
    string isO, is010;
    for (int i = 0; i < 38; i++) { // Loops for the ammount of strings inside cards[0] (which is card1) 

        for (int x = 0; x < rows; x++) { // For every col in table array
            // Adjust spacing between cards as needed
            isO = table[x][i].substr(4, 1);
            is010 = table[x][i].substr(5, 1);
            if (isO == "O" || is010 == "O") {
                textColor(10);
            }
            else{
                textColor(15);
            }
            cout << table[x][i] << "   ";
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