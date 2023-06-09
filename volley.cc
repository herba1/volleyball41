#include <algorithm>
#include <iostream>
#include <sstream>
#include <fstream>
#include <random>
#include <chrono>
#include <string>
#include <vector>
#include <ctime>
 
#include "colors.h"
#include "read.h"

using namespace std;
using namespace std::chrono;

// Function prototypes
// int myrandom (const int &i);
int volley(vector<string> &qaDB, int &qSet);
void print_Questions(vector<string> &vec, int x);

// Please make a question class, this would make things a lot easier instead of these offests of five thing for the vectors of strings..
// You have a alot of work to do..
// Added colors.h and read.h to local directories..
// - Alex~

int main(){
	srand (time(0));	//cpp ref code
	vector<string> qaDB;
	// Why? there's only one question database..
	// const string file = read("enter a file\n");

	ifstream fs("questions.txt");
	if (!fs){ cout << "error " << endl; exit(1);}
	if (fs.is_open()){
		while (!fs.eof()){
			string question; string ans1; string ans2; string ans3; string ans4;string trash;
			getline(fs,question);
			if (question == "")break;
			getline(fs,ans1);
			getline(fs,ans2);
			getline(fs,ans3);
			getline(fs,ans4);
			getline(fs,trash);//get empty line
			qaDB.push_back(question);
			qaDB.push_back(ans1);
			qaDB.push_back(ans2);
			qaDB.push_back(ans3);
			qaDB.push_back(ans4);
		}
		fs.close();
	}// ALL FOR INPUT FILE


	// cin.ignore();
	int qSet = 0;// by intervals of 5 because 5 things per question used to use vec.at(qSet)
	// You need to fix that, I tired fixing it but it would be way to much..

	int outcome = 0;
	outcome = volley(qaDB,qSet);
	if (outcome == 2) cout << "Player 2 gets 3 shots" << endl;
	else if (outcome == 1) cout << "Player 1 gets 3 shots" << endl;
	else if (outcome == -1) cout << "DRAW" << endl;


}

// int myrandom (const int &i) { return rand()%i;}//cpp ref code for random

void print_Questions(vector<string> &vec, int x){
	cout << YELLOW << "--------------------------------------" << RESET << endl;
	for(int i = 0; i < vec.at(x).size(); i++){
		if (vec.at(x).at(i) == 'n' and vec.at(x).at(i-1) == '\\' ) cout << endl;
		else if (vec.at(x).at(i) == '\\' and vec.at(x).at(i+1) == 'n' ) continue;
		else cout << vec.at(x).at(i);
	}
	cout << endl;
	vector<int> random{1,2,3,4};
	// This is my way of doing randoms.. 
	std::random_device generator;
	std::mt19937 dist(generator());
	std::shuffle(random.begin(),random.end(),dist);
	int r = random.at(0);
	int r2 = random.at(1);
	int r3 = random.at(2);
	int r4 = random.at(3);
	// I made it look nicer..
	cout << YELLOW << "--------------------------------------" << RESET << endl;
	cout << GREEN << "1. "<< WHITE << vec.at(x+r) << endl;
	cout << RED << "2. " << WHITE <<vec.at(x+r2) << endl;
	cout << BLUE << "3. " << WHITE << vec.at(x+r3) << endl;
	cout << YELLOW << "4. " << WHITE << vec.at(x+r4) << endl;
	cout << YELLOW << "--------------------------------------" << RESET << endl;

}

int volley(vector<string> &qaDB, int &qSet){
	int turn = 0;
	duration<float> time {60s};//VARIABLE TO SAVE TIME DURATION SET TO 60 INITIALLY
	int pts = 0;//used to check who right answers first
	int pts2 = 0;//used to check who right answers first
	while (true){
		auto start = system_clock::now();//start Player 1 time
		if (qSet >= qaDB.size()){//Make sure question set doesnt go out of bounds
			cout << "NO ONE WINS OUT OF QUESTIONS SORRY" << endl;
			return 0;
		}
		string input;
		print_Questions(qaDB,qSet);
		if (turn == 0){
			cout << "PLAYER 1 says: " << endl;
			getline(cin,input);
			if (input == (qaDB.at(qSet+1))){ 
				cout << GREEN << "good job PLAYER 1\n\n" << WHITE << endl;
				qSet+=5;//If correct move vector questions up 5 so next question set
				pts++;// activate the timer after someone gets a questions right

			}
			else {cout << RED << "wrong!" << WHITE << endl;
				if (pts > 0 or pts2 > 0) {cout << "P1 Lost sorry!\n"; return 2;}
			}
			//if (fAns == 1){cout << "you answered to long dead!\n";break;} //LOSE SO LEAVE
			turn = 1;
		}	
		auto end = system_clock::now();//End Player 1 Time
		duration<float> dur = end - start;// Save Player 1 Time
		if (time < dur and pts2 > 0){cout << "u answered out of time noob" << endl; return 2;}// If P1 time was longer than saved time after someone answerd correctly first fail him
		time = dur;// else save Player 1 time
		if (pts > 0 or pts2 > 0)cout << "time to beat " << duration_cast<seconds>(time).count() << " seconds" << endl;

		print_Questions(qaDB,qSet);

		auto start2 = system_clock::now();//start Player 2 Time
		if (turn == 1){
			cout << "PLAYER 2 says: " << endl;
			getline(cin,input);
			if (input == (qaDB.at(qSet+1))){ 
				cout << GREEN << "good job PLAYER 2 \n\n"<< WHITE <<endl;
				qSet+=5;
				pts2++;//same as above
			}
			else{ cout << RED << "wrong!" << WHITE << endl;
				if (pts > 0 or pts2 > 0) {cout << "P2 Lost sorry!\n";  return 1;}
			}
			turn = 0;
		}	
		auto end2 = system_clock::now();//end player 2 time
		duration<float> dur2 = end2 - start2;// save P2 time
		if (dur2 > time and pts > 0){ cout << "u ansard out of time" << " seconds" << endl; return 1;}
		time = dur2; // save P2 Time
		if (pts > 0 or pts2 > 0)cout << "time to beat " << duration_cast<seconds>(time).count() << endl;
	}

}