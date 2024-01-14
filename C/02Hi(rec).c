#include<stdio.h>
#include<stdlib.h>
int rem(int i, int k)
{
    if(k>=1)
    {
        int q = i/k;
        if(q>0) printf("%d notes : %d\n",k,q);
        rem(i%k,(k==50?10:k/2));
    }
}

int main()
{
    system("cls");

    int i;
    printf("Amount = ");
    scanf("%d",&i);
    rem(i,100);
    
    return 0;
}

