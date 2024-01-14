#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<math.h>

int main()
{
    system("cls");

    int i,j,l,k;

    printf("Limit = ");
    scanf("%d",&l);
    printf("\n");

    float rcount=1,count=0;

    for(i=1;i<=l;i++)
    {
        k=l-rcount;//printf("k=%d",k);
        for(j=1;j<=k;j++)
        {
            if(count==0)
            printf(" ");
        }
        printf("%d ",i);
        count+=1;

        //printf("count %d rcount %d\n",count,rcount);

        if(rcount==count)
        {
            printf("\n");
            count=0;rcount+=1;
        }

        //printf("count %d rcount %d\n",count,rcount);

        
    }

    return 0;
}
