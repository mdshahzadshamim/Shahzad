#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<time.h>
#define COUNT 10
#define NAMESIZE 10

typedef struct policy_information
{
    unsigned int gender: 2;
    unsigned int major_minor: 1;
    unsigned int duration: 4;
    char name[10];
}policy;

int main()
{
    srand(time(NULL));
    policy p[10];
    for(int i = 0; i < COUNT; i++)
    {
        p[i].gender = 0 + rand() % 4;
        p[i].major_minor = 0 + rand() % 2;
        p[i].duration = 0 + rand() % 16;
        for(int j = 0; j < NAMESIZE-1; j++)
        p[i].name[j] = 'A' + rand() % 26;
        p[i].name[NAMESIZE-1] = '\0';
    }

    printf("\nSex\tGroup\tTime\tName\n\n");
    
    for(int i = 0; i < COUNT; i++)
    {
        p[i].gender == 0 ? printf("Male\t") : (p[i].gender == 1 ? printf("Female\t") : printf("Others\t") );
        p[i].major_minor == 0 ? printf("Major\t") : printf("Minor\t");
        printf("%d\t",p[i].duration);
        printf("%s\n", p[i].name);
    }
    return 0;
}