#include <iostream>
#include <vector>
#include <string> 
#include <limits> 

using namespace std;

// Function to print the Tic-Tac-Toe board
void printBoard(const vector<char>& board);

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

bool getPlayerMove(std::vector<std::vector<char>>& board, int player) {
    int x, y;
    char symbol = (player == 1) ? 'X' : 'O';

    while (true) {
        std::cout << "Player " << player << " (" << symbol << "), enter row (0-2) and column (0-2): ";

        if (!(std::cin >> x >> y)) { // Check for non-numeric input
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input. Please enter numbers.\n";
            continue;
        }

        if (x >= 0 && x < 3 && y >= 0 && y < 3) {
            if (board[x][y] == ' ') {
                board[x][y] = symbol;
                return true;
            } else {
                std::cout << "Cell already occupied. Try again.\n";
            }
        } else {
            std::cout << "Invalid coordinates. Please enter numbers between 0 and 2.\n";
        }
    }
}

//Function to validate integer inputs.
int getIntegerInput(const string& prompt);

void initializeBoard(std::vector<std::vector<char>>& board) {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            board[i][j] = ' ';
        }
    }
}

void displayBoard(const std::vector<std::vector<char>>& board) {
    std::cout << "-------------\n";
    for (int i = 0; i < 3; ++i) {
        std::cout << "| ";
        for (int j = 0; j < 3; ++j) {
            std::cout << board[i][j] << " | ";
        }
        std::cout << "\n-------------\n";
    }
}

int main() {
    std::vector<std::vector<char>> board(3, std::vector<char>(3));
    initializeBoard(board);
    displayBoard(board);

    int player = 1; // Start with player 1

    getPlayerMove(board, player);
    displayBoard(board); // Display board after the move

    return 0;
}