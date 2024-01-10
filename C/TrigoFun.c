#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<math.h>

int main()
{
    system("cls");

    float i;
    printf("i = ");
    scanf("%f",&i);
    printf("Sin(%f) : %f\n",i,sin(i));
    printf("Cos(%f) : %f\n",i,cos(i));
    printf("Tan(%f) : %f\n",i,tan(i));
    
    return 0;
}
