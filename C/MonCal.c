#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<math.h>
#include"daymonth.h"

int main()
{
    system("cls");

    int m,sum,ded=0;
    printf("\n");
    printf("I have : ");
    scanf("%d",&sum);
    printf("\n");
    for(m=4;m<=9;m++)
    {
        sum+=22000;
        printf("Total in "); month(m); printf(" :      %d\n",sum);
        ded=(m==4?20020:13220);
        sum-=ded;
        printf("Deductions in "); month(m); printf(" : %d\n",ded);
        printf("Left in "); month(m); printf(" :       %d\n\n",sum);
    }
    
    printf("Left in "); month(m-1); printf(" :    %d\n",sum);
    
    return 0;
}
