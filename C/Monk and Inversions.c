/*Monk's best friend Micro, who happen to be an awesome programmer, 
got him an integer matrix M of size N x N for his birthday. Monk is 
taking coding classes from Micro. They have just completed array 
inversions and Monk was successful in writing a program to count 
the number of inversions in an array. Now, Micro has asked Monk 
to find out the number of inversion in the matrix M. Number of 
inversions, in a matrix is defined as the number of unordered 
pairs of cells {(i,j),(p,q)} such that M[i][j] > M[p][q] & i ≤ p & j ≤ q.
Monk is facing a little trouble with this task and since you 
did not got him any birthday gift, you need to help him with this task.*/
#include<stdio.h>
int main()
{
	int t,a[21][21],i,j,k,l,m,n,inv,p,q,key;
	scanf("%d",&t);
	for(i=1;i<=t;i++)
	{
		inv=0;
		scanf("%d",&n);
		for(j=1;j<=n;j++)
		{
			for(k=1;k<=n;k++)
			{
				scanf("%d",&a[j][k]);
			}
		}
		for(l=1;l<=n;l++)
		{
			for(m=1;m<=n;m++)
			{
				key=a[l][m];
				if(m<n && l<n)
				{
					for(p=l;p<=l;p++)
					{
						for(q=m;q<=n;q++)
						{
							if( (key>a[p][q]) && (l<=p) && (m<=q) )
							{
								inv=inv+1;
							}
						}
					}
					
					for(p=l+1;p<=n;p++)
					{
						for(q=1;q<=n;q++)
						{
							if( (key>a[p][q]) && (l<=p) && (m<=q) )
							{
								inv=inv+1;
							}
						}
					}
				}
				else if(m==n && l<n)
				{
					for(p=l+1;p<=n;p++)
						{
							for(q=1;q<=n;q++)
							{
								if( (key>a[p][q]) && (l<=p) && (m<=q) )
								{
									inv=inv+1;
								}
							}
						}
				}
				else if(m<n && l==n)
				{
					for(p=l;p<=l;p++)
					{
						for(q=m;q<=n;q++)
						{
							if( (key>a[p][q]) && (l<=p) && (m<=q) )
							{
								inv=inv+1;
							}
						}
					}
				}
				else if(m==n && l==n)
				;
			}
		}
		printf("%d\n",inv);
	}
	return 0;
}