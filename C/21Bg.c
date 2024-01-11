#include<stdio.h>
#include"showbits.h"
#define BV(x) (1<<x)
int main()
{
    printf("\nEnter the number: ");
    char num, n1; scanf("%d", &num);
    n1 = num;
    showbits(num); printf("\n");
    for(int i = 0; i < 8; i++)
    {
        if(i%2 == 1)
        n1 |= (num | BV(i));
    }
    num = n1;
    showbits(num); printf("\n");
    return 0;
}