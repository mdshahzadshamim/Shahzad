#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>
#include"daymonthleap.h"
/*SWAPPABLE CALENDAR*/
#define C 2001
#define N 12
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
int main()
{
    system("cls");
    
    int count = 0, mon = 5, year = 2023;
    
    int repeat = 0;
    while(repeat != 27)
    {
        int n = 0;
        if(count == 0)
        {
            printf("\nMonth: "); scanf("%d",&mon);
            printf("Year: "); scanf("%d",&year);
            count++;
        }
        else
        {
            if(repeat == 72) /*up*/ year++;
            else if(repeat == 80) /*down*/ year--;
            else if(repeat == 75) /*left*/
            {
                if(mon == 1)
                {
                    mon = 12;
                    year--;
                }
                else
                mon--;
            }
            else if(repeat == 77) /*right*/
            {
                if(mon == 12)
                {
                    mon = 1;
                    year++;
                }
                else
                mon++;
            }
            else /*anything else*/
            printf("Invalid Input\n");
        }
        
        printf("\n\t\t\t"); month(mon); printf(" %d\n\n",year);
        
        if(!(mon > 0 && mon <= 12))
        {
            printf("Invalid Input\n");
            continue;
        }

        for (int i = 1; i <= 7; i++)
        {
            day_short(i);
            printf("\t");
        }
        printf("\n\n");

        /*  Calculation */
        //#define C 2001
        //#define N 12
        if(year < C)
        {
            int count1 = 0, count2 = 0;
            
            /*Calculating extra days for current year*/
            for (int i = mon; i <= N; i++)
            count1 += month_days(i,year);
            count1 %= 7;

            /*Calculating extra days upto 2000*/
            for (int i = year+1; i < C; i++)
            {
                if(leap(i) == 0)
                count2 += 1;
                else if(leap(i) == 1)
                count2 += 2;
            }

            n = 7 - ((count1 + count2) % 7);            
        }
        else if(year >= C)
        {
            int count1 = 0, count2 = 0;
            
            /*Calculating extra days upto current year minus one*/
            if(year != C)
            for (int i = C; i < year; i++)
            {
                if(leap(i) == 0)
                count1 += 1;
                else if(leap(i) == 1)
                count1 += 2;
            }

            /*Calculating extra days for the current year*/
            for (int i = 1; i < mon; i++)
            count2 += month_days(i,year);
            count2 %= 7;

            n = ((count1 + count2) % 7) + 1;
        }

        for(int space = 1; space < n; space++)
        printf(" \t");

        for(int i = 1, j = n; i <= month_days(mon,year) && j <= 7; i++, j++)
        {
            printf("%d\t",i);

            if(j == 7/* && i < month_days(mon,year)*/)
            {
                j = 0;
                printf("\n");
            }
        }
        
        fflush(stdin);
        printf("\n\nWhat next? . . . ");
        repeat = getkey();
    }
    return 0;
}