#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>
//Determinant Multiplication
#define N 6
int d(int r, int c, int size, int a[][size]);
int main()
{
    system("cls");
    srand(time(NULL));
    int a[N][N];
    int sum=10;for(int i=0;i<N;i++)for(int j=0;j<N;j++)a[i][j] = 1 +  rand() % 100;
    printf("\n");for(int i=0;i<N;i++){for(int j=0;j<N;j++)printf("%d ",a[i][j]);printf("\n");}
    
    int row = 0, sumt = 0;
    for(int col = 0; col < N; col ++)
    sumt += pow(-1,col+2) * d(row,col,N,&a[0]);

    printf("\n\nDeterminant Value = %d\n\n",sumt);
    
    return 0;
}
int d(int row, int col, int size, int a[][size])
{
    if(size == 2)
    {
        /*size -= 1;
        int arr[size][size];
        for(int r = row+1, nr = 0; r < size+1, nr < size; r++, nr++)
        for(int c = 0, nc = 0; c < size+1, nc < size; c++, nc++)
        { if(c == col) { nc--; continue; } arr[nr][nc] = a[r][c]; }
        return((arr[0][0]*arr[1][1])-(arr[0][1]*arr[1][0]));*/
        return((a[0][0]*a[1][1])-(a[0][1]*a[1][0]));
    }
    else
    {
        size -= 1;
        int arr[size][size];
        for(int r = row+1, nr = 0; r < size+1, nr < size; r++, nr++) for(int c = 0, nc = 0; c < size+1, nc < size; c++, nc++)
        { if(c == col) { nc--; continue; } arr[nr][nc] = a[r][c]; }
        //printf("\n");for(int i=0;i<size ;i++){for(int j=0;j<size;j++)printf("%d ",arr[i][j]);printf("\n");}
        int sum = 0;
        for(int col = 0; col < size; col ++)
        sum += pow(-1,col+2) * d(row+1,col,size,&arr[0]);
        //if(size==N-1) printf("%d\t",sum);
    }
    //printf("\n");for(int i=0;i<size;i++){for(int j=0;j<size;j++)printf("%d ",a[i][j]);printf("\n");}
}
/*If stuck, solve another problem*/