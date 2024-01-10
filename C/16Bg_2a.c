#include<stdio.h>
int xstrlen(char *word)
{
    int l = 0;
    while(*word != '\0')
    {
        word++;
        l++;
    }
    return (l);
}
int main()
{
    printf("\n");

    char str[80];
    printf("Enter string : ");
    gets(str);
    int size = xstrlen(str);
    char temp[80];

    char character;
    for(int i = 0, j = 0; i < size; i++)
    {
    character = str[i];
    switch (character)
    {
        case 'a':   break;
        case 'e':   break;
        case 'i':   break;
        case 'o':   break;
        case 'u':   break;
        case 'A':   break;
        case 'E':   break;
        case 'I':   break;
        case 'O':   break;
        case 'U':   break;
        default:
            temp[j] = str[i];
            j++;
            break;
    }
    temp[j] = '\0';
    }

    printf("\nUpdated string : ");
    puts(temp);

    printf("\n");
    return 0;
}