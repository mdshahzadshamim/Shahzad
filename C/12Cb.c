#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<math.h>
#define LC(x) (x>96 && x<123)
#define UC(x) (x>64 && x<91)
#define ALPHA(x) ((LC(x)) || (UC(x)))
#define BIG(x,y) (x>y)

/* T E S T */

int main()
{
    system("cls");
    printf("Started\n");
    do
    {
        fflush(stdin);
        int i,j;
        char k;
        printf("\nEnter an alphabet, k = ");
        scanf("%c",&k);
        //printf("\n");
        if(LC(k))
        printf("Lower Case");
        else if(UC(k))
        printf("Upper Case");

        if(ALPHA(k))
        printf(" Alphabet\n");
        else
        printf("Not An Alphabet\n");

        printf("Enter a number, i = "); scanf("%d",&i);
        printf("Enter another number, j = "); scanf("%d",&j);
        if(BIG(i,j))
        printf("i is greater\n");
        else if(!BIG(j,i))
        printf("i and j are equal\n");
        else
        printf("j is greater\n"); 
        
        if (getchar() != '\n')
        {fflush(stdin); printf("\nTerminated"); exit(1);}
    }while(1);
    
    return 0;
}
