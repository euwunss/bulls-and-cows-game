/*
CS141 - Project #2:

The game "Bulls and Cows", which involves two users: the program receives a 4-digit code from the first player and allows the other player to guess it. The second player has 10 attempts to guess the code. With each guess, the program counts the number of matching digits and gives a hint to the second player: the number of bulls means that some digits match the code digits AND are in their right place; the number of cows suggests that there are as many matches with the first player's code, but the place and order are differing, which means that some digits need to be swapped. The game lasts until the player guesses the code or he/she runs out of tries.

Author: Olha Lashchukevych
UIC NetID: olash2
Date: 01/27/2024
*/

#include <iostream>
#include <string>

using namespace std;

// Function prototypes
void getUserCode(int *code, int size);
void getUserCode(int *code, int size, int turn);
void displayCode(int *code, int size);
bool checkForValid(int *code, int size);
bool checkForWinner(int *code1, int* code2, int size);
void countBullsAndCows(int *origCode, int*guessCode, int size);

int main() {
    const int CODE_SIZE = 4; // 4 digits
    const int GUESS_COUNT = 10;
    int userNums[CODE_SIZE];
    int guessNums[CODE_SIZE];
    bool isWinner = false;
    
    cout << "\n***********************************************\n";
    cout << "              BULLS AND COWS GAME!           \n";
    cout << "***********************************************\n\n"; 

    // Prompt player 1 for a code
    cout << "Enter the solution to use: ";
    getUserCode(userNums, CODE_SIZE);

    cout << "\n\n\n\n\n\n\n\n\n\n\n";

    // Game lasts until player 2 guesses the code or runs out of all tries
    int i = 1;
    while (i <= GUESS_COUNT && !isWinner) {
        // Prompt player 2 for a guess
        cout << "Turn " << i << ". Enter a guess: ";
        getUserCode(guessNums, CODE_SIZE, i);

        // Check and quit the program if player 2 won the game
        isWinner = checkForWinner(userNums, guessNums, CODE_SIZE);
        if (isWinner) {
            cout << "Congratulations! You win!" << endl;
            return 0;
        }

        // If player 2 doesn't guess the code, then game continues, and the program counts the matching digits
        countBullsAndCows(userNums, guessNums, CODE_SIZE);
        i++;
    }

    // When player 2 runs out of all attempts, the loop automatically exits and the program outputs the correct code
    cout << "\nYou lose. The correct answer is: ";
    displayCode(userNums, CODE_SIZE);

    return 0;
}

// Get 4-digit code from player 1
// int *code - int array passed to the function that is supposed to store the input numbers
// int size - size of the array (number of code digits)
void getUserCode(int *code, int size) {
    bool isValid;
    
    // Firstly receive numbers from the user and only then check for validity
    do {
        for (int i = 0; i < size; i++) {
           cin >> code[i];
        }

        // If user's code is invalid, then program allows them to type in numbers again
        isValid = checkForValid(code, size);
        if (!isValid) {
            cout << "Invalid code. Try again." << endl;
            cout << "Enter the solution to use: ";
        }
    } while (!isValid);
}

// Get 4-digit guess from player 2
// int *code - int array passed to the function that is supposed to store the input numbers
// int size - size of the array (number of code digits)
void getUserCode(int *code, int size, int turn) {
    bool isValid;

    // Firstly receive numbers from the user and only then check for validity
    do {
        for (int i = 0; i < size; i++) {
           cin >> code[i];
        }

        // If user's code is invalid, program allows them to type in numbers again
        isValid = checkForValid(code, size);
        if (!isValid) {
            cout << "Invalid code. Try again." << endl;
            cout << "Turn " << turn << ". Enter a guess: ";
        }
    } while (!isValid);
}

// Checks if a user's input code is valid, i.e whether numbers are digits 0-9 and are not repetitive
// int *code - int array passed to the function that is supposed to store the input numbers
// int size - size of the array (number of code digits)
bool checkForValid(int *code, int size) {
    for (int i = 0; i < size; i++) {
        bool isInRange = (code[i] >= 0 && code[i] <= 9);
        if (!isInRange) {
            return false;
        }

        for (int j = i; j < size; j++) {
            if (j == i) {
                continue;
            }

            bool isDuplicate = (code[j] == code[i]);
            if (isDuplicate) {
                return false;
            }
        }
    }

    return true;
}

// Checks whether player 2 got all digits correct and returns true if this is the case to indicate that player 2 won the game
// int *origCode - int array that stores player's 1 code
// int *guessCode - int array that stores player's 2 guess code
// int size - size of the array (number of code digits)
bool checkForWinner(int *origCode, int* guessCode, int size) {
    for (int i = 0; i < size; i++) {
        if (origCode[i] != guessCode[i]) {
            return false;
        }
    }

    return true;
}

// After each guess, this function counts the number of correct numbers that are on their right place (bulls) and correct numbers that need to be swapped to their place (cows)
// int *origCode - int array that stores player's 1 code
// int *guessCode - int array that stores player's 2 guess code
// int size - size of the array (number of code digits)
void countBullsAndCows(int *origCode, int*guessCode, int size) {
    int bullsCount = 0;
    int cowsCount = 0;

    for (int i = 0; i < size; i++) {
        if (guessCode[i] == origCode[i]) {
            bullsCount++;
        }

        for (int j = 0; j < size; j++) {
            if (j == i) {
                continue;
            }

            if (guessCode[j] == origCode[i]) {
                cowsCount++;
            }
        }
    }

    cout << "There are " << bullsCount << " bulls and " << cowsCount << " cows.\n";
}

// Iterates over an int array and outputs the code
// int *code - int array passed to the function that is supposed to store the input numbers
// int size - size of the array (number of code digits)
void displayCode(int *code, int size) {
    for (int i = 0; i < size; i++) {
        cout << code[i] << ' ';
    }
    cout << endl;
}
