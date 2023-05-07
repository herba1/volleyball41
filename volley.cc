#include<iostream>
#include<sstream>
#include<string>
#include<fstream>
#include<vector>
#include"/public/colors.h"
#include"/public/read.h"
using namespace std;

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

	/*for (int i = 0; i < qaDB.size(); i++){
	  cout << qaDB.at(i) << endl;
	  if ((i+1)%5 == 0) cout << endl;
	  }*/
			cin.ignore();
	int qSet = 0;// by intervals of 4 because 5 things per question
	while (true){
		if (qSet >= qaDB.size()){
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
				qSet+=5;

			}
			else cout << RED << "wrong!" << WHITE << endl;
			turn = 1;
		}	
		cout << YELLOW << "--------------------------------------" << WHITE << endl;
		cout << qaDB.at(qSet) << endl;
		cout << YELLOW << "--------------------------------------" << WHITE << endl;
		cout << qaDB.at(qSet+1) << endl;
		cout << qaDB.at(qSet+2) << endl;
		cout << qaDB.at(qSet+3) << endl;
		cout << qaDB.at(qSet+4) << endl;
		cout << YELLOW << "--------------------------------------" << WHITE << endl;
		if (turn == 1){
			cout << "PLAYER 2 says: " << endl;
			getline(cin,input);
			if (input == (qaDB.at(qSet+1))){ 
				cout << GREEN << "good job PLAYER 2 \n\n"<< WHITE <<endl;
				qSet+=5;

			}
			else cout << RED << "wrong!" << WHITE << endl;
			turn = 0;
		}	
	}

}
