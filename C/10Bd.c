#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<math.h>

/* B I N A R Y      E Q U I V A L E N T */

int funr( int k)
{
    if(k>0)
    {
        funr(k/2);
        printf("%d ",k%2);
    }
}

int funn(int k)
{
    int a[100]; int i=0;
    while(k>0)
    {
        a[99-i]=k%2;
        i += 1;
        k = k/2;
    }
    for(int b=100-i;b<100;b++)
    {
        printf("%d ",a[b]);
    }
}

int main()
{
    system("cls");

    int k; 
    char again='y';

    while(again=='y')
    {
        printf("k = ");
        scanf("%d",&k);
        printf("\n");

        printf("Recursive call : "); funr(k); printf("\n");
        printf("Non-recursive call : "); funn(k); 

        printf("\n\nAgain? . . . "); fflush(stdin); scanf("%c",&again); 
        printf("\n");
    }

    return 0;
}
