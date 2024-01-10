#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<math.h>

int funr(int i, int sum)
{
    //Recursive function
    if(i < 10 && i > (-10))
    {sum += i; /*printf("end case %d %d\n",i,sum)*/; return sum;}
    else
    {sum += (i%10); /*printf("normal case %d %d\n",i,sum)*/; return (funr((i/10), sum)); }
}

int funn(int i, int sum)
{
    //Non-recursive function
    for(int j=0;;j++)
    {
        if(i<10 && i>(-10))
        {sum += i; break;}
        else
        {sum += (i%10); i = (i/10);}
    }
    return sum;
}

int main()
{
    system("cls");

    int i,sum=0;
    printf("i = "); scanf("%d",&i); printf("\n");
    printf("Recursive call sum returned = %d\n",funr(i,sum));
    printf("Non-recursive call sum returned = %d",funn(i,sum));
    
    return 0;
}