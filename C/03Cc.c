#include<stdio.h>
#include<stdlib.h>
/*L E A P     Y E A R*/
int main()
{
    system("cls");

    printf("To find whether the year is leap or not . . . \n\n");

    int k;
    char again='y';

    while(again=='y')
    { 
        printf("Year = "); scanf("%d",&k); printf("\n");
        if(k%100==0)
        {
            if(k%400==0)
            printf("Yes");
            else
            printf("No");
        }
        else
        {
            if(k%4==0)
            printf("Yes");
            else
            printf("No");
        }

        printf("\n\nAgain? . . . "); fflush(stdin); scanf("%c",&again); 
        printf("\n");
    }
    
    return 0;
}
