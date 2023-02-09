#include<iostream>
#include<stdlib.h>
using namespace std;
char gap[3][3] = { {'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'} };
char turn = 'X';
bool draw = false;
string player1, player2;
int choice;
int row, column;

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
    if (turn == 'X') {
        //cout << "your turn: " << player1 << endl;
    }
    else if (turn == 'O') {
        //cout << "your turn: " << player1 << endl;
    }
    cin >> choice;

    switch (choice)
    {
    case 1:
        row = 0;
        column = 0;
        break;
    case 2:
        row = 0;
        column = 1;
        break;
    case 3:
        row = 0;
        column = 2;
        break;
    case 4:
        row = 1;
        column = 0;
        break;
    case 5:
        row = 1;
        column = 1;
        break;
    case 6:
        row = 1;
        column = 2;
        break;
    case 7:
        row = 2;
        column = 0;
        break;
    case 8:
        row = 2;
        column = 1;
        break;
    case 9:
        row = 2;
        column = 2;
        break;
    default:
        cout << "invalid choice!" <<  endl;
    }

    if (turn == 'X' && gap[row][column] != 'X' && gap[row][column] != 'O') {
       
        gap[row][column] = 'X';
        turn = 'O';
        cout << "your turn: " << player2 << endl;
    }
    else if (turn == 'O' && gap[row][column] != 'X' && gap[row][column] != 'O') {
        
        gap[row][column] = 'O';
        turn = 'X';
        cout << "your turn: " << player1 << endl;

    }
    else {
       
        cout << "the space is full, choose another one" << endl;
        player_turn();
    }
    
    (Table);
}
bool result() {
    
    for (int i = 0; i < 3; i++)
        if (gap[i][0] == gap[i][1] && gap[i][0] == gap[i][2] || gap[0][i] == gap[1][i] && gap[0][i] == gap[2][i])
            return false;

    

    if (gap[0][0] == gap[1][1] && gap[0][0] == gap[2][2] || gap[0][2] == gap[1][1] && gap[0][2] == gap[2][0])
        return false;

    
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (gap[i][j] != 'X' && gap[i][j] != 'O')
                return true;
    draw = true;
    return false;
}

int main()
{
    cout << "what is the name of the first player?" << endl;
    cin >> player1;
    cout << "what is the name of the second player?" << endl;
    cin >> player2;

    while(result()) {
        Table();
        player_turn();
        (result);
    }
    if (turn == 'X' && draw == false) {
        cout << player1 << "has won!" << endl;
    }
    else if (turn == 'O' && draw == false) {
        cout << player2 << " has won!" << endl;
    }
    else
        cout << "it's a draw";


}
  