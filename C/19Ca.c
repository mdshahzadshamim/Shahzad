#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
    system("cls");

    /*Display contents of a text file with line numbers*/

    FILE *fp; char s[80]; int i = 1;
    fp = fopen("Source.txt","r");
    if(fp == NULL)
    {
        puts("\n\ncannot open file\n");
        exit(1);
    }
    while(fgets(s,79,fp) != NULL)
    {
        printf("%d %s",i,s);
        i++;
    }
    fclose(fp);

    return 0;
}