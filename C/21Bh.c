#include<stdio.h>
#include"showbits.h"
#define BV(x) (1<<x)
int main()
{
    char x;
    printf("\nEnter Number: "); scanf("%d", &x);
    showbits(x); printf("\n");
    if((x & BV(3)) && (x & BV(5)))
    {
        x ^= BV(3);
        x ^= BV(5);
    }
    showbits(x); printf("\n");

    return 0;
}