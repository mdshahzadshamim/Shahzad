#include<stdio.h>
#include<math.h>
#include<string.h>

int getint(char a[50]);

int main()
{
    char a[50];

    scanf("%s",a);
    
    printf("%d",getint(a));

    return 0;
}

int getint(char a[50])
{
    int size = strlen(a);
    int sum = 0;

    int p_n = 0;
    if(a[0] == '-') p_n = 1;
    switch (p_n)
    {
        case 0://positive
                {
                    for(int i = 0; i < size; i++)
                    {
                        sum += (a[i]-48) * pow(10, (size-i-1));
                        //printf("%d\n", sum);
                    }
                    //printf("%d", sum);
                    break;
                }
        case 1://negative
                {
                    for(int i = 1; i < size; i++)
                    {
                        sum += (a[i]-48) * pow(10, (size-i-1));
                        //printf("%d\n", sum);
                    }
                    sum = (-1) * sum;
                    //printf("%d", sum);
                    break;
                }
    }
    return sum;
}