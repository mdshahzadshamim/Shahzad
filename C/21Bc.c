#include<stdio.h>
#define BV(x) (1<<x)
#include "showbits16.h"
int checkbits(int x, int p, int n);
int main()
{
    int x, p, n;
    printf("\nEnter Number: ");         scanf("%d", &x);
    printf("\nStarting Position: ");    scanf("%d", &p);
    printf("\nNo. of Positions: ");     scanf("%d", &n);

    printf("\n");
    showbits16(x);
    printf("\n\nOutput: %d\n", checkbits(x,p,n));
    return 0;
}
int checkbits(int x, int p, int n)
{
    int count = 0;
    for(int i = p; i > p-n; i--)
    {
        if(x & BV(i)) count++;
    }
    if(n == count) return (1);
    else return (0);
}