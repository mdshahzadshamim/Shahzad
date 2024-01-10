#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<math.h>
/*P R I M E     N U M B E R S*/

int getkey();

int funr(int i, int k)
{
    for(int j=k;;j++)
    {
        /*printf(" i=%d, j=%d ",i,j);*/
        
        if(i == j)
        { printf("%d ",j); /*printf("END");*/ break;}
        else if((i%j) == 0)
        { printf("%d ",(j)); funr((i/j),j); break;}
    }
}

int funn(int i)
{
    int k;
    for(int j=2;;j++)
    {
        /*printf(" i=%d, j=%d ",i,j);*/
        
        if(i == j)
        { printf("%d ",j); /*printf("END");*/ break; }
        else if((i%j) == 0)
        { printf("%d ",(j)); i=(i/j); j--; }
    }

}

int main()
{
    system("cls");

    int repeat = 0;
    while(repeat != 27)
    {

    printf("\n\n");/*code*/

    int i,k=2;
    printf("i = "); scanf("%d",&i); printf("\n");
    printf("Recursive call result - "); funr(i,k); printf("\n\n");
    printf("Normal call result - "); funn(i); printf("\n\n");

    fflush(stdin);
    printf("\n\nE N T E R  /  E S C . . . ");
    repeat = getkey(); printf("\n");
    }
    
    return 0;
}

int getkey()
{
    int ch;
    ch = getch();
    if(ch == 0)
    {
        ch = getch();
        return ch;
    }
    return ch;
}