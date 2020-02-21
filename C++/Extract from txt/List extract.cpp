#include<iostream>
#include<fstream>
#include<algorithm>
#include<string>
using namespace std;

template<typename T>
T extract(T& data,ifstream &infile)
{
	//address of infile = data <- txt 
	infile.ignore(256,'=');//limit until equals
	getline(infile,data,'\n');//txt -> data with spaces//*/
	return data;
}
int main()
{
	ifstream infile;
	ofstream outfile;
	string data = "Name =Kenji Shimizu\nAge =19\nScore =98\nHuman =1";
	//string data = "Name =AYEMK with space";
	//bool data = true;
	
	outfile.open("extract.txt");//data >> txt
	outfile << data;
	outfile.close();
	
	infile.open("extract.txt");//------>Start
	cout<<extract(data,infile)<<endl;//Name
	cout<<extract(data,infile)<<endl;//Age
	cout<<extract(data,infile)<<endl;//Score data
	extract(data,infile);//..........//Human or Not!
	int dataint = stoi(data);//......//change extracted into integer
	
	bool databool;
	if(dataint == 1) databool = true;
	else databool = false;
	cout<<boolalpha<<databool<<endl;//shows wether true or false*/
	infile.close();//----------------->End
	
	return 0;
}
