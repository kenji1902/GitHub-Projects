 #include<iostream>
#include<windows.h>
#include<string>
#include<sstream>
#define move 59
#define move1 0
using namespace std;

int saveseatscoord[21][3][14]; float totalmovieprice[7][2];
int numreserveseats,reserveseatsticket;
string cancel;
bool timenew,timeexit;
void ConsoleWindow(short x,short y,short cx,short cy)
{
	HWND consoleWindow = GetConsoleWindow();
	RECT ConsoleRect;
	GetWindowRect(consoleWindow, &ConsoleRect); 
	MoveWindow(consoleWindow, x, y, cx, cy, TRUE);
}

void gotoxy(short x, short y)
{
	COORD XYgraph = {x,y};
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),XYgraph);
}
void textcolor (short x)
{
	HANDLE color=GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(color, x);	
}
void Clear(short x, short y, short v, short h)//x = Xcoordinates | y = Ycoordinates | v = vertical loop long | h = Horizontal loop long
{
	int i,j,k=0;
	char clear = 255;
	for(j=0;j<=v;j++)//vertical
	{
		for(i=0;i<h;i++)//horizontal
		{
			gotoxy(x + i, y + k);cout<<clear;
		}
		k++;
	}
}
void boxCreate(short xpos, short ypos, short length, short width)
{
	int i,k;
	char ulc = 191, hl = 196, urc = 218, vl = 179, llc = 217, lrc = 192;
	gotoxy(xpos+1,ypos+2); cout<<urc;  gotoxy(xpos+width,ypos+2); cout<<ulc;
	gotoxy(xpos+1,ypos+length); cout<<lrc; gotoxy(xpos+width,ypos+length); cout<<llc;
	for(i=1; i < length; i=i*(length/1.01)){
		for(k=0; k < (width-2); k++){
			gotoxy(xpos+2+k,ypos+i+1);cout<<hl;
		}
	}
	for(i=1; i <= width; i=i*(width)){
		for(k=0; k < (length-3); k++){
			gotoxy(xpos+i,ypos+k+3);cout<<vl;
		}
	}
}
void boxGridx2half(short xpos, short ypos,short length, short width, short verticalline,short verticalline2)
{
	int i,k;
	char ulc = 191, hl = 196, urc = 218, vl = 179, llc = 217, lrc = 192, clear = 255;
	char rmc = 195, lmc = 180, mdl = 194, mul = 193, mudl = 197;
	boxCreate(xpos,ypos,length,width);
	for(i=1; i < length; i=i+(length/(length/2))){
		for(k=1; k < (width-1); k++){
			gotoxy(xpos+k+1,ypos+i+1);cout<<hl;
			gotoxy(xpos+1,ypos+i+1);cout<<rmc;
			gotoxy(xpos+width,ypos+i+1);cout<<lmc;
		}
	}
	for(i=1; i < length; i=i+(length/(length/2))){
		for(k=1; k < (width-1); k++){
			if(k > (width-3)){
				if(i < length-1){
				gotoxy(verticalline,ypos+i+2);cout<<vl;	
				}
				gotoxy(verticalline,ypos+i+1);cout<<mudl;
				}
			}
		}
	for(i=1; i < length; i=i+(length/(length/2))){
		for(k=1; k < (width-1); k++){
			if(k > (width-3)){
				if(i < length-1){
				gotoxy(verticalline2,ypos+i+2);cout<<vl;	
				}
				gotoxy(verticalline2,ypos+i+1);cout<<mudl;
				}
			}
		}	
	gotoxy(verticalline,ypos+2);cout<<mdl;gotoxy(verticalline,ypos+length);cout<<mul;
	gotoxy(verticalline2,ypos+2);cout<<mdl;gotoxy(verticalline2,ypos+length);cout<<mul;
	gotoxy(xpos+1,ypos+2); cout<<urc;  gotoxy(xpos+width,ypos+2); cout<<ulc;
	gotoxy(xpos+1,ypos+length); cout<<lrc; gotoxy(xpos+width,ypos+length); cout<<llc;
}
void boxhalfvh(short xpos, short ypos, short length, short width, short verticalline,short horizontalline)
{
	int i,k;
	char ulc = 191, hl = 196, urc = 218, vl = 179, llc = 217, lrc = 192;
	char rmc = 195, lmc = 180, mdl = 194, mul = 193, mudl = 197;	
	boxCreate(xpos,ypos,length,width);
	for(i=1; i < length; i++){
		for(k=1; k < (width-1); k++){
			if(k > (width-3)){
				if(i < length-1){
				gotoxy(verticalline,ypos+i+2);cout<<vl;	
				}
			}
		}
	}for(i=1; i < width-1; i++){
			gotoxy(xpos+i+1,horizontalline+ypos);cout<<hl;
		}
	gotoxy(verticalline,ypos+2);cout<<mdl;gotoxy(verticalline,ypos+length);cout<<mul;
	gotoxy(xpos+1,horizontalline+ypos);cout<<rmc;gotoxy(xpos+width,horizontalline+ypos);cout<<lmc;
	gotoxy(verticalline,ypos+horizontalline);cout<<mudl;
}
void Movieoutputs(short xpos, short ypos)
{
	boxGridx2half(xpos-3,ypos-3,10,40,xpos+16,xpos+16);
	gotoxy(xpos,ypos); cout<<"Choose a movie";
	gotoxy(xpos,ypos+2); cout<<"Choose a time";
	gotoxy(xpos , ypos + 4);cout<<"Letter";
	gotoxy(xpos,ypos + 6);cout<<"Seat Number";
	boxhalfvh(xpos-3,ypos+8,9,40,xpos+19,ypos-11);
	gotoxy(xpos,ypos+ 11); cout <<"Movie name ";
	gotoxy(xpos, ypos+12); cout <<"Movie price ";
	gotoxy(xpos, ypos+13);cout<<"Number of ticket ";
	gotoxy(xpos, ypos+14);cout<<"Total movie price ";
	gotoxy(xpos, ypos+16);cout<<"Payment";
	
	boxGridx2half(xpos-3,ypos+16,6,40,xpos+23,xpos+23);
	gotoxy(xpos, ypos+19);cout<<"Discount card";
	gotoxy(xpos, ypos+21);cout<<"How many Discount card";
	
	gotoxy(xpos, ypos+24);cout<<"The movie price is  Php";
	gotoxy(xpos, ypos+25);cout<<"You have paid       Php";
	gotoxy(xpos, ypos+27);cout<<"Your change is      Php";
	boxhalfvh(xpos-3,ypos+21,7,40,xpos+19,ypos-13);
}
class Movieoption{
	public:
		void Movieoption1(short xpos, short ypos)
		{
			boxCreate(xpos-8,ypos-4,11,40);
			gotoxy(xpos,ypos+2);cout<<"Enter the Movie name";
			gotoxy(xpos,ypos+3);cout<<"\"exit\"= Show summary and exit";
			gotoxy(xpos,ypos+4);cout<<"From Day 1 to 7";
			gotoxy(xpos-7,ypos+8);system("pause");
			Clear(xpos-8,ypos-4,12,41);
		}
		void Movieoption2(short xpos, short ypos)
		{
			boxCreate(xpos-8,ypos-4,11,40);
			gotoxy(xpos-1,ypos+1);cout<<"Enter the Movie time";
			gotoxy(xpos-1,ypos+2);cout<<"\"new\" = new movie";
			gotoxy(xpos-1,ypos+3);cout<<"\"exit\"= Show summary and exit";
			gotoxy(xpos-1,ypos+4);cout<<"From Day 1 to 7";
			gotoxy(xpos-7,ypos+8);system("pause");
			Clear(xpos-8,ypos-4,12,41);
		}
		void Movieoption3_1(short xpos, short ypos)
		{
			boxCreate(xpos-8,ypos-4,11,40);
			gotoxy(xpos,ypos+2);cout<<"Enter the Seat letter";
			gotoxy(xpos,ypos+3);cout<<"From A to G";
		}
		void Movieoption3(short xpos, short ypos)
		{
			Movieoption optionObj;
			boxCreate(xpos-8,ypos-4,11,40);
			string next;
			gotoxy(xpos,ypos);cout<<"Enter  = Press to reserve";
			gotoxy(xpos,ypos+1);cout<<"\"done\" = Check out";
			gotoxy(xpos,ypos+2);cout<<"\"new\"  = Select new Movie";
			gotoxy(xpos,ypos+3);cout<<"\"exit\" = Show summary and exit";
			gotoxy(xpos,ypos+4);cout<<"Press \"N\" to next: ";
			getline(cin,next);
			if(next == "n" || next == "N"){
				Clear(xpos-8,ypos-4,12,41);
				optionObj.Movieoption3_1(xpos,ypos);
			}
			gotoxy(xpos-7,ypos+8);system("pause");
			Clear(xpos-8,ypos-4,12,41);
		}
		void Movieoption4_1(short xpos, short ypos)
		{
			boxCreate(xpos-8,ypos-4,11,40);
			gotoxy(xpos,ypos+1);cout<<"Enter  = Press to reserve";
			gotoxy(xpos,ypos+2);cout<<"Enter the Seat Number";
			gotoxy(xpos,ypos+3);cout<<"From 1 to 20";
			gotoxy(xpos,ypos+4);cout<<"Ex:  1(Enter)R || 1(Enter)Enter";
		}
		void Movieoption4(short xpos, short ypos)
		{
			Movieoption optionObj;
			boxCreate(xpos-8,ypos-4,11,40);
			string next;
			gotoxy(xpos-5,ypos);cout<<"\"CancelR\"= Cancel after reservation";
			gotoxy(xpos-5,ypos+1);cout<<"\"Cancel\" = Cancel before reservation";
			gotoxy(xpos-5,ypos+2);cout<<"\"Undo\" = reserved the chosen seat";
			gotoxy(xpos-5,ypos+3);cout<<"\"done\" = Check in";
			gotoxy(xpos-5,ypos+4);cout<<"\"new\"  = Select new Movie";
			gotoxy(xpos-5,ypos+5);cout<<"N to next: ";
			getline(cin,next);
			if(next == "n" || next == "N"){
				Clear(xpos-8,ypos-4,12,41);
				optionObj.Movieoption4_1(xpos,ypos);
			}
			gotoxy(xpos-7,ypos+8);system("pause");
			Clear(xpos-8,ypos-4,12,41);
		}
		void Movieoption5(short xpos, short ypos)
		{
			boxCreate(xpos-8,ypos-4,11,40);
			gotoxy(xpos,ypos+2);cout<<"Payment for the ticket(s)";
			gotoxy(xpos,ypos+3);cout<<"Payment >= 0 ";
			gotoxy(xpos-7,ypos+8);system("pause");
			Clear(xpos-8,ypos-4,12,41);
		}
		void Movieoption6(short xpos, short ypos)
		{
			boxCreate(xpos-8,ypos-4,11,40);
			gotoxy(xpos,ypos+2);cout<<"\"none\" = No Discount";
			gotoxy(xpos,ypos+3);cout<<"\"yes\"  = Discount(20%)";
			gotoxy(xpos-7,ypos+8);system("pause");
			Clear(xpos-8,ypos-4,12,41);
		}
		void Movieoption7(short xpos, short ypos)
		{
			boxCreate(xpos-8,ypos-4,11,40);
			gotoxy(xpos,ypos+2);cout<<"Discount Card";
			gotoxy(xpos,ypos+3);cout<<"Less than or equals to seat";
			gotoxy(xpos-7,ypos+8);system("pause");
			Clear(xpos-8,ypos-4,12,41);
		}
};
class MovieChoices
{
	public:
	int i;
	string msg;
	void boxChoice(short x, short y)
	{
		int kHori=0, kVerti=0;
		char ulc = 191, hl = 196, urc = 218, vl = 179, llc = 217, lrc = 192, clear = 255;
		char rmc = 195, lmc = 180, mdl = 194, mul = 193, mudl = 197;
		gotoxy(x+1,y+2); cout<<urc;  gotoxy(x+77,y+2); cout<<ulc;
		gotoxy(x+1,y+18); cout<<lrc; gotoxy(x+77,y+18); cout<<llc;
		for(i = 0; i<75;i++)
		{
			gotoxy(i+x+2,y+2);cout<<hl;
			gotoxy(i+x+2,y+4);cout<<hl;
			gotoxy(i+x+2,y+7);cout<<hl;
			gotoxy(i+x+2,y+11);cout<<hl;
			gotoxy(i+x+2,y+14);cout<<hl;
			gotoxy(i+x+2,y+18);cout<<hl;
		}
		for(i=0;i<15;i++)
		{
			gotoxy(x+1,i+y+3);cout<<vl;
			gotoxy(x+77,i+y+3);cout<<vl;
		}
		for(i=0;i<6;i++)
		{
			gotoxy(x+20,i+y+5);cout<<vl;
			gotoxy(x+39,i+y+5);cout<<vl;
			gotoxy(x+58,i+y+5);cout<<vl;
			gotoxy(x+26,i+y+12);cout<<vl;
			gotoxy(x+51,i+y+12);cout<<vl;
		}
		gotoxy(x+34,y+3);cout<<"Movie List";
		for(i=1; i<=4;i++)
		{
			gotoxy(kHori+x+8,y+5);cout<<"Day "<<i;
			gotoxy(kHori+x+2,y+8);cout<<"Time:";
			gotoxy(kHori+x+2,y+9);cout<<"Time:";
			gotoxy(kHori+x+2,y+10);cout<<"Price:";
			if( i < 4)
			{
				gotoxy(kHori+x+20,y+4);cout<<mdl;
				gotoxy(kHori+x+20,y+11);cout<<mul;
			}
			kHori+=19;
			if(i==4)
			{
				kHori = 0;
			}
		}
		for(i=5; i<=7;i++)
		{
			gotoxy(kHori+x+11,y+12);cout<<"Day "<<i;
			gotoxy(kHori+x+2,y+15);cout<<"Time:";
			gotoxy(kHori+x+2,y+16);cout<<"Time:";
			gotoxy(kHori+x+2,y+17);cout<<"Price:";
			if(i < 7)
			{
				gotoxy(kHori+x+26,y+11);cout<<mdl;
				gotoxy(kHori+x+26,y+18);cout<<mul;
			}
			kHori+=25;
		}
		gotoxy(x+1,y+4);cout<<rmc; gotoxy(x+1,y+7);cout<<rmc; gotoxy(x+1,y+11);cout<<rmc;
		gotoxy(x+1,y+14);cout<<rmc; gotoxy(x+77,y+4);cout<<lmc; gotoxy(x+77,y+7);cout<<lmc;
		gotoxy(x+77,y+11);cout<<lmc; gotoxy(x+77,y+14);cout<<lmc; gotoxy(x+20,y+7);cout<<mudl;
		gotoxy(x+39,y+7);cout<<mudl; gotoxy(x+58,y+7);cout<<mudl; gotoxy(x+26,y+14);cout<<mudl;
		gotoxy(x+51,y+14);cout<<mudl;
	}
	void screen(short x, short y)
	{
		int kHori = 0;
		char ulc = 191, hl = 196, urc = 218, vl = 179, llc = 217, lrc = 192, clear = 255;
		textcolor(4);
		gotoxy(x+1,y+2); cout<<urc;  gotoxy(x+107,y+2); cout<<ulc;
		gotoxy(x+1,y+4); cout<<lrc; gotoxy(x+107,y+4); cout<<llc;
		for(i = 0; i<105;i++)
		{
			gotoxy(i+x+2,y+2);cout<<hl;
			gotoxy(i+x+2,y+4);cout<<hl;
			if(i == 0 || i == 104)
			{
				gotoxy(x+kHori+1,y+3);cout<<vl;
				kHori+=106;
			}
			gotoxy(x+51,y+3);cout<<"Screen";
		}
		textcolor(7);
	}
};
class MovieSeatsBox
{
	public:
		string customer,seatletter;
		bool a,b,Time1,Time2,Time3,Unrepeat,inputtime,Price;
		string time;
		void seat(short x,short y)
		{
			int i;
			char ulc = 191, hl = 196, urc = 218, vl = 179, llc = 217, lrc = 192;
			//box............................................................................
			gotoxy(x + 10,y + 10);cout<<urc;        gotoxy(x + 14,y + 10);cout<<ulc;
			gotoxy(x + 10,y + 12);cout<<lrc;        gotoxy(x + 14,y + 12);cout<<llc;
			for(i=0; i <= 2; i++)
			{
				gotoxy(x + 11+i,y + 10);cout<<hl;         
				gotoxy(x + 11+i,y + 12);cout<<hl; 
			} 
			gotoxy(x + 10,y + 11);cout<<vl;
			gotoxy(x + 14,y + 11);cout<<vl;
		}
		void SeatDuplicator(short Xpos, short Ypos)//Xpos = Xcoordinates | Ypos = Ycoordinates
{
	int i,j,k=0,l=0,m=0,n,o=0,p=0,q=0;
	char A = 'A',C = 'C';
	MovieSeatsBox seatsObj;
	MovieChoices movieObj;
	for(n = 0; n<2; n++)//repeat the whole seats
	{
		for(j = 0; j<5; j++)//repeat the 5 collums into 5 rows
		{
			for(i=1;i <= 5; i++)//repeat single box into 5 collums
			{

				seatsObj.seat(Xpos+k+o,Ypos+l);
				if(j<2){
					seatsObj.snum(Xpos+k+o,Ypos+l,0+i+p);	
				}
				else if(j>=2){
					seatsObj.snum(Xpos+k+o,Ypos+l,4+i+p);	
				}
				if(j>=3){
					seatsObj.seat(Xpos+k+o,Ypos+l+6);
					seatsObj.snum(Xpos+k+o,Ypos+l+6,5+i+p);	
				}
				if(i<=4){
					seatsObj.seat((Xpos-25)+k+(o*3.17)+q,Ypos+l+6);
					seatsObj.snum((Xpos-25)+k+(o*3.17)+q,Ypos+l+6,0+i+(p*2.8));	
				}
				if(j>=3)
				{
					seatsObj.seat((Xpos-25)+k+(o*3)+q,Ypos+l+6);
					seatsObj.snum((Xpos-25)+k+(o*3)+q,Ypos+l+6,0+i+(p*3));
				}
				gotoxy(Xpos+8+o,Ypos+11+l);cout<<char (A+j);//converted char num to letters
				gotoxy(Xpos+67,Ypos+11+l);cout<<char (A+j);
				if(j>=3)
				{
					gotoxy(Xpos+38,Ypos+17+l);cout<<char (C+j);
				}
				gotoxy(Xpos-17+(o*3.6),Ypos+17+l);cout<<char (C+j);
				k+=5;					
			}
			l+=3;
			m+=10;
			k=0;
		}
		q-=10;
		o+=30;
		l=0;
		k=0;
		m=0;
		p+=5;
		
	}
}
		void snum(short x, short y, short snum)
		{
			gotoxy(x + 12,y + 11);cout<<snum;
		}
		void inputcanceling(short x, short y, short snum)
		{
			MovieSeatsBox seatsObj;
			textcolor(6);
			seatsObj.seat(x , y);
			seatsObj.snum(x ,y, snum);
			textcolor(7);
		}

