#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <conio.h>
#include <time.h>
#define SIZE 5

int getkey();
void linkfloat();

#pragma pack(1)
typedef struct hell
{
    /*Structure Declaration*/
};
#pragma pack()

/*Declare Functions Below This*/

int main()
{
    system("cls");

    printf("\nI N I T I A T I N G . . . \n");
    
    int repeat = 0;
    while(repeat != 27)
    {
        printf("\n\n");/*code*/

        ;

        fflush(stdin);
        printf("\n\nE N T E R  /  E S C . . . ");
        repeat = getkey(); printf("\n");
    }

    return 0;
}
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
}

void linkfloat()
{
    float a = 0, *b;
    b = &a;/*cause emulator to be linked*/
    a = *b;/*suppress the warning – variable not used*/
}