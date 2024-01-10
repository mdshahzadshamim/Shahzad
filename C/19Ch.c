#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <conio.h>
#include <time.h>
/*Customers & Transactions*/

#define SIZE 100
#define NAMESIZE 10
#define TRCOUNT 10

int getkey();
void linkfloat();

#pragma pack(1)
typedef struct customer
{
    /*Structure Declaration*/
    int acno;
    char name[30];
    float bal;
}cus;
#pragma pack()

#pragma pack(1)
typedef struct transaction
{
    /*Structure Declaration*/
    int accno;
    int t_type;/*Deposit or Withdrawal*/
    float amt;
    int valid;
}tr;
#pragma pack()

/*Declare Functions Below This*/

int main()
{
    system("cls");

    printf("\nI N I T I A T I N G . . . \n\n");

    cus c; int cussize = sizeof(c);
    tr t; int trsize = sizeof(t);

    FILE *fc, *ft;

    fc = fopen("CUSTOMER.DAT","wb+");
    if(fc == NULL)
    {
        puts("Error 1\n");
        exit(1);
    }

    ft = fopen("TRANSACTIONS.DAT","wb+");
    if(ft == NULL)
    {
        puts("Error 2\n");
        fclose(fc);
        exit(2);
    }


    srand(time(NULL));

    for(int i = 0; i < SIZE; i++)
        {
            c.acno = i + 1;//account number
            c.bal = rand() % 100000;
            for(int n = 0; n < NAMESIZE-1; n++)
            c.name[n] = 'A' + rand()%26;
            c.name[NAMESIZE - 1] = '\0';
            fwrite(&c, cussize, 1, fc);
        }
    
    for(int i = 0; i < TRCOUNT; i++)
        {
            t.accno = 1 + rand() % SIZE;//account number
            t.t_type = rand() % 2;//0-deposit & 1-withdrawal
            t.amt = rand() % 10000;
            t.valid = 1;
            fwrite(&t, trsize, 1, ft);
        }

    // rewind(fc);
    // while(fread(&c, cussize, 1, fc) == 1)
    // printf("%d  %f  %s\n",c.acno,c.bal,c.name);
    // printf("\n");
    
    printf("Transaction ID\t");/*14*/
    printf("Account No\t");/*10*/
    printf("   Name   \t");/*10*/
    printf("Previous Balance\t");/*16*/
    printf("Type\t");/*4*/
    printf("Amount\t\t");/*6*/
    printf("Validity\t");/*8*/
    printf("Current Balance\n");/*15*/

    
    int count = 0;
    rewind(ft);

    for(int i = 0; i < TRCOUNT; i++)
    {
        rewind(ft);
        while(fread(&t, trsize, 1, ft) == 1 && t.valid != 1);

        rewind(fc);
        
        while(fread(&c, cussize, 1, fc) == 1)
        {
            if(t.accno == c.acno)
            {
                count++;
                printf("\n%-14d\t",count);
                printf("%-10d\t%10s\t    %8.2f    \t",c.acno,c.name,c.bal);
                if(t.t_type == 0)//deposit
                {
                    c.bal += t.amt;
                    fseek(fc, -cussize, SEEK_CUR);
                    fwrite(&c, cussize, 1, fc);
                    t.valid = 3;
                }
                else if(t.t_type == 1)//withdrawal
                {
                    if(c.bal - t.amt <= 100)
                    {
                        t.valid = 0;
                    }
                    else if(c.bal - t.amt > 100)
                    {
                        c.bal -= t.amt;
                        fseek(fc, -cussize, SEEK_CUR);
                        fwrite(&c, cussize, 1, fc);
                        t.valid = 4;
                    }
                }

                fseek(ft, -trsize, SEEK_CUR);
                fwrite(&t, trsize, 1, ft);
                if(t.t_type==0) printf(" D  \t");/*4*/else printf(" W  \t");/*4*/
                printf("%7.2f\t\t",t.amt);
                if(t.valid!=0) printf(" Valid  \t");/*5*/ else printf(" Invalid\t");/*7*/
                printf("    %8.2f",c.bal);
                break;
            }
        }
    }
    printf("\n");
    //printf("\nCount: %d\n",count);

    // rewind(ft);
    // while(fread(&t, trsize, 1, ft) == 1)
    // printf("%d  %d  %f  %d\n",t.accno,t.t_type,t.amt,t.valid);
    // printf("\n");
    
    // rewind(fc);
    // while(fread(&c, cussize, 1, fc) == 1)
    // printf("%d  %f  %s\n",c.acno,c.bal,c.name);
    // printf("\n");

    fclose(fc); remove("CUSTOMER.DAT"); printf("\nCustomer Data Removed\n");
    fclose(ft); remove("TRANSACTIONS.DAT"); printf("\nTransaction Data Removed\n");

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