#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<math.h>
/* PRIME NUMBERS - SIEVE OF ERATOSTHENES */

int main()
{
    system("cls");
    printf("Initiating . . .\n");
    
    do
    {
        fflush(stdin);
        
        int k;
        printf("\nk = ");
        scanf("%d",&k);

        float s=sqrt(k);
        int a[k],i,j,t,count=0;
        int ct = ((int)(s)) + 1;
        //printf("%d ",ct);

        for(i=0;i<k;i++)
        a[i]=i+1;
        a[0]=0;//1 is not a prime number
        
        for(i=1;i<ct;i++)
        {
            if(a[i]!=0)
            {
                for(j=i+1;j<k;j++)
                {
                    if((a[j]%a[i])==0)
                    a[j]=0;
                }
            }
        }

        printf("Prime numbers within %d : ",k);
        
        for(t=0;t<k;t++)
        {
            if(a[t]!=0)
            {
                count++;
                printf("%d ",a[t]);
            }
        }
        
        printf("\nCount : %d\n",count);
    

        if (getchar() != '\n')
        {fflush(stdin); printf("\nLoop terminated"); exit(1);}
    }while(1);
    
    return 0;
}