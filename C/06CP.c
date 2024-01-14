#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<math.h>
int pct(int i)
{
    int x,y;
    int arr[i][(2*i)-1];
    for(x=0;x<i;x++)
    {
        for(y=0;y<(2*i)-1;y++)
        {
            if(x==0 && y!=i)
            arr[x][y]=0;
            else if(x==0 && y==i)
            arr[x][y]=1;
            else
            arr[x][y]=(y==0?0:arr[x-1][y-1])+(y==0?0:arr[x-1][y+1]);
        }
    }
    for(x=0;x<i;x++)
    {
        for(y=0;y<(2*i)-1;y++)
        {
            if(arr[x][y]==0)
            printf(" ");
            else
            printf("%d",arr[x][y]);
        }
        printf("\n");
    }
}

int main()
{
    system("cls");

    int i;
    printf("i = ");
    scanf("%d",&i);
    printf("%d\n",i);
    pct(i);
    
    return 0;
}
