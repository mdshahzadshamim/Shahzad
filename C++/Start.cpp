#include<iostream>
#include<conio.h>
#include<Windows.h>

using namespace std;

//default values in case no parameters are passed
void cls(short = 0, short = 0);
void gotoxy(short, short);

int main()
{
	cout << "Hello World";
	_getch();
	cls(); //*This will clear all after coordinates 5,0

	// This will to check if the screen is clear, it will print Hey, 
	//after remaining string

	cout << " Hey";

	_getch();
	return 0;
}
void cls(short i, short j)
{
	short m = i, n = j;
	for (; j < 50; j++)
	{
		for (; i < 50; i++)
		{
			gotoxy(i, j);
			putchar(' ');
		}
		i = 0;
	}

	gotoxy(m, n); // Going back to initial position after clear the screen
}

void gotoxy(short col, short row)
{
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD position = { col, row };
	SetConsoleCursorPosition(h, position);
}