#include<stdio.h>
#define A 2
#define N 3
#define B 4
//Multiply Two Square Matrices
//Note that to multiply two matrices AxB & CxD
//Condition : B=C
//The output matrixis of size : AxD
int main()
{
    int a[A][N],b[N][B],sum1=1,sum2=2,c[A][B];
    for(int i=0;i<A;i++)for(int j=0;j<N;j++)a[i][j]=sum1++;
    for(int i=0;i<N;i++)for(int j=0;j<B;j++)b[i][j]=sum2++;

    for(int i=0;i<A;i++)for(int j=0;j<B;j++)
    {
        int sum=0;
        for(int k=0;k<N;k++)
        sum += a[i][k]*b[k][j];
        c[i][j]=sum;
    }

    printf("\n");for(int i=0;i<A;i++){for(int j=0;j<N;j++)printf("%d ",a[i][j]);printf("\n");}
    printf("\n");for(int i=0;i<N;i++){for(int j=0;j<B;j++)printf("%d ",b[i][j]);printf("\n");}
    printf("\n");for(int i=0;i<A;i++){for(int j=0;j<B;j++)printf("%d ",c[i][j]);printf("\n");}

    return 0;
}