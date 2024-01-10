#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <unistd.h>
#define SIZE 5
int getkey();
typedef struct judge_score
{
    int js1;
    int js2;
    int js3;
    int total;
}js;
int main()
{
    printf("\nI N I T I A T I N G . . . \n");

    int repeat = 0;
    while(repeat != 27)
    {
        printf("\n\n");/*code*/
        
        js player[SIZE];
        srand(time(NULL));
        //sleep(1);
        
        int highest = 0, no = 0;

        for(int i = 0; i < SIZE; i++)
        {
            player[i].js1 = 1 + rand() % 5;
            player[i].js2 = 1 + rand() % 5;
            player[i].js3 = 1 + rand() % 5;
            player[i].total = player[i].js1+player[i].js2+player[i].js3;
            if(player[i].total > highest)
            {
                highest = player[i].total;
                no = i + 1;
            }
        }
        /*for(int i = 0; i < SIZE; i++)
        printf("Player %d : %d\n",i+1,player[i].total);*/
        printf("MVP : Player %d\n",no);

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