		void theatre(short x, short y, short seatnum)
		{	
			int historyreserveholder;
			MovieSeatsBox seatsObj;
			seatsObj.inputcanceling(x,y,seatnum);
			Clear(42,24,0,15);
			RepeatReservation:
			gotoxy(42, 24);getline(cin,cancel);
			numreserveseats++;
			historyreserveholder += numreserveseats-1;
			if(cancel == "Cancel" || cancel == "cancel")
			{
				textcolor(7);
				seatsObj.seat(x,y);
				seatsObj.snum(x,y,seatnum);
				numreserveseats = historyreserveholder;
			}
			else if(cancel == "Undo" || cancel == "undo")
			{
				textcolor(4);
				seatsObj.seat(x,y);
				seatsObj.snum(x,y,seatnum);
				numreserveseats = historyreserveholder;
				textcolor(7);
			}
			else if(cancel == "cancelr" || cancel == "CancelR")
			{
				textcolor(7);
				seatsObj.seat(x,y);
				seatsObj.snum(x,y,seatnum);
				numreserveseats-=2;
			}
			else if(cancel == "-help")
			{
				Movieoption optionObj;
					optionObj.Movieoption4(26,6);
					goto RepeatReservation;
			}
			else
			{
				textcolor(4);
				seatsObj.seat(x,y);
				seatsObj.snum(x,y,seatnum);
				textcolor(7);
			}
		}
		void Arrayseatsave(short Row, short Column, short addColumn, short x, short y, short xAdd, short seatnumber)
		{
			saveseatscoord[Row][0][Column+addColumn] = x + xAdd;
			saveseatscoord[Row][1][Column+addColumn] = y;
			saveseatscoord[Row][2][Column+addColumn] = seatnumber;
			if(cancel == "Cancel"||cancel == "cancel"||cancel == "cancelr" || cancel == "CancelR"){
				saveseatscoord[Row][0][Column+addColumn] = 0;
				saveseatscoord[Row][1][Column+addColumn] = 0;
				saveseatscoord[Row][2][Column+addColumn] = 0;
			}
		}
		void AtoGArraysave(short Row, short addColumn, short x, short y, short xAdd, short seatnumber,string ABCDEFG)
		{
			MovieSeatsBox seatsObj;
			if(ABCDEFG == "a"){
				seatsObj.Arrayseatsave(Row,0,addColumn,x,y,xAdd,seatnumber);
			}
			if(ABCDEFG == "b"){
				seatsObj.Arrayseatsave(Row,1,addColumn,x,y,xAdd,seatnumber);
			}
			if(ABCDEFG == "c"){
				seatsObj.Arrayseatsave(Row,2,addColumn,x,y,xAdd,seatnumber);
			}
			if(ABCDEFG == "d"){
				seatsObj.Arrayseatsave(Row,3,addColumn,x,y,xAdd,seatnumber);
			}
			if(ABCDEFG == "e"){
				seatsObj.Arrayseatsave(Row,4,addColumn,x,y,xAdd,seatnumber);
			}
			if(ABCDEFG == "f"){
				seatsObj.Arrayseatsave(Row,5,addColumn,x,y,xAdd,seatnumber);
			}
			if(ABCDEFG == "g"){
				seatsObj.Arrayseatsave(Row,6,addColumn,x,y,xAdd,seatnumber);
			}
		}
		void CtoGArraysave(short Row, short addColumn, short x, short y, short xAdd, short seatnumber,string ABCDEFG)
		{
			MovieSeatsBox seatsObj;
			if(ABCDEFG == "c"){
				seatsObj.Arrayseatsave(Row,2,addColumn,x,y,xAdd,seatnumber);
			}
			if(ABCDEFG == "d"){
				seatsObj.Arrayseatsave(Row,3,addColumn,x,y,xAdd,seatnumber);
			}
			if(ABCDEFG == "e"){
				seatsObj.Arrayseatsave(Row,4,addColumn,x,y,xAdd,seatnumber);
			}
			if(ABCDEFG == "f"){
				seatsObj.Arrayseatsave(Row,5,addColumn,x,y,xAdd,seatnumber);
			}
			if(ABCDEFG == "g"){
				seatsObj.Arrayseatsave(Row,6,addColumn,x,y,xAdd,seatnumber);
			}
		}
		void FtoGArraysave(short Row, short addColumn, short x, short y, short xAdd, short seatnumber,string ABCDEFG)
		{
			MovieSeatsBox seatsObj;

			if(ABCDEFG == "f"){
				seatsObj.Arrayseatsave(Row,5,addColumn,x,y,xAdd,seatnumber);
			}
			if(ABCDEFG == "g"){
				seatsObj.Arrayseatsave(Row,6,addColumn,x,y,xAdd,seatnumber);
			}	
		}									
		void seats1_20(short x, short y,short ABincrs,short CDEincrs,short FGdcrs, string ABCDEFG,short addColumn)
		{	
				MovieSeatsBox seatsObj;
				Repeatseatnumber:
				Clear(move1+39,24,0,15);	
				gotoxy(move1+39, 24);getline(cin,customer);
				seatsObj.seatletter;
				Clear(12,1,1,30);

				if(customer == "1")
				{
					seatsObj.theatre(x,y+0,1);
					int Row = 0,seatnumber = 1, xAdd = 0;
					seatsObj.AtoGArraysave(Row,addColumn,x,y,xAdd,seatnumber,ABCDEFG);			
				}
				else if(customer == "2")
				{
					seatsObj.theatre(x+5,y+0,2);
					int Row = 1,seatnumber = 2, xAdd = 5;
					seatsObj.AtoGArraysave(Row,addColumn,x,y,xAdd,seatnumber,ABCDEFG);		
				}
				else if(customer == "3")
				{
					seatsObj.theatre(x+10,y+0,3);
					int Row = 2,seatnumber = 3, xAdd = 10;
					seatsObj.AtoGArraysave(Row,addColumn,x,y,xAdd,seatnumber,ABCDEFG);	
				}
				else if(customer== "4")
				{
					seatsObj.theatre(x+15,y+0,4);
					int Row = 3,seatnumber = 4, xAdd = 15;
					seatsObj.AtoGArraysave(Row,addColumn,x,y,xAdd,seatnumber,ABCDEFG);	
				}
				else if(customer == "5")
				{
					seatsObj.theatre(x+20+CDEincrs-FGdcrs,y+0,5);
					int Row = 4,seatnumber = 5, xAdd = 20 + CDEincrs - FGdcrs;
					seatsObj.AtoGArraysave(Row,addColumn,x,y,xAdd,seatnumber,ABCDEFG);	
				}
				else if(customer == "6")
				{
					seatsObj.theatre(x+25+ABincrs+CDEincrs-FGdcrs,y+0,6);
					int Row = 5,seatnumber = 6, xAdd = 25 + ABincrs + CDEincrs - FGdcrs;
					seatsObj.AtoGArraysave(Row,addColumn,x,y,xAdd,seatnumber,ABCDEFG);	
				}
				else if(customer == "7")
				{
					seatsObj.theatre(x+30+ABincrs+CDEincrs-FGdcrs,y+0,7);
					int Row = 6,seatnumber = 7, xAdd = 30 + ABincrs + CDEincrs - FGdcrs;
					seatsObj.AtoGArraysave(Row,addColumn,x,y,xAdd,seatnumber,ABCDEFG);	
				}
				else if(customer == "8")
				{
					seatsObj.theatre(x+35+ABincrs+CDEincrs-FGdcrs,y+0,8);
					int Row = 7,seatnumber = 8, xAdd = 35 + ABincrs + CDEincrs - FGdcrs;
					seatsObj.AtoGArraysave(Row,addColumn,x,y,xAdd,seatnumber,ABCDEFG);		
				}
				else if(customer == "9")
				{
					seatsObj.theatre(x+40+ABincrs+CDEincrs-FGdcrs,y+0,9);
					int Row = 8,seatnumber = 9, xAdd = 40 + ABincrs + CDEincrs - FGdcrs;
					seatsObj.AtoGArraysave(Row,addColumn,x,y,xAdd,seatnumber,ABCDEFG);		
				}
				else if(customer == "10")
				{
					seatsObj.theatre(x+45+(ABincrs+CDEincrs*2)-(FGdcrs*2),y+0,10);
					int Row = 9,seatnumber = 10, xAdd = 45 + (ABincrs + CDEincrs*2) - (FGdcrs*2);
					seatsObj.AtoGArraysave(Row,addColumn,x,y,xAdd,seatnumber,ABCDEFG);		
				}
				else if(customer == "11" )
				{
					if(ABCDEFG=="c"||ABCDEFG=="d"||ABCDEFG=="e"||ABCDEFG=="f"||ABCDEFG=="g" && ABCDEFG!="a" && ABCDEFG!="b")
					{
						seatsObj.theatre(x+50+(CDEincrs*2)-FGdcrs,y+0,11);
						int Row = 10,seatnumber = 11, xAdd = 50 + (CDEincrs*2) - FGdcrs;
						seatsObj.CtoGArraysave(Row,addColumn,x,y,xAdd,seatnumber,ABCDEFG);	
					}
						
				}
				else if(customer == "12")
				{
					if(ABCDEFG=="c"||ABCDEFG=="d"||ABCDEFG=="e"||ABCDEFG=="f"||ABCDEFG=="g" && ABCDEFG!="a" && ABCDEFG!="b")
					seatsObj.theatre(x+55+(CDEincrs*2)-FGdcrs,y+0,12);
					{
						int Row = 11,seatnumber = 12, xAdd = 55+(CDEincrs*2)-FGdcrs;
						seatsObj.CtoGArraysave(Row,addColumn,x,y,xAdd,seatnumber,ABCDEFG);	
					}
				}
				else if(customer== "13")
				{
					if(ABCDEFG=="c"||ABCDEFG=="d"||ABCDEFG=="e"||ABCDEFG=="f"||ABCDEFG=="g" && ABCDEFG!="a" && ABCDEFG!="b")
					seatsObj.theatre(x+60+(CDEincrs*2)-FGdcrs,y+0,13);
					{
						int Row = 12,seatnumber = 13, xAdd = 60+(CDEincrs*2)-FGdcrs;
						seatsObj.CtoGArraysave(Row,addColumn,x,y,xAdd,seatnumber,ABCDEFG);	
					}
				}
				else if(customer == "14")
				{
					if(ABCDEFG=="c"||ABCDEFG=="d"||ABCDEFG=="e"||ABCDEFG=="f"||ABCDEFG=="g" && ABCDEFG!="a" && ABCDEFG!="b")
					seatsObj.theatre(x+65+(CDEincrs*2)-FGdcrs,y+0,14);
					{
						int Row = 13,seatnumber = 14, xAdd = 65+(CDEincrs*2)-FGdcrs;
						seatsObj.CtoGArraysave(Row,addColumn,x,y,xAdd,seatnumber,ABCDEFG);	
					}
				}
				else if(customer== "15")
				{
					if(ABCDEFG=="c"||ABCDEFG=="d"||ABCDEFG=="e"||ABCDEFG=="f"||ABCDEFG=="g" && ABCDEFG!="a" && ABCDEFG!="b")
					seatsObj.theatre(x+70+(CDEincrs+10)-(FGdcrs*2),y+0,15);
					{
						int Row = 14,seatnumber = 15, xAdd = 70 + (CDEincrs+10) - (FGdcrs*2);
						seatsObj.CtoGArraysave(Row,addColumn,x,y,xAdd,seatnumber,ABCDEFG);		
					}
				}
				else if(customer == "16")
				{
					if(ABCDEFG=="c"||ABCDEFG=="d"||ABCDEFG=="e"||ABCDEFG=="f"||ABCDEFG=="g" && ABCDEFG!="a" && ABCDEFG!="b")
					seatsObj.theatre(x+75+(CDEincrs+10)-(FGdcrs*2),y+0,16);
					{
						int Row = 15,seatnumber = 16, xAdd = 75 + (CDEincrs+10) - (FGdcrs*2);
						seatsObj.CtoGArraysave(Row,addColumn,x,y,xAdd,seatnumber,ABCDEFG);	
					}
				}
				else if(customer == "17")
				{
					if(ABCDEFG=="c"||ABCDEFG=="d"||ABCDEFG=="e"||ABCDEFG=="f"||ABCDEFG=="g" && ABCDEFG!="a" && ABCDEFG!="b")
					seatsObj.theatre(x+80+(CDEincrs+10)-(FGdcrs*2),y+0,17);
					{
						int Row = 16,seatnumber = 17, xAdd = 80 + (CDEincrs+10) - (FGdcrs*2);
						seatsObj.CtoGArraysave(Row,addColumn,x,y,xAdd,seatnumber,ABCDEFG);		
					}
				}
				else if(customer == "18")
				{
					if(ABCDEFG=="c"||ABCDEFG=="d"||ABCDEFG=="e"||ABCDEFG=="f"||ABCDEFG=="g" && ABCDEFG!="a" && ABCDEFG!="b")
					seatsObj.theatre(x+85+(CDEincrs+10)-(FGdcrs*2),y+0,18);
					{
						int Row = 17,seatnumber = 18, xAdd = 85 + (CDEincrs+10) - (FGdcrs*2);
						seatsObj.CtoGArraysave(Row,addColumn,x,y,xAdd,seatnumber,ABCDEFG);	
					}
				}
				else if(customer == "19")
				{
					if(ABCDEFG=="f"||ABCDEFG=="g" && ABCDEFG!="c" && ABCDEFG!="d" && ABCDEFG!="e" && ABCDEFG!="b" && ABCDEFG!="a")
					seatsObj.theatre(x+90+(CDEincrs+10)-(FGdcrs*2),y+0,19);
					{
						int Row = 18,seatnumber = 19, xAdd = 90 + (CDEincrs+10) - (FGdcrs*2);
						seatsObj.FtoGArraysave(Row,addColumn,x,y,xAdd,seatnumber,ABCDEFG);	
					}
				}
				else if(customer == "20")
				{
					if(ABCDEFG=="f"||ABCDEFG=="g"&& ABCDEFG!="c" && ABCDEFG!="d" && ABCDEFG!="e" && ABCDEFG!="b" && ABCDEFG!="a")
					seatsObj.theatre(x+95+(CDEincrs+10)-(FGdcrs*2),y+0,20);
					{
						int Row = 19,seatnumber = 20, xAdd = 95 + (CDEincrs+10) - (FGdcrs*2);
						seatsObj.FtoGArraysave(Row,addColumn,x,y,xAdd,seatnumber,ABCDEFG);
					}
				}
				else if(customer == "Done" || customer == "done")
				{
					a = false;
					b = false;
					inputtime = true;
					Price = true;
					Clear(41,29,3,15);
					Clear(41,34,0,15);
					Clear(44,37,0,12);
					Clear(44,37,0,12);
					Clear(44,42,1,12);
					Clear(44,45,0,12);
				}
				else if(customer == "New" || customer == "new")
				{
					system("cls");
					memset(saveseatscoord, 0, sizeof(saveseatscoord));
					SeatDuplicator(30+move,16);
					a = false;
					b = false;
					Unrepeat = false;
					inputtime = false;
					
				}
				else if(customer =="-help"){
					Movieoption optionObj;
					optionObj.Movieoption4(26,6);
					goto Repeatseatnumber;
				}
				else
				{
				Clear(move1+39,24,0,15);
				}
				
		}	
};

