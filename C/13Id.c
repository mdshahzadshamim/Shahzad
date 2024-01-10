#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

int modify(int *a)
{
    for(int i=0;i<10;i++)
    a[i]=a[i]*5;
}


int main()
{
    system("cls");

    /*int k;
    printf("k = ");
    scanf("%d",&k);
    printf("\n");*/

    int a[10];
    for(int i=0;i<10;i++)
    a[i]=i+1;

    modify(a);

    for(int i=0;i<10;i++)
    printf("%d ",a[i]);

    return 0;
}
