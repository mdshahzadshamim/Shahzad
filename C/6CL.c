#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<math.h>

int main()
{
    system("cls");

    int lim;
    printf("Limit = ");
    scanf("%d",&lim);
    printf("\n");
    int i,j,k,l,m,n,a[lim+1][lim+1],count=0;

    for(i=0;i<=lim;i++)
    {
        for(j=0;j<=lim;j++)
        {
            a[i][j] = pow(i,3) + pow(j,3);
        }
    }

    for(k=0;k<=lim;k++)
    {
        for(l=0;l<=lim;l++)
        {
            for(m=0;m<=lim;m++)
            {
                for(n=0;n<=lim;n++)
                {
                    if(k<l && m<n && k<m && l>n)
                    if(k!=m && k!=n && l!=m && l!=n)
                    if(a[k][l]==a[m][n])
                    {
                        printf("%d + %d = %d + %d = %d\n",a[k][0],a[0][l],a[m][0],a[0][n],a[k][l]);
                        count += 1;
                    }
                }
            }
        }
    }
    printf("\nCount = %d\n",count);
    return 0;
}