class message
{
	public:
		float totalprice,LEGITPRICE, TotalLEGITPRICE,payment,discounted_price, TTOTALPRICE,a[7][4];;
		int RecordX,RecordY,Recordseatnum,ticket,i, k, j; 
		string x[7][4], CChoiceM, CChoiceT,NA;
		char Decision;
		bool Time1, Time2;
		stringstream conv;
	void inputmovies()
	{
		char vl = 186, urc = 187, lrc = 188, load = 177, ll = 179,
		ulc = 201, llc = 200, hl = 205, l = 196;
		NA = "N/A";
		int NAI = 0;
		
		do {
			gotoxy(8, 3); cout << "Enter the movies: ";
			for (i = 0, k = 1, j = 0; i < 7; i++, k++) {
				gotoxy(5, 3 + k); cout << "Movie (Day " << k << "): ";
				getline(cin, x[i][j]);	
				if (x[i][j] == "") {
					x[i][j] = NA;
				}
			}
			bool stringans = false;
			gotoxy(37, 3); cout << "Enter Time: ";
			gotoxy(39, 4); cout << x[0][0];
			for (i = 0, j = 1, k = 1; j < 3; j++, k++) {
				stringans = false;
				gotoxy(40, 4 + k); cout << "Time " << k << ": ";
				if (x[0][0] != NA) {
					while (stringans == false){
					gotoxy(48, 4 + k); textcolor(4); cout << "00:00 AB"; textcolor(7);
					gotoxy (48, 4 + k); getline(cin, x[i][j]);
					
					if (x[i][j] == x[0][1]) {
						if (x[i][j] == ""){
							stringans = false;
						}
						else if (x[i][j].size() == 8) {
							stringans = true;
						}
						else {
							cin.clear();
							Clear(48, 5, 0, 50);
							stringans = false;
						}
					}
					else if (x[i][j] == x[0][2]) {
						if (x[i][j] == "") {
							x[i][j] = NA;
							stringans = true;
						}
						else if (x[i][j].size() == 8) {
							stringans = true;
						}
						else {
							cin.clear();
							Clear(48, 6, 0, 50);
							stringans = false;
						}
					}
				}
			}
				else {
					x[i][j] = NA;
					cout << x[i][j];
				}
			}
			gotoxy(39, 4 + k); cout << x[1][0];
			for (i = 1, j = 1, k = 1; j < 3; j++, k++) {
				stringans = false;
				gotoxy(40, 7 + k); cout << "Time " << k << ": ";
				if (x[1][0] != NA) {
					while (stringans == false){
					gotoxy (48, 7 + k); textcolor(4); cout << "00:00 AB"; textcolor(7);
					gotoxy (48, 7 + k); getline(cin, x[i][j]);
					if (x[i][j] == x[1][1]) {
						if (x[i][j] == ""){
							stringans = false;
						}
						else if (x[i][j].size() == 8) {
							stringans = true;
						}
						else {
							cin.clear();
							Clear(48, 8, 0, 50);
							stringans = false;
						}
					}
					else if (x[i][j] == x[1][2]) {
						if (x[i][j] == "") {
							x[i][j] = NA;
							stringans = true;
						}
						else if (x[i][j].size() == 8) {
							stringans = true;
						}
						else {
							cin.clear();
							Clear(48, 9, 0, 50);
							stringans = false;
						}
					}
				}
			}
				else {
					x[i][j] = NA;
					cout << x[i][j];
				}
			}
			gotoxy(39, 7 + k); cout << x[2][0];
			for (i = 2, j = 1, k = 1; j < 3; j++, k++) {
				stringans = false;
				gotoxy(40, 10 + k); cout << "Time " << k << ": ";
				if (x[2][0] != NA) {
					while (stringans == false){
					gotoxy (48, 10 + k); textcolor(4); cout << "00:00 AB"; textcolor(7);
					gotoxy (48, 10 + k); getline(cin, x[i][j]);
					if (x[i][j] == x[2][1]) {
						if (x[i][j] == ""){
							stringans = false;
						}
						else if (x[i][j].size() == 8) {
							stringans = true;
						}
						else {
							cin.clear();
							Clear(48, 11, 0, 50);
							stringans = false;
						}
					}
					else if (x[i][j] == x[2][2]) {
						if (x[i][j] == "") {
							x[i][j] = NA;
							stringans = true;
						}
						else if (x[i][j].size() == 8) {
							stringans = true;
						}
						else {
							cin.clear();
							Clear(48, 12, 0, 50);
							stringans = false;
						}
					}
				}
			}
				else {
					x[i][j] = NA;
					cout << x[i][j];
				}
			}
			gotoxy(39, 10 + k); cout << x[3][0];
			for (i = 3, j = 1, k = 1; j < 3; j++, k++) {
				stringans = false;
				gotoxy(40, 13 + k); cout << "Time " << k << ": ";
				if (x[3][0] != NA) {
					while (stringans == false){
					gotoxy (48, 13 + k); textcolor(4); cout << "00:00 AB"; textcolor(7);
					gotoxy (48, 13 + k); getline(cin, x[i][j]);
					if (x[i][j] == x[3][1]) {
						if (x[i][j] == ""){
							stringans = false;
						}
						else if (x[i][j].size() == 8) {
							stringans = true;
						}
						else {
							cin.clear();
							Clear(48, 14, 0, 50);
							stringans = false;
						}
					}
					else if (x[i][j] == x[3][2]) {
						if (x[i][j] == "") {
							x[i][j] = NA;
							stringans = true;
						}
						else if (x[i][j].size() == 8) {
							stringans = true;
						}
						else {
							cin.clear();
							Clear(48, 15, 0, 50);
							stringans = false;
						}
					}
				}
			}
				else {
					x[i][j] = NA;
					cout << x[i][j];
				}
			}
			gotoxy(39, 13 + k); cout << x[4][0];
			for (i = 4, j = 1, k = 1; j < 3; j++, k++) {
				stringans = false;
				gotoxy(40, 16 + k); cout << "Time " << k << ": ";
				if (x[4][0] != NA) {
					while (stringans == false){
					gotoxy (48, 16 + k); textcolor(4); cout << "00:00 AB"; textcolor(7);
					gotoxy (48, 16 + k); getline(cin, x[i][j]);
					if (x[i][j] == x[4][1]) {
						if (x[i][j] == ""){
							stringans = false;
						}
						else if (x[i][j].size() == 8) {
							stringans = true;
						}
						else {
							cin.clear();
							Clear(48, 17, 0, 50);
							stringans = false;
						}
					}
					else if (x[i][j] == x[4][2]) {
						if (x[i][j] == "") {
							x[i][j] = NA;
							stringans = true;
						}
						else if (x[i][j].size() == 8) {
							stringans = true;
						}
						else {
							cin.clear();
							Clear(48, 18, 0, 50);
							stringans = false;
						}
					}
				}
			}
				else {
					x[i][j] = NA;
					cout << x[i][j];
				}
			}
			gotoxy(39, 16 + k); cout << x[5][0];
			for (i = 5, j = 1, k = 1; j < 3; j++, k++) {
				stringans = false;
				gotoxy(40, 19 + k); cout << "Time " << k << ": ";
				if (x[5][0] != NA) {
					while (stringans == false){
					gotoxy (48, 19 + k); textcolor(4); cout << "00:00 AB"; textcolor(7);
					gotoxy (48, 19 + k); getline(cin, x[i][j]);
					if (x[i][j] == x[5][1]) {
						if (x[i][j] == ""){
							stringans = false;
						}
						else if (x[i][j].size() == 8) {
							stringans = true;
						}
						else {
							cin.clear();
							Clear(48, 20, 0, 50);
							stringans = false;
						}
					}
					else if (x[i][j] == x[5][2]) {
						if (x[i][j] == "") {
							x[i][j] = NA;
							stringans = true;
						}
						else if (x[i][j].size() == 8) {
							stringans = true;
						}
						else {
							cin.clear();
							Clear(48, 21, 0, 50);
							stringans = false;
						}
					}
				}
			}
				else {
					x[i][j] = NA;
					cout << x[i][j];
				}
			}
			gotoxy(39, 19 + k); cout << x[6][0];
			for (i = 6, j = 1, k = 1; j < 3; j++, k++) {
				stringans = false;
				gotoxy(40, 22 + k); cout << "Time " << k << ": ";
				if (x[6][0] != NA) {
					while (stringans == false){
					gotoxy (48, 22 + k); textcolor(4); cout << "00:00 AB"; textcolor(7);
					gotoxy (48, 22 + k); getline(cin, x[i][j]);
					if (x[i][j] == x[6][1]) {
						if (x[i][j] == ""){
							stringans = false;
						}
						else if (x[i][j].size() == 8) {
							stringans = true;
						}
						else {
							cin.clear();
							Clear(48, 23, 0, 50);
							stringans = false;
						}
					}
					else if (x[i][j] == x[6][2]) {
						if (x[i][j] == "") {
							x[i][j] = NA;
							stringans = true;
						}
						else if (x[i][j].size() == 8) {
							stringans = true;
						}
						else {
							cin.clear();
							Clear(48, 24, 0, 50);
							stringans = false;
						}
					}
				}
			}
				else {
					x[i][j] = NA;
					cout << x[i][j];
				}
			}
			bool Condition = false;
			gotoxy(67, 3); cout << "Enter Price: ";
			gotoxy(69, 4); cout << x[0][0];
			for (i = 0, j = 3, k = 1; j < 4; j++, k++) {
				gotoxy(71, 4 + k); cout << "Price: ";
				conv << x[0][3];
				conv >> a[0][3];
				if (x[0][0] != NA) {
					while (Condition == false){
					gotoxy(78, 5); cin >> a[i][j];
					if (a[i][j] > 0) {
						Condition = true;
					}
					else{
						cin.clear();
						cin.ignore(INT_MAX,'\n');
						Clear(78, 5, 0, 50);
						Condition = false;
					}
				}
			}
				else {
					a[i][j] = NAI;
					cout << a[i][j];
				}
			}
			Condition = false;
			gotoxy(69, 4 + k); cout << x[1][0];
			for (i = 1, j = 3, k = 1; j < 4; j++, k++) {
				gotoxy(71, 6 + k); cout << "Price: ";
				conv << x[1][3];
				conv >> a[1][3];
				if (x[1][0] != NA) {
					while (Condition == false){
					gotoxy(78, 7); cin >> a[i][j];
					if (a[i][j] > 0) {
						Condition = true;
					}
					else {
						cin.clear();
						cin.ignore(INT_MAX,'\n');
						Clear(78, 7, 0, 50);
						Condition = false;
					}
				}
			}
				else {
					a[i][j] = NAI;
					cout << a[i][j];
				}
			}
			Condition = false;
			gotoxy(69, 6 + k); cout << x[2][0];
			for (i = 2, j = 3, k = 1; j < 4; j++, k++) {
				gotoxy(71, 8 + k); cout << "Price: ";
				conv << x[2][3];
				conv >> a[2][3];
				if (x[2][0] != NA) {
					while (Condition == false){
					gotoxy(78, 9); cin >> a[i][j];
					if (a[i][j] > 0) {
						Condition = true;
					}
					else {
						cin.clear();
						cin.ignore(INT_MAX,'\n');
						Clear(78, 9, 0, 50);
						Condition = false;
					}
				}
			}
				else {
					a[i][j] = NAI;
					cout << a[i][j];
				}
			}
			Condition = false;
			gotoxy(69, 8 + k); cout << x[3][0];
			for (i = 3, j = 3, k = 1; j < 4; j++, k++) {
				gotoxy(71, 10 + k); cout << "Price: ";
				conv << x[3][3];
				conv >> a[3][3];
				if (x[3][0] != NA) {
					while (Condition == false){
					gotoxy(78, 11); cin >> a[i][j];
					if (a[i][j] > 0) {
						Condition = true;
					}
					else {
						cin.clear();
						cin.ignore(INT_MAX,'\n');
						Clear(78, 11, 0, 50);
						Condition = false;
					}
				}
			}
				else {
					a[i][j] = NAI;
					cout << a[i][j];
				}
			}
			Condition = false;
			gotoxy(69, 10 + k); cout << x[4][0];
			for (i = 4, j = 3, k = 1; j < 4; j++, k++) {
				gotoxy(71, 12 + k); cout << "Price: ";
				conv << x[4][3];
				conv >> a[4][3];
				if (x[4][0] != NA) {
					while (Condition == false){
					gotoxy(78, 13); cin >> a[i][j];
					if (a[i][j] > 0) {
						Condition = true;
					}
					else {
						cin.clear();
						cin.ignore(INT_MAX,'\n');
						Clear(78, 13, 0, 50);
						Condition = false;
					}
				}
			}
				else {
					a[i][j] = NAI;
					cout << a[i][j];
				}
			}
			Condition = false;
			gotoxy(69, 12 + k); cout << x[5][0];
			for (i = 5, j = 3, k = 1; j < 4; j++, k++) {
				gotoxy(71, 14 + k); cout << "Price: ";
				conv << x[5][3];
				conv >> a[5][3];
				if (x[5][0] != NA) {
					while (Condition == false){
					gotoxy(78, 15); cin >> a[i][j];
					if (a[i][j] > 0) {
						Condition = true;
					}
					else {
						cin.clear();
						cin.ignore(INT_MAX,'\n');
						Clear(78, 15, 0, 50);
						Condition = false;
					}
				}
			}
				else {
					a[i][j] = NAI;
					cout << a[i][j];
				}
			}
			Condition = false;
			gotoxy(69, 14 + k); cout << x[6][0];
			for (i = 6, j = 3, k = 1; j < 4; j++, k++) {
				gotoxy(71, 16 + k); cout << "Price: ";
				conv << x[6][3];
				conv >> a[6][3];
				if (x[6][0] != NA) {
					while (Condition == false){
					gotoxy(78, 17); cin >> a[i][j];
					if (a[i][j] > 0) {
						Condition = true;
					}
					else {
						cin.clear();
						cin.ignore(INT_MAX,'\n');
						Clear(78, 17, 0, 50);
						Condition = false;
					}
				}
			}
				else {
					a[i][j] = NAI;
					cout << a[i][j];
				}
			}
			cin.ignore(INT_MAX,'\n');
			gotoxy(0, 28); cout << "Press Y to restart, Any key to continue: ";
			cin >> Decision;
			cin.clear();
			cin.ignore(INT_MAX,'\n');
			system("pause");
			system("cls");
			i = 0, k = 0, j = 0;
			
			}
			while (Decision == 'Y' || Decision == 'y');
			system("cls");	
		}	
	void Display(short xpos, short ypos)
	{
		MovieChoices movieObj;
		movieObj.boxChoice(xpos-2,ypos-6);
		boxGridx2half(xpos-32,ypos-6,18,30,xpos-24,xpos-12);
		gotoxy(xpos-29,ypos-3); cout<<"Days";
		gotoxy(xpos-20,ypos-3); cout<<"Amount";
		gotoxy(xpos-10,ypos-3); cout<<"Tickets";
		for(int i = 1,j = 1; i<15;i++){
			if(i%2!=0){
				gotoxy(xpos-29,ypos-2+i);cout<<"Day "<<j;
				j++;
			}
		}
		gotoxy(xpos,ypos); cout<<x[0][0]; 
		gotoxy(xpos+19,ypos); cout<<x[1][0]; 
		gotoxy(xpos+38,ypos); cout<<x[2][0]; 
		gotoxy(xpos+57,ypos); cout<<x[3][0]; 
		gotoxy(xpos,ypos+7); cout<<x[4][0]; 
		gotoxy(xpos+25,ypos+7); cout<<x[5][0];
		gotoxy(xpos+50,ypos+7); cout<<x[6][0];
		
		gotoxy(xpos+6,ypos+2); cout<<x[0][1]; 
		gotoxy(xpos+6,ypos+3); cout<<x[0][2];
		gotoxy(xpos+25,ypos+2); cout<<x[1][1];
		gotoxy(xpos+25,ypos+3); cout<<x[1][2];
		gotoxy(xpos+45,ypos+2); cout<<x[2][1];
		gotoxy(xpos+45,ypos+3); cout<<x[2][2];
		gotoxy(xpos+63,ypos+2); cout<<x[3][1];
		gotoxy(xpos+63,ypos+3); cout<<x[3][2];
		
		gotoxy(xpos+6,ypos+9); cout<<x[4][1];
		gotoxy(xpos+6,ypos+10); cout<<x[4][2];
		gotoxy(xpos+31,ypos+9);cout<<x[5][1];
		gotoxy(xpos+31,ypos+10);cout<<x[5][2];
		gotoxy(xpos+56,ypos+9);cout<<x[6][1];
		gotoxy(xpos+56,ypos+10);cout<<x[6][2];
		
		gotoxy(xpos+6,ypos+4); cout<<" Php"<<a[0][3];
		gotoxy(xpos+25,ypos+4); cout<<" Php"<<a[1][3];
		gotoxy(xpos+44,ypos+4); cout<<" Php"<<a[2][3];
		gotoxy(xpos+63,ypos+4); cout<<" Php"<<a[3][3];
		gotoxy(xpos+6,ypos+11); cout<<" Php"<<a[4][3];
		gotoxy(xpos+31,ypos+11); cout<<" Php"<<a[5][3];
		gotoxy(xpos+56,ypos+11); cout<<" Php"<<a[6][3];
	}
	void DecisionTime(bool TTime1, bool TTime2)
	{
		message inputObj;
		MovieSeatsBox seatsObj;
		seatsObj.SeatDuplicator(30+move,16);
		
		if(TTime1 == true){
		for(i=0;i<21;i++)
			{
				for(k=0;k<7;k++)
				{
					for(j=0;j<3;j++)
					{
						if(j == 0)
						{
							RecordX=saveseatscoord[i][j][k];	
						}
						else if(j == 1)
						{
							RecordY=saveseatscoord[i][j][k];
						}
						else if(j == 2)
						{
							Recordseatnum=saveseatscoord[i][j][k];
						}
					
					}
					if(RecordX != 0 && RecordY != 0 && Recordseatnum !=0){
					textcolor(4);
					seatsObj.seat(RecordX,RecordY);
					seatsObj.snum(RecordX,RecordY,Recordseatnum);
					textcolor(7);
					}
					
				}
				
			}
		}
		if(TTime2 == true){
		for(i=0;i<21;i++)
			{
				for(k=7;k<14;k++)
				{
					for(j=0;j<3;j++)
					{
						if(j == 0)
						{
							RecordX=saveseatscoord[i][j][k];	
						}
						else if(j == 1)
						{
							RecordY=saveseatscoord[i][j][k];
						}
						else if(j == 2)
						{
							Recordseatnum=saveseatscoord[i][j][k];
						}
					}
					if(RecordX != 0 && RecordY != 0 && Recordseatnum !=0){
					textcolor(4);
					seatsObj.seat(RecordX,RecordY);
					seatsObj.snum(RecordX,RecordY,Recordseatnum);
					textcolor(7);
					}
				}
				
			}
		}
	
	}
	void askMovie(short xpos, short ypos)
	{
		message inputObj;
		string NA = "N/A";
		bool asker = false; 
		while (asker == false){
		RepeatMovie:
		Clear(xpos+34,ypos+8,0,14);
		gotoxy(xpos +34,ypos+8); getline(cin, CChoiceM);
			if (CChoiceM == x[0][0]) {
				if (CChoiceM == NA) {
					Clear(xpos+16,ypos-1,0,50);
					asker = false;
				}
				else {
					asker = true;
					timenew = false;
				}
			}
			else if (CChoiceM == x[1][0]) {
				if (CChoiceM == NA) {
					Clear(xpos+16,ypos-1,0,50);
					asker = false;
				}
				else {
					asker = true;
					timenew = false;
				}
			}
			else if (CChoiceM == x[2][0]) {
				if (CChoiceM == NA) {
					Clear(xpos+16,ypos-1,0,50);
					asker = false;
				}
				else {
					asker = true;
					timenew = false;
				}
			}
			else if (CChoiceM == x[3][0]) {
				if (CChoiceM == NA) {
					Clear(xpos+16,ypos-1,0,50);
					asker = false;
				}
				else {
					asker = true;
					timenew = false;
				}
			}
			else if (CChoiceM == x[4][0]) {
				if (CChoiceM == NA) {
					Clear(xpos+16,ypos-1,0,50);
					asker = false;
				}
				else {
					asker = true;
					timenew = false;
				}
			}
			else if (CChoiceM == x[5][0]) {
				if (CChoiceM == NA) {
					Clear(xpos+16,ypos-1,0,50);
					asker = false;
				}
				else {
					asker = true;
					timenew = false;
				}
			}
			else if (CChoiceM == x[6][0]) {
				if (CChoiceM == NA) {
					Clear(xpos+16,ypos-1,0,50);
					asker = false;
				}
				else {
					asker = true;
					timenew = false;
				}
			}
			else if(CChoiceM =="-help"){
					Movieoption optionObj;
					optionObj.Movieoption1(26,6);
					goto RepeatMovie;
				}
			else if(CChoiceM == "Exit" || CChoiceM == "exit")
				{
					system("cls");
					asker = true;
					timenew = false;
					inputObj.exitprog(20,10);	
				}	
			else{
				Clear(xpos+34,ypos+8,0,14);
				asker = false;
			}
		}
	}
	void exitprog(short xpos,short ypos)
	{
		message inputObj;
		float finalprice=0;
		int finaltix=0;
		boxGridx2half(xpos,ypos-3,18,40,xpos+18,xpos+30);
		gotoxy(xpos+3,ypos); cout<<"Movie Name";
		gotoxy(xpos+20,ypos); cout<<"Amount";
		gotoxy(xpos+32,ypos); cout<<"Tickets";
		boxGridx2half(xpos,24,4,40,xpos+18,xpos+30);
		for (int i = 0; i < 7;i++)
		{
			finalprice+=totalmovieprice[i][0];
			finaltix+=totalmovieprice[i][1];
		}
		gotoxy(xpos+3,ypos+17);cout<<"Week Total";
		gotoxy(xpos+20,ypos+17);cout<<finalprice;
		gotoxy(xpos+32,ypos+17);cout<<finaltix;
		timeexit = true;
	}
	void TIMER(short xpos, short ypos)
	{
		message inputObj;
		bool choices = false;
		if (CChoiceM == x[0][0]) {
			while(choices == false){
				RepeatTime:
				Clear(xpos+34,ypos+10,0,15);
				gotoxy(xpos+34,ypos+10); getline(cin,CChoiceT);
				numreserveseats = 0;
				if (CChoiceT == x[0][1] || CChoiceT == x[0][2]){
					
					choices = true;
					if(CChoiceT == x[0][1]){
						Time1 = true;
						Time2 = false;
						inputObj.DecisionTime(true,false);
					}
					else if(CChoiceT == x[0][2]){
						Time1 = false;
						Time2 = true;
						inputObj.DecisionTime(false,true);
					}
				}
				else if(CChoiceT =="-help"){
					Movieoption optionObj;
					optionObj.Movieoption2(26,6);
					goto RepeatTime;
				}
				else if (CChoiceT == "new"||CChoiceT == "New"){	
					choices = true;
					timenew = true;;
				}
				else if(CChoiceT == "Exit" || CChoiceT == "exit")
				{
					system("cls");
					choices = true;
					inputObj.exitprog(20,10);	
				}
				else {
					Clear(xpos+34,ypos+10,0,15);
					choices = false;
				}
			}
		}
		else if (CChoiceM == x[1][0]){
			while(choices == false){
				RepeatTime1:
				Clear(xpos+34,ypos+10,0,15);
				gotoxy(xpos+34,ypos+10); getline(cin,CChoiceT);
				numreserveseats = 0;
				if (CChoiceT == x[1][1] || CChoiceT == x[1][2]){
					
					choices = true;
					if(CChoiceT == x[1][1]){
						Time1 = true;
						Time2 = false;
						inputObj.DecisionTime(true,false);
					}
					else if(CChoiceT == x[1][2]){
						Time1 = false;
						Time2 = true;
						inputObj.DecisionTime(false,true);
					}
				}
				else if(CChoiceT =="-help"){
					Movieoption optionObj;
					optionObj.Movieoption2(26,6);
					goto RepeatTime1;
					}
				else if (CChoiceT == "new"||CChoiceT == "New"){	
					choices = true;
					timenew = true;;
				}
				else if(CChoiceT == "Exit" || CChoiceT == "exit")
				{
					system("cls");
					choices = true;
					inputObj.exitprog(20,10);	
				}
				else {
					Clear(xpos+34,ypos+10,0,15);
					choices = false;
				}
			}
		}
		else if (CChoiceM == x[2][0]){
			while(choices == false){
				RepeatTime2:
				Clear(xpos+34,ypos+10,0,15);	
				gotoxy(xpos+34,ypos+10); getline(cin,CChoiceT);
				numreserveseats = 0;
				if (CChoiceT == x[2][1] || CChoiceT == x[2][2]){
					
					choices = true;
					if(CChoiceT == x[2][1]){
						Time1 = true;
						Time2 = false;
						inputObj.DecisionTime(true,false);
					}
					else if(CChoiceT == x[2][2]){
						Time1 = false;
						Time2 = true;
						inputObj.DecisionTime(false,true);
					}
				}
				else if(CChoiceT =="-help"){
					Movieoption optionObj;
					optionObj.Movieoption2(26,6);
					goto RepeatTime2;
					}
				else if (CChoiceT == "new"||CChoiceT == "New"){	
					choices = true;
					timenew = true;;
				}
				else if(CChoiceT == "Exit" || CChoiceT == "exit")
				{
					system("cls");
					choices = true;
					inputObj.exitprog(20,10);	
				}	
				else {
					Clear(xpos+34,ypos+10,0,15);
					choices = false;
				}
				
			}
		}
		else if (CChoiceM == x[3][0]){
			while(choices == false){
				RepeatTime3:
				Clear(xpos+34,ypos+10,0,15);	
				gotoxy(xpos+34,ypos+10); getline(cin,CChoiceT);
				numreserveseats = 0;
				if (CChoiceT == x[3][1] || CChoiceT == x[3][2]){
					
					choices = true;
					if(CChoiceT == x[3][1]){
						Time1 = true;
						Time2 = false;
						inputObj.DecisionTime(true,false);
					}
					else if(CChoiceT == x[3][2]){
						Time1 = false;
						Time2 = true;
						inputObj.DecisionTime(false,true);
					}
				}
				else if(CChoiceT =="-help"){
					Movieoption optionObj;
					optionObj.Movieoption2(26,6);
					goto RepeatTime3;
					}
				else if (CChoiceT == "new"||CChoiceT == "New"){	
					choices = true;
					timenew = true;;
				}
				else if(CChoiceT == "Exit" || CChoiceT == "exit")
				{
					system("cls");
					choices = true;
					inputObj.exitprog(20,10);	
				}
				else {
					Clear(xpos+34,ypos+10,0,15);
					choices = false;
				}
				
			}
		}
		else if (CChoiceM == x[4][0]){
			while(choices == false){
				RepeatTime4:
				Clear(xpos+34,ypos+10,0,15);	
				gotoxy(xpos+34,ypos+10); getline(cin,CChoiceT);
				numreserveseats = 0;
				if (CChoiceT == x[4][1] || CChoiceT == x[4][2]){
					
					choices = true;
					if(CChoiceT == x[4][1]){
						Time1 = true;
						Time2 = false;
						inputObj.DecisionTime(true,false);
					}
					else if(CChoiceT == x[4][2]){
						Time1 = false;
						Time2 = true;
						inputObj.DecisionTime(false,true);
					}
				}
				else if(CChoiceT =="-help"){
					Movieoption optionObj;
					optionObj.Movieoption2(26,6);
					goto RepeatTime4;
					}
				else if (CChoiceT == "new"||CChoiceT == "New"){	
					choices = true;
					timenew = true;;
				}
				else if(CChoiceT == "Exit" || CChoiceT == "exit")
				{
					system("cls");
					choices = true;
					inputObj.exitprog(20,10);	
				}	
				else {
					Clear(xpos+34,ypos+10,0,15);
					choices = false;
				}
			}
		} 
		else if (CChoiceM == x[5][0]){
			while(choices == false){
				RepeatTime5:
				Clear(xpos+34,ypos+10,0,15);	
				gotoxy(xpos+34,ypos+10); getline(cin,CChoiceT);
				numreserveseats = 0;
				if (CChoiceT == x[5][1] || CChoiceT == x[5][2]){
					
					choices = true;
					if(CChoiceT == x[5][1]){
						Time1 = true;
						Time2 = false;
						inputObj.DecisionTime(true,false);
					}
					else if(CChoiceT == x[5][2]){
						Time1 = false;
						Time2 = true;
						inputObj.DecisionTime(false,true);
					}
				}
				else if(CChoiceT =="-help"){
					Movieoption optionObj;
					optionObj.Movieoption2(26,6);
					goto RepeatTime5;
					}
				else if (CChoiceT == "new"||CChoiceT == "New"){	
					choices = true;
					timenew = true;;
				}
				else if(CChoiceT == "Exit" || CChoiceT == "exit")
				{
					system("cls");
					choices = true;
					inputObj.exitprog(20,10);	
				}	
				else {
					Clear(xpos+34,ypos+10,0,15);
					choices = false;
				}
			}
		} 
		else if (CChoiceM == x[6][0]){
			while(choices == false){
				RepeatTime6:
				Clear(xpos+34,ypos+10,0,15);	
				gotoxy(xpos+34,ypos+10); getline(cin,CChoiceT);
				numreserveseats = 0;
				if (CChoiceT == x[6][1] || CChoiceT == x[6][2]){
					
					choices = true;
					if(CChoiceT == x[6][1]){
						Time1 = true;
						Time2 = false;
						inputObj.DecisionTime(true,false);
					}
					else if(CChoiceT == x[6][2]){
						Time1 = false;
						Time2 = true;
						inputObj.DecisionTime(false,true);
					}
				}
				else if(CChoiceT =="-help"){
					Movieoption optionObj;
					optionObj.Movieoption2(26,6);
					goto RepeatTime6;
					}
				else if (CChoiceT == "new"||CChoiceT == "New"){	
					choices = true;
					timenew = true;;
				}
				else if(CChoiceT == "Exit" || CChoiceT == "exit")
				{
					system("cls");
					choices = true;
					inputObj.exitprog(20,10);	
				}	
				else {
					Clear(xpos+34,ypos+10,0,15);
					choices = false;
				}
			}
		}
	}
	
