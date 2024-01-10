#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>
int main()
{
    system("cls");

    FILE *fs, *ft; char ch;

    fs = fopen("Source.txt","r");

    if(fs == NULL)
    {
        puts("\n\ncannot open file\n");
        exit(1);
    }

    ft = fopen("Target.txt","a");

    if(ft == NULL)
    {
        puts("\n\ncannot open file\n");
        fclose(fs); exit(2);
    }

    while(1)
    {
        ch = fgetc(fs);
        if(ch == EOF) break;
        else fputc(ch,ft);
    }

    fclose(fs); fclose(ft); printf("\nDone\n");
    char z = getch(); //remove("Target.txt");

    return 0;
}