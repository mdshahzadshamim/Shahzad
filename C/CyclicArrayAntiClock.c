#include<stdio.h>
int main()
{
    int n,sum=10;
    printf("\nEnter size of array : ");scanf("%d",&n);printf("\n");int a[n][n];
    for(int i=0;i<n;i++)for(int j=0;j<n;j++)a[i][j]=sum++;
    for(int i=0;i<n;i++){for(int j=0;j<n;j++)printf("%d ",a[i][j]);printf("\n");}

    for(int rep=0;rep<(n/2);rep++)
    {
        int k=n-(2*rep);
        int temp[n];
        
        for(int i=rep;i<rep+k-1;i++)
        {
            //Step 0 : Temp[Array] ← 1st Row
            temp[i]=a[rep][i];
            //Step 1 : 1st Row ← Last Column
            a[rep][i]=a[i][n-rep-1];
            //Step 2 : Last Column ← Last Row
            a[i][n-rep-1]=a[n-rep-1][n-1-i];
            //Step 3 : Last Row ← 1st Column
            a[n-rep-1][n-1-i]=a[n-1-i][rep];
            //Step 4 : 1st Column ← Temp[Array]
            a[n-1-i][rep]=temp[i];
        }     
        
        // n-rep-1 & rep+k-1 give the same value

    }

    printf("\n");for(int i=0;i<n;i++){for(int j=0;j<n;j++)printf("%d ",a[i][j]);printf("\n");}
    
    return 0;
}