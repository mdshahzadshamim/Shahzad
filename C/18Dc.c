#include<stdio.h>
#include<math.h>
#include<string.h>

//Just need to add a line for number of digits after deciimal to be printed

float getfloat(char a[50]);

int main()
{
    char a[50];

    scanf("%s",a);
    
    printf("%f",getfloat(a));

    return 0;
}

float getfloat(char a[50])
{
    int size = strlen(a);
    float sum = 0;

    int p_n = 0;
    if(a[0] == '-') p_n = 1;
    switch (p_n)
    {
        case 0:
                {
                    int i;
                    for(i = 0; i < size && a[i] != '.'; i++)
                    {
                        sum += (a[i]-48) * pow(10, (size-i-1));
                        //printf("%f\n", sum);
                    }
                    if(a[i] == '.')
                    {
                        sum /= pow(10,strlen(&a[i]));
                        i++;
                        int negpow = -1;
                        while(i < size)
                        {
                            sum += (a[i]-48) * pow(10, (negpow));
                            negpow--;
                            i++;
                        }
                    }
                    //printf("%f", sum);
                    return sum;
                    break;
                }
        case 1:
                {
                    int i;
                    for(i = 1; i < size && a[i] != '.'; i++)
                    {
                        sum += (a[i]-48) * pow(10, (size-i-1));
                        //printf("%f\n", sum);
                    }
                    if(a[i] == '.')
                    {
                        sum /= pow(10,strlen(&a[i]));
                        i++;
                        int negpow = -1;
                        while(i < size)
                        {
                            sum += (a[i]-48) * pow(10, (negpow));
                            negpow--;
                            i++;
                        }
                    }
                    sum = (-1) * sum;
                    //printf("%f", sum);
                    return sum;
                    break;
                }
    }
}