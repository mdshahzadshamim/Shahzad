#include<stdio.h>
float show1(int a, int b)
{printf("\nIn The Function1 : %f",(float)a/b);return((float)a/b);}
float show2(int a, int b)
{printf("\nIn The Function2 : %f",(float)a/b);return((float)a/b);}
float show3(int a, int b)
{printf("\nIn The Function3 : %f",(float)a/b);return((float)a/b);}
float show4(int a, int b)
{printf("\nIn The Function4 : %f",(float)a/b);return((float)a/b);}
int main()
{
    float (*s[4])(int, int);
    s[0] = show1;
    s[1] = show2;
    s[2] = show3;
    s[3] = show4;
    
    int b = 4; float sum = 0;
    for(int i = 0; i < 4; i++)
    sum += s[i](i, b);
    printf("\nSum : %f\n",sum);

    // s = show;
    // (*s)();
    // s();
    return 0;
}