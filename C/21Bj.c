#include<stdio.h>
#define BV(x) (1<<x)
void showbits(char n);
int main()
{
    printf("\nEnter Number: "); char x; scanf("%d", &x);
    showbits(x); printf("\n");
    return 0;
}

void showbits(char n)
{
    for(int i = 7; i >= 0; i--)
    n & BV(i) ? printf("1 ") : printf("0 ");
}