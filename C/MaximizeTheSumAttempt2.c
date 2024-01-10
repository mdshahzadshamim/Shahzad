#include<stdio.h>
#include<stdlib.h>

typedef struct array
{
    long element;
    int count;
    long product;
}e;

int main()
{
    int tc;
    scanf("%d",tc);
    for(int t = 0; t < tc; t++)
    {
        int m, k; scanf("%d %d",&m,&k);

        e *a;
        int size = sizeof(e);
        a = malloc(size * m);
        
        for(int i = 0; i < m; i++)
        {
            scanf("%ld",&a[i].element);//scan array
            if(a[i].element < 0)
            a[i].element = 0;//negative nos removed
        }
        for(int i = 0; i < m; i++)
        {
            a[i].count = 0;
            for(int j = i; j < m; j++)
            if(a[i].element == a[j].element)
            {
                a[i].count += 1;
                a[j].element = 0;
                a[j].count = 0;
            }
        }
        for(int i = 0; i < m; i++)
        a[i].product = a[i].element * a[i].count;

        long sum = 0;
        for(int i = 0; i < k; i++)
        {
            long greatest = a[0].product;
            int n = 0;
            for(int j = 0; j < m; j++)
            if(a[j].product > greatest)
            {
                greatest = a[j].product;
                n = j;
            }

            sum += greatest;
            a[n].product = 0;
        }
        printf("%ld\n", sum);
    }
    //compare the element with previous unique elements
    //if present then leave if absent compare it to the array elements to find count
    //when all counting is done, multiply the size with element and store it in the product dimension
    //at last find the atmost k largest elements from the product and add them
    return 0;
}