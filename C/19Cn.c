#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<conio.h>
#include"replace_substring.h"
#pragma +rch
//char *rep(char *str, char *find, char *repwth)

int main()
{
    FILE *fp, *ft;
    fp = fopen("Source.txt", "r");
    ft = fopen("19CN.txt","w");

    char str[80];
    char finda[] = " a ";
    char findb[] = " an ";
    char findc[] = " the ";
    char repwth[] = " ";
    while(fgets(str,79,fp) != NULL)
    {
        char *s = str;
        s = rep(s,finda,repwth);
        s = rep(s,findb,repwth);
        s = rep(s,findc,repwth);

        fputs(s,ft);
    }
    fclose(fp);
    fclose(ft);
    getch();
    remove("19CN.txt");

    return 0;
}