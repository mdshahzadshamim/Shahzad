# include<stdio.h>
#include<stdlib.h>
#include <conio.h>
void selection(int *, int);
void bubble(int *, int);
void insertion(int *, int);
void swap(int *,int *);
int getkey();

int main()
{
    system("cls");

    printf("\nI N I T I A T I N G . . . \n");
    //printf("\n\nEnter :\ns for selection sort\nb for bubble sort\ni for insertion sort");
    
    int repeat = 0;
    while(repeat != 27)
    {
        printf("\n\n");
        /*char k;
        printf("Select the sorting algorithm . . . ");
        scanf("%c",&k);*/
        /*code*/
        printf("Size : ");
        int n; scanf("%d",&n);
        
        if(n==0)
        {
            printf("\nLoop terminated");
            return 0;
        }

        int a[n],b[n],c[n];printf("%d elements : ",n);
        for(int s=0;s<n;s++)
        {
            scanf("%d",&a[s]);
            b[s]=a[s];
            c[s]=a[s];
        }

        //switch (k)
        //{
            //case 's':
            selection(a,n);//break;
            //case 'b':
            bubble(b,n);//break;
            //case 'i':
            insertion(c,n);//break;
        //}

        fflush(stdin);
        printf("\n\nE N T E R  /  E S C . . . ");
        repeat = getkey(); printf("\n");
    }
    return 0;
    }
/*Swap Function*/
void swap(int *a,int *b)
{
    int t;
    t=*a;
    *a=*b;
    *b=t;
}
/*Selection Sort*/
void selection(int *a, int n)
{
    int count=0;
    printf("\nSelection Sort\n\n");
    int i, j, min_elt_indx;//n=size
    /*scanf("%d",&n);int a[n];printf("%d elements : ",n);
    for(int s=0;s<n;s++)scanf("%d",&a[s]);*/

    // One by one move boundary of unsorted subarray
    for (i = 0; i < n-1; i++)
    {
        // Find the minimum element in unsorted array
        min_elt_indx = i;
        for (j = i+1; j < n; j++)
          if (a[j] < a[min_elt_indx])
            min_elt_indx = j;
 
        // Swap the found minimum element with the first element
           if(min_elt_indx != i)
            {swap(&a[min_elt_indx], &a[i]);count++;}
    }
    
    printf("Sorted Array : ");
    for(int p=0;p<n;p++)
    printf("%d ",a[p]);
    printf("\n");
    
    printf("Swap f/n call count : %d\n",count);
}
/*Bubble Sort*/
void bubble(int *a, int n)
{
    int count=0;
    printf("\nBubble Sort\n\n");
    int i,j;
    /*scanf("%d",&n);int a[n];printf("%d elements : ",n);
    for(int s=0;s<n;s++)scanf("%d",&a[s]);*/

    for (i=0; i<n-1; i++)
    // Last i elements are already in place
        for (j=0; j<n-i-1; j++)
        //Compare and swap if the former is greater than later
            if (a[j] > a[j+1])
            {  swap(&a[j], &a[j+1]);count++;  }
    
    printf("Sorted Array : ");
    for(int p=0;p<n;p++)
    printf("%d ",a[p]);
    printf("\nSwap f/n call count : %d\n",count);
}
/*Insertion Sort*/
void insertion(int *a, int size)
{
    int count1=0,count2=0;
    printf("\nInsertion Sort\n\n");
    int i,j,key;
    /*scanf("%d",&size);int a[size];printf("%d elements : ",size);
    for(int s=0;s<size;s++)scanf("%d",&a[s]);*/
    
    //One by one move the boundary of sorted array
    //Starting with the 2nd element
    for(i=1;i<size;i++)
    {
        //Find the right place for the new element in the sorted array
        key=a[i];
        j=i-1;
        while(j>=0 && a[j]>key)
        {
            //Shift the array until you find the right place for key element
            a[j+1]=a[j];count1++;
            j--;
        }
        //Put the new element on its place
        a[j+1]=key;count2++;
    }
    
    printf("Sorted Array : ");
    for(int p=0;p<size;p++)
    printf("%d ",a[p]);
    printf("\nShift count : %d",count1);
    printf("\nKey placement count : %d\n",count2);
}
//GetKey
int getkey()
{
    int ch;
    ch = getch();
    if(ch == 0)
    {
        ch = getch();
        return ch;
    }
    return ch;
}