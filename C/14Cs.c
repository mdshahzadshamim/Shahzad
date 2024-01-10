#include<stdio.h>
#include<stdlib.h>
//Check Sudoku
#define N 9
int sumrow = 0;
int sumcol = 0;
int a[N][N] = {
                {5,3,4,6,7,8,9,1,2},
                {6,7,2,1,9,5,3,4,8},
                {1,9,8,3,4,2,5,6,7},
                {8,5,9,7,6,1,4,2,3},
                {4,2,6,8,5,3,7,9,1},
                {7,1,3,9,2,4,8,5,6},
                {9,6,1,5,3,7,2,8,4},
                {2,8,7,4,1,9,6,3,5},
                {3,4,5,2,8,6,1,7,9}
              };
int row(int rowno);
int column(int colno);
int matrix3(int rowno, int colno);

int main()//Main Function
{
    system("cls");

    int sumrow = 0, sumcol = 0, summatrix3 = 0;
    for(int i = 0; i < N; i++)
    {
        sumrow += row(i);
        sumcol += column(i);         
    }
    for(int i = 0; i < N; i = i+3) for(int j = 0; j < N; j = j+3)
    summatrix3 += matrix3(i,j);

    if(sumrow > N || sumcol > N || summatrix3 > N)
    printf("\n\nIncorrect Solution\n\n");
    else if(sumrow == N && sumcol == N && summatrix3 == N)
    printf("\n\nCorrect Solution\n\n");
    else if(sumrow < N || sumcol < N || summatrix3 < N)
    printf("\n\nError Solution\n\n");
    else
    printf("\n\nError\n\n");

    //printf("R : %d\tC : %d\tM :%d\t\n\n",sumrow,sumcol,summatrix3);

    return 0;
}

int row(int rowno)
{
    //code
    int count[N] = {0,0,0,0,0,0,0,0,0};
    for(int j = 0; j < N; j++)
    {
        for(int c = 0; c < N; c++) if(a[rowno][j] == c+1) {count[c] += 1; if(count[c] > 1) count[c] = 1;}
    }
    int total = 0; for(int t = 0; t < N; t++) total += count[t];
    //printf("%d\t", total);
    if(total > N) return (0); else if(total == N) return (1); else if(total < N) return (-1);
    /*for(int j = 0; j < N; j++)
    {
        if(a[rowno][j])
    }*/
}
int column(int colno)
{
    //code
    int count[N] = {0,0,0,0,0,0,0,0,0};
    for(int i = 0; i < N; i++)
    {
        for(int c = 0; c < N; c++) if(a[i][colno] == c+1) {count[c] += 1; if(count[c] > 1) count[c] = 1;}
    }
    int total = 0; for(int t = 0; t < N; t++) total += count[t];
    //printf("%d\t", total);
    if(total > N) return (0); else if(total == N) return (1); else if(total < N) return (-1);
    /*for(int i = 0; i < N; i++)
    {
        if(a[i][colno])
    }*/
}
int matrix3(int rowno, int colno)
{
    //code
    int count[N] = {0,0,0,0,0,0,0,0,0};
    for(int i = rowno; i < rowno + 3; i++)for(int j = colno; j < colno + 3; j++)
    {
        for(int c = 0; c < N; c++) if(a[i][j] == c+1) {count[c] += 1; if(count[c] > 1) count[c] = 1;}
    }
    int total = 0; for(int t = 0; t < N; t++) total += count[t];
    //printf("%d\t", total);
    if(total > N) return (0); else if(total == N) return (1); else if(total < N) return (-1);
    /*for(int i = rowno; i < rowno + 3; i++)for(int i = colno; i < colno + 3; i++)
    {
        if(a[i][j])
    }*/
}