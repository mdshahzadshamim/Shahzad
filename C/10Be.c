#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<math.h>

/* SUM OF NATURAL NUMBERS */

int funr( int k, int i, int sum)
{
    if(i > k)
    return sum;
    else
    {
        sum += i;
        i += 1;
        funr(k,i,sum);
    }
}

int funn(int k,int sum)
{
    for(int i=1;i<=k;i++)
    {
        sum += i;
    }
    return sum;
}

int main()
{
    system("cls");

    int k;
    printf("A value b/n 1 to 43300, k = ");
    scanf("%d",&k);
    printf("\n");
    if(k<1 || k>43300)
    {
        printf("Unexpected input\n");
        exit(1);
    }

    printf("Recursive call : "); printf("%d\n",funr(k,1,0));
    printf("Non-recursive call : "); printf("%d\n",funn(k,0));

    return 0;
}
