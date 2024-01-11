//Sports Champion : 9-bit Manipulation
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include"showbits.h"
#define BV(x) (1<<x)

// #define cricket BV(0)
// #define basketball BV(1)
// #define football BV(2)
// #define hockey BV(3)
// #define lawn_tennis BV(4)
// #define table_tennis BV(5)
// #define carrom BV(6)
// #define chess BV(7)

int main()
{
    short unsigned int game;
    printf("\nEnter Score Code: ");
    scanf("%u", &game);
    showbits(game);printf("\n");
    int sum = 0;
    for(int i = 0; i < 8; i++)
    if(game & BV(i)) sum++;
    if(sum >= 5) printf("Champion\n");
    else printf("Looser\n");
    return 0;
}