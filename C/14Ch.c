#include<stdio.h>
//Square Matrix or not
int main()
{
    int n=4,sum=10,check1=0,check2=0;
    int a[n][n],b[n][n];
    for(int i=0;i<n;i++)for(int j=0;j<n;j++){a[i][j]=sum++;b[i][j]=5;}
    for(int i=0;i<n;i++)for(int j=n-i-1;j<n;j++)
    {
        if(a[i][j] != a[j][i]) check1++;
        if(b[i][j] != b[j][i]) check2++;       
    }
    for(int i=0;i<n;i++){for(int j=0;j<n;j++){printf("%d ",a[i][j]);}printf("\n");}
    if(check1>0)printf("Matrix is Not Symmetric\n\n");else printf("Matrix is Symmetric\n\n");
    for(int i=0;i<n;i++){for(int j=0;j<n;j++){printf("%d ",b[i][j]);}printf("\n");}
    if(check2>0)printf("Matrix is Not Symmetric\n");else printf("Matrix is Symmetric\n");
    
    return 0;
}