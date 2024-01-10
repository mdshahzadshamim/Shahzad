#include<stdio.h>
#include<string.h>
#include<math.h>
//Fibonacci Words
int main()
{
    int n; scanf("%d",&n);
    char t0[100] = "a", t1[100] = "b",temp[100];
    if(n==0) puts(t0);
    else if(n==1) puts(t1);
    else
    {
        while(n>=2)
        {
            strcpy(temp,t1);//Copy first string to temp
            strcat(t1,t0);//Concatenate first string with zeroth
            strcpy(t0,temp);//Copy temp string to zeroth

            n--;
        }
        puts(t1);
    }

    return 0;
}