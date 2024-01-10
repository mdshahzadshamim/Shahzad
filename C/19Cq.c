#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define N 30

int main()
{
    FILE *fp;
    fp = fopen("Source.txt", "r");
    if(fp == NULL)
    {
        printf("Error in opening Source.txt");
        exit (1);
    }
    int word_size = 0, word_count = 0;
    char ch, buffer[N][10];
    int i = 0, j = 0;
    while(1)
    {
        ch = fgetc(fp);
        if(ch == ' ' || ch == '\n' || ch == '.' || ch == '\0' || ch == EOF)
        {
            if(word_size > 0)
            {
                word_count++;
                buffer[i][j] = '\0';
                i++;
                j = 0;
            }

            word_size = 0;
            // printf("%2d\n", word_count);
        }
        else
        {
            buffer[i][j] = ch;
            word_size++;
            j++;
        }

        if(ch == EOF)
        break;
    }
    fclose(fp);
    printf("\nWord Count: %2d\n\n", word_count);

    int k = 0;
    for(int j = 0; j < word_count-1; j++)
    {
        // puts(buffer[j]);
        strrev(buffer[j]);
        printf("%s ", buffer[j]);
    }

    return 0;
}