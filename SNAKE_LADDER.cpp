#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

const int BOARD_SIZE = 100;
const int NUM_SNAKES = 5;
const int NUM_LADDERS = 5;

int snakes[NUM_SNAKES][2] = {
    {16, 6},   
    {47, 26},  
    {49, 11},  
    {56, 53},  
    {62, 19}   
};

int ladders[NUM_LADDERS][2] = {
    {1, 38},  
    {4, 14},   
    {9, 31},   
    {21, 42},  
    {28, 84}   
};

int playerPositions[2] = {0, 0};  
int currentPlayer = 0;  

void printBoard() {
    for (int i = 1; i <= BOARD_SIZE; ++i) {
        cout << i << " ";
        if (i % 10 == 0)
            cout << endl;
    }
}

int rollDice() {
    return rand() % 6 + 1;
}

void movePlayer(int player, int roll) {
    playerPositions[player] += roll;

    if (playerPositions[player] > BOARD_SIZE)
        playerPositions[player] = BOARD_SIZE; 

    for (int i = 0; i < NUM_SNAKES; ++i) {
        if (playerPositions[player] == snakes[i][0]) {
            cout << "Player " << (player + 1) << " encountered a snake! Sliding down from " << snakes[i][0] << " to " << snakes[i][1] << endl;
            playerPositions[player] = snakes[i][1];
        }
    }

    for (int i = 0; i < NUM_LADDERS; ++i) {
        if (playerPositions[player] == ladders[i][0]) {
            cout << "Player " << (player + 1) << " found a ladder! Climbing up from " << ladders[i][0] << " to " << ladders[i][1] << endl;
            playerPositions[player] = ladders[i][1];
        }
    }
}

bool checkWin() {
    return playerPositions[currentPlayer] == BOARD_SIZE;
}

int main() {
    srand(static_cast<unsigned>(time(0)));  

    cout << "Welcome to Snake and Ladders Game (Game of fun)-> " << endl;

    while (true) {
        cout << "Player " << (currentPlayer + 1) << "'s turn" << endl;
        cout << "Press Enter to roll the dice...";
        cin.ignore();  

        int roll = rollDice();
        cout << "Player " << (currentPlayer + 1) << " rolled a " << roll << endl;

        movePlayer(currentPlayer, roll);
        cout << "Player " << (currentPlayer + 1) << " is now on square " << playerPositions[currentPlayer] << endl;

        if (checkWin()) {
            cout << "Player " << (currentPlayer + 1) << " wins!" << endl;
            break;
        }
        currentPlayer = (currentPlayer + 1) % 2;
    }
}
