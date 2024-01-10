#include<stdio.h>
//Add Two Matrices
int main()
{
    int sum1=10,sum2=20,n=6;
    int a[n][n],b[n][n],c[n][n];
    
    for(int i=0;i<n;i++)for(int j=0;j<n;j++){a[i][j]=sum1++;b[i][j]=sum2++;c[i][j]=a[i][j]+b[i][j];}
    printf("\n");for(int i=0;i<n;i++){for(int j=0;j<n;j++)printf("%d ",a[i][j]);printf("\n");}
    printf("\n");for(int i=0;i<n;i++){for(int j=0;j<n;j++)printf("%d ",b[i][j]);printf("\n");}
    printf("\n");for(int i=0;i<n;i++){for(int j=0;j<n;j++)printf("%d ",c[i][j]);printf("\n");}

    return 0;
}