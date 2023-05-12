#include <iostream>
#include "colors.h"
#include <cstdlib>
#include <ctime>


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


void set_ship1() {
	string Carrier;
	string BattleShip;
	string Cruiser;
	string Submarine;
	string Destroyer;
	
	cout << "Player 1, place the cordinates to place your Carrier (Format: 'A5')" << endl;
	printBoard();
	for (int i = 0; i < 5; i++) {
		getline(cin, Carrier);
		if (Carrier.length() < 2 or Carrier.length() > 3  or isdigit(Carrier[0]) or Carrier[0] < 'A' or Carrier[0] > 'J' or stoi(Carrier.substr(1)) < 1 or stoi(Carrier.substr(1)) > BOARD)  {
			cout << "ERROR: MUST USE VALID INPUT" << endl;
			i--;
			continue;
      	}
		int row = Carrier[0] - 'A';
		int col = stoi(Carrier.substr(1));
		col = col - 1;
		board[row][col] = '*';
	}
	printBoard();
	cout << "Player 1, place the cordinates for your Battleship (Format: 'A5')" << endl;
	for (int i = 0; i < 4; i++) {
		getline(cin, BattleShip);
		if (BattleShip.length() < 2 or BattleShip.length() > 3 or isdigit(BattleShip[0]) or BattleShip[0] < 'A' or BattleShip[0] > 'J' or stoi(BattleShip.substr(1)) < 1 or stoi(BattleShip.substr(1)) > BOARD) {
			cout << "ERROR: MUST USE VALID INPUT" << endl;
			i--;
			continue;
		}
		int row = BattleShip[0] - 'A';
		int col = stoi(BattleShip.substr(1));
		col = col - 1;
		board[row][col] = '*';
	}
	printBoard();
	cout << "Player 1, place the cordinates for your Cruiser (Format: 'A5')" << endl;
	for (int i = 0; i < 3; i++) {
		getline(cin, Cruiser);
		if (Cruiser.length() <  2 or Cruiser.length() > 3 or isdigit(Cruiser[0]) or Cruiser[0] < 'A' or Cruiser[0] > 'J' or stoi(Cruiser.substr(1)) < 1 or stoi(Cruiser.substr(1)) > BOARD) {
			cout << "ERROR: MUST USE VALID INPUT" << endl;
			i--;
			continue;
		}
		int row = Cruiser[0] - 'A';
		int col = stoi(Cruiser.substr(1));
        col = col - 1;
		board[row][col] = '*';
  }
	printBoard();
	cout << "Player 1, place the cordinates for your Submarine (Format: 'A5')" << endl;
	for (int i = 0; i < 3; i++) {
		getline(cin, Submarine);
		if (Submarine.length() < 2 or Submarine.length() > 3 or isdigit(Submarine[0]) or Submarine[0] < 'A' or Submarine[0] > 'J' or stoi(Submarine.substr(1)) < 1 or stoi(Submarine.substr(1)) > BOARD) {
			cout << "ERROR: MUST USE VALID INPUT" << endl;
			i--;
			continue;
		}
		int row = Submarine[0] - 'A';
		int col = stoi(Submarine.substr(1));
        col = col - 1;
		board[row][col] = '*';
	}
	printBoard();
	cout << "Player 1, place the cordinates for your Destroyer (Format: 'A5')" << endl;
	for (int i = 0; i < 2; i++) {
		getline(cin, Destroyer); 
		if (Destroyer.length() < 2 or Destroyer.length() > 3 or isdigit(Destroyer[0]) or Destroyer[0] < 'A' or Destroyer[0] > 'J' or stoi(Destroyer.substr(1)) < 1 or stoi(Destroyer.substr(1)) > BOARD) {
			cout << "ERROR: MUST USE VALID INPUT" << endl;
			i--;
			continue;
		}
		 int row = Destroyer[0] - 'A';
         int col = stoi(Destroyer.substr(1));
         col = col - 1;
         board[row][col] = '*';
	
	}
	printBoard();
}

