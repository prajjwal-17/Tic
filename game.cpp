#include <iostream>
#include <cstdlib> // For system("cls") or system("clear") to clear screen
#include <limits> // For clearing input buffer
using namespace std;

void printBoard();
int checkWin();
void clearScreen();

char board[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
string player1Name, player2Name;

int main() {
    int choice = 1;

    while (choice == 1) {
        cout << "Enter the name of Player 1: ";
        cin >> player1Name;

        cout << "Enter the name of Player 2: ";
        cin >> player2Name;

        int player = 1, input, status = -1;
        printBoard();

        while (status == -1) {
            player = (player % 2 == 0) ? 2 : 1;
            char mark = (player == 1) ? 'X' : 'O';
            cout << "Please enter a number for " << ((player == 1) ? player1Name : player2Name) << " (Player " << player << ")\n";

            while (true) {
                if (!(cin >> input) || input < 1 || input > 9) {
                    cout << "Invalid input. Please enter a number between 1 and 9.\n";
                    cin.clear(); // Clear error flag
                    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input
                } else if (board[input] == 'X' || board[input] == 'O') {
                    cout << "Invalid input. Cell already marked. Please choose an empty cell.\n";
                } else {
                    board[input] = mark;
                    printBoard();
                    break;
                }
            }

            status = checkWin();

            if (status == 1) {
                cout << ((player == 1) ? player1Name : player2Name) << " (Player " << player << ") is the Winner\n";
                break;
            } else if (status == 0) {
                cout << "Match ends in a Draw\n";
                break;
            }

            player++;
        }

        cout << "Do you want to play again?\nEnter 1 to play again\nEnter any other number to exit: ";
        cin >> choice;

        if (choice == 1) {
            // Reset the game state
            for (int i = 1; i <= 9; i++) {
                board[i] = '0' + i;
            }
        }
    }

    cout << "Press any key to exit...";
    cin.ignore(); // Ignore any remaining characters
    cin.get(); // Wait for a key press
    return 0;
}

void printBoard() {
    clearScreen();
    cout << "\n\n";
    cout << "=== TIC TAC TOE ===\n\n";
    cout << "     |     |     \n";
    cout << "  " << board[1] << "  |  " << board[2] << "  |  " << board[3] << "  \n";
    cout << "_____|_____|_____\n";
    cout << "     |     |     \n";
    cout << "  " << board[4] << "  |  " << board[5] << "  |  " << board[6] << "  \n";
    cout << "_____|_____|_____\n";
    cout << "     |     |     \n";
    cout << "  " << board[7] << "  |  " << board[8] << "  |  " << board[9] << "  \n";
    cout << "     |     |     \n";
    cout << "\n\n";
}

int checkWin() {
    if (board[1] == board[2] && board[2] == board[3]) {
        return 1;
    }
    if (board[1] == board[4] && board[4] == board[7]) {
        return 1;
    }
    if (board[7] == board[8] && board[8] == board[9]) {
        return 1;
    }
    if (board[3] == board[6] && board[6] == board[9]) {
        return 1;
    }
    if (board[1] == board[5] && board[5] == board[9]) {
        return 1;
    }
    if (board[3] == board[5] && board[5] == board[7]) {
        return 1;
    }
    if (board[2] == board[5] && board[5] == board[8]) {
        return 1;
    }
    if (board[4] == board[5] && board[5] == board[6]) {
        return 1;
    }
    if (board[1] == board[2] && board[2] == board[3]) {
        return 1;
    }

    int count = 0;
    for (int i = 1; i <= 9; i++) {
        if (board[i] == 'X' || board[i] == 'O') {
            count++;
        }
    }

    if (count == 9) {
        return 0;
    }

    return -1;
}

void clearScreen() {
#ifdef _WIN32
    system("cls");
#else
    // Assume Unix-like system
    system("clear");
#endif
/usr/bin/bash: line 1: wq: command not found
