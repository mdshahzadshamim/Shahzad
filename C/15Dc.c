#include<stdio.h>
int main()
{
    char a[]="123456789";//Note that the position entered here should start from zero
    printf("\n%s\n",a);
    int i,j;
    scanf("%d%d",&i,&j);//1st is position and 2nd is number of characters to extract
    if(j == 0) printf("%s",&a[i-1]);//providing address of from where to print the string
    else
    for (int p = i-1; p < i+j-1; p++)
    printf("%c",a[p]);//printing character wise → can be saved as a different string also

    return 0;
}