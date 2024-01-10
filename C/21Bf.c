#include<stdio.h>
#include"showbits.h"
#define BV(x) (1<<x)
int main()
{
    printf("\nEnter the number: ");
    char num, n1 = 0; scanf("%d", &num);
    showbits(num); printf("\n");
    for(int i = 0; i < 8; i++)
    {
        if(i < 4)
        n1 += ((num & BV(i)) << 4);
        else
        n1 += ((num & BV(i)) >> 4);
    }
    num = n1;
    showbits(num); printf("\n");
    return 0;
}