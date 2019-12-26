#include<iostream>
#include<windows.h>
void textcolor (short x)
{
	HANDLE color=GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(color, x);	
}
