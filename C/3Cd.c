#include<stdio.h>
#include<stdlib.h>
#include"day.h"
/*F I R S T   D A Y   O F   Y E A R*/
int main()
{
    system("cls");

    printf("To find the first day of the year . . . \n\n");

    char again='y';

    while(again=='y')
    {
        int k,c=2001;

        printf("Year = "); scanf("%d",&k); printf("\n");

        if(k-c==0) day(2);
        else
        {
            int i,l=0,nl=0; 
            for(i=(k-c<0?k:c);i<(k-c<0?c:k);i++)
            {
                if(i%100==0)
                { if(i%400==0) l+=1; else nl+=1; }
                else
                { if(i%4==0)  l+=1; else nl+=1; }
            }
            int tot=(2*l)+nl;
            int dv=( k-c<0 ? (((tot/7)+1)*7) - tot + 2 : (tot%7) + 2 );
            day( dv<=7 ? dv : dv%7 );
        }

        printf("\n\nAgain? . . . "); fflush(stdin); scanf("%c",&again); 
        printf("\n");
    }
    
    return 0;
}
