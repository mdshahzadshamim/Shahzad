#include<stdio.h>
#define N 5
#define B 4
int shift(int n, int *a)
{
    int temp=a[0];
	for(int i=0; i<n-1; i++)
	a[i]=a[i+1];
    a[n-1]=temp;
}
//Circular Shift Array to Left
int main()
{
    int sum=0,a[N],direction;
    for(int i=0;i<N;i++)a[i]=sum++;
    printf("\n");for(int i=0;i<N;i++)printf("%d ",a[i]);printf("\n");
    printf("\nHow many places to shift to left? . . . ");int place;scanf("%d",&place);
    
    for(int p=0;p<place;p++)
    {
        /*int temp=a[0];
        for(int i=0;i<N-1;i++)
        {
            a[i]=a[i+1];
        }
        a[N-1]=temp;*/
        shift(N,a);
    }

    printf("\n");for(int i=0;i<N;i++)printf("%d ",a[i]);printf("\n");

    int sum1=10,b[B][N];for(int i=0;i<B;i++)for(int j=0;j<N;j++){b[i][j]=sum1++;}
    printf("\n");for(int i=0;i<B;i++){for(int j=0;j<N;j++)printf("%d ",b[i][j]);printf("\n");}

    for(int r=0;r<N;r++)for(int p=0;p<place;p++)shift(N,&b[r][0]);
    printf("\n");for(int i=0;i<B;i++){for(int j=0;j<N;j++)printf("%d ",b[i][j]);printf("\n");}

    return 0;
}