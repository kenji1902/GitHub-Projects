#include<iostream>
#include<windows.h>
void ConsoleWindow(short x,short y,short cx,short cy)
{
	HWND consoleWindow = GetConsoleWindow();
	RECT ConsoleRect;
	GetWindowRect(consoleWindow, &ConsoleRect); 
	MoveWindow(consoleWindow, x, y, cx, cy, TRUE);
}
