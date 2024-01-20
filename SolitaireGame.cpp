#include "SolitaireGame.h"
#include "Card.h"

using namespace std;

const int rows = 7;
const int cols = 17;

int currentArea = 0;
int verticalPos = 1;
int horizontalPos = 0;

vector<string>* currentCard = {};

string arr1[cols] = { "*H", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " " };
string arr2[cols] = { "*D", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " " };
string arr3[cols] = { "*S", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " " };
string arr4[cols] = { "*C", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " " };
string arr5[cols] = { "SS", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " " };
string arr6[cols] = { " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " " };
string arr7[cols] = { "**", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " " };


bool isFirstPass = true;

SolitaireGame::SolitaireGame(){
}

void SolitaireGame::solitaireMain(Deck* deck) {

}

void SolitaireGame::solitaireLoop(Deck* deck) {
    useArrowKeys(&verticalPos, &horizontalPos);
    system("cls");
    makeTable(deck);
}

void SolitaireGame::useArrowKeys(int* verticalPos, int* horizontalPos) {
    int c, ex;
    c = _getch();

    if (c && c != 224)
    {
        
    }
    else
    {
        switch (ex = _getch())

        {
        case KEY_UP     /* H */:
            if (*verticalPos == 2) {
                if (*horizontalPos != 4) {
                    *verticalPos = *verticalPos - 1;
                }
            }
            break;
        case KEY_DOWN   /* K */:
            if (*verticalPos == 1) {
                *verticalPos = *verticalPos + 1;
            }
            break;
        case KEY_LEFT   /* M */:
            if (*horizontalPos > 0) {
                if (*horizontalPos == 5 && *verticalPos == 1) {
                    *horizontalPos = *horizontalPos - 2;
                }
                else {
                    *horizontalPos = *horizontalPos - 1;

                }
            }
            break;
        case KEY_RIGHT: /* P */
            if (*horizontalPos < 6) {
                if (*horizontalPos == 3 && *verticalPos == 1) {
                    *horizontalPos = *horizontalPos + 2;
                }
                else {
                    *horizontalPos = *horizontalPos + 1;

                }
            }
            break;
        default:
            
            break;
        }
    }
}


void SolitaireGame::makeTable(Deck* deck){
    const int rows = 7;
	const int cols = 17;
    
    if (isFirstPass) {
        Card tempCard = Deck(*deck).drawCard();
        tempCard.flip();
        arr1[2] = tempCard.getID();
        arr2[2] = Deck(*deck).drawCard().getID();
        arr2[3] = Deck(*deck).drawCard().getID();
        arr3[2] = Deck(*deck).drawCard().getID();
        arr3[3] = Deck(*deck).drawCard().getID();
        arr3[4] = Deck(*deck).drawCard().getID();
        arr4[2] = Deck(*deck).drawCard().getID();
        arr4[3] = Deck(*deck).drawCard().getID();
        arr4[4] = Deck(*deck).drawCard().getID();
        arr4[5] = Deck(*deck).drawCard().getID();
        arr5[2] = Deck(*deck).drawCard().getID();
        arr5[3] = Deck(*deck).drawCard().getID();
        arr5[4] = Deck(*deck).drawCard().getID();
        arr5[5] = Deck(*deck).drawCard().getID();
        arr5[6] = Deck(*deck).drawCard().getID();
        arr6[0] = Deck(*deck).drawCard().getID();
        arr6[2] = Deck(*deck).drawCard().getID();
        arr6[3] = Deck(*deck).drawCard().getID();
        arr6[4] = Deck(*deck).drawCard().getID();
        arr6[5] = Deck(*deck).drawCard().getID();
        arr6[5] = Deck(*deck).drawCard().getID();
        arr6[6] = Deck(*deck).drawCard().getID();
        arr6[7] = Deck(*deck).drawCard().getID();
        arr7[2] = Deck(*deck).drawCard().getID();
        arr7[3] = Deck(*deck).drawCard().getID();
        arr7[4] = Deck(*deck).drawCard().getID();
        arr7[5] = Deck(*deck).drawCard().getID();
        arr7[5] = Deck(*deck).drawCard().getID();
        arr7[6] = Deck(*deck).drawCard().getID();
        arr7[7] = Deck(*deck).drawCard().getID();
        arr7[8] = Deck(*deck).drawCard().getID();
        isFirstPass = false;
    }

    vector<string*> array2D = { arr1, arr2, arr3, arr4, arr5, arr6, arr7 };

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
            if (array2D[i][x] == "SS") {
                table[i].push_back("           ");
                table[i].push_back("           ");
                table[i].push_back("           ");
                table[i].push_back("           ");
                table[i].push_back("           ");
            }
            else if(array2D[i][x] != " " && array2D[i][x+1]== " ") {
                table[i].push_back("  _______  ");
                if ((array2D[i][x]).substr(0, 2) == "10") {
                    table[i].push_back(" |" + array2D[i][x] + "    | ");
                }
                else {
                    table[i].push_back(" |" + array2D[i][x] + "     | ");
                }
                table[i].push_back(" |       | ");
                table[i].push_back(" |       | ");
                table[i].push_back(" |_______| ");
            }
            else if(array2D[i][x] != " " && array2D[i][x + 1] != " ") {
                table[i].push_back("  _______  ");
                if (array2D[i][x].substr(0, 2) == "10") {
                    table[i].push_back(" |" + array2D[i][x] + "    | ");
                }
                else {
                    table[i].push_back(" |" + array2D[i][x] + "     | ");
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

    currentCard = &table[horizontalPos];
    currentArea = verticalPos;

    // Print cards horizontally
    printTable(table);
}

void SolitaireGame::printTable(vector<vector<string>> table) {
    for (int i = 0; i < 38; i++) { // Loops for the ammount of strings inside cards[0] (which is card1) 

        for (int x = 0; x < rows; x++) { // For every col in table array
            // Adjust spacing between cards as needed
            if (table[x] == *currentCard) {
                switch (currentArea) {
                case 1:
                    if (i < 6) {
                        textColor(10);

                    }
                    else {
                        textColor(15);

                    }
                    break;
                case 2:
                    if (i > 5) {
                        textColor(10);

                    }
                    else {
                        textColor(15);

                    }
                    break;
                }

            }
            else {
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