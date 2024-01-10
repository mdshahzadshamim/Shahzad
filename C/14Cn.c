#include<stdio.h>
#include<math.h>
int main()
{
    float a[6][3] = {
                       {137.4,80.9,0.78},
                       {155.2,92.62,0.89},
                       {149.3,97.93,1.35},
                       {160.0,100.25,9.00},
                       {155.6,68.95,1.25},
                       {149.7,120.0,1.75}
                    };
    float area[6][2]; int largest;
    for(int i = 0; i < 6; i++)
    {
        area[i][0] = sin(a[i][2]);
        area[i][1] = 0.5 * a[i][0] * a[i][1] * sin(area[i][0]);
        if(i==0) largest=i;
        else
        if(area[i]>area[largest])
        largest=i;
    }

    //Printing Values
    printf("\n"); for(int i = 0; i < 6; i++) printf("%f\t%f\t%f\t%f\t%f\n", a[i][0], a[i][1], a[i][2], area[i][0], area[i][1]);
    printf("\nLargest Plot : %dth, %f units\n",largest,area[largest][1]);

    return 0;
}

//{{137.4,155.2,149.3,160.0,155.6,149.7},{80.9,92.62,97.93,100.25,68.95,120.0},{0.78,0.89,1.35,9.00,1.25,1.75}};
//{{137.4,80.9,0.78}, {155.2,92.62,0.89}, {149.3,97.93,1.35}, {160.0,100.25,9.00}, {155.6,68.95,1.25}, {149.7,120.0,1.75}};