#include<iostream>
using namespace std;
int main()
{
	string word;
	cout<<"numfilter: ";
	getline(cin,word);
	for(int i = 0; i < word.length(); i++)
	{
		if(word[i] < '0' | word[i] > '9')
		{
			word.erase(i,1);
			i--;
			//word = "invalid";
		}
	}
	cout<<"filtered: "<<word<<endl<<endl;
	return 0;
}
