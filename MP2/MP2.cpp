// 
// ECCS 1611 - Programming 1 - Fall Semester 2021
// Machine Problem 2 (MP2) - Beetle!
// 
// MP2.cpp
// 
// Last Updated: October 28, 2021
// Hailey M. Wendt
// 
// This program is a game called Beetle that is played by 2 people. 
// The purpose of this game is to create your beetle either from building 
// it yourself or consuming your opponent's beetle. 
// Each player "rolls" a 6-sided die, where each number corresponds to a 
// certain body part for the beetle (head, body, leg, eye, antenna, tail).
// To win the game, you must complete your beetle before your opponent.
// 
// Some code was provided by Dr. Stephany as hints

#include <iostream>
#include <string>
#include <cmath>
#include <cstdlib>
#include <iomanip>

using namespace std;

// Function Prototypes
int rollDie(void);
bool isBodyPart(string currentBody, char c);
bool isBeetleComplete(string currentBody);
char getUserInput(void);
char convertDieToPart(int roll);
int legsFunction(string currentBody, int count);
bool bodyPresent(string currentBody);
bool headPresent(string currentBody);
int eyeFunction(string currentBody, int count);
int antennaFunction(string currentBody, int count);

int main()
{
    // Ask user to enter names for Player 1 and Player 2, and read them in
    string playerName1 = "";
    string playerName2 = "";
    cout << "Enter player one's name: ";
    cin >> playerName1;
    cout << "Enter player two's name: ";
    cin >> playerName2;

    // Initializing currentPlayer and currentPlayerName
    string currentPlayerName = "";
    int currentPlayer = 0;

    // Player's beetle strings
    string player1Beetle = "_____________";
    string player2Beetle = "_____________";
    string currentBody = "_____________";

    //Initializing beetle display string
    char displayBeetle = ' ';

    cout << "Hello! Let's play a dice game!\n";
    while (isBeetleComplete(currentBody) == false) {

        // Displays the current player's name
        cout << endl << currentPlayerName << endl;

        // Assigns the number rolled to die to be displayed
        int die = rollDie();
        cout << "DIE ROLL = " << die << endl;

        // Assigns the converted body part to c
        char c = convertDieToPart(die);

        // Assigns the userInput (build/consume) to input
        char input = getUserInput();

        // Building the beetle
        if (input == 'B' || input == 'b') {
            // Filling in user string
            if (c == 'B' && currentBody[1] == '_') {
                currentBody[0] = 'B';
            }
            // Checks for body and if roll is head
            if (c == 'H' && currentBody[0] == 'B' && currentBody[1] == '_') {
                currentBody[1] = 'H';
            }
            // Checks for body and if roll is leg
            if (c == 'L' && currentBody[0] == 'B') {
                int legCount = legsFunction(currentBody, 0);
                //Only allows for only 6 legs to be made
                if (legCount < 6) {
                    currentBody[2 + legCount] = 'L';
                }
            }
            // Checks for body and if roll is tail
            if (c == 'T' && currentBody[0] == 'B' && currentBody[12] == '_') {
                currentBody[12] = 'T';
            }
            // Checks for head and if roll is eye
            if (c == 'E' && currentBody[1] == 'H') {
                int eyeCount = eyeFunction(currentBody, 0);
                if (eyeCount == 1) {
                    currentBody[8] = 'E';
                }
                else {
                    currentBody[9] = 'E';
                }
            }
            // Checks for head and if roll is antenna
            if (c == 'A' && currentBody[1] == 'H') {
                int antennaCount = antennaFunction(currentBody, 0);
                if (antennaCount == 1) {
                    currentBody[10] = 'A';
                }
                else {
                    currentBody[11] = 'A';
                }
            }

        }
        // Consuming the beetle
        if (input == 'C' || input == 'c') {
            //Checks for body part to be leg and L in the string, and replace the L with an underscore
            if (c == 'L' && currentBody[7] == 'L') {
                currentBody[7] = '_';
            }
            else if (c == 'L' && currentBody[6] == 'L') {
                currentBody[6] = '_';
            }
            else if (c == 'L' && currentBody[5] == 'L') {
                currentBody[5] = '_';
            }
            else if (c == 'L' && currentBody[4] == 'L') {
                currentBody[4] = '_';
            }
            else if (c == 'L' && currentBody[3] == 'L') {
                currentBody[3] = '_';
            }
            else if (c == 'L' && currentBody[2] == 'L') {
                currentBody[2] = '_';
            }
            //Checks for body part to be eye and E in the string, and replace the E with an underscore
            if (c == 'E' && currentBody[9] == 'E') {
                currentBody[9] = '_';
            }
            else if (c == 'E' && currentBody[8] == 'E') {
                currentBody[8] = '_';
            }
            //Checks for body part to be antenna and A in the string, and replace the A with an underscore
            if (c == 'A' && currentBody[11] == 'A') {
                currentBody[11] = '_';
            }
            else if (c == 'A' && currentBody[10] == 'A') {
                currentBody[10] = '_';
            }
            //Checks for body part to be tail and T in the string, and replace the T with an underscore
            if (c == 'T' && currentBody[12] == 'T') {
                currentBody[12] = '_';
            }

        }

        // Swap players - player 1 even, player 2 odd
        // this is player 1 to player 2
        if (currentPlayer % 2 == 0) {
            // Builds and displays the beetle if the player chooses
            if (input == 'B' || input == 'b') {
                cout << "Current Body: " << player1Beetle << endl;
                cout << "Display the beetle? Yes (Y/y) or No (N/n): ";
                cin >> displayBeetle;
                if (displayBeetle == 'Y' || displayBeetle == 'y') {
                    if (player1Beetle[10] == 'A' && player1Beetle[11] == '_') {
                        cout << "                A     " << endl;
                        cout << "                A     " << endl;
                        cout << "                A     " << endl;
                        cout << "                A     " << endl;
                    }
                    else if (player1Beetle[10] == 'A' && player1Beetle[11] == 'A') {
                        cout << "                A  A  " << endl;
                        cout << "                A  A  " << endl;
                        cout << "                A  A  " << endl;
                        cout << "                A  A  " << endl;
                    }
                    else {
                        cout << "                      " << endl;
                        cout << "                      " << endl;
                        cout << "                      " << endl;
                        cout << "                      " << endl;
                    }
                    if (player1Beetle[1] == 'H' && player1Beetle[8] == 'E' && player1Beetle[9] == 'E') {
                        cout << "             HHHHHHHHH" << endl;
                        cout << "             H       H" << endl;
                        cout << "             H  O O  H" << endl;
                        cout << "             H       H" << endl;
                        cout << "             H   V   H" << endl;
                        cout << "             HHHHHHHHH" << endl;
                    }
                    else if (player1Beetle[1] == 'H' && player1Beetle[8] == 'E' && player1Beetle[9] == '_') {
                        cout << "             HHHHHHHHH" << endl;
                        cout << "             H       H" << endl;
                        cout << "             H  O    H" << endl;
                        cout << "             H       H" << endl;
                        cout << "             H   V   H" << endl;
                        cout << "             HHHHHHHHH" << endl;
                    }
                    else if (player1Beetle[1] == 'H' && player1Beetle[8] == '_' && player1Beetle[9] == '_') {
                        cout << "             HHHHHHHHH" << endl;
                        cout << "             H       H" << endl;
                        cout << "             H       H" << endl;
                        cout << "             H       H" << endl;
                        cout << "             H   V   H" << endl;
                        cout << "             HHHHHHHHH" << endl;
                    }
                    else {
                        cout << "                      " << endl;
                        cout << "                      " << endl;
                        cout << "                      " << endl;
                        cout << "                      " << endl;
                        cout << "                      " << endl;
                        cout << "                      " << endl;
                    }
                    if (player1Beetle[0] == 'B' && player1Beetle[12] == 'T') {
                        cout << "       BBBBBBBBBBBBBBB" << endl;
                        cout << "       B             B" << endl;
                        cout << " TTTTTTB             B" << endl;
                        cout << "       B             B" << endl;
                        cout << "       BBBBBBBBBBBBBBB" << endl;
                    }
                    else if (player1Beetle[0] == 'B' && player1Beetle[12] == '_') {
                        cout << "       BBBBBBBBBBBBBBB" << endl;
                        cout << "       B             B" << endl;
                        cout << "       B             B" << endl;
                        cout << "       B             B" << endl;
                        cout << "       BBBBBBBBBBBBBBB" << endl;
                    }
                    else {
                        cout << "                      " << endl;
                        cout << "                      " << endl;
                        cout << "                      " << endl;
                        cout << "                      " << endl;
                        cout << "                      " << endl;
                    }
                    if (player1Beetle[2] == 'L' && player1Beetle[3] == 'L' && player1Beetle[4] == 'L' && player1Beetle[5] == 'L' && player1Beetle[6] == 'L' && player1Beetle[7] == 'L') {
                        cout << "          L L L L L L  " << endl;
                        cout << "          L L L L L L  " << endl;
                    }
                    else if (player1Beetle[2] == 'L' && player1Beetle[3] == 'L' && player1Beetle[4] == 'L' && player1Beetle[5] == 'L' && player1Beetle[6] == 'L' && player1Beetle[7] == '_') {
                        cout << "          L L L L L    " << endl;
                        cout << "          L L L L L    " << endl;
                    }
                    else if (player1Beetle[2] == 'L' && player1Beetle[3] == 'L' && player1Beetle[4] == 'L' && player1Beetle[5] == 'L' && player1Beetle[6] == '_' && player1Beetle[7] == '_') {
                        cout << "          L L L L      " << endl;
                        cout << "          L L L L      " << endl;
                    }
                    else if (player1Beetle[2] == 'L' && player1Beetle[3] == 'L' && player1Beetle[4] == 'L' && player1Beetle[5] == '_' && player1Beetle[6] == '_' && player1Beetle[7] == '_') {
                        cout << "          L L L        " << endl;
                        cout << "          L L L        " << endl;
                    }
                    else if (player1Beetle[2] == 'L' && player1Beetle[3] == 'L' && player1Beetle[4] == '_' && player1Beetle[5] == '_' && player1Beetle[6] == '_' && player1Beetle[7] == '_') {
                        cout << "          L L          " << endl;
                        cout << "          L L          " << endl;
                    }
                    else if (player1Beetle[2] == 'L' && player1Beetle[3] == '_' && player1Beetle[4] == '_' && player1Beetle[5] == '_' && player1Beetle[6] == '_' && player1Beetle[7] == '_') {
                        cout << "          L            " << endl;
                        cout << "          L            " << endl;
                    }
                    else {
                        cout << "                       " << endl;
                        cout << "                       " << endl;
                    }
                }
                player1Beetle = currentBody;
                currentBody = player2Beetle;
                currentPlayer++; // updated to odd
                currentPlayerName = playerName2; // swap name            
            }
            // Consumes and displays the beetle if the player chooses
            if (input == 'C' || input == 'c') {
                cout << "Current Body: " << player1Beetle << endl;
                cout << "Display the beetle? Yes (Y/y) or No (N/n): ";
                cin >> displayBeetle;
                if (displayBeetle == 'Y' || displayBeetle == 'y') {
                    if (player1Beetle[10] == 'A' && player1Beetle[11] == '_') {
                        cout << "                A     " << endl;
                        cout << "                A     " << endl;
                        cout << "                A     " << endl;
                        cout << "                A     " << endl;
                    }
                    else if (player1Beetle[10] == 'A' && player1Beetle[11] == 'A') {
                        cout << "                A  A  " << endl;
                        cout << "                A  A  " << endl;
                        cout << "                A  A  " << endl;
                        cout << "                A  A  " << endl;
                    }
                    else {
                        cout << "                      " << endl;
                        cout << "                      " << endl;
                        cout << "                      " << endl;
                        cout << "                      " << endl;
                    }
                    if (player1Beetle[1] == 'H' && player1Beetle[8] == 'E' && player1Beetle[9] == 'E') {
                        cout << "             HHHHHHHHH" << endl;
                        cout << "             H       H" << endl;
                        cout << "             H  O O  H" << endl;
                        cout << "             H       H" << endl;
                        cout << "             H   V   H" << endl;
                        cout << "             HHHHHHHHH" << endl;
                    }
                    else if (player1Beetle[1] == 'H' && player1Beetle[8] == 'E' && player1Beetle[9] == '_') {
                        cout << "             HHHHHHHHH" << endl;
                        cout << "             H       H" << endl;
                        cout << "             H  O    H" << endl;
                        cout << "             H       H" << endl;
                        cout << "             H   V   H" << endl;
                        cout << "             HHHHHHHHH" << endl;
                    }
                    else if (player1Beetle[1] == 'H' && player1Beetle[8] == '_' && player1Beetle[9] == '_') {
                        cout << "             HHHHHHHHH" << endl;
                        cout << "             H       H" << endl;
                        cout << "             H       H" << endl;
                        cout << "             H       H" << endl;
                        cout << "             H   V   H" << endl;
                        cout << "             HHHHHHHHH" << endl;
                    }
                    else {
                        cout << "                      " << endl;
                        cout << "                      " << endl;
                        cout << "                      " << endl;
                        cout << "                      " << endl;
                        cout << "                      " << endl;
                        cout << "                      " << endl;
                    }
                    if (player1Beetle[0] == 'B' && player1Beetle[12] == 'T') {
                        cout << "       BBBBBBBBBBBBBBB" << endl;
                        cout << "       B             B" << endl;
                        cout << " TTTTTTB             B" << endl;
                        cout << "       B             B" << endl;
                        cout << "       BBBBBBBBBBBBBBB" << endl;
                    }
                    else if (player1Beetle[0] == 'B' && player1Beetle[12] == '_') {
                        cout << "       BBBBBBBBBBBBBBB" << endl;
                        cout << "       B             B" << endl;
                        cout << "       B             B" << endl;
                        cout << "       B             B" << endl;
                        cout << "       BBBBBBBBBBBBBBB" << endl;
                    }
                    else {
                        cout << "                      " << endl;
                        cout << "                      " << endl;
                        cout << "                      " << endl;
                        cout << "                      " << endl;
                        cout << "                      " << endl;
                    }
                    if (player1Beetle[2] == 'L' && player1Beetle[3] == 'L' && player1Beetle[4] == 'L' && player1Beetle[5] == 'L' && player1Beetle[6] == 'L' && player1Beetle[7] == 'L') {
                        cout << "          L L L L L L  " << endl;
                        cout << "          L L L L L L  " << endl;
                    }
                    else if (player1Beetle[2] == 'L' && player1Beetle[3] == 'L' && player1Beetle[4] == 'L' && player1Beetle[5] == 'L' && player1Beetle[6] == 'L' && player1Beetle[7] == '_') {
                        cout << "          L L L L L    " << endl;
                        cout << "          L L L L L    " << endl;
                    }
                    else if (player1Beetle[2] == 'L' && player1Beetle[3] == 'L' && player1Beetle[4] == 'L' && player1Beetle[5] == 'L' && player1Beetle[6] == '_' && player1Beetle[7] == '_') {
                        cout << "          L L L L      " << endl;
                        cout << "          L L L L      " << endl;
                    }
                    else if (player1Beetle[2] == 'L' && player1Beetle[3] == 'L' && player1Beetle[4] == 'L' && player1Beetle[5] == '_' && player1Beetle[6] == '_' && player1Beetle[7] == '_') {
                        cout << "          L L L        " << endl;
                        cout << "          L L L        " << endl;
                    }
                    else if (player1Beetle[2] == 'L' && player1Beetle[3] == 'L' && player1Beetle[4] == '_' && player1Beetle[5] == '_' && player1Beetle[6] == '_' && player1Beetle[7] == '_') {
                        cout << "          L L          " << endl;
                        cout << "          L L          " << endl;
                    }
                    else if (player1Beetle[2] == 'L' && player1Beetle[3] == '_' && player1Beetle[4] == '_' && player1Beetle[5] == '_' && player1Beetle[6] == '_' && player1Beetle[7] == '_') {
                        cout << "          L            " << endl;
                        cout << "          L            " << endl;
                    }
                    else {
                        cout << "                       " << endl;
                        cout << "                       " << endl;
                    }
                }
                player2Beetle = currentBody;
                currentBody = player1Beetle; currentPlayer++; // updated to odd
                currentPlayerName = playerName2; // swap name
            }
        }
        // this is player 2 to player 1
        else { 
            // Builds and displays the beetle if the player chooses
            if (input == 'B' || input == 'b') {
                cout << "Current Body: " << player2Beetle << endl;
                cout << "Display the beetle? Yes (Y/y) or No (N/n): ";
                cin >> displayBeetle;
                if (displayBeetle == 'Y' || displayBeetle == 'y') {
                        if (player2Beetle[10] == 'A' && player2Beetle[11] == '_') {
                            cout << "                A     " << endl;
                            cout << "                A     " << endl;
                            cout << "                A     " << endl;
                            cout << "                A     " << endl;
                        }
                        else if (player2Beetle[10] == 'A' && player2Beetle[11] == 'A') {
                            cout << "                A  A  " << endl;
                            cout << "                A  A  " << endl;
                            cout << "                A  A  " << endl;
                            cout << "                A  A  " << endl;
                        }
                        else {
                            cout << "                      " << endl;
                            cout << "                      " << endl;
                            cout << "                      " << endl;
                            cout << "                      " << endl;
                        }
                        if (player2Beetle[1] == 'H' && player2Beetle[8] == 'E' && player2Beetle[9] == 'E') {
                            cout << "             HHHHHHHHH" << endl;
                            cout << "             H       H" << endl;
                            cout << "             H  O O  H" << endl;
                            cout << "             H       H" << endl;
                            cout << "             H   V   H" << endl;
                            cout << "             HHHHHHHHH" << endl;
                        }
                        else if (player2Beetle[1] == 'H' && player2Beetle[8] == 'E' && player2Beetle[9] == '_') {
                            cout << "             HHHHHHHHH" << endl;
                            cout << "             H       H" << endl;
                            cout << "             H  O    H" << endl;
                            cout << "             H       H" << endl;
                            cout << "             H   V   H" << endl;
                            cout << "             HHHHHHHHH" << endl;
                        }
                        else if (player2Beetle[1] == 'H' && player2Beetle[8] == '_' && player2Beetle[9] == '_') {
                            cout << "             HHHHHHHHH" << endl;
                            cout << "             H       H" << endl;
                            cout << "             H       H" << endl;
                            cout << "             H       H" << endl;
                            cout << "             H   V   H" << endl;
                            cout << "             HHHHHHHHH" << endl;
                        }
                        else {
                            cout << "                      " << endl;
                            cout << "                      " << endl;
                            cout << "                      " << endl;
                            cout << "                      " << endl;
                            cout << "                      " << endl;
                            cout << "                      " << endl;
                        }
                        if (player2Beetle[0] == 'B' && player2Beetle[12] == 'T') {
                            cout << "       BBBBBBBBBBBBBBB" << endl;
                            cout << "       B             B" << endl;
                            cout << " TTTTTTB             B" << endl;
                            cout << "       B             B" << endl;
                            cout << "       BBBBBBBBBBBBBBB" << endl;
                        }
                        else if (player2Beetle[0] == 'B' && player2Beetle[12] == '_') {
                            cout << "       BBBBBBBBBBBBBBB" << endl;
                            cout << "       B             B" << endl;
                            cout << "       B             B" << endl;
                            cout << "       B             B" << endl;
                            cout << "       BBBBBBBBBBBBBBB" << endl;
                        }
                        else {
                            cout << "                      " << endl;
                            cout << "                      " << endl;
                            cout << "                      " << endl;
                            cout << "                      " << endl;
                            cout << "                      " << endl;
                        }
                        if (player2Beetle[2] == 'L' && player2Beetle[3] == 'L' && player2Beetle[4] == 'L' && player2Beetle[5] == 'L' && player2Beetle[6] == 'L' && player2Beetle[7] == 'L') {
                            cout << "          L L L L L L  " << endl;
                            cout << "          L L L L L L  " << endl;
                        }
                        else if (player2Beetle[2] == 'L' && player2Beetle[3] == 'L' && player2Beetle[4] == 'L' && player2Beetle[5] == 'L' && player2Beetle[6] == 'L' && player2Beetle[7] == '_') {
                            cout << "          L L L L L    " << endl;
                            cout << "          L L L L L    " << endl;
                        }
                        else if (player2Beetle[2] == 'L' && player2Beetle[3] == 'L' && player2Beetle[4] == 'L' && player2Beetle[5] == 'L' && player2Beetle[6] == '_' && player2Beetle[7] == '_') {
                            cout << "          L L L L      " << endl;
                            cout << "          L L L L      " << endl;
                        }
                        else if (player2Beetle[2] == 'L' && player2Beetle[3] == 'L' && player2Beetle[4] == 'L' && player2Beetle[5] == '_' && player2Beetle[6] == '_' && player2Beetle[7] == '_') {
                            cout << "          L L L        " << endl;
                            cout << "          L L L        " << endl;
                        }
                        else if (player2Beetle[2] == 'L' && player2Beetle[3] == 'L' && player2Beetle[4] == '_' && player2Beetle[5] == '_' && player2Beetle[6] == '_' && player2Beetle[7] == '_') {
                            cout << "          L L          " << endl;
                            cout << "          L L          " << endl;
                        }
                        else if (player2Beetle[2] == 'L' && player2Beetle[3] == '_' && player2Beetle[4] == '_' && player2Beetle[5] == '_' && player2Beetle[6] == '_' && player2Beetle[7] == '_') {
                            cout << "          L            " << endl;
                            cout << "          L            " << endl;
                        }
                        else {
                            cout << "                       " << endl;
                            cout << "                       " << endl;
                        }
                    }
                player2Beetle = currentBody;
                currentBody = player1Beetle; currentPlayer++; // updated to even
                currentPlayerName = playerName1; // swap name
            }
            // Consumes and displays the beetle if the player chooses
            if (input == 'C' || input == 'c') {
                cout << "Current Body: " << player2Beetle << endl;
                cout << "Display the beetle? Yes (Y/y) or No (N/n): ";
                cin >> displayBeetle;
                if (displayBeetle == 'Y' || displayBeetle == 'y') {
                        if (player2Beetle[10] == 'A' && player2Beetle[11] == '_') {
                            cout << "                A     " << endl;
                            cout << "                A     " << endl;
                            cout << "                A     " << endl;
                            cout << "                A     " << endl;
                        }
                        else if (player2Beetle[10] == 'A' && player2Beetle[11] == 'A') {
                            cout << "                A  A  " << endl;
                            cout << "                A  A  " << endl;
                            cout << "                A  A  " << endl;
                            cout << "                A  A  " << endl;
                        }
                        else {
                            cout << "                      " << endl;
                            cout << "                      " << endl;
                            cout << "                      " << endl;
                            cout << "                      " << endl;
                        }
                        if (player2Beetle[1] == 'H' && player2Beetle[8] == 'E' && player2Beetle[9] == 'E') {
                            cout << "             HHHHHHHHH" << endl;
                            cout << "             H       H" << endl;
                            cout << "             H  O O  H" << endl;
                            cout << "             H       H" << endl;
                            cout << "             H   V   H" << endl;
                            cout << "             HHHHHHHHH" << endl;
                        }
                        else if (player2Beetle[1] == 'H' && player2Beetle[8] == 'E' && player2Beetle[9] == '_') {
                            cout << "             HHHHHHHHH" << endl;
                            cout << "             H       H" << endl;
                            cout << "             H  O    H" << endl;
                            cout << "             H       H" << endl;
                            cout << "             H   V   H" << endl;
                            cout << "             HHHHHHHHH" << endl;
                        }
                        else if (player2Beetle[1] == 'H' && player2Beetle[8] == '_' && player2Beetle[9] == '_') {
                            cout << "             HHHHHHHHH" << endl;
                            cout << "             H       H" << endl;
                            cout << "             H       H" << endl;
                            cout << "             H       H" << endl;
                            cout << "             H   V   H" << endl;
                            cout << "             HHHHHHHHH" << endl;
                        }
                        else {
                            cout << "                      " << endl;
                            cout << "                      " << endl;
                            cout << "                      " << endl;
                            cout << "                      " << endl;
                            cout << "                      " << endl;
                            cout << "                      " << endl;
                        }
                        if (player2Beetle[0] == 'B' && player2Beetle[12] == 'T') {
                            cout << "       BBBBBBBBBBBBBBB" << endl;
                            cout << "       B             B" << endl;
                            cout << " TTTTTTB             B" << endl;
                            cout << "       B             B" << endl;
                            cout << "       BBBBBBBBBBBBBBB" << endl;
                        }
                        else if (player2Beetle[0] == 'B' && player2Beetle[12] == '_') {
                            cout << "       BBBBBBBBBBBBBBB" << endl;
                            cout << "       B             B" << endl;
                            cout << "       B             B" << endl;
                            cout << "       B             B" << endl;
                            cout << "       BBBBBBBBBBBBBBB" << endl;
                        }
                        else {
                            cout << "                      " << endl;
                            cout << "                      " << endl;
                            cout << "                      " << endl;
                            cout << "                      " << endl;
                            cout << "                      " << endl;
                        }
                        if (player2Beetle[2] == 'L' && player2Beetle[3] == 'L' && player2Beetle[4] == 'L' && player2Beetle[5] == 'L' && player2Beetle[6] == 'L' && player2Beetle[7] == 'L') {
                            cout << "          L L L L L L  " << endl;
                            cout << "          L L L L L L  " << endl;
                        }
                        else if (player2Beetle[2] == 'L' && player2Beetle[3] == 'L' && player2Beetle[4] == 'L' && player2Beetle[5] == 'L' && player2Beetle[6] == 'L' && player2Beetle[7] == '_') {
                            cout << "          L L L L L    " << endl;
                            cout << "          L L L L L    " << endl;
                        }
                        else if (player2Beetle[2] == 'L' && player2Beetle[3] == 'L' && player2Beetle[4] == 'L' && player2Beetle[5] == 'L' && player2Beetle[6] == '_' && player2Beetle[7] == '_') {
                            cout << "          L L L L      " << endl;
                            cout << "          L L L L      " << endl;
                        }
                        else if (player2Beetle[2] == 'L' && player2Beetle[3] == 'L' && player2Beetle[4] == 'L' && player2Beetle[5] == '_' && player2Beetle[6] == '_' && player2Beetle[7] == '_') {
                            cout << "          L L L        " << endl;
                            cout << "          L L L        " << endl;
                        }
                        else if (player2Beetle[2] == 'L' && player2Beetle[3] == 'L' && player2Beetle[4] == '_' && player2Beetle[5] == '_' && player2Beetle[6] == '_' && player2Beetle[7] == '_') {
                            cout << "          L L          " << endl;
                            cout << "          L L          " << endl;
                        }
                        else if (player2Beetle[2] == 'L' && player2Beetle[3] == '_' && player2Beetle[4] == '_' && player2Beetle[5] == '_' && player2Beetle[6] == '_' && player2Beetle[7] == '_') {
                            cout << "          L            " << endl;
                            cout << "          L            " << endl;
                        }
                        else {
                            cout << "                       " << endl;
                            cout << "                       " << endl;
                        }
                    }
                player1Beetle = currentBody;
                currentBody = player2Beetle; currentPlayer++; // updated to even
                currentPlayerName = playerName1; // swap name
            }
            cout << endl;
        }
    }
    cout << currentPlayerName << " is the winner!" << endl;
    return 0;
}

