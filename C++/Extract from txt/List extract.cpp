#include<iostream>
#include<fstream>
#include<algorithm>
#include<string>
using namespace std;

template<typename T>
T extract(T& data)
{
	ifstream infile;
	infile.open("extract.txt");//data << txt 
	infile.ignore(256,'=');//limit until equals
	infile >> data; //txt >> data
	infile.close();
	return data;
}
int main()
{
	ifstream infile;
	ofstream outfile;
	string data = "Age = 19";
	//string data = "Name = AYEMK";
	//bool data = true;
	//string getdata;
	
	outfile.open("extract.txt");//data >> txt
	outfile << data;
	outfile.close();
	
	cout<<extract(data)<<endl;
	int dataint = stoi(data);
	dataint += 1;
	cout<<dataint;
	/*infile.open("extract.txt");//data << txt 
	infile.ignore(256,'=');//limit until equals
	
	infile >> dataint;
	cout<<dataint;
	infile.close();*/
	
	/*getline(infile,getdata);
	cout<<getdata;
	infile.close();*/
}
