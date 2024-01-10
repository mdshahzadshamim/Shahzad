#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
int main()
{    
    char a[10]; printf("Enter Value : "); gets(a);

    int value = 0, temp = 0;//Convert string into integer form if convertible
    int length = strlen(a);
    while(temp<length)
    {
        if((int)a[temp] > 47 && (int)a[temp] < 58)//Check if it is integer
        {
            int tempint = a[temp] - '0';//temporary integer value
            value += tempint * pow(10,length-temp-1);//adding the decimal values
        }
        else
        {
            printf("\nInvalid Input\n");exit(1);//the ascii value is not of an int
            exit(1);
        }
        
        temp++;
    }

    printf("\nValue = %d\n",value);
    
    return 0;
}