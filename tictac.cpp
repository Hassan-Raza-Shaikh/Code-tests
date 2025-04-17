#include <iostream>
#include <unistd.h>   // for usleep (macOS/Linux sleep)
#include <cstdlib>    // for system("clear")
using namespace std;

//---------------------------------------------Global-----------------------------------
char board[3][3] = { {'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'} };
int currentPlayer = 1;
char currentMarker;

// ANSI color codes
#define RESET   "\033[0m"
#define YELLOW  "\033[1;33m"
#define GREEN   "\033[1;32m"
#define BLUE    "\033[1;34m"
#define CYAN    "\033[1;36m"
#define RED     "\033[1;31m"
#define WHITE   "\033[1;37m"

// Function to add a delay effect
void delay(int milliseconds) {
    usleep(milliseconds * 1000); // Convert ms to microseconds
}

// Function to clear the screen
void clearScreen() {
    cout << "\033[2J\033[1;1H"; // ANSI escape sequence to clear screen
}

//--------------------------------------------Board set----------------------------------
void drawBoard() {
    clearScreen();
    cout << CYAN << "\n Game Loaded Successfully!" << RESET << "\n";

    for (int i = 0; i < 3; i++) {
        cout << "\t\t\t";
        for (int j = 0; j < 3; j++) {
            cout << YELLOW << " " << board[i][j] << " " << RESET;
            if (j < 2) cout << "|";
        }
        cout << "\n";
        if (i < 2) {
            cout << "\t\t\t---|---|---\n";
        }
    }
    cout << "\n";
}

//----------------------------------------Win checks-----------------------------------------
bool checkWin() {
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2]) return true;
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i]) return true;
    }
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2]) return true;
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0]) return true;
    return false;
}

//---------------------------------------Draw checks------------------------------------------
bool isDraw() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] != 'X' && board[i][j] != 'O') return false;
        }
    }
    return true;
}

//--------------------------------------Occupancy--------------------------------------------
bool placeMarker(int slot) {
    int row = (slot - 1) / 3;
    int col = (slot - 1) % 3;
    if (board[row][col] != 'X' && board[row][col] != 'O') {
        board[row][col] = currentMarker;
        return true;
    }
    return false;
}

//------------------------------------Swap---------------------------------------------------
void swapPlayer() {
    currentPlayer = (currentPlayer == 1) ? 2 : 1;
    currentMarker = (currentMarker == 'X') ? 'O' : 'X';
}

//------------------------------------Game-----------------------------------------------------
void playGame() {
    cout << BLUE << "\t\t*****************************************\n" << RESET;
    cout << CYAN << "\t\t*                                       *\n";
    cout << "\t\t*     " << YELLOW << "WELCOME TO TICTAC GAME!" << CYAN << "     *\n";
    cout << "\t\t*                                       *\n";
    cout << BLUE << "\t\t*****************************************\n" << RESET;

    cout << CYAN << "\nLoading the game...\n" << RESET;
    for (int i = 0; i < 10; i++) {
        cout << "*";
        cout.flush();
        delay(100); // Add short pause for loading effect
    }

    cout << "\n\n\nPlayer 1, choose your marker (X or O): ";
    cin >> currentMarker;
    while (currentMarker != 'X' && currentMarker != 'O') {
        cout << RED << "Invalid choice. Choose X or O: " << RESET;
        cin >> currentMarker;
    }
    drawBoard();

    for (int turn = 0; turn < 9; turn++) {
        int slot;
        cout << CYAN << "Player " << currentPlayer << "'s turn. Enter slot (1-9): " << RESET;
        cin >> slot;

        while (slot < 1 || slot > 9 || !placeMarker(slot)) {
            cout << RED << "Invalid move! Try again: " << RESET;
            cin >> slot;
        }

        drawBoard();

        if (checkWin()) {
            cout << GREEN << "Player " << currentPlayer << " wins!\a\n" << RESET;
            return;
        }

        if (isDraw()) {
            cout << YELLOW << "It's a draw!\a\n" << RESET;
            return;
        }

        swapPlayer();
    }
}

//---------------------------------Main------------------------------------------
int main() {
    playGame(); 
    return 0;
}