void set_ship2() {
 string Carrier;
    string BattleShip;
    string Cruiser;
    string Submarine;
    string Destroyer;

    cout << "Player 2, chose the cordinates to place your Carrier (Format: 'A5')" << endl;
    for (int i = 0; i < 5; i++) {
        getline(cin, Carrier);
        if (Carrier.length() != 2 or isdigit(Carrier[0]) or Carrier[0] < 'A' or Carrier[0] > 'J' or stoi(Carrier.substr(1)) < 1 or stoi(Carrier.substr(1)) > BOARD) {
            cout << "ERROR: MUST USE VALID INPUT" << endl;
            i--;
            continue;
        }

        int row = Carrier[0] - 'A';
        int col = stoi(Carrier.substr(1));
        col = col - 1;
		board2[row][col] = '*';
    }
    cout << "Player 2, place the cordinates for your Battleship (Format: 'A5')" << endl;
    for (int i = 0; i < 4; i++) {
        getline(cin, BattleShip);
        if (BattleShip.length() != 2 or isdigit(BattleShip[0]) or BattleShip[0] < 'A' or BattleShip[0] > 'J' or stoi(BattleShip.substr(1)) < 1 or stoi(BattleShip.substr(1)) > BOARD) {
            cout << "ERROR: MUST USE VALID INPUT" << endl;
            i--;
            continue;
        }
        int row = BattleShip[0] - 'A';
        int col = stoi(BattleShip.substr(1));
        col = col - 1;
		board2[row][col] = '*';
    }
    cout << "Player 2, place the cordinates for your Cruiser (Format: 'A5')" << endl;
    for (int i = 0; i < 3; i++) {
        getline(cin, Cruiser);
        if (Cruiser.length() != 2 or isdigit(Cruiser[0]) or Cruiser[0] < 'A' or Cruiser[0] > 'J' or stoi(Cruiser.substr(1)) < 1 or stoi(Cruiser.substr(1)) > BOARD) {
            cout << "ERROR: MUST USE VALID INPUT" << endl;
            i--;
            continue;
        }
        int row = Cruiser[0] - 'A';
        int col = stoi(Cruiser.substr(1));
        col = col - 1;
		board2[row][col] = '*';
    }
    cout << "Player 2, place the cordinates for your Submarine (Format: 'A5')" << endl;
    for (int i = 0; i < 3; i++) {
        getline(cin, Submarine);
        if (Submarine.length() != 2 or isdigit(Submarine[0]) or Submarine[0] < 'A' or Submarine[0] > 'J' or stoi(Submarine.substr(1)) < 1 or stoi(Submarine.substr(1)) > BOARD) {
            cout << "ERROR: MUST USE VALID INPUT" << endl;
            i--;
            continue;
        }
        int row = Submarine[0] - 'A';
        int col = stoi(Submarine.substr(1));
        col = col - 1;
		board2[row][col] = '*';
    }
	  cout << "Player 2, place the cordinates for your Destroyer (Format: 'A5')" << endl;                                                                                                               
        for (int i = 0; i < 2; i++) { 
			getline(cin, Destroyer);
	  		if (Destroyer.length() != 2 or isdigit(Destroyer[0]) or Destroyer[0] < 'A' or Destroyer[0] > 'J' or stoi(Destroyer.substr(1)) < 1 or stoi(Destroyer.substr(1)) > BOARD) {
			cout << "ERROR: MUST USE VALID INPUT" << endl;
            i--;
            continue;
		}
	  	int row = Destroyer[0] - 'A';
        int col = stoi(Destroyer.substr(1));
        col = col - 1;
		board2[row][col] = '*';
	}
}
		void player1_board() {	
			set_ship1();
			cout << CYAN << "Player 1 this is your board!" << WHITE << endl;
			cout << "  ";
			for (int col = 0; col < BOARD; col++) {
				cout << CYAN << COL[col] << WHITE << " "; //prints the outer int colums
			}
			cout << endl;
			for (int row = 0; row < BOARD; row++) {
			 cout << MAGENTA <<  ROW[row] << WHITE << " "; // prints the outer char rows
				for (int col = 0; col < BOARD; col++) {
		     		if (board[row][col] == '*') { cout << GREEN << "* " << WHITE; }
					else { cout << "- "; }
				}
				cout << endl;        
			}
		}

		void player2_board() {
			set_ship2();
			cout << RED << "Player 2, this is your board!" << WHITE << endl;
			cout << "  ";
			  for (int col = 0; col < BOARD; col++) {
			  cout << YELLOW << COL[col] << WHITE << " "; //prints the outer int colums
			    }
			cout << endl;
			for (int row = 0; row < BOARD; row++) {
				  cout << GREEN <<  ROW[row] << WHITE << " "; // prints the outer char rows
				for (int col = 0; col < BOARD; col++) {
					   if (board2[row][col] == '*') { cout << GREEN << "* "; }
					else { cout << "- "; }
					 }
				cout << endl;
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
		 cout << "These are Battle-Ships you will use for the game: " << endl;
   		 cout << " Carrier(5 spaces)" << endl;
    	 cout << " Battleship(4 spaces)" << endl;
   		 cout << " Cruiser(3 spaces)" << endl;
    	 cout << " Submarine(3 spaces)" << endl;
   	 	 cout << " Destoyer(2 spaces)" << endl;
		Battle_Ship();
	   // player1_board();
		//player2_board();
	}
