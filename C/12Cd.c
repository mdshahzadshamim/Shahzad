#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<math.h>
#define AM(x,y) ((x+y)/2)
#define ABS(x) (x>0?x:(x*(-1)))
#define UCTLC(x) (x+32)
#define BIG(x,y,z) (x>y && x>z)

/* T E S T */

int main()
{
    system("cls");
    printf("Initiating . . .\n");
    do
    {
        fflush(stdin);

        float i,j;
        printf("\nArithmetic Mean\nEnter a number, i = "); scanf("%f",&i);
        printf("Enter another number, j = "); scanf("%f",&j);
        printf("Arithmetic Mean of i and j = %f\n",AM(i,j));

        int k;
        printf("\nAbsolute Value\nEnter a number, k = "); scanf("%d",&k);
        printf("Absolute value of k = %d\n",ABS(k));

        char c; int utl;
        printf("\nConvert to Lower Case\nEnter an alphabet, c = ");
        fflush(stdin); scanf("%c",&c); utl=(int)(c);
        if(utl>64 && utl<91)
        printf("Lower case of %c is %c\n",c,UCTLC(utl));
        else printf("Invalid data entered\n");

        int p,q,r;
        printf("\nGreatest of three\nEnter a number, p = "); scanf("%d",&p);
        printf("Enter another number, q = "); scanf("%d",&q);
        printf("Enter another number, r = "); scanf("%d",&r);
        if(BIG(p,q,r)) printf("p is greatest\n");
        else if(BIG(q,r,p)) printf("q is greatest\n");
        else if(BIG(r,q,p)) printf("r is greatest\n");
        else printf("Invalid data entered\n");

        if (getchar() != '\n')
        {fflush(stdin); printf("\nTerminated"); exit(1);}
    }while(1);
    
    return 0;
}
