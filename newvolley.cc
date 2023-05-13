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


// Please make a question class, this would make things a lot easier instead of these offests of five thing for the vectors of strings..
// You have a alot of work to do..
// Added colors.h and read.h to local directories..
// - Alex~
class questionSet{
	private:
		string q;
		string a1;
		string a2;
		string a3;
		string a4;
	public:
		questionSet(string new_q, string new_a, string new_a2, string new_a3, string new_a4){
			q = new_q; a1 = new_a; a2 = new_a2; a3 = new_a3; a4 = new_a4;
		}
		//No sets because all questions will be added in CSTOR only
		string get_a1(){return a1;}
		string get_a2(){return a2;}
		string get_a3(){return a3;}
		string get_a4(){return a4;}
		string get_q(){return q;}
};

// Function prototypes
// int myrandom (const int &i);
int volley(vector<questionSet> &qaDB, int &qSet);
int print_Questions(vector<questionSet> &vec, int x);

int main(){
	srand (time(0));	//cpp ref code
	vector<questionSet> qaDB;
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
			questionSet temp(question,ans1,ans2,ans3,ans4);
			qaDB.push_back(temp);
		}
		fs.close();
	}// ALL FOR INPUT FILE
	std::random_device generator;
	std::mt19937 dist(generator());
	std::shuffle(qaDB.begin(),qaDB.end(),dist); // used betancourt randomnizer on the entire question set to get unique questions every new run

	int qSet = 0;// used to traverse the question DB

	// You need to fix that, I tired fixing it but it would be way to much..
	// fixed i think bruhaps?

	int outcome = 0;
	outcome = volley(qaDB,qSet);
	if (outcome == 2) cout << "Player 2 gets 3 shots" << endl;
	else if (outcome == 1) cout << "Player 1 gets 3 shots" << endl;
	else if (outcome == -1) cout << "DRAW" << endl;
	else if (outcome == 0) cout << "NO ONE WINS AHAHAHAHAHAHAHAHA" << endl;


}


int print_Questions(vector<questionSet> &vec, int x){
	cout << YELLOW << "--------------------------------------" << RESET << endl;
	for(int i = 0; i < vec.at(x).get_q().size(); i++){
		if (vec.at(x).get_q().at(i) == 'n' and vec.at(x).get_q().at(i-1) == '\\' ) cout << endl;
		else if (vec.at(x).get_q().at(i) == '\\' and vec.at(x).get_q().at(i+1) == 'n' ) continue;
		else cout << vec.at(x).get_q().at(i);
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
	int correct = 0;// used to echo the correct choice with int input
	// I made it look nicer..
	cout << YELLOW << "--------------------------------------" << RESET << endl;
	cout << GREEN << "1. ";
	if (r == 1){ cout << vec.at(x).get_a1() << endl; correct = 1;}
	else if (r == 2 ) cout << vec.at(x).get_a2() << endl;						
	else if (r == 3 ) cout << vec.at(x).get_a3() << endl;						
	else if (r == 4 ) cout << vec.at(x).get_a4() << endl;						
	cout << RED << "2. ";
	if (r2 == 1){ cout << vec.at(x).get_a1() << endl; correct = 2;}
	else if (r2 == 2 ) cout << vec.at(x).get_a2() << endl;						
	else if (r2 == 3 ) cout << vec.at(x).get_a3() << endl;						
	else if (r2 == 4 ) cout << vec.at(x).get_a4() << endl;						
	cout << BLUE << "3. ";
	if (r3 == 1){ cout << vec.at(x).get_a1() << endl;correct = 3;}
	else if (r3 == 2 ) cout << vec.at(x).get_a2() << endl;						
	else if (r3 == 3 ) cout << vec.at(x).get_a3() << endl;						
	else if (r3 == 4 ) cout << vec.at(x).get_a4() << endl;						
	cout << YELLOW << "4. ";
	if (r4 == 1){ cout << vec.at(x).get_a1() << endl;correct = 4;}
	else if (r4 == 2 ) cout << vec.at(x).get_a2() << endl;						
	else if (r4 == 3 ) cout << vec.at(x).get_a3() << endl;						
	else if (r4 == 4 ) cout << vec.at(x).get_a4() << endl;						
	cout << YELLOW << "--------------------------------------" << RESET << endl;
	return correct;
}

int volley(vector<questionSet> &qaDB, int &qSet){
	int turn = 0;
	duration<float> time {60s};//VARIABLE TO SAVE TIME DURATION SET TO 60 INITIALLY
	int pts = 0;//used to check who right answers first
	int pts2 = 0;//used to check who right answers first
	int correct = 0;
	while (true){
		auto start = system_clock::now();//start Player 1 time
		if (qSet >= qaDB.size()){//Make sure question set doesnt go out of bounds
			cout << "NO ONE WINS OUT OF QUESTIONS SORRY" << endl;
			return 0;
		}
		string input;
		correct  = print_Questions(qaDB,qSet);
		if (turn == 0){
			cout << "PLAYER 1 says: " << endl;
			getline(cin,input);
			if (stoi(input) == correct){ 
				cout << GREEN << "good job PLAYER 1\n\n" << WHITE << endl;
				qSet++;//If correct move vector up 1 to next question set This is so i can reshuffle the vector and q and A's
				pts++;// activate the timer after someone gets a questions right

			}
			else {cout << RED << "wrong!" << WHITE << endl;
				if (pts > 0 or pts2 > 0) {cout << "P1 Lost sorry!\n"; return 2;}
			}
			//if (fAns == 1){cout << "you answered to long dead!\n";break;} //LOSE SO LEAVE
			turn = 1;
		}	
		correct = 0;//reset correct answer
		auto end = system_clock::now();//End Player 1 Time
		duration<float> dur = end - start;// Save Player 1 Time
		if (time < dur and pts2 > 0){cout << "u answered out of time noob" << endl; return 2;}// If P1 time was longer than saved time after someone answerd correctly first fail him
		time = dur;// else save Player 1 time
		if (pts > 0 or pts2 > 0)cout << "time to beat " << duration_cast<seconds>(time).count() << " seconds" << endl;

		correct = print_Questions(qaDB,qSet);

		auto start2 = system_clock::now();//start Player 2 Time
		if (turn == 1){
			cout << "PLAYER 2 says: " << endl;
			getline(cin,input);
			if (stoi(input) == correct){ 
				cout << GREEN << "good job PLAYER 2 \n\n"<< WHITE <<endl;
				qSet++;
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

