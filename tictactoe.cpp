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

//Function to validate integer inputs.
int getIntegerInput(const string& prompt);


int main() {


    return 0;
}