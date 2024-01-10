#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

/* T E S T */

int main()
{
    system("cls");\

    int a[10],b[10];
    for(int i=0;i<10;i++)
    a[i]=i;
    
    for(int i=0;i<10;i++)
    printf("%d ",a[i]);

    for(int i=9,j=0;i>=0,j<10;i--,j++)
    b[j]=a[i];
    
    printf("\n");

    for(int i=0;i<10;i++)
    printf("%d ",b[i]);

    return 0;
}
