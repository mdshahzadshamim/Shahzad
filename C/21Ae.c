// HMS Time : 16-bit Manipulation
// This question can also be solved without using structures and unions 
#include<stdio.h>
#include"showbits.h"
#define BV(x) (1<<x)

typedef struct timeind
{
    unsigned int h, m, s;
}thmr;

typedef union timeinunion
{
    short unsigned int hms;
    unsigned char time[2];
}tu;

thmr t = {0,0,0};

thmr *tf()
{
    printf("\n");
    tu val; printf("Time: "); scanf("%u", &val.hms);
    printf("\n");
    showbits(val.time[1]); showbits(val.time[0]);
    printf("\n\n");
    int i, v = 0;
    for(i = 0; i < 5; i++)  {if(val.time[0] & BV(i)) t.s += BV(v);  v++;}   v=0;
    for(i = 5; i < 8; i++)  {if(val.time[0] & BV(i)) t.m += BV(v);  v++;}
    for(i = 0; i < 3; i++)  {if(val.time[1] & BV(i)) t.m += BV(v);  v++;}   v=0;
    for(i = 3; i < 8; i++)  {if(val.time[1] & BV(i)) t.h += BV(v);  v++;}
}

int main()
{
    tf();
    printf("H\tM\tS\n\n");
    printf("%u\t%u\t%u\n", t.h, t.m, t.s);
    return 0;
}