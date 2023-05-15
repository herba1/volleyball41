#include <iostream>
#include "colors.h"
#include <cstdlib>
#include <vector>

#include"newvolley.cc"

using namespace std;


const int BOARD = 10;
int COL[BOARD] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
char ROW [BOARD] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'};
char board[BOARD][BOARD]; //player 1 set  board
char board2[BOARD][BOARD]; //player 2 set board
char hit_board[BOARD][BOARD]; //Player 2 attack board
char hit_board2[BOARD][BOARD]; //Player 1 attack board

int hits = 0; 
int misses = 0; 
int hits2 = 0;
int misses2 = 0;

void printBoard() {
	cout << "  ";
	for (int col = 0; col < BOARD; col++) {
		cout << CYAN << COL[col] << WHITE << " "; 
	}
	cout << endl;
	for (int i = 0; i < BOARD; i++) {
		cout << MAGENTA << ROW[i] << WHITE << " ";
		for (int j = 0; j < BOARD; j++) {
			if (board[i][j] == '*') {
				cout << GREEN << "* " << WHITE;
			} else { cout << "- "; }
		}
		cout << endl;
	}
}
void printBoard2() {
	cout << "  ";
	for (int col = 0; col < BOARD; col++) {
		cout << BLUE << COL[col] << WHITE << " ";
	}
	cout << endl;
	for (int i = 0; i < BOARD; i++) {
		cout << YELLOW << ROW[i] << WHITE << " ";
		for (int j = 0; j < BOARD; j++) {
			if (board2[i][j] == '*') {
				cout << GREEN << "* " << WHITE;
			} else { cout << "- "; }
		}
		cout << endl;
	}
}

void set_ship1() {
	vector<string> ships = {"Carrier", "Battleship", "Cruiser", "Submarine", "Destroyer"};
	vector<int> ships_size = {5, 4, 3, 3, 2};
	int i = 0;
	while(i < ships.size()) {
		string ship = ships[i];
		int size = ships_size[i];
		cout << YELLOW << "- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -" << WHITE << endl;
		cout << GREEN << "Player 1" << WHITE << " place the cordinate to place your " << ship << " with a size of " << size  << " spaces (Format: 'A5')" << endl;
		printBoard();
		string user;
		getline(cin, user);
		if (user.length() < 2 or user.length() > 3 or !isalpha(user[0]) or !isdigit(user[1]) or (user.length() == 3 and !isdigit(user[2])) or user[0] < 'A' or user[0] > 'J' or stoi(user.substr(1)) < 1 or stoi(user.substr(1)) > BOARD) {  
			cout << RED << "ERROR: MUST USE A VALID COORDINATE"  << WHITE << endl; 
			continue;
		}
		int row = user[0] - 'A';
		int col = stoi(user.substr(1)) - 1;
		string choice;
		cout << "Type 'H' for horizontal or 'V' for vertical" << endl;
		getline(cin, choice);
		if (choice.length() > 1 or choice.length() < 1  or !isalpha(choice[0]) or (choice != "H" and choice != "V")) 	{ 
			cout << RED <<  "ERROR: INVALID INPUT" << WHITE; 
			continue;
		}

		if (choice == "H") {
			for (int i = col; i < col + size; i++) {
				if (col + size > BOARD) {
					cout <<  RED <<  "ERROR: MUST STAY IN BOUNDS" << WHITE << endl;
					exit(1);
				}
				else if (board[row][i] == '*') {
					cout << RED << "ERROR: SHIPS CANNOT OVERLAP" << WHITE << endl;
					exit(1);
				}
				else board[row][i] = '*';
			}
		}

		if (choice == "V") {
			for (int i = row; i < row + size; i++) {
				if (row + size > BOARD) {
				cout << RED <<  "ERROR: MUST STAY IN BOUNDS" << WHITE << endl;
				exit(1);
			}
				else if (board[i][col] == '*') {
				cout << RED << "ERROR: SHIPS CANNOT OVERLAP" << WHITE << endl;
				exit(1);
				}
			 	else board[i][col] = '*';
			}
		}

		i++;
		if (i == 5) { 
			cout << "Player 1, this is your board! GOODLUCK!" << endl;
			printBoard();
			break;
		}
	}
}

