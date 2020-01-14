#include<iostream>
#include<vector>
#include<string>

using namespace std;

void numFilter(vector<char>vecarray, string *svec)
{	
	
	for (auto it = vecarray.begin(); it < vecarray.end(); ) // or for (vector<char>::iterator it = vecarray.begin(); it < vecarray.end(); )
	{
		
		if (*it < '0' || *it >'9')//..................!number detector
		{
			remove_if(vecarray.begin(),vecarray.end(),it);
			 /*tel num use (delete bottom if used)
			vecarray.clear();
			break;*/
			vecarray.erase(it);    //.................erase 1st array
			it = vecarray.begin(); //.................go to 1st array*/
		}
		else if (*it >= '0' || *it <= '9')//..........if number detected then increment.
		{	
			it++;
		}
	}
	if (vecarray.empty() == true)
		*svec = "invalid";
	else
	{
		string str(vecarray.begin(), vecarray.end());//converts vector char to string.
		*svec = str;
	}
}
int main()
{
	string input;
	string svec1;
	while (1)
	{
		cout << "Number Filter: ";
		getline(cin, input);

		vector<char> vecarray1(input.length());
		for (int i = 0; i < vecarray1.size(); i++)
			vecarray1[i] = input[i];

		numFilter(vecarray1,&svec1);//for telephone number where characters is not allowed.
		
		cout << "Tel Number: " << svec1 << endl << endl;
		cin.clear();
	}
	return 0;
}
