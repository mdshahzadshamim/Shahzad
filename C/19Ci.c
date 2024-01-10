#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <conio.h>
#include <time.h>
#include "month.h"
/*Arrange Employee by Experience*/

#define SIZE 10
#define NAMESIZE 10

int getkey();
void linkfloat();

#pragma pack(1)
typedef struct date_of_joining
{
    /*Structure Declaration*/
    int d, m, y;
}doj;
#pragma pack()

#pragma pack(1)
typedef struct employee
{
    /*Structure Declaration*/
    int empcode;
    char name[NAMESIZE];
    float salary;
    doj joined;
    int compute;
}emp;
#pragma pack()

/*Declare Functions Below This*/
void generate(emp e[]);
int compare(const void *pa, const void *pb);

int main()
{
    system("cls");

    printf("\nI N I T I A T I N G . . . \n\n");

    FILE *fe, *ft;

    fe = fopen("EMP19CI.DAT", "wb+");
    if(fe == NULL)
    {
        puts("Error 1\n");
        exit(1);
    }
    ft = fopen("19CIT.DAT","wb+");
    if(ft == NULL)
    {
        puts("Error 1\n");
        exit(1);
    }

    emp e[SIZE],k;
    //int n = sizeof(e)/sizeof(emp);

    generate(e);

    printf("Employee Data BEFORE Sorting the Joining Dates:\n");
    printf("\nEmp Code\t");
    printf("Name      \t");
    printf("Salary  \t");
    printf("Date of Joining\n\n");

    fwrite(&e, sizeof(emp), SIZE, fe);
    
    rewind(fe);
    while(fread(&k, sizeof(emp), 1, fe) == 1)
    {
        printf("%-8d\t%-10s\t%8.2f\t",k.empcode,k.name,k.salary);
        month_short(k.joined.m);
        printf(" ");
        if(k.joined.d < 10)
            printf("0");
        printf("%d %d\n", k.joined.d, k.joined.y);
    }

    printf("\n");

    qsort(e, SIZE, sizeof(emp), compare);

    printf("Employee Data AFTER Sorting the Joining Dates:\n");
    printf("\nEmp Code\t");
    printf("Name      \t");
    printf("Salary  \t");
    printf("Date of Joining\n\n");

    fwrite(&e, sizeof(emp), SIZE, ft);
    
    rewind(ft);
    while(fread(&k, sizeof(emp), 1, ft) == 1)
    {
        printf("%-8d\t%-10s\t%8.2f\t",k.empcode,k.name,k.salary);
        month_short(k.joined.m);
        printf(" ");
        if(k.joined.d < 10)
            printf("0");
        printf("%d %d\n", k.joined.d, k.joined.y);
    }

    fclose(fe); remove("EMP19CI.DAT"); printf("\nEmp Data Removed\n");
    fclose(ft); remove("19CIT.DAT"); printf("\nAranged Emp Data Removed\n");

    return 0;
}

void generate(emp e[])
{
    srand(time(NULL));

    for(int i = 0; i < SIZE; i++)
    {
        /*code*/
        e[i].empcode = i + 1;
        for(int j = 0; j < NAMESIZE-1; j++)
        e[i].name[j] = 'A' + rand() % 26;
        e[i].name[NAMESIZE-1] = '\0';
        e[i].joined.y = 2000 + rand() % 23;
        e[i].joined.m = 1 + rand() % 12;
        e[i].joined.d = 1 + rand() % 28;
        e[i].salary = 25000 + (rand() % 100) * 100;
        e[i].compute = e[i].joined.y * 10000 + e[i].joined.m * 100 + e[i].joined.d;
        //  printf("%ld\n",e[i].compute);
    }
}

int compare(const void *pa, const void *pb)
{
    const emp *a = pa;
    const emp *b = pb;
    return a->compute - b->compute;
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