void set_ship2() {
	vector<string> ships = {"Carrier", "Battleship", "Cruiser", "Submarine", "Destroyer"};
	vector<int> ships_size = {5, 4, 3, 3, 2};
	int i = 0;
	while(i < ships.size()) {
		string ship = ships[i];
		int size = ships_size[i];
		cout << YELLOW << "- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -" << WHITE << endl;
		cout << CYAN << "Player 2" << WHITE << " place the cordinate to place your " << ship << " with a size of " << size  << " spaces (Format: 'A5')" << endl;
		printBoard2();
		string user;
		getline(cin, user);
		if (user.length() < 2 or user.length() > 3 or !isalpha(user[0]) or !isdigit(user[1]) or (user.length() == 3 and !isdigit(user[2])) or user[0] < 'A' or user[0] > 'J' or stoi(user.substr(1)) < 1 or stoi(user.substr(1)) > BOARD) {
			cout << RED << "ERROR: MUST USE A VALID COORDINATE"  << WHITE << endl;
			continue;
		}
		int row = user[0] - 'A';
		int col = stoi(user.substr(1)) - 1;
		string choice;
		cout << "Type 'H' for horizontal or 'V' for vertical" << endl;
		getline(cin, choice);
		if (choice.length() > 1 or choice.length() < 1  or !isalpha(choice[0]) or (choice != "H" and choice != "V")) {	
				cout << RED <<  "ERROR: INPUT MUST BE VALID, MUST BE IN BOUNDS, AND CANNOT OVERLAP'\n" << WHITE;
			continue;
		}

		 if (choice == "H") {
            for (int i = col; i < col + size; i++) {
                if (col + size > BOARD) {
                    cout <<  RED <<  "ERROR: MUST STAY IN BOUNDS" << WHITE << endl;
                    exit(1);
                }
                else if (board2[row][i] == '*') {
                    cout << RED << "ERROR: SHIPS CANNOT OVERLAP" << WHITE << endl;
                    exit(1);
                }
                else board2[row][i] = '*';
            }
        }

        if (choice == "V") {
            for (int i = row; i < row + size; i++) {
                if (row + size > BOARD) {
                cout << RED <<  "ERROR: MUST STAY IN BOUNDS" << WHITE << endl;
                exit(1);
            }
                else if (board2[i][col] == '*') {
                cout << RED << "ERROR: SHIPS CANNOT OVERLAP" << WHITE << endl;
                exit(1);
                }
                else board2[i][col] = '*';
            }
        }

		i++;
		if (i == 5) {
			cout << CYAN << "Player 2, this is your board! GOODLUCK!" << endl;
			printBoard2();
			break;
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


void Battle_Ship(vector<questionSet> &qaDB, int &qSet) {
	//set_ship1(); //herb
	//set_ship2();	// herb

	while (true) {
		if (hits == 3) { 
			cout << "ALL SHIPS ARE DESTROYED, ABANDONED SHIP" << endl;
			cin.ignore();
			cout << "PLAYER 1 WINS" << endl;
			exit(1);
		}
		if (misses == 10) {
			cout << "YOU HAVE USED UP ALL YOUR MISSES!" << endl;
			exit(1);
		}
		if (hits2 == 3) {
			cout << "ALL SHIPS ARE DESTROYED, ABANDONED SHIP" << endl;
			cin.ignore();
			cout << "PLAYER 2 WINS" << endl;
			exit(1);
		}
		if (misses2 == 10) {
			cout << "YOU HAVE USED UP ALL YOUR MISSES!" << endl;
			exit(1);
		}
		// default to player one

		int battleTurn = 0;// herb
		cout << endl;
		battleTurn = volley(qaDB,qSet);
		cin.ignore();

		if(battleTurn == 1){
			cout << "Player 1 it is your turn!" << endl;
			cout << "You have 3 shots " << endl;
			set_ship1();
			for (int i = 0; i < 3; i++){
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
				cout << endl;
			}
		}
		if (battleTurn == 1) continue;//after it runs go back to answer jeopardy
		if (battleTurn == 2){

			cout << "Player 2 it is your turn!" << endl;
			cout << "You get 3 Shots" << endl;
			set_ship2();
			for (int i = 0; i < 3; i++){
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
		if (battleTurn == 2) continue; // same as above
		else if(battleTurn == 0) {cout << "draw\n"; exit(1);}
		else cout << "volley fail check me" << endl;
	}

}

/*
   int main() {
   system("figlet 'WELCOME TO BATTLESHIP' | lolcat");
   cout << "These are Battle-Ships you will use for the game: " << endl;
   cout << " Carrier(5 spaces)" << endl;
   cout << " Battleship(4 spaces)" << endl;
   cout << " Cruiser(3 spaces)" << endl;
   cout << " Submarine(3 spaces)" << endl;
   cout << " Destoyer(2 spaces)" << endl;
//	set_ship1();
set_ship2();
//	Battle_Ship();
// player1_board();
//player2_board();
}*/
