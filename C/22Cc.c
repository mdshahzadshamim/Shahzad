#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<time.h>
#define COUNT 10

typedef struct datemonthyear
{
    unsigned int day: 5;
    unsigned int month: 4;
    unsigned int year: 12;
}dmy;

int compare(const void *pa, const void *pb);

int main()
{
    srand(time(NULL));
    dmy date[10];
    for(int i = 0; i < COUNT; i++)
    {
        date[i].day = 1 + rand() % 28;
        date[i].month = 1 + rand() % 12;
        date[i].year = 2000 + rand() % 24;
    }

    qsort(date, 10, sizeof(dmy), compare);

    printf("\nDay\tMonth\tYear\n\n");
    for(int i = 0; i < COUNT; i++)
    printf("%u\t%u\t%d\n", date[i].day, date[i].month, date[i].year);
    return 0;
}

int compare(const void *pa, const void *pb)
{
    const dmy *a = pa;
    const dmy *b = pb;
    return a->year - b->year;
}