#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define COUNT 3
/*REVERSE THE STRING*/
char *reverse(char *s)
{
    int l = strlen(s);
    char a[l], *ptr;
    for(int i = l-1; i >= 0; i--)
    {
        a[i] = *s;
        s++;
    }
    a[l]='\0';

    /*Instead of using array, to use string:
    1. Dynamically declare a string of length + 1
    2. Copy "\0" to this string
    3. Add length to the address, i.e.; t = t+length
    4. Add "\0" at this position of the string
    5. Copy each character of the original string to this consecutively
       by decreasing the t-position by 1 in every iteration
    */
    
    ptr = (char *)malloc(l+1);
    strcpy(ptr,a);
    s = ptr;
}
int main()
{
    char *s[] = {
                    "To err is human...",
                    "But to really mess things up...",
                    "One needs to know C!"
                };

    int d=0;printf("\n");
    while(d<COUNT)
    puts(s[d++]);

    int i=0;
    while(i<COUNT)
    {
        s[i] = reverse(s[i]);
        i++;
    }

    int o=0;printf("\n");
    while(o<COUNT)
    puts(s[o++]);

    return 0;
}