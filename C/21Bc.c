#include<stdio.h>
#define BV(x) (1<<x)
int checkbits(int x, int p, int n);
int main()
{
    int x, p, n;
    printf("\nEnter Number: ");         scanf("%d", &x);
    printf("\nStarting Position: ");    scanf("%d", &p);
    printf("\nNo. of Positions: ");     scanf("%d", &n);

    printf("\nOutput: %d\n", checkbits(x,p,n));
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