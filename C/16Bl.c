#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
int getkey();
int main()
{
    printf("\nInitiating . . . ");

    int line = 7, l;
    char *style[] = { " #### ", "#     ", "     #", "#    #" };
    int table[7][10] = {/*numbers:  0 1 2 3 4 5 6 7 8 9*/
                         /*line 1*/{0,2,0,0,3,0,0,0,0,0},
                         /*line 2*/{3,2,2,2,3,1,1,2,3,3},
                         /*line 3*/{3,2,2,2,3,1,1,2,3,3},
                         /*line 4*/{3,2,0,0,0,0,0,2,0,0},
                         /*line 5*/{3,2,1,2,2,2,3,2,3,2},
                         /*line 6*/{3,2,1,2,2,2,3,2,3,2},
                         /*line 7*/{0,2,0,0,2,0,0,2,0,2}
                        };

    int repeat = 0;
    while(repeat != 27)
    {
        /*code*/
        printf("\n\nEnter a 5-digit number : ");int n; scanf("%d",&n);printf("\n\n");
        int n1 = n/10000, n2 = (n/1000)%10, n3 = (n/100)%10, n4 = (n/10)%10, n5 = n%10;

        for(l = 0; l < line; l++)
        {
            printf("%s  ",style[table[l][n1]]);
            printf("%s  ",style[table[l][n2]]);
            printf("%s  ",style[table[l][n3]]);
            printf("%s  ",style[table[l][n4]]);
            printf("%s  ",style[table[l][n5]]);
            printf("\n");
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
/*
 ####
#    #
#    #
 ####
#    #
#    #
 ####

0 1 2 3 4 5 6 7 8 9

numbers: 0 1 2 3 4 5 6 7 8 9
line 1 - 0 2 0 0 3 0 0 0 0 0
line 2 - 3 2 2 2 3 1 1 2 3 3
line 3 - 3 2 2 2 3 1 1 2 3 3
line 4 - 3 2 0 0 0 0 0 2 0 0
line 5 - 3 2 1 2 2 2 3 2 3 2
line 6 - 3 2 1 2 2 2 3 2 3 2
line 7 - 0 2 0 0 2 0 0 2 0 2
*/