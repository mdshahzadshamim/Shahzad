#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <conio.h>
#include <time.h>
#define SIZE 20
#define NAMESIZE 5

int getkey();
void linkfloat();

#pragma pack(1)
typedef struct test_cricketers
{
    /*Structure Declaration*/
    char name[NAMESIZE];
    int age;
    int test_match_count;
    int avg_run;
}player;
#pragma pack()

/*Declare Functions Below This*/
void generate(player p[]);
int compare(const void *pa, const void *pb);

int main()
{
    system("cls");

    printf("\nI N I T I A T I N G . . . \n");

    player p[SIZE];
    generate(p);
    
    /*printf("\n\n");
    for(int i = 0; i < SIZE; i++)
    printf("%s\t%d\t%d\t%d\n",p[i].name,p[i].age,p[i].test_match_count,p[i].avg_run);*/


    int n = sizeof(p) / sizeof(player);
    int repeat = 0;
    while(repeat != 27)
    {
        printf("\n\n");/*code*/

        qsort(p, n, sizeof(player), compare);

        printf("PLAYER\tAGE\tMATCHES\tAVG\n\n");
        for(int i = 0; i < SIZE; i++)
        printf("%s\t%d\t%d\t%d\n",p[i].name,p[i].age,p[i].test_match_count,p[i].avg_run);

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

void generate(player p[])
{
    /*code*/
    srand(time(NULL));
    for(int i = 0; i < SIZE; i++)
    {
        for(int j = 0; j < NAMESIZE-1; j++)
        p[i].name[j] = 'A' + rand() % 26;
        p[i].name[NAMESIZE-1] = '\0';

        p[i].age = 18 + rand() % 17;
        p[i].test_match_count = 1 + rand() % 60;
        p[i].avg_run = 40 + rand() % 85;
    }
}

int compare(const void *pa, const void *pb)
{
    const player *a = pa;
    const player *b = pb;
    return a->avg_run - b->avg_run;
}

/*->*/