	void infoQuestion(short xpos, short ypos)
	{
		message inputObj;
		bool PRICERANGE = false;
		if (CChoiceM == x[0][0]) {
			gotoxy(xpos+37,ypos+ 17); cout << x[0][0];//movie name
			gotoxy(xpos+37, ypos+18); cout << a[0][3];//movie price
			LEGITPRICE = a[0][3];
			gotoxy(xpos+37, ypos+19);cout<<numreserveseats;//tickets
			totalprice = LEGITPRICE * numreserveseats;
			gotoxy(xpos+37, ypos+20);cout<<totalprice;
			
			if (CChoiceT == x[0][1]||CChoiceT == x[0][2]) {
				RepeatPayment:Clear(xpos+37,ypos+22,0,13);
				gotoxy(xpos + 37, ypos+22);cin>>payment;
				if(payment < totalprice){
					cin.clear();
					cin.ignore(INT_MAX,'\n');
					Movieoption optionObj;
					optionObj.Movieoption5(26,6);
					goto RepeatPayment;
				}
			}
		}
		else if (CChoiceM == x[1][0]) {
			gotoxy(xpos+37, ypos+17); cout<< x[1][0];
			gotoxy(xpos+37, ypos+18); cout<< a[1][3];
			LEGITPRICE = a[1][3];
			gotoxy(xpos+37, ypos+19);cout<<numreserveseats;//tickets
			totalprice = LEGITPRICE * numreserveseats;
			gotoxy(xpos+37, ypos+20);cout<<totalprice;
		
			if (CChoiceT == x[1][1]||CChoiceT == x[1][2]) {
				RepeatPayment2:Clear(xpos+37,ypos+22,0,13);
				gotoxy(xpos + 37, ypos+22);cin>>payment;
				if(payment < totalprice){
					cin.clear();
					cin.ignore(INT_MAX,'\n');
					Movieoption optionObj;
					optionObj.Movieoption5(26,6);
					goto RepeatPayment2;
				}
			}
		}
		else if (CChoiceM == x[2][0]) {
			gotoxy(xpos+37, ypos+17); cout<< x[2][0];
			gotoxy(xpos+37, ypos+18); cout<< a[2][3];
			LEGITPRICE = a[2][3];
			gotoxy(xpos+37, ypos+19);cout<<numreserveseats;//tickets
			totalprice = LEGITPRICE * numreserveseats;
			gotoxy(xpos+37, ypos+20);cout<<totalprice;
			
			if (CChoiceT == x[2][1]||CChoiceT == x[2][2]) {	
				RepeatPayment4:Clear(xpos+37,ypos+22,0,13);
				gotoxy(xpos + 37, ypos+22);cin>>payment;
				if(payment < totalprice){
					cin.clear();
					cin.ignore(INT_MAX,'\n');
					Movieoption optionObj;
					optionObj.Movieoption5(26,6);
					goto RepeatPayment4;
				}	
			}
		}
		else if (CChoiceM == x[3][0]) {
			gotoxy(xpos+37, ypos+17); cout<< x[3][0];
			gotoxy(xpos+37, ypos+18); cout<< a[3][3];
			LEGITPRICE = a[3][3];
			gotoxy(xpos+37, ypos+19);cout<<numreserveseats;//tickets
			totalprice = LEGITPRICE * numreserveseats;
			gotoxy(xpos+37, ypos+20);cout<<totalprice;
			
			if (CChoiceT == x[3][1]||CChoiceT == x[3][2]) {
				RepeatPayment6:Clear(xpos+37,ypos+22,0,13);
				gotoxy(xpos + 37, ypos+22);cin>>payment;
				if(payment < totalprice){
					cin.clear();
					cin.ignore(INT_MAX,'\n');
					Movieoption optionObj;
					optionObj.Movieoption5(26,6);
					goto RepeatPayment6;
				}
				
			}

		}
		else if (CChoiceM == x[4][0]) {
			gotoxy(xpos+37, ypos+17); cout<< x[4][0];
			gotoxy(xpos+37, ypos+18); cout<< a[4][3];
			LEGITPRICE = a[4][3];
			gotoxy(xpos+37, ypos+19);cout<<numreserveseats;//tickets
			totalprice = LEGITPRICE * numreserveseats;
			gotoxy(xpos+37, ypos+20);cout<<totalprice;
			if (CChoiceT == x[4][1]||CChoiceT == x[4][2]) {
				RepeatPayment8:Clear(xpos+37,ypos+22,0,13);
				gotoxy(xpos + 37, ypos+22);cin>>payment;
				if(payment < totalprice){
					cin.clear();
					cin.ignore(INT_MAX,'\n');
					Movieoption optionObj;
					optionObj.Movieoption5(26,6);
					goto RepeatPayment8;
				}
			}
		}
		else if (CChoiceM == x[5][0]) {
			gotoxy(xpos+37, ypos+17); cout<< x[5][0];
			gotoxy(xpos+37, ypos+18); cout<< a[5][3];
			LEGITPRICE = a[5][3];
			gotoxy(xpos+37, ypos+19);cout<<numreserveseats;//tickets
			totalprice = LEGITPRICE * numreserveseats;
			gotoxy(xpos+37, ypos+20);cout<<totalprice;
		
			if (CChoiceT == x[5][1]||CChoiceT == x[5][2]) {
				RepeatPayment10:Clear(xpos+37,ypos+22,0,13);
				gotoxy(xpos + 37, ypos+22);cin>>payment;
				if(payment < totalprice){
					cin.clear();
					cin.ignore(INT_MAX,'\n');
					Movieoption optionObj;
					optionObj.Movieoption5(26,6);
					goto RepeatPayment10;
				}	
			}
		}
		else if (CChoiceM == x[6][0]) {
			gotoxy(xpos+37, ypos+17); cout<< x[6][0];
			gotoxy(xpos+37, ypos+18); cout<< a[6][3];
			LEGITPRICE = a[6][3];
			gotoxy(xpos+37, ypos+19);cout<<numreserveseats;//tickets
			totalprice = LEGITPRICE * numreserveseats;
			gotoxy(xpos+37, ypos+20);cout<<totalprice;
			
			if (CChoiceT == x[6][1]||CChoiceT == x[6][2]) {
				RepeatPayment12:Clear(xpos+37,ypos+22,0,13);
				gotoxy(xpos + 37, ypos+22);cin>>payment;
				if(payment < totalprice){
					cin.clear();
					cin.ignore(INT_MAX,'\n');
					Movieoption optionObj;
					optionObj.Movieoption5(26,6);
					goto RepeatPayment12;
				}
			}
		}
	}
	void Discount(float payment, double totalprice, short xpos, short ypos)
	{	
		string card;
		float pay;
		int Numberofcards;
		stringstream conv;
		bool CARDASKER = false, cardverify = false;
		reserveseatsticket += numreserveseats;
		while (cardverify == false)
		{
		RepeatDiscount:
		Clear(xpos+40,ypos+10,0,10);	
		gotoxy(xpos+40, ypos+10);getline(cin,card);
		if (card == "Yes" || card == "yes"&& numreserveseats > 0){
			conv << payment;
			conv >> pay;
			while (CARDASKER == false){
				RepeatDiscountCards:
				gotoxy(xpos+40,ypos+12);cin>>Numberofcards;
				if (Numberofcards <= numreserveseats && Numberofcards > 0)
				{
					CARDASKER = true;	
				}
				else
				{
					Clear(xpos+40,ypos+12,0,10);
					CARDASKER = false;
					cin.clear();
					cin.ignore(INT_MAX,'\n');
				}
			}
			numreserveseats -= Numberofcards;
			TTOTALPRICE = LEGITPRICE * Numberofcards;
			TTOTALPRICE *= .80;
			TotalLEGITPRICE = LEGITPRICE * numreserveseats;
			TotalLEGITPRICE += TTOTALPRICE;
			gotoxy(xpos+39, ypos+15);cout<<TotalLEGITPRICE;
			gotoxy(xpos+39, ypos+16);cout<<pay;
			discounted_price = pay - TotalLEGITPRICE;
			gotoxy(xpos+39, ypos+18);cout<<discounted_price;
			cardverify = true;
			if (CChoiceM == x[0][0])
			{
				totalmovieprice[0][0] += TotalLEGITPRICE;
				totalmovieprice[0][1] += reserveseatsticket;
			}
			else if (CChoiceM == x[1][0])
			{
				totalmovieprice[1][0] += TotalLEGITPRICE;
				totalmovieprice[1][1] += reserveseatsticket;
			}
			else if (CChoiceM == x[2][0])
			{
				totalmovieprice[2][0] += TotalLEGITPRICE;
				totalmovieprice[2][1] += reserveseatsticket;
			}
			else if (CChoiceM == x[3][0])
			{
				totalmovieprice[3][0] += TotalLEGITPRICE;
				totalmovieprice[3][1] += reserveseatsticket;
			}
			else if (CChoiceM == x[4][0])
			{
				totalmovieprice[4][0] += TotalLEGITPRICE;
				totalmovieprice[4][1] += reserveseatsticket;
			}
			else if (CChoiceM == x[5][0])
			{
				totalmovieprice[5][0] += TotalLEGITPRICE;
				totalmovieprice[5][1] += reserveseatsticket;
			}
			else if (CChoiceM == x[6][0])
			{
				totalmovieprice[6][0] += TotalLEGITPRICE;
				totalmovieprice[6][1] += reserveseatsticket;
			}
		}
		else if (card =="None" || card == "none"){
			conv << payment;
			conv >> pay;
			totalprice = LEGITPRICE * numreserveseats;
			gotoxy(xpos+40, ypos+15);cout<<totalprice;//movie price
			gotoxy(xpos+40, ypos+16);cout<<pay;//payment
	
			pay -= totalprice;
			gotoxy(xpos+40, ypos+18);cout<<pay;//change
			if (CChoiceM == x[0][0])
			{
				totalmovieprice[0][0] += totalprice;
				totalmovieprice[0][1] += reserveseatsticket;
			}
			else if (CChoiceM == x[1][0])
			{
				totalmovieprice[1][0] += totalprice;
				totalmovieprice[1][1] += reserveseatsticket;
			}
			else if (CChoiceM == x[2][0])
			{
				totalmovieprice[2][0] += totalprice;
				totalmovieprice[2][1] += reserveseatsticket;
			}
			else if (CChoiceM == x[3][0])
			{
				totalmovieprice[3][0] += totalprice;
				totalmovieprice[3][1] += reserveseatsticket;
			}
			else if (CChoiceM == x[4][0])
			{
				totalmovieprice[4][0] += totalprice;
				totalmovieprice[4][1] += reserveseatsticket;
			}
			else if (CChoiceM == x[5][0])
			{
				totalmovieprice[5][0] += totalprice;
				totalmovieprice[5][1] += reserveseatsticket;
			}
			else if (CChoiceM == x[6][0])
			{
				totalmovieprice[6][0] += totalprice;
				totalmovieprice[6][1] += reserveseatsticket;
			}
			cardverify = true;
		}
		else if(card =="-help"){
					Movieoption optionObj;
					optionObj.Movieoption6(26,6);
					optionObj.Movieoption7(26,6);
					goto RepeatDiscount;
				}
		else {
			Clear(xpos+40,ypos+10,0,10);
			cin.clear();
			cardverify = false;	
			}				
		}
	}
	void tMPrice(short xpos,short ypos)
	{
		for (int i = 0,k=0; i < 7; k+=2,i++)
		{
			Clear(xpos+76,ypos+k-22,0,10);
			Clear(xpos+88,ypos+k-22,0,9);
		}
		for (int i = 0,k=0; i < 7; k+=2,i++)
		{
			gotoxy(xpos + 77, ypos + k - 22); cout<<totalmovieprice[i][0];
			gotoxy(xpos + 89, ypos + k - 22); cout<<totalmovieprice[i][1];
		}
	numreserveseats = 0;
	reserveseatsticket = 0;
	}
	
};

