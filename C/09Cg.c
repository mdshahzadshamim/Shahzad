#include<stdio.h>
#include<stdlib.h>

int gcd(int *a, int *b)
{
    int t=0;
    if((*a)%(*b) == 0)
    {
        printf("\n%d",*b);
    }
    else
    {
        t = (*a)%(*b);
        *a = *b;
        *b = t;
        gcd(a, b);
    }
}

int main()
{
    system("cls");

    int a,b;
    printf("a = "); scanf("%d",&a);
    printf("b = "); scanf("%d",&b);

    gcd(&a, &b);
    
    return 0;
}
