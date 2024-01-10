#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <conio.h>
#include <time.h>
#define SIZE 20
#define BOOKNAME 10
#define AUTHOR 10
#define BOOKPRICE 1500

int getkey();
void linkfloat();
static int count = SIZE / 2;

#pragma pack(1)
typedef struct library
{
    /*Structure Declaration*/
    int accession_no;
    char title[BOOKNAME];
    char author[AUTHOR];
    int price;
    char issued[5];
}lib;
#pragma pack()

/*Declare Functions Below This*/
void generate(lib b[]);
//Six Functions
void addbook(lib b[]);

int main()
{
    system("cls");

    printf("\nI N I T I A T I N G . . . \n");

    lib b[SIZE];//book

    generate(b);
    
    int repeat = 0;
    while(repeat != 27)
    {
        printf("\n\n");/*code*/

        /*printf("Accession No\tTitle\t\tAuthor\t\tPrice in INR\tIssued\n\n");

        for(int i = 0; i < count; i++)
        printf("%d\t\t%s\tAUTHOR %s\t%d\t\t%s\n",b[i].accession_no,b[i].title,b[i].author,b[i].price,b[i].issued);*/

        printf("Option 1 : Add book info\n");
        printf("Option 2 : Display book info\n");
        printf("Option 3 : List all books by an author\n");
        printf("Option 4 : Print the title of the book\n");
        printf("Option 5 : Print the count of books in the library\n");
        printf("Option 6 : List the books in the order of accession number\n");
        printf("Option 7 : To exit, press esc after this\n\n");

        printf("Enter Option : "); int temp; scanf("%d",&temp); printf("\n");

        switch (temp)
        {
            case 1: addbook(b);
                    break;
            case 2: int an; printf("Enter Accession No : "); scanf("%d",&an);
                    printf("A. No\tTitle\t\tAuthor\t\tPrice\t\tIssued\n\n");
                    printf("%d\t%s\t%s\t%d\t\t%s\n",b[an-1].accession_no,b[an-1].title,b[an-1].author,b[an-1].price,b[an-1].issued);
                    break;
            case 3: char aut[AUTHOR]; printf("Enter Author : "); scanf("%s",aut);
                    printf("A. No\tTitle\t\tAuthor\t\tPrice\t\tIssued\n\n");
                    for(int i = 0; i < count; i++)
                    if(strcmp(b[i].author,aut) == 0)
                    printf("%d\t%s\t%s\t%d\t\t%s\n",b[i].accession_no,b[i].title,b[i].author,b[i].price,b[i].issued);
                    break;
            case 4: int an1; printf("Enter Accession No : "); scanf("%d",&an1);
                    printf("Title : %s\n",b[an1-1].title);
                    break;
            case 5: printf("Count of books : %d",count);
                    break;
            case 6: printf("A. No\tTitle\t\tAuthor\t\tPrice\t\tIssued\n\n");
                    for(int i = 0; i < count; i++)
                    printf("%d\t%s\t%s\t%d\t\t%s\n",b[i].accession_no,b[i].title,b[i].author,b[i].price,b[i].issued);
                    break;
            case 7: break;
        }

        fflush(stdin);
        printf("\n\nE N T E R  /  E S C . . . ");
        repeat = getkey(); printf("\n");
    }

    return 0;
}
int getkey()
{
    int ch;
    ch = getch();
    if(ch == 0)
    {
        ch = getch();
        return ch;
    }
    return ch;
}

void linkfloat()
{
    float a = 0, *b;
    b = &a;/*cause emulator to be linked*/
    a = *b;/*suppress the warning – variable not used*/
}

void generate(lib b[])
{
    srand(time(NULL));

    for(int i = 0; i < SIZE / 2; i++)
    {
        b[i].accession_no = i + 1;
        for(int j = 0; j < BOOKNAME-1; j++)
        b[i].title[j] = 'A' + rand() % 26;
        b[i].title[BOOKNAME-1] = '\0';
        int temp_a = rand() % 5;
        if(temp_a == 0)
        strcpy(b[i].author,"ONE      ");
        else if(temp_a == 1)
        strcpy(b[i].author,"TWO      ");
        else if(temp_a == 2)
        strcpy(b[i].author,"THREE    ");
        else if(temp_a == 3)
        strcpy(b[i].author,"FOUR     ");
        else if(temp_a == 4)
        strcpy(b[i].author,"FIVE     ");
        //b[i].author[AUTHOR-1] = '\0';
        b[i].price = 100 + rand() % BOOKPRICE;
        int temp = rand() % 2;
        if(temp == 0)
            strcpy(b[i].issued,"No");
        else if(temp == 1)
            strcpy(b[i].issued,"Yes");
    }
}


void addbook(lib b[])
{
    //add a book
    fflush(stdin);
    b[count].accession_no = count + 1;
    printf("Title : "); gets(b[count].title);
    if(strlen(b[count].title) < BOOKNAME)
    {
        int space = BOOKNAME - strlen(b[count].title);
        for(int i = strlen(b[count].title); i < BOOKNAME-1; i++)
            b[count].title[i] = 32;
        b[count].title[BOOKNAME-1] = '\0';
    }
    fflush(stdin);
    printf("Author : "); gets(b[count].author);
    if(strlen(b[count].author) < AUTHOR)
    {
        int space = AUTHOR - strlen(b[count].author);
        for(int i = strlen(b[count].author); i < AUTHOR-1; i++)
            b[count].author[i] = 32;
        b[count].author[AUTHOR-1] = '\0';
    }
    fflush(stdin);
    printf("Price : "); scanf("%d",&b[count].price);
    fflush(stdin);
    printf("Issued : "); int temp; scanf("%d",&temp);
    if(temp == 0)
        strcpy(b[count].issued,"No");
    else if(temp == 1)
        strcpy(b[count].issued,"Yes");
    count++;
}