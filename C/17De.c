#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <time.h>
#define SIZE 100
#define NAMESIZE 25

int getkey();
void linkfloat();

#pragma pack(1)
typedef struct experience
{
    int y;
    int m;
    int d;
}exp;
#pragma pack()

#pragma pack(1)
typedef struct date_of_joining
{
    int d;
    int m;
    int y;
    exp ovrl_exp;
}date;
#pragma pack()

#pragma pack(1)
typedef struct employee
{
    /*Structure Declaration*/
    int code;
    char name[NAMESIZE];
    date d;
}emp;
#pragma pack()

/*Declare Functions Below This*/
void generate(emp e[]);
int leap(int year);
int day_count(int month, int year);

int main()
{
    system("cls");

    printf("\nI N I T I A T I N G . . . \n");

    emp e[SIZE];

    generate(e);
    
    int repeat = 0;
    while(repeat != 27)
    {
        printf("\n\n");/*code*/

        int limit,more_or_less;
        printf("Employee Experience Limit : "); scanf("%d",&limit);
        printf("Below(0) / Above(1) : "); scanf("%d",&more_or_less);

        printf("\n");

        printf("Code\tName\t\t\t\tJoined\t\tExperience\n\n");

        if(more_or_less == 0)
        {
            for(int i = 0; i < SIZE; i++)
            if(e[i].d.ovrl_exp.y < limit)
            printf("%d\t%s\t%d/%d/%d\t%d Years %d Months %d Days\n",e[i].code,e[i].name,e[i].d.d,e[i].d.m,e[i].d.y,e[i].d.ovrl_exp.y,e[i].d.ovrl_exp.m,e[i].d.ovrl_exp.d);
        }
        else if(more_or_less == 1)
        {
            for(int i = 0; i < SIZE; i++)
            if(e[i].d.ovrl_exp.y >= limit)
            printf("%d\t%s\t%d/%d/%d\t%d Years %d Months %d Days\n",e[i].code,e[i].name,e[i].d.d,e[i].d.m,e[i].d.y,e[i].d.ovrl_exp.y,e[i].d.ovrl_exp.m,e[i].d.ovrl_exp.d);
        }
        
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

void generate(emp e[])
{
    srand(time(NULL));

    time_t now = time(NULL);
    struct tm *t = localtime(&now);

    
    //Day of the month
    int day = t->tm_mday;
    //Months since January
    int month = (t->tm_mon) + 1;
    //Years since 1900
    int year = (t->tm_year) + 1900;

    for(int i = 0; i < SIZE; i++)
    {
        /*code*/
        e[i].code = i + 1;
        for(int j = 0; j < NAMESIZE-1; j++)
        e[i].name[j] = 'A' + rand() % 26;
        e[i].name[NAMESIZE-1] = '\0';
        e[i].d.y = 2000 + rand() % 23;
        e[i].d.m = 1 + rand() % 12;
        e[i].d.d = 1 + rand() % 28;
        //Calculate Experience
        if(e[i].d.d <= day)
        {
            //Calculate months upto this month
            e[i].d.ovrl_exp.d = day - e[i].d.d;
            
            if(e[i].d.m <= month)
            {
                e[i].d.ovrl_exp.y = year - e[i].d.y;
                e[i].d.ovrl_exp.m = month - e[i].d.m;
            }
            else if(e[i].d.m > month)
            {
                e[i].d.ovrl_exp.y = (year - 1)- e[i].d.y;
                e[i].d.ovrl_exp.m = (12 + month) - e[i].d.m;
            }
        }
        else if(e[i].d.d > day)
        {
            //Calculate months upto last month
            if(month == 1)
            {
                month = 13;
                year -= 1;
            }

            e[i].d.ovrl_exp.d = (day_count(month-1, year) - e[i].d.d) + day;
            
            if(e[i].d.m <= month - 1)
            {
                e[i].d.ovrl_exp.y = year - e[i].d.y;
                e[i].d.ovrl_exp.m = (month - 1) - e[i].d.m;
            }
            else if(e[i].d.m > month - 1)
            {
                e[i].d.ovrl_exp.y = (year - 1)- e[i].d.y;
                e[i].d.ovrl_exp.m = (12 + month - 1) - e[i].d.m;
            }
        }
    }//Loop End
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

int day_count(int month, int year)
{
    if(month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
    return 31;
    else if(month == 4 || month == 6 || month == 9 || month == 11)
    return 30;
    else if(month == 2)
    {
        if(leap(year) == 1)
        return 29;
        else if(leap(year) == 0)
        return 28;
    }
}
/*->*/