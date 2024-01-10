#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<math.h>

int main()
{
    system("cls");

    int i;
    printf("Amount = ");
    scanf("%d",&i);

    if(i>=100)
    {
        int q = i/100;
        printf("100 notes : %d\n",q);
        int r = i%100;
        i = r;
    }
    if(i>=50)
    {
        int q = i/50;
        printf("50 notes : %d\n",q);
        int r = i%50;
        i = r;
    }
    if(i>=10)
    {
        int q = i/10;
        printf("10 notes : %d\n",q);
        int r = i%10;
        i = r;
    }
    if(i>=5)
    {
        int q = i/5;
        printf("5 notes : %d\n",q);
        int r = i%5;
        i = r;
    }
    if(i>=2)
    {
        int q = i/2;
        printf("2 notes : %d\n",q);
        int r = i%2;
        i = r;
    }
    if(i>=1)
    {
        int q = i/1;
        printf("1 notes : %d\n",q);
        int r = i%1;
        i = r;
    }
    
    return 0;
}

