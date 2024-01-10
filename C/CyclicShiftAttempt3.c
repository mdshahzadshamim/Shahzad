#include<stdio.h>
#include<math.h>
int value(int length, char *a)
{
    int decval = 0, temp = 0;
    while(temp<length)
    {
        if(a[temp] == '0' || a[temp] == '1')
        {
            int tempint = a[temp] - '0';
            decval += tempint * pow(2,length-temp-1);
        }
        temp++;
    }
    return(decval);
}

int main()
{
    int t,itr;scanf("%d",&t);
    for(itr=0;itr<t;itr++)
    {
        int n; long unsigned int k;scanf("%d%lu",&n,&k);
        char a[n]; scanf("%s",a);
        
        int val[n],high=0,c;
        val[0]=value(n,a);
        for(c=0;c<n-1;c++)
        {
            char temp=a[0]; int i;
            for(i=0;i<n-1;i++)
            {
                a[i]=a[i+1];
            }
            a[n-1]=temp;

            val[c+1]=value(n,a);
            if(val[c+1]>val[c])high=c+1;
        }
        
        int q=0; for(int i=0;i<n;i++) if(val[i] == val[high]) q++;

        int nov=0;int x=0,result=0;
        while(nov<k%q)
        {
            if(val[x] == val[high]) nov++;
            if(x!=n-1) x++; else if(x==n-1) x=0;
            result++; 
        }result--;

        long unsigned int output = n*(k/q)+result;
        
        printf("%lu\n",output);
    }

	return 0;
}