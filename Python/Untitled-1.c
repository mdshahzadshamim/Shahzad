#include<stdio.h>
int main()
{
	int t,n,k,a[1000000],b[1000000],frac,i,j,w,x,y,z,v;
	scanf("%d", &t);  
	for(i=0;i<t;i++)
	{
		scanf("%d", &n);scanf("%d", &k);frac=k%n;
		for(j=1;j<=n;j++)
		{
			scanf("%d", &a[j]);
		}
		
		for(w=n-frac+1,x=1;w<=n,x<=frac;w++,x++)
		{
			b[x]=a[w];
		}
		
		for(y=n-frac;y>=1;y--)
		{
			a[y+frac]=a[y];
		}
		
		for(z=1;z<=frac;z++)
		{
			a[z]=b[z];
		}
		
		for(v=1;v<=n;v++)
		{
			printf("%d ", a[v]);
		}
		printf("\n");
	}
	
	return 0;
}