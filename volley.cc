#include<iostream>
#include<chrono>
#include<sstream>
#include<string>
#include<fstream>
#include<vector>
#include"/public/colors.h"
#include"/public/read.h"
using namespace std;
using namespace std::chrono;
int main(){
	vector<string> qaDB;
	int turn = 0;
	cout << "enter a file " << endl;
	string file;
	cin >> file;
	ifstream fs(file);
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
	}
	duration<float> time {60s};//VARIABLE TO SAVE TIME DURATION SET TO 60 INITIALLY
	cout << "time to beat " << duration_cast<seconds>(time).count() << endl;
	/*for (int i = 0; i < qaDB.size(); i++){
	  cout << qaDB.at(i) << endl;
	  if ((i+1)%5 == 0) cout << endl;
	  }*/
	cin.ignore();
	int qSet = 0;// by intervals of 5 because 5 things per question used to use vec.at(qSet)
	int pts = 0;//used to check who right answers first
	int pts2 = 0;//used to check who right answers first
	while (true){
		auto start = system_clock::now();//start Player 1 time
		if (qSet >= qaDB.size()){//Make sure question set doesnt go out of bounds
			cout << "NO ONE WINS OUT OF QUESTIONS SORRY" << endl;
			exit(1);
		}
		string input;

		cout << YELLOW << "--------------------------------------" << WHITE << endl;
		cout << qaDB.at(qSet) << endl;
		cout << YELLOW << "--------------------------------------" << WHITE << endl;
		cout << qaDB.at(qSet+1) << endl;
		cout << qaDB.at(qSet+2) << endl;
		cout << qaDB.at(qSet+3) << endl;
		cout << qaDB.at(qSet+4) << endl;
		cout << YELLOW << "--------------------------------------" << WHITE << endl;
		
		if (turn == 0){
			cout << "PLAYER 1 says: " << endl;
			getline(cin,input);
			if (input == (qaDB.at(qSet+1))){ 
				cout << GREEN << "good job PLAYER 1\n\n" << WHITE << endl;
				qSet+=5;//If correct move vector questions up 5 so next question set
				pts++;// activate the timer after someone gets a questions right

			}
			else cout << RED << "wrong!" << WHITE << endl;
			//if (fAns == 1){cout << "you answered to long dead!\n";break;} //LOSE SO LEAVE
			turn = 1;
		}	
		auto end = system_clock::now();//End Player 1 Time
		duration<float> dur = end - start;// Save Player 1 Time
		if (time < dur and pts2 > 0){cout << "u answered out of time noob" << endl; break;}// If P1 time was longer than saved time after someone answerd correctly first fail him
		time = dur;// else save Player 1 time
		if (pts > 0 or pts2 > 0)cout << "time to beat " << duration_cast<seconds>(time).count() << endl;
		
		cout << YELLOW << "--------------------------------------" << WHITE << endl;
		cout << qaDB.at(qSet) << endl;
		cout << YELLOW << "--------------------------------------" << WHITE << endl;
		cout << qaDB.at(qSet+1) << endl;
		cout << qaDB.at(qSet+2) << endl;
		cout << qaDB.at(qSet+3) << endl;
		cout << qaDB.at(qSet+4) << endl;
		cout << YELLOW << "--------------------------------------" << WHITE << endl;
		
		auto start2 = system_clock::now();//start Player 2 Time
		if (turn == 1){
			cout << "PLAYER 2 says: " << endl;
			getline(cin,input);
			if (input == (qaDB.at(qSet+1))){ 
				cout << GREEN << "good job PLAYER 2 \n\n"<< WHITE <<endl;
				qSet+=5;
				pts2++;//same as above
			}
			else cout << RED << "wrong!" << WHITE << endl;
			turn = 0;
		}	
		auto end2 = system_clock::now();//end player 2 time
		duration<float> dur2 = end2 - start2;// save P2 time
		if (dur2 > dur and pts > 1){ cout << "u ansard out of time" << endl; break;}
		time = dur2; // save P2 Time
		if (pts > 0 or pts2 > 0)cout << "time to beat " << duration_cast<seconds>(time).count() << endl;
	}



}
