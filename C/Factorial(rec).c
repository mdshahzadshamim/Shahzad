#include<stdio.h>
#include<stdlib.h>
int fac(int i)
{
    if(i==1) return (i);
    else return (i*fac(i-1));
}

int main()
{
    system("cls");

    int i;
    printf("i = ");
    scanf("%d",&i);
    printf("Factorial : %d",fac(i));
    
    return 0;
}