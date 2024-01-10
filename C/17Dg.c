#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <conio.h>
#include <time.h>
#include "leap.h"
#define SIZE 5

int getkey();
void linkfloat();

#pragma pack(1)
typedef struct date_of_the_year
{
    /*Structure Declaration*/
    int day;
    int month;
    int year;
}dt;
#pragma pack()

/*Declare Functions Below This*/
int compare_dt(dt first, dt second);

int main()
{
    system("cls");

    printf("\nI N I T I A T I N G . . . \n");
    
    int repeat = 0;
    while(repeat != 27)
    {
        printf("\n\n");/*code*/

        printf("Enter two dates . . . \n");

        dt first; printf("\nFirst :\n");
        
        printf("Year - "); scanf("%d",&first.year);
        if(first.year <= 0)
        { printf("Invalid Input\n"); continue; }
        
        printf("Month - "); scanf("%d",&first.month);
        if(first.month <= 0 || first.month > 12)
        { printf("Invalid Input\n"); continue; }

        printf("Day - "); scanf("%d",&first.day);
        if(first.day <= 0 || first.day > day_count(first.month,first.year))
        { printf("Invalid Input\n"); continue; }
        
        dt second; printf("\nSecond :\n");
        
        printf("Year - "); scanf("%d",&second.year);
        if(second.year <= 0)
        { printf("Invalid Input\n"); continue; }
        
        printf("Month - "); scanf("%d",&second.month);
        if(second.month <= 0 || second.month > 12)
        { printf("Invalid Input\n"); continue; }

        printf("Day - "); scanf("%d",&second.day);
        if(second.day <= 0 || second.day > day_count(second.month,second.year))
        { printf("Invalid Input\n"); continue; }

        int temp = compare_dt(first,second);
        printf("\nOutput : %d\n",temp);

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

int compare_dt(dt first, dt second)
{
    //Compare two dates of the year
    if(first.day == second.day && first.month == second.month && first.year == second.year)
        return 0;
    else
        return 1;
}