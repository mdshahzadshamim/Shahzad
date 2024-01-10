# include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>
void abbreviate(char *name);
int getkey();
int main()
{
    system("cls");

    printf("\nInitiating . . . \n");

    int repeat = 0;
    while(repeat != 27)
    {
        char name[25];
        printf("\nEnter name : "); gets(name);
        abbreviate(name);
        printf("\nAbbreviated name : "); puts(name);

        
        fflush(stdin);
        printf("\nRepeat . . . ");
        repeat = getkey(); printf("\n");
    }

    return 0;
}
void abbreviate(char *name)
{
    int space_count = 0;
    for(int i = 0; i < strlen(name); i++)
    if(name[i] == 32) space_count++;

    for(int i = 1; i < name[i] != '\0' && space_count > 0; i++)
    if(name[i] != 32)
    {
        
        if(name[i-1] == 32)
        {
            space_count--;
        }
        else
        {
            for(int j = i; name[j] != '\0'; j++)
            name[j] = name[j+1];
            i--;
        }
    }
}
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