#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <conio.h>
#include <time.h>
#define SIZE 10

int getkey();
void linkfloat();

#pragma pack(1)
typedef struct parts
{
    /*Structure Declaration*/
    char s_no[5];
    int yom;
    char material[SIZE];
    int quant;
}part;
#pragma pack()

/*Declare Functions Below This*/
void retrieve(part p[], char *lower_lim, char *upper_lim);
void generate(part p[]);

int main()
{
    system("cls");

    printf("\nI N I T I A T I N G . . . \n");

    part p[360];
    generate(p);
    
    int repeat = 0;
    while(repeat != 27)
    {
        printf("\n\n");/*code*/
        
        printf("To retrieve info about parts, Enter the following : \n\n");
        printf("Lower Limit : "); char lim_l[5]; scanf("%s",lim_l);
        printf("Upper Limit : "); char lim_u[5]; scanf("%s",lim_u);
        retrieve(p,lim_l,lim_u);

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

void generate(part p[])
{
    /*code*/
    srand(time(NULL));
    
    int count = 0;
    
    for(char f = 'A'; f <= 'F'; f++)
    {
        for(char s = 'A'; s <= 'F'; s++)
        {
            for(char t = '0'; t <= '9'; t++)
            {
                p[count].s_no[0] = f;
                p[count].s_no[1] = s;
                p[count].s_no[2] = t;
                p[count].s_no[3] = '\0';
                //printf("%s\n",p[count].s_no);
                p[count].yom = rand() % (2023 - 2000) + 2000;
                for(int mat = 0; mat < SIZE-1; mat++)
                p[count].material[mat] = 'A' + rand() % 26;
                p[count].material[SIZE-1] = '\0';
                p[count].quant = rand() % 100;
                count++;
            }
        }
    }
    //printf("\n\nCOUNT : %d",count);

}

void retrieve(part p[], char *lower_lim, char *upper_lim)
{
    /*code*/
    int lower = -1, upper = -1;
    int i = 0;
    while(lower < 0)
    {
        if(strcmp(lower_lim,p[i].s_no) == 0)
        lower  = i;
        i++;
    }
    while(upper < 0)
    {
        if(strcmp(upper_lim,p[i].s_no) == 0)
        upper  = i;
        i++;
    }

    //printf("Lower : %d\tUpper : %d\n\n",lower,upper);

    printf("\nS.No\tY.O.M\tMaterial\tQuantity\n\n");
    for(int j = lower; j <= upper; j++)
    printf("%s\t%d\t%s\t%d\n",p[j].s_no,p[j].yom,p[j].material,p[j].quant);
}

/*->*/