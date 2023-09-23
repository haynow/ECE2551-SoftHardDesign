#include <iostream>

using namespace std;

// Global Variables
char board[3][3] = {
    {' ', ' ', ' '},
    {' ', ' ', ' '},
    {' ', ' ', ' '}
};

void displayBoard() {     // Form The Board
    cout << "    C1  C2  C3" << endl;
    cout << "   +---+---+---+" << endl;
    for (int i = 1; i <= 3; i++) {
        cout << "R" << i << " | ";
        for (int j = 0; j < 3; ++j) {
            cout << board[i-1][j] << " | ";
        }
        cout << endl;
        cout << "   +---+---+---+" << endl;
    }
}

char checkWinner() {
    char winner[9]; // 9 because theres only 9 total winning chances
    winner[0] = ' '; // For Tie States
    int winner_size = 0;
    for (int i = 0; i < 3; ++i) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != ' ') { // X Axis Check
            winner[winner_size] = board[i][0];
            winner_size++;
        }
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != ' ') { // Y Axis Check
            winner[winner_size] = board[0][i];
            winner_size++;
        }
    }

    if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != ' ') { // L -> R Lateral
        winner[winner_size] = board[0][0];
        winner_size++;
    }
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != ' ') { // R -> L Lateral
        winner[winner_size] = board[0][2];
        winner_size++;
    }

    if (winner[0] == ' ') {
        return 't'; // return tie 
    }

    for (int i = 0; i < winner_size; i++) {
        if (winner[0] != winner[i]) {
            return 'i'; // return invalid game
        }
    }
    return winner[0]; // return winner
}

bool isValidInput(int input) {
    return (input >= 0 && input <= 7);
}

int main() {                    // Ask for the input values, binary, so 7 = 1,1,1 while 2 = 0,1,0
    bool loop = true;

    while (loop) {

        for (int i = 0; i < 3; ++i) {
            int rowValue;
            do {
                cout << "Input Row #" << i + 1 << " (Values between 0-7): ";
                cin >> rowValue;
            } while (!isValidInput(rowValue));

            for (int j = 0; j < 3; ++j) {
                board[i][j] = (rowValue & (1 << j)) ? 'X' : 'O';
            }
        }


        displayBoard();

        char winner = checkWinner();                       //Results
        if (winner == 'X' || winner == 'O') {
            cout << "Who Won?: " << winner << endl;
        }

        else if (winner == 't') {

            cout << "It's a tie!" << endl;
        }

        else {
            cout << "Not a valid Tic-Tac-Toe game!" << endl << "Play again." << endl;  //If multiple winners
            cout << endl;
                
        }

        char playAgain;
        cout << "Would you like to play again? (Y / N): ";   //Ask to play again, Y means yes anything else means no
        cin >> playAgain;
        if (playAgain != 'Y')
            loop = false;
    }

    return 0;
}