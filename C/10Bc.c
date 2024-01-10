#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<math.h>

/* F I B O N A C C I */

int funr(int i, int k, int a, int b)
{
    if(i > k)
    return 0;
    else
    {
        if(i==1 || i==2)
        printf("%d ",1);
        else
        {
            int t=a+b;
            a=b; b=t;
            printf("%d ",b);
        }
        i += 1;
        funr(i,k,a,b);
    }
    
    
}

int funn(int k)
{
    int a=1,b=1;
    for(int i=1;i<=k;i++)
    {
        //printf("%d %d %d\n",i,a,b);
        if(i==1 || i==2)
        printf("%d ",1);
        else
        {
            int t=a+b;
            a=b;
            b=t;
            printf("%d ",b);
        }
    }
}

int main()
{
    system("cls");

    int k;
    printf("A value b/n 1 to 46, k = ");
    scanf("%d",&k);
    printf("\n");
    if(k<1 || k>46)
    {
        printf("unexpected value entered . . .\n");
        exit(1);
    }

    printf("Recursive call : "); funr(1,k,1,1); printf("\n");
    printf("Non-recursive call : "); funn(k); printf("\n");

    return 0;
}
