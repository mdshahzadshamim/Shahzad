#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
int main()
{
    system("cls");

    int i,j,c=10,a[5][5],s=0;
    
    for(i=0;i<5;i++)
    for(j=0;j<5;j++)
    {
        a[i][j]=c;
        c++;
    }
    
    for(i=0;i<5;i++)
    for(j=0;j<5;j++)
    {
        if(a[i][j]>s)
        s=a[i][j];
    }

    printf("\n\n%d\n\n",s);

    return 0;
}