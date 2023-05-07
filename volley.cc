#include<iostream>
#include<sstream>
#include<string>
#include<fstream>
#include<vector>
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
	
	for (int i = 0; i < qaDB.size(); i++){
		cout << qaDB.at(i) << endl;
		if ((i+1)%5 == 0) cout << endl;
	}

	/*while (true){
	  string input;
	  cout << "whats 9+10 ?" << endl;
	  if (turn == 0){
	  cout << "PLAYER 1 says: " << endl;
	  cin >> input;
	  if (input == "21") cout << "good job \n";
	  else cout << "wrong!" << endl;
	  turn = 1;
	  }	
	  if (turn == 1){
	  cout << "PLAYER 2 says: " << endl;
	  cin >> input;
	  if (input == "21") cout << "good job \n";
	  else cout << "wrong!" << endl;
	  turn = 0;
	  }	
	  }*/

}
