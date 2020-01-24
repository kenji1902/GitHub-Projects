
#include<iostream>
#include<vector>
#include<string>
using namespace std;

void Line(int maxline)
{
	for (int i = 0; i < maxline; i++)
	{
		cout << "=";
	}
	cout << endl;
}
int _average(int &average, int &score1, int &score2 )
{
	return average = (score1 + score2) / 2;
}
struct player_record
{
	string nickname = " "; //set to default values for uninitialized warning
	int age = 0;
	int score_1 = 0;
	int score_2 = 0;
	int average = 0;
};
void maximum(vector<player_record> add,int &Hscore,string&Hscorename)
{
	for (int j = 0; j != add.size();j++)
	{
		if (Hscore <= add[j].average)
		{
			Hscore = add[j].average;
			Hscorename = add[j].nickname;
		}
		if (j == add.size() - 1)//...............// at the end of analysis
		{
			for (int j = 0; j != add.size();j++) // to check again average
			{
				if (Hscore <= add[j].average)
				{
					Hscore = add[j].average;
					Hscorename = add[j].nickname;
					cout << "name: " << Hscorename << endl;
					cout << "score: " << Hscore << endl << endl;
				}
			}
		}
	}
}
void minimum(vector<player_record>add,int &Hscore, string&Hscorename)
{
	for (int j = 0; j != add.size();j++)
	{
		if (Hscore >= add[j].average)
		{
			Hscore = add[j].average;
			Hscorename = add[j].nickname;
		}
		if (j == add.size() - 1)//...............// at the end of analysis
		{
			for (int j = 0; j != add.size();j++) // check again for average
			{
				if (Hscore >= add[j].average)
				{
					Hscore = add[j].average;
					Hscorename = add[j].nickname;
					cout << "name: " << Hscorename << endl;
					cout << "score: " << Hscore << endl << endl;
				}
			}
		}
	}
}
int main()
{
	char choice;
	string name, Hscorename;
	int getage, //.............// get the age
		score1, //.............// get the score 1
		score2, //.............// get the score 2
		i = 0, //..............// to add players
		Hscore,
		average; //............// storage of average
	vector<player_record> add; //to make player_record an array type
//___________________________________________________________________
	Line(50);
	cout << "                        Menu\n";
	Line(50);
	cout << "[1] - Add Record\n";
	cout << "[2] - View Players Records\n";
	cout << "[3] - Compute for the average\n";
	cout << "[4] - Show the player(s) who gets the max average\n";
	cout << "[5] - Show the Player(s) who gets the min average\n";
	cout << "[6] - Exit\n";
	Line(50);
//___________________________________________________________________
	while (1)
	{
	repeat:
		cout << "choice: ";
		cin >> choice;
		cout << endl;
		switch (choice) {
		case '1' :
				cin.ignore(INT_MAX, '\n');// remove the newline of cin
				cout << "Nick name: ";
				getline(cin, name);
				cout << "age: ";
				cin >> getage;
				cout << "score 1: ";
				cin >> score1;
				cout << "score 2: ";
				cin >> score2;
				cin.ignore(INT_MAX,'\n');
				cout << endl;
				add.push_back(player_record()); //put every player_record 
				add[i].nickname = name;         //values to vector add
				add[i].age = getage;
				add[i].score_1 = score1;
				add[i].score_2 = score2;
				add[i].average = _average(average, add[i].score_1, add[i].score_2);
				i++;//.........................//new player
				Line(50);
				break;
		case '2':
				for (int j = 0; j != add.size(); j++)
				{
					cout << "nickname: " << add[j].nickname << endl;
					cout << "age: " << add[j].age << endl;
					cout << "Score 1: " << add[j].score_1 << endl;
					cout << "Score 2: " << add[j].score_2 << endl << endl;
					if (j == add.size() - 1)
						Line(50);
				}
				break;
		case '3':
				for (int j = 0; j != add.size(); j++)
				{
					cout << "nickname: " << add[j].nickname << endl;
					cout << "average score: " << _average(average, add[j].score_1, add[j].score_2) << endl << endl;
					if (j == add.size() - 1)
						Line(50);
				}
				break;
		case '4': //maximum
			if (add.empty() == true) goto repeat; 
			
				Hscore = 0;
				Hscorename;
				cout << "High Score: " << endl << endl;
				maximum(add, Hscore, Hscorename);
				Line(50);
				break;
		case '5': //minimum
				
				if (add.empty() == true) goto repeat;
				Hscore = add[0].score_1;
				Hscorename;
				cout << "Lowest Score: " << endl << endl;
				minimum(add, Hscore, Hscorename);
				Line(50);
				break;
		case '6':
				exit(1);
				break;
		}
	}
}
