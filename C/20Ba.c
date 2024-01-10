/*REPLACE A SUB-STRING*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "replace_substring.h"
int main(int argc, char *argv[])
{
    if (argc != 4)
    {
        printf("Error with %s: Inappropriate Argument Count\n", argv[0]);
        return 1;
    }

    FILE *fi;
    char s[256];
    const char *oldword = argv[1];
    const char *newword = argv[2];

    fi = fopen(argv[3], "r");

    if(fi == NULL)
    {
        puts("\n\nCannot open file\n");
        exit(1);
    }

    int no_of_lines = 0;
    while(fgets(s,255,fi) != NULL)
    no_of_lines++;

    char **str = malloc(no_of_lines * sizeof(char *));
    if (str == NULL)
    {
        perror("Memory allocation failed");
        fclose(fi);
        return 1;
    }

    rewind(fi);

    int i = 0;
    
    while(fgets(s,255,fi) != NULL)
    {
        char *found;
        found = strstr(s, oldword);
        
        if(found)
            str[i] = rep(s, oldword, newword);
        else
            str[i] = strdup(s);

        i++;
    }

    i = 0;

    fclose(fi);
    fi = fopen(argv[3], "w");
    
    while(i < no_of_lines)
    {
        fputs(str[i], fi);
        free(str[i]);

        i++;
    }

    free(str);

    fclose(fi);

    return 0;
}


/*
This is the Source File.
This is a Line.
This is Line 3.
This is an act of example.
This is Line 5.

20Ba is izz Source.txt
*/
