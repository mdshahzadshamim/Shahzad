#include<stdio.h>
#include<stdlib.h>
int main()
{
    system("cls");
    
    int n,i,j,k;
    printf("n = ");
    scanf("%d",&n);

    for(i=n;i>0;i--)
    {
        for(j=0;j<i;j++)
        {
            printf("%c",65+j%26);
        }
        for(j=0;j<1+(2*(n-i-1));j++)
        {
            if(i==n)
            continue;
            printf(" ");
        }
        for(j=i-1;j>=0;j--)
        {
            if(i==n&&j==i-1)
            continue;
            printf("%c",65+j%26);
        }
        printf("\n");
    }

    return 0;
}