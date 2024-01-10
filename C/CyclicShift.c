#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int *shift(int n, int a[])
{
	int i=0,k=a[0];
	for(i=0; i<n; i++)
	a[i]=a[i+1];
    a[n]=k;
    return a;
}
int value(int n, int a[])
{
    int i=0,v=0;
    for(i=n-1; i>=0; i--)
    v = v + (a[i] * pow(2,n-i));
    return v;
}
int main()
{
	int t,i;
	scanf("%d",&t);printf("%d",t);
	for(i=0; i<t; i++)
	{
        int count=0,eqcount=0;
		int n,k,j;
        char a[100001],b[100001],c[100001];
		scanf("%d",&n);printf("%d",n);
		scanf("%d",&k);printf("%d",k);
        for(j=0; j<n; j++)
		{
            scanf("%c",&a[j]);
            b[j]=a[j];
            c[j]=b[j];
		}
        /*int p,q;
        for(p=0; p<n; p++)
        {
            count+=1;
            if(value(n,a) < value(n,shift(n,a)))
            {
                for(q=0; q<n; q++)
                b[q]=a[q];
            }
        }
        int r,s;
        while(k==0)
        {
            eqcount+=1;
            if(value(n,shift(n,a)) == value(n,b) )
            k--;
        }

        printf("%d\n",eqcount);*/

	}
	return 0;
}