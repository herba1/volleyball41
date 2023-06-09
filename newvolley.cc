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
#include<gtest/gtest.h>
using namespace std;
using namespace std::chrono;


// Thanks for taking the advice, code looks good now!
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
template<typename T>
void shuffle_vector(vector<T> &vec);
int volley(vector<questionSet> &qaDB, int &qSet);
int print_Questions(vector<questionSet> &vec, int x);

	vector<questionSet> qaDB;
/*

int main(int argc, char** argv){
	testing::InitGoogleTest(&argc, argv);
	srand (time(0));	//cpp ref code
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
	shuffle_vector(qaDB);
	// used betancourt randomnizer on the entire question set to get unique questions every new run

	int qSet = 0;// used to traverse the question DB


	return RUN_ALL_TESTS();

}*/
/*
	TEST(printQuestions, BadTest) {
		EXPECT_EQ(print_Questions(qaDB, -1), 0);
		EXPECT_EQ(print_Questions(qaDB, -2'000'000'000), 0);
		EXPECT_EQ(print_Questions(qaDB, qaDB.size()+1), 0);
		EXPECT_EQ(print_Questions(qaDB, qaDB.size()+90), 0);
		EXPECT_EQ(print_Questions(qaDB, qaDB.size()+10000000), 0);
	}
	TEST(printQuestions, GoodTest) {
		EXPECT_EQ(print_Questions(qaDB, 0), 1 or 2 or 3 or 4);//test min
		EXPECT_EQ(print_Questions(qaDB, 13), 1 or 2 or 3 or 4);//test normal
		EXPECT_EQ(print_Questions(qaDB, qaDB.size()-1), 1 or 2 or 3 or 4);//test max
	}
*/
// You could make this a member of the questionSet class..
int print_Questions(vector<questionSet> &vec, int x){
	if (x<0 or x >= vec.size())return 0;//out of questions 
	cout << YELLOW << "--------------------------------------" << RESET << endl;
	for(int i = 0; i < vec.at(x).get_q().size(); i++){
		if (vec.at(x).get_q().at(i) == 'n' and vec.at(x).get_q().at(i-1) == '\\' ) cout << endl;
		else if (vec.at(x).get_q().at(i) == '\\' and vec.at(x).get_q().at(i+1) == 'n' ) continue;
		else cout << vec.at(x).get_q().at(i);
	}

	cout << endl;
	vector<int> random{1,2,3,4};
	// This is my way of doing randoms.. 
	shuffle_vector(random);
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
		auto start = system_clock::now();//start Player 1 t4ime
		if (qSet >= qaDB.size() or qSet < 0){//Make sure question set doesnt go out of bounds
			cout << "NO ONE WINS OUT OF QUESTIONS...SORRY!" << endl;
			return 0;
		}
		//int input = 0;
		correct  = print_Questions(qaDB,qSet);
		if (turn == 0){
			cout << "PLAYER 1 says:(choose a number 1 - 4):  " << endl;
			// Use read, you don't have to stoi
			int input = -1;
			set_raw_mode(true);
			while (true){
				input = quick_read();
				if(input == ERR)usleep(10'000);
				else if (input > 0) break;
			}
			set_raw_mode(false);
			input -= 48;
			if (input < 1 or input > 4) cout << input << " BOO YOUU BAD ANSA \n";
			if (input == correct){ 
				cout << GREEN << "GOOD JOB PLAYER 1\n\n" << WHITE << endl;
				qSet++;//If correct move vector up 1 to next question set This is so i can reshuffle the vector and q and A's
				pts++;// activate the timer after someone gets a questions right

			}
			else {cout << RED << "WRONG!" << WHITE << endl;
				if (pts > 0 or pts2 > 0) {cout << GREEN << "Player 1 " << WHITE << " Lost! Sorry!\n"; return 2;}
			}
			//if (fAns == 1){cout << "you answered to long dead!\n";break;} //LOSE SO LEAVE
			turn = 1;
		}	
		correct = 0;//reset correct answer
		auto end = system_clock::now();//End Player 1 Time
		duration<float> dur = end - start;// Save Player 1 Time
		if (time < dur and pts2 > 0){cout << "You answered out of time noob" << endl; return 2;}// If P1 time was longer than saved time after someone answerd correctly first fail him
		time = dur;// else save Player 1 time
		if (pts > 0 or pts2 > 0)cout << "Time to beat " << duration_cast<seconds>(time).count() << " seconds" << endl;

		correct = print_Questions(qaDB,qSet);

		auto start2 = system_clock::now();//start Player 2 Time
		if (turn == 1){
			cout << "PLAYER 2 says: " << endl;
			// Use read, you don't have to stoi

			//input = read();
			int input = -1;
			set_raw_mode(true);
			while (true){
				input = quick_read();
				if(input == ERR)usleep(10'000);
				else if (input > 0)break;
			}
			set_raw_mode(false);
			input -= 48;
			if (input - 48 < 1 or input > 4) cout << input << " BOO YOUU BAD ANSA \n";
			if (input == correct){ 
				cout << CYAN << "GOOD JOB PLAYER 2 \n\n"<< WHITE <<endl;
				qSet++;
				pts2++;//same as above
			}
			else{ cout << RED << "WRONG!" << WHITE << endl;
				if (pts > 0 or pts2 > 0) {cout << CYAN << "Player 2 " << WHITE << " Lost! Sorry!\n";  return 1;}
			}
			turn = 0;
		}	
		auto end2 = system_clock::now();//end player 2 time
		duration<float> dur2 = end2 - start2;// save P2 time
		if (dur2 > time and pts > 0){ cout << " You answered out of time" << " seconds" << endl; return 1;}
		time = dur2; // save P2 Time
		if (pts > 0 or pts2 > 0)cout << "Time to beat " << duration_cast<seconds>(time).count() << endl;
	}

}

template<typename T>
void shuffle_vector(vector<T> &vec) {
	std::random_device generator;
	std::mt19937 dist(generator());
	std::shuffle(vec.begin(),vec.end(),dist);
}
