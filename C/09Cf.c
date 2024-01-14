#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<math.h>

float d(float x1, float y1, float x2, float y2)
{
    return (sqrt(pow(y2-y1,2)+pow(x2-x1,2)));
}

float ar(float x1, float y1, float x2, float y2, float x3, float y3)
{
    float s,a,b,c,area;
    a = d(x1,y1,x2,y2);
    b = d(x2,y2,x3,y3);
    c = d(x1,y1,x3,y3);
    s = (a+b+c)/2;
    area = sqrt(s*(s-a)*(s-b)*(s-c));
    printf("\n%f",area);
    return (area);
}

int main()
{
    system("cls");

    float x,y,x1,y1,x2,y2,x3,y3,a,a1,a2,a3;
    printf("x = "); scanf("%f",&x);
    printf("y = "); scanf("%f",&y);
    printf("x1 = "); scanf("%f",&x1);
    printf("y1 = "); scanf("%f",&y1);
    printf("x2 = "); scanf("%f",&x2);
    printf("y2 = "); scanf("%f",&y2);
    printf("x3 = "); scanf("%f",&x3);
    printf("y3 = "); scanf("%f",&y3);

    a = ar(x1,y1,x2,y2,x3,y3);
    a1 = ar(x,y,x2,y2,x3,y3);
    a2 = ar(x1,y1,x,y,x3,y3);
    a3 = ar(x1,y1,x2,y2,x,y);

    if(a >= a1+a2+a3-0.1 && a <= a1+a2+a3+0.1)
    printf("\n%d",1);
    else
    printf("\n%d",0);
     
    return 0;
}