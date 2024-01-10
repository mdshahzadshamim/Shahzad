#include<stdio.h>
#include<math.h>
int main()
{
    float a[11][2] = {
                        {34.22,102.43},
                        {39.87,100.93},
                        {41.85,97.43},
                        {43.23,97.81},
                        {40.06,98.32},
                        {53.29,98.32},
                        {53.29,100.07},
                        {54.14,97.08},
                        {49.12,91.59},
                        {40.71,94.85},
                        {55.15,94.65}
                    };
    
    float sumx = 0, sumy = 0, sumx2 = 0, sumy2 = 0, sumxy = 0;
    for(int i = 0; i < 11; i++)
    {
        sumx += a[i][0];
        sumy += a[i][1];
        sumx2 += pow(a[i][0],2);
        sumy2 += pow(a[i][1],2);//printf("%f\t%f\n",pow(a[i][1],2),sumy2);
        sumxy += a[i][0]*a[i][1];
    }

    float correlation = (sumxy-(sumx*sumy))/sqrt(((11 * sumx2) - pow(sumx, 2))* ((11 * sumy2) - pow(sumy, 2)));
    printf("\nCorrelation coefficient\t=\t%f\n",correlation);
    //printf("%f\t%f\t%f\t%f\t%f",sumx,sumy,sumx2,sumy2,sumxy);
    //Note that to make more accurate calculations use high storage date, eg. double instead of float
    
    return 0;
}