int main()
{
	MovieSeatsBox seatsObj;
	MovieChoices movieObj;
	message inputObj;
	int i,j,z=0;
	seatsObj.Unrepeat = false, seatsObj.Price = false, seatsObj.inputtime = false;
	bool start = false; timeexit = false;
	int xpos,ypos,cxpos,cypos;
	gotoxy(33,9);cout<<"Note: Input Letters will set to default."<<endl;
	gotoxy(33,10);cout<<"Define The size of Console ( default 1500 x 850 )"<<endl;
	gotoxy(43,12);cout<<"X position of the Console: ";
	gotoxy(43,13);cout<<"Y position of the Console: ";
	gotoxy(43,14);cout<<"Width of the Console     : ";
	gotoxy(43,15);cout<<"Length of the Console    : ";
	gotoxy(70,12);cin>>xpos;
	gotoxy(70,13);cin>>ypos;
	gotoxy(70,14);cin>>cxpos;
	gotoxy(70,15);cin>>cypos;
	gotoxy(33,17);system("pause");
	system("cls");
	start = true;
	ConsoleWindow(0+xpos,0+ypos,1500+cxpos,850+cypos);
	cin.clear();
	cin.ignore(INT_MAX, '\n');
	memset(totalmovieprice,0,sizeof(totalmovieprice));
	memset(saveseatscoord,'\0', sizeof(saveseatscoord));
	numreserveseats = 0;
	inputObj.Time1;
	inputObj.Time2;
	if(start == true) 
	inputObj.inputmovies();
	
	seatsObj.SeatDuplicator(30+move,16);
	seatsObj.a=false,seatsObj.b=false;
		while(seatsObj.b==false) 
		{
			seatsObj.a;
			if(seatsObj.a==false)
			{
				while(seatsObj.Unrepeat == false){
					gotoxy(20,16);cout<<"\"-help\" Show Option";
					inputObj.Display(move + 45,6);
					movieObj.screen(13+move,18);
					Movieoutputs(move1+20,18);
					inputObj.askMovie(move1 + 5, 10);
					seatsObj.Unrepeat = true;	
				}
				repeattime:
				while(seatsObj.inputtime == false){
					inputObj.tMPrice(5,27);
					inputObj.TIMER(move1 + 5,10);
					seatsObj.inputtime = true;
				}
				while(seatsObj.Price == true){
					inputObj.infoQuestion(move1 + 5,12);
					inputObj.Discount(inputObj.payment,inputObj.totalprice,move1 + 5,27);
					inputObj.tMPrice(5,27);
					seatsObj.Price = false;
					seatsObj.inputtime = false;
					goto repeattime;
					}
				seatsObj.a=true;
			}
			if(timenew == true){
				system("cls");
				memset(saveseatscoord, 0, sizeof(saveseatscoord));
				seatsObj.SeatDuplicator(30+move,16);
				seatsObj.a = false;
				seatsObj.b = false;
				seatsObj.Unrepeat = false;
				seatsObj.inputtime = false;
				numreserveseats = 0;
				reserveseatsticket = 0;
			}
			Timeexit:
			if(timeexit == true){
				Clear(76,4,15,27);
				for(int i = 1,j = 0; i<15;j++,i+=2){
					gotoxy(23,11+i);cout<<inputObj.x[j][0];
				}
				for (int i = 0,k=0; i < 7; k+=2,i++)
				{
					gotoxy(40,12+k); cout<<totalmovieprice[i][0];
					gotoxy(52,12+k); cout<<totalmovieprice[i][1];
				}
				cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
				system("pause");
				return 0;
			}
			Repeatseatletter:
			Clear(move1+39,22,0,15);
			if(timenew == false){
				gotoxy(move1 + 39,22);getline(cin,seatsObj.seatletter);
				if(seatsObj.seatletter == "A"|| seatsObj.seatletter == "a")
				{
					if(inputObj.Time1 == true){
						seatsObj.seats1_20(30+move,16,5,0,0,"a",0);
					}
					else if(inputObj.Time2 == true){
						seatsObj.seats1_20(30+move,16,5,0,0,"a",7);
					}
				}
				else if(seatsObj.seatletter == "B" || seatsObj.seatletter == "b")
				{
					if(inputObj.Time1 == true){
						seatsObj.seats1_20(30+move,19,5,0,0,"b",0);
					}
					else if(inputObj.Time2 == true){
						seatsObj.seats1_20(30+move,19,5,0,0,"b",7);
					}
				}
				else if(seatsObj.seatletter == "C" ||seatsObj.seatletter == "c")
				{
					if(inputObj.Time1 == true){
						seatsObj.seats1_20(5+move,22,0,5,0,"c",0);
					}
					else if(inputObj.Time2 == true){
						seatsObj.seats1_20(5+move,22,0,5,0,"c",7);
					}
				}
				else if(seatsObj.seatletter == "D" || seatsObj.seatletter == "d")
				{
					if(inputObj.Time1 == true){
						seatsObj.seats1_20(5+move,25,0,5,0,"d",0);
					}
					else if(inputObj.Time2 == true){
						seatsObj.seats1_20(5+move,25,0,5,0,"d",7);
					}
				}
				else if(seatsObj.seatletter == "E" || seatsObj.seatletter == "e")
				{
					if(inputObj.Time1 == true){
						seatsObj.seats1_20(5+move,28,0,5,0,"e",0);
					}
					else if(inputObj.Time2 == true){
							seatsObj.seats1_20(5+move,28,0,5,0,"e",7);
					}
				
				}
				else if(seatsObj.seatletter == "F" || seatsObj.seatletter == "f")
				{
					if(inputObj.Time1 == true){
						seatsObj.seats1_20(5+move,31,0,5,5,"f",0);
					}
					else if(inputObj.Time2 == true){
						seatsObj.seats1_20(5+move,31,0,5,5,"f",7);
					}
					
				}
				else if(seatsObj.seatletter == "G" || seatsObj.seatletter == "g")
				{
					if(inputObj.Time1 == true){
						seatsObj.seats1_20(5+move,34,0,5,5,"g",0);
					}
					else if(inputObj.Time2 == true){
						seatsObj.seats1_20(5+move,34,0,5,5,"g",7);
					}
				}
				else if(seatsObj.seatletter == "Done" || seatsObj.seatletter == "done")
				{
					seatsObj.a = false;
					seatsObj.b = false;
					seatsObj.inputtime = true;
					seatsObj.Price = true;
					Clear(41,29,3,15);
					Clear(41,34,0,15);
					Clear(44,37,0,12);
					Clear(45,39,0,10);
					Clear(44,42,1,12);
					Clear(44,45,0,12);
				}
				else if(seatsObj.seatletter == "New" || seatsObj.seatletter == "new")
				{
					system("cls");
					memset(saveseatscoord, 0, sizeof(saveseatscoord));
					seatsObj.SeatDuplicator(30+move,16);
					seatsObj.a = false;
					seatsObj.b = false;
					seatsObj.Unrepeat = false;
					seatsObj.inputtime = false;
					numreserveseats = 0;
					reserveseatsticket = 0;				
				}
				else if(seatsObj.seatletter == "Exit" || seatsObj.seatletter == "exit")
				{
					system("cls");
					seatsObj.a = true;
					seatsObj.b = true;
					timeexit = true;
					inputObj.exitprog(20,10);
					goto Timeexit;	
				}
				else if(seatsObj.seatletter =="-help"){
						Movieoption optionObj;
						optionObj.Movieoption3(26,6);
						goto Repeatseatletter;
				}
				else{
					Clear(move1+39,22,0,15);
				}
			}
		}
return 0;
}
