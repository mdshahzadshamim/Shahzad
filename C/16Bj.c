#include<stdio.h>
#include<conio.h>
#include<Windows.h>
#include<stdlib.h>
#define Vowel (line[i] == 'A' || line[i] == 'a' || line[i] == 'E' || line[i] == 'e' \
 || line[i] == 'I' || line[i] == 'i' || line[i] == 'O' || line[i] == 'o' || \
line[i] == 'U' || line[i] == 'u')\
&& (line[i+1] == 'A' || line[i+1] == 'a' || line[i+1] == 'E' || line[i+1] == 'e' \
 || line[i+1] == 'I' || line[i+1] == 'i' || line[i+1] == 'O' || line[i+1] == 'o' || \
line[i+1] == 'U' || line[i+1] == 'u')

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

int count_2vow(char *line)
{
    int i, j, count = 0;
    for (i = 0; line[i] != '\0'; i++)
	if (Vowel)
	{
        count++;
        /*printf("%d\n",i);*/
    }
    return (count);
}
int main()
{
    system("cls");

    printf("\nInitiating . . . \n");

    int repeat = 0;
    while(repeat != 27)
    {
        char line[80];
        printf("\nEnter the line : "); gets(line);
        int count = count_2vow(line);
        printf("\nNo of such occurances : %d\n",count);
        
        fflush(stdin);
        printf("\nRepeat . . . ");
        repeat = getkey(); printf("\n");
    }
return 0;
}