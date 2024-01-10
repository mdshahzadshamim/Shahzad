#include<stdio.h>
#include<conio.h>
#include<Windows.h>
/*The best solution for this would be using string.h functions*/
#define THE (line[i] == 'T' || line[i] == 't') && (line[i+1] == 'H' || line[i+1] == 'h') \
 && (line[i+2] == 'E' || line[i+2] == 'e') && (line[i+3] == ' ' || line[i+3] == '\0')

void del_the(char *line)
{
int i, j;
for (i = 0; line[i] != '\0'; i++)
	if (THE)
		for (j = i; line[j] != '\0'; j++)
			line[j] = line[j + 4];
}
int main()
{
char line[80];
puts("Enter the line");
gets(line);
del_the(line);
printf("\nLine without 'the'\n");
puts(line);
_getch();
return 0;
}