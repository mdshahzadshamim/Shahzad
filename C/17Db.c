#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include<conio.h>
#include<time.h>
#include<unistd.h>

#define SIZE 200
#define NAMESIZE 20

int getkey();
void linkfloat();

#pragma pack(1)
typedef struct customer
{
    /*Structure Declaration*/
    int acno;
    char name[NAMESIZE];
    float bal;
}cust;
#pragma pack()

void less(cust c[], float lim);
void witd_dep(cust *c);

int main()
{
    system("cls");

    printf("\nI N I T I A T I N G . . . \n");

    cust c[SIZE];
    
    srand(time(NULL));//seed

    for(int i = 0; i < SIZE; i++)
        {
            c[i].acno = i + 1;//account number
            c[i].bal = rand()%300;
            for(int n = 0; n < NAMESIZE-1; n++)
            c[i].name[n] = 'A' + rand()%26;
            c[i].name[NAMESIZE - 1] = '\0';
        }
    
    int repeat = 0;
    while(repeat != 27)
    {
        printf("\n\n");/*code*/

        printf("Option 1 : Check Accounts with below a specified Balance\n");
        printf("Option 2 : Deposit/Withdrawal\n");
        printf("Enter Option : ");
        int temp; scanf("%d",&temp);
        if(temp == 1)
        {
            float limit; printf("Enter Limit : "); scanf("%f",&limit);
            less(c,limit);
        }
        else if(temp == 2)
        {
            int a; printf("Account Number : "); scanf("%d",&a);
            witd_dep(&c[a-1]);
        }
        else
        printf("Invalid Input\n");

        /*for(int i = 0; i < SIZE; i++)
        printf("Account Number : %d\nAccount Holder Name : %s\nBalance : %f\n",c[i].acno,c[i].name,c[i].bal);*/

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

void less(cust c[], float lim)
{
    /*code*/
    for(int i = 0; i < SIZE; i++)
    {
        if(c[i].bal<lim)
        {
            printf("Account Number : %d\tCustomer Name : %s\tBalance : %f\n",c[i].acno,c[i].name,c[i].bal);
        }
    }
}

void witd_dep(cust *c)
{
    /*code*/
    printf("Account Number : %d\tCustomer Name : %s\tBalance : %f\n",c->acno,c->name,c->bal);
    int dep; printf("Option 0 : Withdraw\nOption 1 : Deposit\nEnter Option : "); scanf("%d",&dep);
    if(dep == 1)
    {
        float temp; printf("Enter Amount : "); scanf("%f",&temp);
        c->bal += temp;
        printf("Account Number : %d\tCustomer Name : %s\tBalance : %f\n",c->acno,c->name,c->bal);
    }
    else if(dep == 0)
    {
        /*code*/
        float temp; printf("Enter Amount : "); scanf("%f",&temp);
        if((c->bal) - temp < 100)
        printf("The balance is insufficint for the specified withdrawal\n");
        else if((c->bal) - temp >= 100)
        {
            c->bal -= temp;
            printf("Account Number : %d\tCustomer Name : %s\tBalance : %f\n",c->acno,c->name,c->bal);
        }
    }
}

/*->*/