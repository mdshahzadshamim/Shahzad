#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int fac(int i)
{
    if(i==1 || i == 0)
    return (1);
    else
    return (fac(i-1));
}
float fun(float x, int y, int i, float sum, int t)
{
    //printf("x=%f,y=%d,i=%d,sum=%f,t=%d\n",x,y,i,(i>t-1?0:(pow(-1,i)*pow(x,y)/fac(y))),t);
    
    if(i>t-1)
    return (0);
    else
    {
        sum += (pow(-1,i)*pow(x,y)/fac(y)) + fun(x,y+2,i+1,sum,t);
        return (sum);
    }
}
int main()
{
    system("cls");

    float x,sum=0;
    int y=1,i=0,t;

    printf("x : "); scanf("%f",&x);
    printf("t : "); scanf("%d",&t); printf("\n");

    sum = fun(x,y,i,sum,t);
    printf("\nFor x = %f, reps = %d, total sum = %f",x,t,sum);

    return 0;
}