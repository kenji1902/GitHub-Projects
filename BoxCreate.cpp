#include<iostream>
#include<windows.h>
using namespace std;
void gotoxy(short x, short y)
{
	COORD XYgraph = {x,y};
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),XYgraph);
}
void boxCorners(short xpos, short ypos, short length, short width)
{
	char ulc = 191, urc = 218, llc = 217, lrc = 192;
	gotoxy(xpos+1,ypos+2); cout<<urc;  gotoxy(xpos+width,ypos+2); cout<<ulc;
	gotoxy(xpos+1,ypos+length); cout<<lrc; gotoxy(xpos+width,ypos+length); cout<<llc;
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
void boxGridx2(short xpos, short ypos,short length, short width)
{
	int i,k;
	char ulc = 191, hl = 196, urc = 218, vl = 179, llc = 217, lrc = 192, clear = 255;
	char rmc = 195, lmc = 180, mdl = 194, mul = 193, mudl = 197;
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
	for(i=1; i < length; i=i+(length/(length/2))){
		for(k=1; k < (width-1); k++){
			gotoxy(xpos+k+1,ypos+i+1);cout<<hl;
			gotoxy(xpos+1,ypos+i+1);cout<<rmc;
			gotoxy(xpos+width,ypos+i+1);cout<<lmc;
		}
	}
	gotoxy(xpos+1,ypos+2); cout<<urc;  gotoxy(xpos+width,ypos+2); cout<<ulc;
	gotoxy(xpos+1,ypos+length); cout<<lrc; gotoxy(xpos+width,ypos+length); cout<<llc;
	
}
void boxGridx2half(short xpos, short ypos,short length, short width, short verticalline)
{
	int i,k;
	char ulc = 191, hl = 196, urc = 218, vl = 179, llc = 217, lrc = 192, clear = 255;
	char rmc = 195, lmc = 180, mdl = 194, mul = 193, mudl = 197;
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
	gotoxy(verticalline,ypos+2);cout<<mdl;gotoxy(verticalline,ypos+length);cout<<mul;
	gotoxy(xpos+1,ypos+2); cout<<urc;  gotoxy(xpos+width,ypos+2); cout<<ulc;
	gotoxy(xpos+1,ypos+length); cout<<lrc; gotoxy(xpos+width,ypos+length); cout<<llc;
	
}
void boxhalfv(short xpos, short ypos, short length, short width, short verticalline)
{
	int i,k;
	char ulc = 191, hl = 196, urc = 218, vl = 179, llc = 217, lrc = 192, clear = 255;
	char rmc = 195, lmc = 180, mdl = 194, mul = 193, mudl = 197;	
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
	for(i=1; i < length; i++){
		for(k=1; k < (width-1); k++){
			if(i < length-1){
			gotoxy(verticalline,ypos+i+2);cout<<vl;	
			}
		}
	}
	gotoxy(verticalline,ypos+2);cout<<mdl;gotoxy(verticalline,ypos+length);cout<<mul;
}
void boxhalfvh(short xpos, short ypos, short length, short width, short verticalline,short horizontalline)
{
	int i,k;
	char ulc = 191, hl = 196, urc = 218, vl = 179, llc = 217, lrc = 192, clear = 255;
	char rmc = 195, lmc = 180, mdl = 194, mul = 193, mudl = 197;	
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
int main()
{
	boxGridx2half(10,10,41,60,20);
	cout<<"\n\n\n\n";
}
