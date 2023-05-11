#include <iostream>
#include "/public/colors.h"
#include <cstdlib>
#include <ctime>
using namespace std;

const int BOARD = 10;
int COL[BOARD] = {1, 2, 3, 4, 5, 6, 7, 8, 9 , 10};
char ROW [BOARD] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'};
char board[BOARD][BOARD]; //player 1 set  board
char board2[BOARD][BOARD]; //player 2 set board
char hit_board[BOARD][BOARD]; //Player 2 attack board
char hit_board2[BOARD][BOARD]; //Player 1 attack board

int hits = 0; 
int misses = 0;
int hits2 = 0;
int misses2 = 0;

void player1_board() {
//	cout << "  ";
//	for (int col = 0; col < BOARD; col++) {
//		cout << CYAN << COL[col] << WHITE << " "; //prints the outer int colums
//	}
//	cout << endl;
	for (int row = 0; row < BOARD; row++) {
//		cout << MAGENTA <<  ROW[row] << WHITE << " "; // prints the outer char rows
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
		// if (board[row][col] == '*') { cout << "* "; }
		//else { cout << "- "; }
		//}
	 //	cout << endl;        
		}
	}
}

void player2_board() {
//cout << "  ";
  //  for (int col = 0; col < BOARD; col++) {
    // cout << CYAN << COL[col] << WHITE << " "; //prints the outer int colums
   // }
    //cout << endl;
    for (int row = 0; row < BOARD; row++) {
    //  cout << MAGENTA <<  ROW[row] << WHITE << " "; // prints the outer char rows
        for (int col = 0; col < BOARD; col++) {
            board2[9][1] = '*';
            board2[9][2] = '*';
            board2[9][3] = '*';
            board2[9][4] = '*';
            board2[5][5] = '*';
            board2[6][5] = '*';
            board2[7][5] = '*';
            board2[2][2] = '*';
            board2[3][2] = '*';
            board2[4][2] = '*';
            board2[1][8] = '*';
            board2[1][9] = '*';
      //   if (board[row][col] == '*') { cout << "* "; }
        //else { cout << "- "; }
     // }
     // cout << endl;
        }
    }
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

void updateBoard2(int row2, int col2) {
  cout << "  ";
  for (int col = 0; col < BOARD; col++) {
        cout << YELLOW << COL[col] << WHITE << " "; //prints the outer int colums
        }
    cout << endl;
    for (int i = 0; i < BOARD; i++) {
        cout << GREEN << ROW[i] << WHITE << " ";
        for (int j = 0; j < BOARD; j++) {
            if (i == row2 and j == col2) {
              if (board2[i][j] == '*') {
                  hit_board2[i][j] = '*';
                  hits2 ++;
                }
               if (board2[i][j] != '*') {
                  hit_board2[i][j] = 'X';
                   misses2 ++;
                }
             }
               if (hit_board2[i][j] == '*') {
               cout << GREEN << "* " << WHITE;
             } else if (hit_board2[i][j] == 'X') {
               cout << RED << "X " << WHITE;
             } else  { cout << "- "; }
        }
        cout << endl;
    }
    cout << "Hits: " << hits2 << endl;
    cout << "Misses: " << misses2 << endl;
}

void Battle_Ship() {
player1_board();
player2_board();
while (true) {
		if (hits == 3) { 
		cout << "ALL SHIPS ARE DESTROYED, ABANDONED SHIP" << endl;
		cin.ignore();
		cout << "PLAYER 2 WINS" << endl;
		exit(1);
		}
		if (misses == 10) {
		cout << "YOU HAVE USED UP ALL YOUR MISSES!" << endl;
		exit(1);
		}
		cout << "Player 1 it is your turn!" << endl;
		string choice1;
		cout << "Enter a row to hit a ship (e.g A, B, C...J)" << endl;
		getline(cin, choice1);
		if (choice1.length() != 1 or isdigit(choice1[0]) or choice1 < "A" or choice1 > "J") {
			cout << "ERROR, MUST USE VALID CHAR" << endl;
			continue;	
		} 

		int choice2;
		cout << "Enter a col to hit a ship (e.g 1, 2, 3...10) " << endl;
		cin >> choice2;
		if (choice2 < 1 or choice2 > 10) {
			cout << "ERROR: MUST USE VALID COL" << endl;
			continue;
		} 
		int row = choice1[0] - 'A'; 
        int col = choice2 - 1;   
        cout << "Your cordinates are: " << choice1 << choice2 << endl;
       	cin.ignore();
		updateBoard(row, col);
		// I could seperate these 2 bc it is getting messy
        // But it is working as intended so... yeah :D
		if (hits2 == 3) {
        cout << "ALL SHIPS ARE DESTROYED, ABANDONED SHIP" << endl;
        cin.ignore();
        cout << "PLAYER 1 WINS" << endl;
        exit(1);
        }
        if (misses2 == 10) {
        cout << "YOU HAVE USED UP ALL YOUR MISSES!" << endl;
        exit(1);
        }
		cout << endl;
		cout << "Player 2 it is your turn!" << endl;
        string choice3;
        cout << "Enter a row to hit a ship (e.g A, B, C...J)" << endl;
        getline(cin, choice3);
        if (choice3.length() != 1 or isdigit(choice3[0]) or choice3 < "A" or choice3 > "J") {
            cout << "ERROR, MUST USE VALID CHAR" << endl;
            continue;
        }
        int choice4;
        cout << "Enter a col to hit a ship (e.g 1, 2, 3...10) " << endl;
        cin >> choice4;
        if (choice4 < 1 or choice4 > 10) {
            cout << "ERROR: MUST USE VALID COL" << endl;
            continue;
        }
        int row2 = choice3[0] - 'A';
        int col2 = choice4 - 1;    // convert column number to index
        cout << "Your cordinates are: " << choice3 << choice4 << endl;
        cin.ignore();
        updateBoard2(row2, col2);
		}
	}


int main() {
	 system("figlet 'WELCOME TO BATTLESHIP' | lolcat");
	Battle_Ship();
}
