#include <iostream>
#include <cstdlib>
using namespace std;

char gap[3][3] = { {'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'} };
char turn = 'X';
string player1, player2;

void Table() {
    cout << "   |     |  " << endl;
    cout << " " << gap[0][0] << " | " << gap[0][1] << "   | " << gap[0][2] << endl;
    cout << "___|_____|___" << endl;
    cout << "   |     |  " << endl;
    cout << " " << gap[1][0] << " | " << gap[1][1] << "   | " << gap[1][2] << endl;
    cout << "___|_____|___" << endl;
    cout << "   |     |  " << endl;
    cout << " " << gap[2][0] << " | " << gap[2][1] << "   | " << gap[2][2] << endl;
    cout << "   |     |  " << endl;
}

void player_turn() {
    int choice;
    cout << "It's " << (turn == 'X' ? player1 : player2) << "'s turn. Enter a number (1-9): ";

    while (true) {
        cin >> choice;

        if (choice < 1 || choice > 9) {
            cout << "Invalid choice! Enter a number between 1 and 9: ";
            continue;
        }

        int row = (choice - 1) / 3;
        int column = (choice - 1) % 3;

        if (gap[row][column] != 'X' && gap[row][column] != 'O') {
            gap[row][column] = turn;
            break;
        }
        else {
            cout << "The space is occupied. Choose another one: ";
        }
    }

    // Switch the turn after a valid move
    turn = (turn == 'X' ? 'O' : 'X');
}

bool result() {
    for (int i = 0; i < 3; i++) {
        if (gap[i][0] == gap[i][1] && gap[i][0] == gap[i][2]) {
            return false;
        }
        if (gap[0][i] == gap[1][i] && gap[0][i] == gap[2][i]) {
            return false;
        }
    }

    if (gap[0][0] == gap[1][1] && gap[0][0] == gap[2][2]) {
        return false;
    }
    if (gap[0][2] == gap[1][1] && gap[0][2] == gap[2][0]) {
        return false;
    }

    // Check for a draw
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (gap[i][j] != 'X' && gap[i][j] != 'O') {
                return true;
            }
        }
    }
    return false;
}

int main() {
    cout << "What is the name of the first player? ";
    cin >> player1;
    cout << "What is the name of the second player? ";
    cin >> player2;

    while (result()) {
        Table();
        player_turn();
    }

    // Determine the winner after the game has ended
    string winner;
    if (turn == 'X') {
        winner = player2; // Player 2 (O) has won
    }
    else if (turn == 'O') {
        winner = player1; // Player 1 (X) has won
    }
    else {
        winner = "Nobody"; // It's a draw
    }

    if (winner != "Nobody") {
        cout << winner << " has won!" << endl;
    }
    else {
        cout << "It's a draw!" << endl;
    }

    return 0;
}
