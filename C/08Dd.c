#include<stdio.h>
#include<stdlib.h>
void fun(int k)
{
    if(k%100==0)
    {
        if(k%400==0)
        printf("Yes");
        else
        printf("No");
    }
    else
    {
        if(k%4==0)
        printf("Yes");
        else
        printf("No");
    }
}

int main()
{
    system("cls");

    int k;
    printf("k = ");
    scanf("%d",&k);
    printf("\n");
    fun(k);
    
    return 0;
}
