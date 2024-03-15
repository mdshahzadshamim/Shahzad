#include<iostream>
using namespace std;
#define size 3

struct matrix
{
    int data[size][size];
};

matrix setmatrix (int a);
void printmatrix (matrix a);
matrix operator + (matrix a, matrix b);

int main()
{
    matrix a, b, c;
    a = setmatrix(10);
    b = setmatrix(15);

    c = a + b;

    cout << endl;
    printmatrix(a);
    printmatrix(b);
    printmatrix(c);

    return 0;
}

matrix setmatrix (int k)
{
    matrix temp;
    for(int i = 0; i < size; i++)
    for(int j = 0; j < size; j++)
    {
        temp.data[i][j] = k;
        k++;
    }
    return temp;
}
void printmatrix (matrix a)
{
    for(int i = 0; i < size; i++)
    {
        for(int j = 0; j < size; j++)
        cout << a.data[i][j] << '\t';
        cout << '\n';
    }
    cout << '\n';
}
matrix operator + (matrix a, matrix b)
{
    matrix temp;
    for(int i = 0; i < size; i++)
    for(int j = 0; j < size; j++)
    temp.data[i][j] = a.data[i][j] + b.data[i][j];
    return temp;
}