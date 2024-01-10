#include<stdio.h>
#define BV(x) (1<<x)
int main()
{
    int x;
    printf("\nEnter Number: "); scanf("%d", &x);
    if((x & BV(3)) && (x & BV(6)) && (x & BV(7)))
    printf("On\n");
    else
    printf("Off\n");

    return 0;
}