/**
rollDie - simulated rolling one 6 sided die.
@return: the random number for the die roll
*/
int rollDie(void) {
    srand(time(0));
    int die = rand() % 6 + 1;
    return die;
}

/**
isBodyPart - checks to see if a player's beetle currently has that body part
@param currentBody: the current player's beetle
@param c: assigns the body part to c
@return: true if the body parts exists in the string; false it it doesn't
*/
bool isBodyPart(string currentBody, char c) { 
    for (int i = 0; i < currentBody.length(); i++) {
        if (currentBody.at(i) == 'c') {
            return true;
        }
    }
    return false;
}

/**
isBeetleComplete - checks to see if the beetle had been fully built with the maximum of all body parts.
@param currentBody: the current player's beetle
@return: true if enitre string is correct; false if it's not
*/
bool isBeetleComplete(string currentBody) {
    if (currentBody == "BHLLLLLLEEAAT") {
        return true;
    }
    return false;
}

/**
getUserInput - asks whether or not the player wants to build their beetle or consume their opponent's beetle 
@return: character is B/b or C/c
*/
char getUserInput(void) {
    char userInput = ' ';
    cout << "Do you want to build your beetle (b or B) or consume the opposing player's beetle (c or C)?";
    cin >> userInput;
    return userInput;
}

