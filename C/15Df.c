#include<stdio.h>
#include<string.h>
#include<math.h>
int main()
{
    char a[10];
    gets(a);int i=0,b[10],sum=0;
    while(i<10)
    {
        if(a[i]=='X')
        b[i]=10;
        else if(a[i]-'0' < 10 && a[i]-'0' >= 0 )
        b[i]=a[i]-'0';
        else printf("Invalid Input");

        sum += (10-i)*b[i];
        i++;
    }
    if(sum%11 == 0)
    printf("Correct ISBN");
    else
    printf("Incorrect ISBN");
    
    return 0;
}