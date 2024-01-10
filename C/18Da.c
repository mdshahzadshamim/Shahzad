#include<stdio.h>

void xgets(char a[50]);
void xputs(char a[50]);

int main()
{
    char a[50];

    xgets(a);
    
    xputs(a);

    return 0;
}

void xgets(char a[50])
{
    for(int i = 0; i < 50; i++)
    {
        scanf("%c",&a[i]);

        if(a[i] == '\n')
        {
            a[i] = '\0';
            break;
        }
    }

}
void xputs(char a[50])
{
    for(int i = 0; i < 50; i++)
    {
        printf("%c",a[i]);
        if(a[i] == '\0') break;
    }
}
