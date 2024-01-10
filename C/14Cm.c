//Find mean & standard deviation
//∑
#include<stdio.h>
#include<math.h>
int main()
{
    int  a[15] = {-6,-12,8,13,11,6,7,2,-6,-9,-10,11,10,9,2};
    float sum = 0,b[15];
    for(int i = 0; i < 15; i++) sum += a[i];
    float mean = sum / 15; int sum1 = 0;
    for(int i = 0; i < 15; i++)
    {
        b[i] = a[i] - mean;
        sum1 += pow(b[i], 2);
    }
    float standard_deviation = sqrt(sum1/14);printf("\n");
    for(int i = 0; i < 15; i++) printf("%d\t%f\n",a[i],b[i]);
    printf("\nMean = %f\n",mean);
    printf("\nStandard Deviation = %f\n",standard_deviation);

    return 0;
}