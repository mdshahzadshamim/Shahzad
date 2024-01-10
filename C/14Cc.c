#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
//Transpose of Matrix
int main()
{
    system("cls");

    int i,j,c=10,a[5][5],s=1;
    
    for(i=0;i<5;i++)
    for(j=0;j<5;j++)
    {
        a[i][j]=c;
        c++;
    }

    for(i=0;i<5;i++)
    {for(j=0;j<5;j++)
    {printf("%d ",a[i][j]);}printf("\n");}
    
    printf("\n");
    
    for(i=0;i<4;i++)
    {
        for(j=s;j<5;j++)
        {
            int t = a[i][j];
            a[i][j] = a[j][i];
            a[j][i] = t;
        }
        s++;
    }

    for(i=0;i<5;i++)
    {for(j=0;j<5;j++)
    {printf("%d ",a[i][j]);}printf("\n");}
    
    for(i=0;i<5;i++)
    

    return 0;
}