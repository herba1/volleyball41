#include<iostream>
#include"battleship.cc"
//#include"newvolley.cc"
using namespace std;

int main(){
srand (time(0));    //cpp ref code
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
    shuffle_vector(qaDB);
    int qSet = 0;// used to traverse the question DB

	system("figlet 'WELCOME TO VOLLEYBATTLE SHIPARDY' | lolcat");
   	 cout << YELLOW << "- - - - - - - - - - - - - - - - - - - - - - - -" << WHITE << endl;
	 cout << MAGENTA << "INSTRUCTIONS" << WHITE << ": Each player will first start by placing their battle ships on their board" << endl;
	 cout << "After that is complete: the game will start and it will work by who can answer C++ trivia questions the fastest" << endl;
	 cout << "The faster player will receive 3 shots to hit a ship, first player to sink " << RED << "ALL" << WHITE << " their oppenents ships WINS!" << endl;
	 cout << GREEN << "GOODLUCK TO ALL!" << WHITE << endl;
	 set_ship1();
	 set_ship2();
	 Battle_Ship(qaDB, qSet);
   }

