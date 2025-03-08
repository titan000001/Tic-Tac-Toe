#include <iostream>
#include <vector>
#include <string> 
#include <limits> 

using namespace std;


// Function to check if a player has won
bool checkWin(const vector<char>& board, char player);

// Function to check if the board is full (a draw)
bool checkDraw(const vector<char>& board);

// Function to get player names
void getPlayerNames(string& playerXName, string& playerOName);

// Function to get a valid player move
int getValidMove(const vector<char>& board, const string& playerName);

// Function to display the current score
void displayScore(int playerXScore, int playerOScore, const string& playerXName, const string& playerOName);

// Function to ask if players want to play again
bool playAgain();

// Function to reset the game board
void resetBoard(vector<char>& board);

// Function to handle the game loop
void playGame(string playerXName, string playerOName, int& playerXScore, int& playerOScore);

bool getPlayerMove(vector<vector<char>>& board, int player) {
    int x, y;
    char symbol = (player == 1) ? 'X' : 'O';

    while (true) {
        cout << "Player " << player << " (" << symbol << "), enter row (0-2) and column (0-2): ";

        if (!(cin >> x >> y)) { // Check for non-numeric input
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please enter numbers.\n";
            continue;
        }

        if (x >= 0 && x < 3 && y >= 0 && y < 3) {
            if (board[x][y] == ' ') {
                board[x][y] = symbol;
                return true;
            } else {
                cout << "Cell already occupied. Try again.\n";
            }
        } else {
            cout << "Invalid coordinates. Please enter numbers between 0 and 2.\n";
        }
    }
}

//Function to validate integer inputs.
int getIntegerInput(const string& prompt);

void initializeBoard(vector<vector<char>>& board) {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            board[i][j] = ' ';
        }
    }
}

void displayBoard(const vector<vector<char>>& board) {
    cout << "-------------\n";
    for (int i = 0; i < 3; ++i) {
        cout << "| ";
        for (int j = 0; j < 3; ++j) {
            cout << board[i][j] << " | ";
        }
        cout << "\n-------------\n";
    }
}

int main() {
    vector<vector<char>> board(3, vector<char>(3));
    initializeBoard(board);
    displayBoard(board);

    int player = 1; // Start with player 1

    getPlayerMove(board, player);
    displayBoard(board); // Display board after the move

    return 0;
}