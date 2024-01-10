#include<stdio.h>
int main()
{
    int t; scanf("%d",&t);
    for(int tc = 0; tc < t; tc++)
    {
        int m, k; scanf("%d %d",&m,&k);

        long *a;
        a = (long *)malloc(m*sizeof(long));

        long *b;
        b = (long *)malloc(m*sizeof(long));
        
        int n = m;
        for(int i = 0; i < m; i++) scanf("%ld",&b[i]);

        for(int i = 0, j = 0; i < m; i++)
        if(b[i] > 0)
        {
            a[j] = b[i];
            j++;
            n = j;
        }

        long *unique;
        unique = (long *)malloc(n*sizeof(long));

        int *count;
        count = (long *)malloc(n*sizeof(long));

        int u = n;//unique values
        for(int i = 0; i < n; i++)
        {
            unique[i] = 0;
            for(int j = 0; j < n; j++) if(a[j] > 0) unique[i] = a[j];

            count[i] = 0;
            for(int j = 0; j < n; j++)
            if(a[j] == unique[i])
            {
                count[i] += 1;;
                a[j] = 0;
            }
            
            if(unique[i] == 0)
            {
                u = i;
                break;
            }
        }

        long *p;
        p = (long *)malloc(u*sizeof(long));

        for(int i = 0; i < u; i++) p[i] = unique[i] * count[i];

        long sum = 0;
        for(int i = 0; i < k; i++)
        {
            long pmax = 0; int temp = 0;
            for(int j = 0; j < u; j++)
            if(p[j] > pmax)
            {
                pmax = p[j];
                temp = j;
            }
            sum += pmax;
            p[temp] = 0;
        }

        printf("%ld\n",sum);
    }
    return 0;
}