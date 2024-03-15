#include<bits/stdc++.h>
#include<pqxx/pqxx>
using namespace std;
void quickSort(int a[], int low, int high);
int partitionIndex(int a[], int low, int high);
int main()
{
    int a[] = {8,7,6,5,4,3,2,1};
    quickSort(a, 0, 7);

    for(int i = 0; i < 8; i++)
    cout << a[i] << ' ';

    return 0;
}
void quickSort(int a[], int low, int high)
{
    if(low < high)
    {
        int p = partitionIndex(a, low, high);
        quickSort(a, low, p-1);
        quickSort(a, p+1, high);
    }
}
int partitionIndex(int a[], int low, int high)
{
    int pivot = a[low];
    int i = low, j = high;
    while(i < j)
    {
        while(a[i] <= pivot && i <= high - 1)
        {
            i++;
        }
        while(a[j] > pivot && j >= low + 1)
        {
            j--;
        }
        if(i < j)
        swap(a[i], a[j]);
    }
    swap(a[low],a[j]);
    return j;
}