#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<math.h>

/* SEARCH A NUMBER IN ARRAY AND COUNT */
/*Note - Instead of scanning each element of the array, 
I have assigned values according to the subscript.
And then searched the value entered*/

int main()
{
    system("cls");
    printf("Initiating . . .");
    
    do
    {
        fflush(stdin);
        
        int k;
        printf("\n\nArray Size = ");
        scanf("%d",&k);

        int a[k],i;
        for(i=0;i<k;i++)
        {
            if(i%2==0)
            a[i]=2;
            else if(i%3==0)
            a[i]=3;
            else if(i%5==0)
            a[i]=5;
            else if(i%7==0)
            a[i]=7;
            else if(i%11==0)
            a[i]=11;
            else
            a[i]=0;
        }

        int s, sum=0;
        printf("\nDivisible by? 2,3,5,7,11,others(0) : ");
        scanf("%d",&s);
        if(!(s==2 || s==3 || s==5 || s==7 || s==11 || s==0))
        {printf("\nInvalid Input"); continue;}

        for(i=0;i<k;i++)
        {
            if(a[i]==s)
            sum += 1;
        }

        printf("\nCount of numbers divisible by %d = %d",s,sum);


        if (getchar() != '\n')
        {fflush(stdin); printf("\n\nLoop terminated"); exit(1);}
    }while(1);
    
    return 0;
}