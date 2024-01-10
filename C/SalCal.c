#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>
#include"month.h"

int main()
{
    system("cls");
    printf("Initiating . . .\n");
    int mon = 1;
    do
    {
        fflush(stdin);
        
        float basic = 13303.8;
        /*float hra = 0.5*basic;
        float bonus = 0.2*basic;
        float wbp = 0.415*basic;
        float pf = 0.154*basic;*/
        float ptnpm = 600;
        float varpay = 0.125*basic;

        float salary;

        printf("\nEnter Month(1-12) : ");
        int mon;
        scanf("%d",&mon);

        if(mon==11 || mon==2 || mon==5 || mon==8)
        salary = (1.961*basic) + (3*varpay) - 600;
        else
        salary = (1.961*basic) - 600;

        printf("Salary for "); month(mon); printf(" : %f\n",salary);
    
        if (getchar() != '\n')
        {fflush(stdin); printf("\nLoop terminated"); exit(1);}
    }while(1);
    
    return 0;
}