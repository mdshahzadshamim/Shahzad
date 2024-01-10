#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
#include<Windows.h>
//This program has been copied from a public-view git repo

void pagebreak(FILE *fp);

int main()
{
FILE *fp;
fp = fopen("Source.txt", "r");
if (fp == NULL)
{
	puts("Can't open the file.");
	exit(1);
}
pagebreak(fp);
fclose(fp);
_getch();
return 0;
}

	void pagebreak(FILE *fp)
{
/*Dot counts the numebr of lines*/
int dot = 0;
char ch;
while (1)
{
	ch = fgetc(fp);
	if (ch == EOF)
		break;
	printf("%c", ch);
	/*If a full stop appears so the line is terminated here*/
	if (ch == '.')
	{
		/*If dot == 50 so, 50 lines have been printed, 
		so a page breakmsg should be appear here*/
		if (dot == 50)
		{
			printf("Press any key. . .");
			_getch();
			system("cls");
			/*Dot variable reinitialization*/
			dot = 1;
		}
		else
			dot++;
	}

}
}