//Newspaper Reader Statistics : 8-bit Manipulation
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define BV(x) (1<<x)
#define COUNT 10
#define Upper_class BV(0)
#define Middle_class BV(1)
#define Lower_class BV(2)
#define English BV(3)
#define Hindi BV(4)
#define Regional_language BV(5)
#define Daily BV(6)
#define Supplement BV(7)
#define Tabloid BV(8)

typedef struct respondant_data
{
    unsigned int ec_status,  pref_lang, paper_categ;
}r_d;

int main()
{
    srand(time(NULL));

    // printf("\n\nEnter the details for %d respondants...\n\n",COUNT);
    printf("\n");
    r_d r[10];
    for(int i = 0; i < COUNT; i++)
    {
        // printf("Respondant No. %d\n",i+1);
        // printf("Economic Status: ");
        r[i].ec_status = BV( 0 + rand()%3);
        // printf("%d\n",r[i].ec_status);
        // printf("Preferred Language: ");
        r[i].pref_lang = BV(3 + rand()%3);
        // printf("%d\n",r[i].pref_lang);
        // printf("Paper Category: ");
        r[i].paper_categ = BV(6 + rand()%3);
        // printf("%d\n",r[i].paper_categ);
        // printf("\n");
    }

    int temp1 = 0, temp2 = 0, temp3 = 0;
    
    for(int i = 0; i < COUNT; i++)
    {
        if((r[i].pref_lang & English) && (r[i].paper_categ & Daily)) temp1++;
        if((r[i].ec_status & Upper_class) && (r[i].paper_categ & Tabloid)) temp2++;
        if(r[i].pref_lang & Regional_language) temp3++;
    }
    
    // printf("SN\tEc\tLn\tPa\n\n");
    // for(int i = 0; i < COUNT; i++)
    // {
    //     printf("%d\t%d\t%d\t%d\n", i+1, r[i].ec_status, r[i].pref_lang, r[i].paper_categ);
    // }
    // printf("\n");

    printf("English Daily Readers(x,8,64): %d\n",temp1);
    printf("Upper Class Tabloid Readers(1,y,256): %d\n",temp2);
    printf("Regional Language Readers(x,32,z): %d\n",temp3);

    return 0;
}