/**
convertDieToPart - takes the die value and returns the character that represents the beetle body part
@param roll: the int value representing the die roll
@return: character associated with the die roll
*/
char convertDieToPart(int roll) {
    char bodyPart = ' ';

    if (roll == 1) {
        bodyPart = 'B';
    }
    else if (roll == 2) {
        bodyPart = 'H';
    }
    else if (roll == 3) {
        bodyPart = 'L';
    }
    else if (roll == 4) {
        bodyPart = 'E';
    }
    else if (roll == 5) {
        bodyPart = 'A';
    }
    else if (roll == 6) {
        bodyPart = 'T';
    }
    return bodyPart;
}

/**
legsFunction - checks to see how many legs there currently are
@param currentBody: the current player's beetle
@param count: counts the number of legs
@return: count
*/
int legsFunction(string currentBody, int count) {
    if (currentBody[2] == 'L') {
        count++;
    }
    if (currentBody[3] == 'L') {
        count++;
    }
    if (currentBody[4] == 'L') {
        count++;
    }
    if (currentBody[5] == 'L') {
        count++;
    }
    if (currentBody[6] == 'L') {
        count++;
    }
    if (currentBody[7] == 'L') {
        count++;
    }
    return count;
}

/**
bodyPresent - checks to see if there is a body
@param currentBody: the current player's beetle
@return: true if the plays beetle has a body; false if the player's beetle doesn't.
*/
bool bodyPresent(string currentBody) {
    if (currentBody[0] == 'B') {
        return true;
    }
    else { return false; }
}

/**
headPresent - checks to see if the head is present
@param currentBody: the current player's beetle
@return: true if the player's beetle has a head; false if the player's beetle doesn't
*/
bool headPresent(string currentBody) {
    if (currentBody[1] == 'H') {
        return true;
    }
    return false;
}

/**
eyeFunction - checks to see how many eyes there currently are
@param currentBody: the current player's beetle
@param count: counts the number of eyes
@return: count
*/
int eyeFunction(string currentBody, int count) {
    if (currentBody[8] == 'E') {
        count++;
    }
    if (currentBody[9] == 'E') {
        count++;
    }
    return count;
}

/**
antennaFunction - checks to see how many antennas there currently are
@param currentBody: the current player's beetle
@param count: counts the number of antenna
@return: count 
*/
int antennaFunction(string currentBody, int count) {
    if (currentBody[10] == 'A') {
        count++;
    }
    if (currentBody[11] == 'A') {
        count++;
    }
    return count;
}
