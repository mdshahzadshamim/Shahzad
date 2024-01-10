#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{

    if (argc != 4)
    {
        printf("Error with %s: Inappropriate Argument Count\n", argv[0]);
        return 1;
    }
    const char *sign = argv[1];
    const char *one = argv[2];
    const char *two = argv[3];

    char temp[2]; float answer;
    strcpy(temp, argv[1]);

    switch (temp[0])
    {
        case '+': answer = (atof(one) + atof(two)); break;
        case '-': answer = (atof(one) - atof(two)); break;
        case 'x': answer = (atof(one) * atof(two)); break;
        case '/': answer = (atof(one) / atof(two)); break;
        default: printf("Invalid Input");
    }
    printf("Answer : %f", answer);

    return 0;
}