#include <iostream>
#include <windows.h>
#include <string.h>

using namespace std;
void typewritter(string &line, unsigned short Timer)
{
	for(int x = 0; x < line.size(); x++)
	{
		cout<<line[x];Sleep(Timer);
	}
}

int main()
{
	string Word = "This is a typewritter..pfft";
	typewritter(Word,50);
	return 0;
}

