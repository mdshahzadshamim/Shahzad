#include<stdio.h>
#include<math.h>
int main()
{
    float ar[10][2] = {
                        {3.0,1.5},
                        {4.5,2.0},
                        {5.5,3.5},
                        {6.5,5.0},
                        {7.5,6.0},
                        {8.5,7.5},
                        {8.0,9.0},
                        {9.0,10.5},
                        {9.5,12.0},
                        {10.0,14.0}
                    };

    float x = 0.0, y = 0.0, xy = 0.0, x2 = 0.0;
    for(int i = 0; i < 10; i++)
    {
        x += ar[i][0];
        y += ar[i][1];
        xy += ar[i][0]*ar[i][1];
        x2 += ar[i][0]*ar[i][0];
    }
    float b = (10*xy-x*y)/(10*x2-x*x);
    float a = (y/10) - b*(x/10);
    printf("\n\ny = %f + %fx\n\n",a,b);
    for(int i = 0; i < 10; i++)
    {
        printf("%f\t\t%f\t%f\t%f\t\t%f\n",ar[i][1],a,b,ar[i][0],a+b*ar[i][0]);
    }
    
    return 0;
}