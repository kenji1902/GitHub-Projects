#include<iostream>
#include<windows.h>
void gotoxy(short x, short y)
{
	COORD XYgraph = {x,y};
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),XYgraph);
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


