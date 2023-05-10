#include <iostream>
#include "/public/colors.h"
using namespace std;

const int BOARD = 10;
int COL[BOARD] = {1, 2, 3, 4, 5, 6, 7, 8, 9 , 10};
char ROW [BOARD] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'};
char board[BOARD][BOARD]; //player 1 board
char board2[BOARD][BOARD]; //player 2 board
char hit_board[BOARD][BOARD]; //Player 2 Offense
char hit_board2[BOARD][BOARD]; //Player 1 Offense

int hits = 0;
int misses = 0;

void player1_board() {
	//cout << "  ";
	for (int col = 0; col < BOARD; col++) {
	//	cout << CYAN << COL[col] << WHITE << " "; //prints the outer int colums
	}
	//cout << endl;
	for (int row = 0; row < BOARD; row++) {
	//	cout << MAGENTA <<  ROW[row] << WHITE << " "; // prints the outer char rows
		for (int col = 0; col < BOARD; col++) {
			board[0][0] = '*';
			board[0][1] = '*';
			board[0][2] = '*';
			board[0][3] = '*';
			board[0][4] = '*';
			board[3][2] = '*';
			board[4][2] = '*';
			board[5][2] = '*';
			board[4][2] = '*';
			board[7][8] = '*';		
			board[8][8] = '*';
			board[9][8] = '*';
		 //if (board[row][col] == '*') { cout << "* "; }
		//else { cout << "- "; }
	//	}
	//	cout << endl;        
		}
	}
}
void player2_board() {

}

void updateBoard(int row, int col) {
  cout << "  ";
  for (int col = 0; col < BOARD; col++) {
        cout << CYAN << COL[col] << WHITE << " "; //prints the outer int colums
    	}
    cout << endl;
    for (int i = 0; i < BOARD; i++) {
        cout << MAGENTA << ROW[i] << WHITE << " ";
        for (int j = 0; j < BOARD; j++) {
			if (i == row and j == col) {  
              if (board[i][j] == '*') {
                  hit_board[i][j] = '*';  
				  hits ++;
             	}
               if (board[i][j] != '*') {
				  hit_board[i][j] = 'X';
				   misses ++;
                }
			 }
			   if (hit_board[i][j] == '*') {
               cout << GREEN << "* " << WHITE;   
	      	 } else if (hit_board[i][j] == 'X') {
			   cout << RED << "X " << WHITE;
			 } else  { cout << "- "; }  
        }
        cout << endl;
    }
	cout << "Hits: " << hits << endl;
	cout << "Misses: " << misses << endl;
}

void updateBoard2(int row, int col) {

}

void battle() {
player1_board();
     while (true) {
		if (hits == 12) { 
		cout << "ALL SHIPS ARE DESTROYED, ABANDONED SHIP" << endl;
		cin.ignore();
		cout << "PLAYER 2 WINS" << endl;
		exit(1);
		}
		if (misses == 10) {
		cout << "YOU HAVE USED UP ALL YOUR CHANCES!" << endl;
		exit(1);
		}
		char choice1;
		cout << "Enter a row to hit a ship" << endl;
		cin >> choice1;
		//if (choice1.length() != 1 or (!isalpha(choice1[0]) or (toupper(choice1[0]) < 'A' or toupper(choice1[0]) > 'J'))) {
		//	cout << "ERROR, MUST USE VALID CHAR" << endl;
		//	continue;
	//	}
		int choice2;
		cout << "Enter a col to hit a ship" << endl;
		cin >> choice2;
		int row = choice1 - 'A'; 
        int col = choice2 - 1;    // convert column number to index
        cout << "Your coordinates are: " << choice1 << choice2 << endl;
       	cin.ignore();
		updateBoard(row, col);
		 }
	}

void battle2() {

}

int main() {
	//player1_board(board);
	battle();
}
