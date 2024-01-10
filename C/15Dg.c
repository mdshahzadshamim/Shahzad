#include<stdio.h>
#include<string.h>
#include<math.h>
int main()
{
    char a[16]; gets(a);
    int b[16],sum1=0,sum2=0;
    for(int i=14; i>=0; i=i-2)
    {
        int temp = 0;
        temp = 2 * (a[i]-'0');
        if(temp>=10) temp -= 9;
        sum1 += temp;
        //printf("%d ",temp);
    }
    //printf("\nsum1 : %d\n",sum1);
    for(int i=15; i>=0; i=i-2)
    {
        sum2 += a[i]-'0';
    }
    //printf("sum2 : %d\n",sum2);
    if((sum1+sum2)%10 == 0)
    printf("Correct Credit Card Number");
    else
    printf("Inorrect Credit Card Number");

    return 0;
}