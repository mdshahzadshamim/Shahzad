#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define N 10
int main()
{
    FILE *fp;
    fp = fopen("Source.txt", "r");
    if(fp == NULL)
    {
        printf("Error in opening Source.txt");
        exit (1);
    }
    int word_size = 0, four_letter_word_count = 0, word_count = 0;
    char ch, buffer[80];
    while(1)
    {
        ch = fgetc(fp);
        if(ch == ' ' || ch == '\n' || ch == '.' || ch == '\0' || ch == EOF)
        {
            if(word_size > 0)
            word_count++;

            if(word_size == 4)
            {
                // printf("FOUR\n");
                four_letter_word_count++;
            }

            word_size = 0;
            // printf("%2d\n", word_count);
        }
        else
        {
            // printf("%c", ch);
            word_size++;
        }

        if(ch == EOF)
        break;
    }
    fclose(fp);
    printf("\nWord Count: %2d\n4-Letter word Count: %2d\n", word_count, four_letter_word_count);

    return 0;
}