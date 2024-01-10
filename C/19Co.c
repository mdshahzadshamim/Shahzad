#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>
#include<time.h>
#define N 30

void linkfloat();

int main()
{
    system("cls");

    srand(time(NULL));

    typedef struct employee
    {
        char name[10];
        int empno;
    }emp;

    typedef struct transaction
    {
        int empno;
        int status;//0-incoming 1-outgoing
    }trn;
    
    FILE *fp;
    fp = fopen("19CL.DAT","wb+");
    if(fp == NULL)
    {
        puts("\nCannot open file 1\n");
        exit(1);
    }

    emp e; int r = 1;
    int strsize = sizeof(e);
    for(int i = 0; i < N; i++)//Current Employees
    {
        for(int j = 0; j < 9; j++)
        e.name[j] = 'A' + rand() % 26;
        e.name[9] = '\0';
        e.empno = 0 + r;
        r++;
        fwrite(&e, strsize, 1, fp);
    }//Generated & Stored

    FILE *ft;
    ft = fopen("19CO_TRNASACTION.DAT", "wb+");
    if(ft == NULL)
    {
        puts("\nCannot open file 2\n");
        exit(2);
    }

    trn t; r = 1;
    int in = 0;
    int out = 0;
    int trnsize = sizeof(t);
    // int temp = 0;
    for(int i = 0; i < N/5; i++)//Incoming & Outgoing Students
    {
        t.status =  0 + rand() % 2;
        if(t.status == 0)//Incoming
        {
            in++;
            t.empno = N + r;
            r++;
        }
        else if(t.status == 1)//Outgoing
        {
            out++;
            t.empno = 1 + rand() % N;
            // printf("\n%d", i);
            printf(" \nOG: %d, Roll: %d", out, t.empno);
        }
        fwrite(&t, trnsize, 1, ft);
    }//Generated & Stored

    FILE *fu;
    fu = fopen("19CO_UPDATED.DAT", "wb+");
    if(fu == NULL)
    {
        puts("\nCannot open file 3\n");
        exit(3);
    }

    rewind(fp);
    
    for(int i = 0; i < N; i++)
    {        
        fread(&e, strsize, 1, fp);
        int count = 0;
        
        rewind(ft);
        while(fread(&t, trnsize, 1, ft) == 1)
        if(e.empno != t.empno)
        count++;

        if(count == N/5)
        fwrite(&e, strsize, 1, fu);
    }

    rewind(ft);
    while(fread(&t, trnsize, 1, ft) == 1)
    if(t.status == 0)
    {
        for(int j = 0; j < 9; j++)
        e.name[j] = 'A' + rand() % 26;
        e.name[9] = '\0';
        e.empno = t.empno;

        fwrite(&e, strsize, 1, fu);
    }

    int k = 0;
    int temp = 1;
    rewind(fu);printf("\nMissing:\t");
    while(fread(&e, strsize, 1, fu) == 1)
    {
        k++;
        if(e.empno != k)
        {
            printf("%2d\t", k);
            fseek(fu, -strsize, SEEK_CUR);
        }
    }
    printf("\n\n");
    k = 0; //To count total entries
    rewind(fu);printf("\nMissing:\t");
    while(fread(&e, strsize, 1, fu) == 1)
    {
        k++;
    }

    // To check increased outgoing count
    rewind(fu);rewind(fp);emp y;
    for(int i = 0; i < N + N/5; i++)
    {
        fread(&e, strsize, 1, fu);//updated
        fread(&y, strsize, 1, fp);//original
        printf("\n%2d --- ", y.empno);
        if(y.empno == e.empno || (e.empno > N && y.empno == N))
        printf("%2d", e.empno);
        else fseek(fu, -strsize, SEEK_CUR);
    }

    printf("\n\nOutgoing : %d", out);
    printf("\nIncoming : %d", in);
    printf("\nCurrent Count : %d\n", k);

    fclose(fp);
    fclose(ft);
    fclose(fu);

    remove("19CL.DAT");
    remove("19CO_TRNASACTION.DAT");
    remove("19CO_UPDATED.DAT");

    return 0;
}

void linkfloat()
{
    float a = 0, *b;
    b = &a;/*cause emulator to be linked*/
    a = *b;/*suppress the warning – variable not used*/
}