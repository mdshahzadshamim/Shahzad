#include<stdio.h>
#include<math.h>
float distance(float x1, float y1, float x2, float y2);
int main()
{
    float a[10][2] = {
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

    float b[9], sum = 0.0;
    for(int i = 0; i < 9; i++)
    {
        b[i]=distance(a[i][0], a[i][1], a[i+1][0], a[i+1][1]);
        sum += b[i];
        //sum += distance(a[i][0], a[i][1], a[i+1][0], a[i+1][1]);
        //printf("\n %f \n", sum);
    }
    printf("\n\nTotal Distance = %f\n\n",sum);
    
    return 0;
}
float distance(float x1, float y1, float x2, float y2)
{
    //printf("%f",sqrt(pow(y2 - y1, 2) + pow(x2 - x2, 2)));
    return(sqrt(pow(y2 - y1, 2) + pow(x2 - x1, 2)));
}