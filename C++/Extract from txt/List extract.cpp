#include<iostream>
#include<fstream>
#include<algorithm>
#include<string>
using namespace std;

template<typename T>
T extract(T& data)
{
	ifstream infile;
	infile.open("extract.txt");//data <- txt 
	infile.ignore(256,'=');//limit until equals
	/*infile >> data; //txt -> data
	infile.close();//*/
	getline(infile,data);//with space
	infile.close();//*/
	return data;
}
int main()
{
	ifstream infile;
	ofstream outfile;
	string data = "Age =19";
	//string data = "Name =AYEMK with space";
	//bool data = true;
	
	outfile.open("extract.txt");//data >> txt
	outfile << data;
	outfile.close();
	
	cout<<extract(data)<<endl;
	/*int dataint = stoi(data);//change extracted in to integer
	dataint += 1; //test
	cout<<dataint;
	infile.open("extract.txt");//data << txt*/ 

	
	
}
