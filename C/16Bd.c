#include<stdio.h>
#include<stdlib.h>
#include<string.h>
/*C A L E N D A R*/
#define C 2001
#define N 12
int month(int i)
{
    switch(i)
    {
        case 1:
            printf("January");
            break;
        case 2:
            printf("February");
            break;
        case 3:
            printf("March");
            break;
        case 4:
            printf("April");
            break;
        case 5:
            printf("May");
            break;
        case 6:
            printf("June");
            break;
        case 7:
            printf("July");
            break;
        case 8:
            printf("August");
            break;
        case 9:
            printf("September");
            break;
        case 10:
            printf("October");
            break;
        case 11:
            printf("November");
            break;
        case 12:
            printf("December");
            break;
    }
}

int day(int i)
{
    switch(i)
    {
        case 7:
            printf("Sun");
            break;
        case 1:
            printf("Mon");
            break;
        case 2:
            printf("Tue");
            break;
        case 3:
            printf("Wed");
            break;
        case 4:
            printf("Thu");
            break;
        case 5:
            printf("Fri");
            break;
        case 6:
            printf("Sat");
            break;
    }
}

int leap(int year)
{
    if(year%100 == 0)
    {
        if(year%400 == 0)
        return (1);
        else
        return (0);
    }
    else
    {
        if(year%4 == 0)
        return (1);
        else
        return (0);
    }
}

int month_days(int i, int year)
{
    int days;
    switch(i)
    {
        case 1:
            days = 31;
            break;
        case 2:
            if(leap(year) == 0) days = 28;
            else if(leap(year) == 1) days = 29;
            break;
        case 3:
            days = 31;
            break;
        case 4:
            days = 30;
            break;
        case 5:
            days = 31;
            break;
        case 6:
            days = 30;
            break;
        case 7:
            days = 31;
            break;
        case 8:
            days = 31;
            break;
        case 9:
            days = 30;
            break;
        case 10:
            days = 31;
            break;
        case 11:
            days = 30;
            break;
        case 12:
            days = 31;
            break;
    }
    return(days);
}

int main()
{
    system("cls");
    
    char repeat[5] = "Yes";
    while(strcmp(repeat,"No"))
    {
        int mon=5, year=2023, n = 0;
        printf("\nMonth: "); scanf("%d",&mon);
        printf("Year: "); scanf("%d",&year);
        printf("\n\t\t\t"); month(mon); printf(" %d\n\n",year);
        
        if(!(mon > 0 && mon <= 12))
        {
            printf("Invalid Input\n");
            continue;
        }

        for (int i = 1; i <= 7; i++)
        {
            day(i);
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
        printf("\n\nRepeat? . . . ");
        gets(repeat);
    }
    return 0;
}