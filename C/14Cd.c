#include<stdio.h>
#include<windows.h>
//Game
int main()
{
    int a[4][4]={1,4,15,7,8,10,2,11,14,3,6,13,12,9,5,0}; 
    return 0;
}


//To position the cursor
/*#include<windows.h>
void gotoxy(short col,short row)
{
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD position = {col,row};
    SetConsoleCursorPosition(h,position);
}*/

//To scan the arrow keys
//up arrow key - 72, down arrow key - 80
//left arrow key - 75, right arrow key - 77

/*#include<conio.h>
int getkey()
{
    int ch;
    ch = getch();
    if(ch == 0)
    {
        ch = getch();
        return ch;
    }
    return ch;
}*/