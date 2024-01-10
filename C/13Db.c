#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<math.h>

/* S O R T I N G */
int swap(int *a, int *b)
{
    int t=*a;
    *a=*b;
    *b=t;
}

int selection(int *a, int size)
{
    if(size==1);
    else
    {
        int i,j,k=a[0];
        for(i=1;i<size;i++)
        {
            if(a[i]<k)
            swap(&a[0],&a[i]);
            k=a[0];
            /*for(int t=0;t<5;t++)
            printf("%d ",a[t]);printf("\n");*/
        }
        selection(&a[(size-(size-1))],size-1);
    }
    

}

int bubble(int *a, int size)
{
    if(size>1)
    {
        int i=0;
        while(i<size-1)
        {
            if(a[i]>a[i+1])
            swap(&a[i],&a[i+1]);
            i++;
            /*for(int t=0;t<5;t++)
            printf("%d ",a[t]);printf("\n");*/
        }
        bubble(a,size-1);
    }
}

int insertion(int *a, int size)
{
    int i,j,key;
    for(j=1;j<size;j++)
    for(i=0;i<j;i++)
    {
        if(a[j]<a[i])
        swap(&a[j],&a[i]);
        /*for(int t=0;t<5;t++)
        printf("%d ",a[t]);printf("\n");*/
    }
}

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
        
        int a[k];
        printf("\nEnter the %d elements : ",k);
        for(int i=0;i<k;i++)
        scanf("%d",&a[i]);
        
        //int a[]={4,3,5,2,1};
        char sort;
        printf("\nEnter - selection(s), bubble(b), insertion(i) : ");fflush(stdin);
        scanf("%c",&sort);
        if(!(sort=='s' ||sort=='b' ||sort=='i'))
        {
            printf("\nInvalid Input"); continue;
        }

        switch (sort)
        {
            case 's':
                selection(a,k);
                break;
            case 'b':
                bubble(a,k);
                break;
            case 'i':
                insertion(a,k);
                break;
        }

        printf("\n");
        for(int i=0;i<k;i++)
        printf("%d ",a[i]);
    

        if (getchar() != '\n')
        {fflush(stdin); printf("\n\nLoop terminated"); exit(1);}
    }while(1);
    
    return 0;
}