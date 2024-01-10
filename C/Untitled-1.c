#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *replace(char *s, const char *find, const char *repwth);

int main(int argc, char *argv[]) {
    if (argc != 4) {
        printf("Usage: %s <old_word> <new_word> <filename>\n", argv[0]);
        return 1;
    }

    FILE *fi;
    char s[256];
    const char *oldword = argv[1];
    const char *newword = argv[2];

    fi = fopen(argv[3], "r+");

    if (fi == NULL) {
        perror("Cannot open file");
        return 1;
    }

    int no_of_lines = 0;
    while (fgets(s, 255, fi) != NULL)
        no_of_lines++;

    char **str = malloc(no_of_lines * sizeof(char *));
    if (str == NULL) {
        perror("Memory allocation failed");
        fclose(fi);
        return 1;
    }

    rewind(fi);

    int i = 0;
    while (fgets(s, 255, fi) != NULL) {
        char *found = strstr(s, oldword);
        if (found) {
            str[i] = replace(s, oldword, newword);
        } else {
            str[i] = strdup(s); // Copy unchanged line
        }
        i++;
    }

    rewind(fi);

    i = 0;
    while (i < no_of_lines) {
        fputs(str[i], fi);
        free(str[i]); // Free memory for each modified line
        i++;
    }

    free(str); // Free memory for the array of strings

    fclose(fi);

    return 0;
}

char *replace(char *s, const char *find, const char *repwth) {
    // Calculate the length of the result string
    size_t len = strlen(s) + strlen(repwth) - strlen(find) + 1;

    char *result = (char *)malloc(len);
    if (result == NULL) {
        perror("Memory allocation failed");
        exit(1);
    }

    char *ptr = s;
    char *p = strstr(ptr, find);
    char *q = result;

    while (p) {
        // Copy everything before the found string
        while (ptr != p) {
            *q = *ptr;
            q++;
            ptr++;
        }

        // Copy the replacement string
        strcpy(q, repwth);
        q += strlen(repwth);
        ptr += strlen(find);

        // Find the next occurrence
        p = strstr(ptr, find);
    }

    // Copy the remaining part of the original string
    strcpy(q, ptr);

    return result;
}