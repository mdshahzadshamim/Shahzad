#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
int main()
{
    FILE *fs, *ft;
    char ch;
    fs = fopen("Source.txt","r");
    if(fs == NULL)
    {
        puts("Error\n");
        exit(1);
    }
    ft = fopen("19Cd.txt","w");
    if(ft == NULL)
    {
        puts("Error\n");
        exit(2);
    }
    while(1)
    {
        ch = fgetc(fs);
        if(ch > 96 && ch < 123)
        ch = 64 + (ch-96);

        if(ch == EOF)
            break;
        else
            fputc(ch,ft);
    }
    fclose(fs);
    fclose(ft);
    printf("Done\n"); char z = getch();
    remove("19Cd.txt");
    return 0;
}