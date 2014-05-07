#include <windows.h> 
#include <iostream>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

using namespace std;

#include "myconsole.h"
//given in the last semester by Dr. Mehreem Saeed
void PlaceCursor(int x,int y)
{
    COORD c;
    c.X = x;
    c.Y = y;

    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(h,c);
}

//this function checks if a key is pressed and if a key is pressed
//then it returns the ascii code of the key pressed
int CheckKeyPressed(int waitTime)
{
	HANDLE h= GetStdHandle(STD_INPUT_HANDLE);
	INPUT_RECORD r;
	DWORD w = 1;
	DWORD eventss;
	DWORD waitResult=0;
	int keypressed = false;
	int toReturn = 0;

	waitResult = WaitForSingleObject(h,waitTime);

	if (waitResult == WAIT_OBJECT_0)
	{
		//FlushConsoleInputBuffer(h);..commented out as this takes to asynchronous mode on some systems
		keypressed = ReadConsoleInput(h,&r,1,&eventss);
		
		if (keypressed && r.EventType==KEY_EVENT && r.Event.KeyEvent.bKeyDown)
			toReturn = r.Event.KeyEvent.wVirtualKeyCode;
		//this should make sure that checkKeyPressed is not called twice for arrow keys
		if (toReturn == 224)
			toReturn = CheckKeyPressed(waitTime);

		
		FlushConsoleInputBuffer(h);
	}
	return toReturn;
}

//changes the color of a certain co-ordinate
//color can be BACKGROUND_GREEN, BACKGROUND_BLUE,BACKGROUND_RED or a combination of these using | operator
bool SetColorAtPoint(int x,int y,int color)
{
    COORD c,size;
    c.X = x;
    c.Y = y;
    size.X = 1;
    size.Y = 1;


    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    
    WORD w = color;
    unsigned long written = 0;

    WriteConsoleOutputAttribute(h,&w,1,c,&written);

    if (written)
        return true;

    return false;
}