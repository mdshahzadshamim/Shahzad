#include<stdio.h>
#include"showbits16.h"
#define BV(x) (1<<x)
int main()
{
    printf("\nEnter the number: ");
    unsigned short int num, n1 = 0; scanf("%d", &num);
    showbits16(num); printf("\n");
    for(int i = 0; i < 16; i++)
    {
        if(i < 8)
        n1 += ((num & BV(i)) << 8);
        else
        n1 += ((num & BV(i)) >> 8);
    }
    num = n1;
    showbits16(num); printf("\n");
    return 0;
}