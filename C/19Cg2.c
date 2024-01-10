/*Substitution Cipher*/
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
char substitute(char c);
char decipher(char c);
int main()
{
    system("cls");

    srand(time(NULL));
    
    FILE *fp, *ft;

    fp = fopen("Preamble.txt","r");
    if(fp == NULL)
    exit(1);
    ft = fopen("Temp.txt","w+");
    if(ft == NULL)
    exit(2);
    
    char ch;
    while(1)
    {
        ch = fgetc(fp);

        if(ch == EOF)
            break;
        else
        {
            ch = substitute(ch);
            fputc(ch,ft);
        }
    }

    printf("Cipher Text :\n\n");
    rewind(ft);
    while(1)
    {
        ch = fgetc(ft);
        if(ch == EOF)
            break;
        printf("%c",ch);
    }
    //printf("\n");

    printf("Decipherred Text :\n\n");
    rewind(ft);
    while(1)
    {
        ch = fgetc(ft);
        if(ch == EOF)
            break;
        printf("%c",decipher(ch));
    }

    //printf("\n"); 

    fclose(fp);fclose(ft);
    remove("Temp.txt");

    return 0;
}

char substitute(char c)
{
    switch (c)
    {
        case 'a': c = 'Q'; break;
        case 'b': c = 'W'; break;
        case 'c': c = 'E'; break;
        case 'd': c = 'R'; break;
        case 'e': c = 'T'; break;
        case 'f': c = 'Y'; break;
        case 'g': c = 'U'; break;
        case 'h': c = 'I'; break;
        case 'i': c = 'O'; break;
        case 'j': c = 'P'; break;
        case 'k': c = 'A'; break;
        case 'l': c = 'S'; break;
        case 'm': c = 'D'; break;
        case 'n': c = 'F'; break;
        case 'o': c = 'G'; break;
        case 'p': c = 'H'; break;
        case 'q': c = 'J'; break;
        case 'r': c = 'K'; break;
        case 's': c = 'L'; break;
        case 't': c = 'Z'; break;
        case 'u': c = 'X'; break;
        case 'v': c = 'C'; break;
        case 'w': c = 'V'; break;
        case 'x': c = 'B'; break;
        case 'y': c = 'N'; break;
        case 'z': c = 'M'; break;

        case 'A': c = 'q'; break;
        case 'B': c = 'w'; break;
        case 'C': c = 'e'; break;
        case 'D': c = 'r'; break;
        case 'E': c = 't'; break;
        case 'F': c = 'y'; break;
        case 'G': c = 'u'; break;
        case 'H': c = 'i'; break;
        case 'I': c = 'o'; break;
        case 'J': c = 'p'; break;
        case 'K': c = 'a'; break;
        case 'L': c = 's'; break;
        case 'M': c = 'd'; break;
        case 'N': c = 'f'; break;
        case 'O': c = 'g'; break;
        case 'P': c = 'h'; break;
        case 'Q': c = 'j'; break;
        case 'R': c = 'k'; break;
        case 'S': c = 'l'; break;
        case 'T': c = 'z'; break;
        case 'U': c = 'x'; break;
        case 'V': c = 'c'; break;
        case 'W': c = 'v'; break;
        case 'X': c = 'b'; break;
        case 'Y': c = 'n'; break;
        case 'Z': c = 'm'; break;
        
        case '0': c = ')'; break;
        case '1': c = '!'; break;
        case '2': c = '@'; break;
        case '3': c = '#'; break;
        case '4': c = '$'; break;
        case '5': c = '%'; break;
        case '6': c = '^'; break;
        case '7': c = '&'; break;
        case '8': c = '*'; break;
        case '9': c = '('; break;
    }
    return (c);
}

char decipher(char c)
{
    switch (c)
    {
        case 'Q': c = 'a'; break;
        case 'W': c = 'b'; break;
        case 'E': c = 'c'; break;
        case 'R': c = 'd'; break;
        case 'T': c = 'e'; break;
        case 'Y': c = 'f'; break;
        case 'U': c = 'g'; break;
        case 'I': c = 'h'; break;
        case 'O': c = 'i'; break;
        case 'P': c = 'j'; break;
        case 'A': c = 'k'; break;
        case 'S': c = 'l'; break;
        case 'D': c = 'm'; break;
        case 'F': c = 'n'; break;
        case 'G': c = 'o'; break;
        case 'H': c = 'p'; break;
        case 'J': c = 'q'; break;
        case 'K': c = 'r'; break;
        case 'L': c = 's'; break;
        case 'Z': c = 't'; break;
        case 'X': c = 'u'; break;
        case 'C': c = 'v'; break;
        case 'V': c = 'w'; break;
        case 'B': c = 'x'; break;
        case 'N': c = 'y'; break;
        case 'M': c = 'z'; break;

        case 'q': c = 'A'; break;
        case 'w': c = 'B'; break;
        case 'e': c = 'C'; break;
        case 'r': c = 'D'; break;
        case 't': c = 'E'; break;
        case 'y': c = 'F'; break;
        case 'u': c = 'G'; break;
        case 'i': c = 'H'; break;
        case 'o': c = 'I'; break;
        case 'p': c = 'J'; break;
        case 'a': c = 'K'; break;
        case 's': c = 'L'; break;
        case 'd': c = 'M'; break;
        case 'f': c = 'N'; break;
        case 'g': c = 'O'; break;
        case 'h': c = 'P'; break;
        case 'j': c = 'Q'; break;
        case 'k': c = 'R'; break;
        case 'l': c = 'S'; break;
        case 'z': c = 'T'; break;
        case 'x': c = 'U'; break;
        case 'c': c = 'V'; break;
        case 'v': c = 'W'; break;
        case 'b': c = 'X'; break;
        case 'n': c = 'Y'; break;
        case 'm': c = 'Z'; break;
        
        case ')': c = '0'; break;
        case '!': c = '1'; break;
        case '@': c = '2'; break;
        case '#': c = '3'; break;
        case '$': c = '4'; break;
        case '%': c = '5'; break;
        case '^': c = '6'; break;
        case '&': c = '7'; break;
        case '*': c = '8'; break;
        case '(': c = '9'; break;
    }
    return (c);
}