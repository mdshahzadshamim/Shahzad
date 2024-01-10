#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>
#include<time.h>
#define N 30

void linkfloat();

int main()
{
    //system("cls");

    srand(time(NULL));

    typedef struct student
    {
        char name[10];
        int roll;
    }sdt;

    typedef struct transaction
    {
        int roll;
        int status;//0-incoming 1-outgoing
    }trn;
    
    FILE *fp;
    fp = fopen("19CL.DAT","wb+");
    if(fp == NULL)
    {
        puts("\nCannot open file 1\n");
        exit(1);
    }

    sdt s; int r = 1;
    int strsize = sizeof(s);
    for(int i = 0; i < N; i++)//Current Students
    {
        for(int j = 0; j < 9; j++)
        s.name[j] = 'A' + rand() % 26;
        s.name[9] = '\0';
        s.roll = 0 + r;
        r++;
        fwrite(&s, strsize, 1, fp);
    }//Generated & Stored

    FILE *ft;
    ft = fopen("19CL_TRNASACTION.DAT", "wb+");
    if(ft == NULL)
    {
        puts("\nCannot open file 2\n");
        exit(2);
    }

    trn t; r = 1;
    int in = 0;
    int out = 0;
    int trnsize = sizeof(t);
    int temp = 0;
    for(int i = 0; i < N/5; i++)//Incoming & Outgoing Students
    {
        temp++;
        //printf("\nCount: %d", temp);
        t.status =  0 + rand() % 2;
        if(t.status == 0)//Incoming
        {
            in++;
            t.roll = N + r;
            r++;
            // printf("\n%d", i);
        }
        else if(t.status == 1)//Outgoing
        {
            out++;
            t.roll = 1 + rand() % N;
            // printf("\n%d", i);
            // printf(" \nOG: %d, Roll: %d", out, t.roll);
        }
        fwrite(&t, trnsize, 1, ft);
        // printf("\nRoll: %d", t.roll);
    }//Generated & Stored

    /*Note: The outgoing count may sometimes be higher than expected
    Reason being the same outgoing roll rendomly generated multiple times*/

    FILE *fu;
    fu = fopen("19CL_UPDATED.DAT", "wb+");
    if(fu == NULL)
    {
        puts("\nCannot open file 3\n");
        exit(3);
    }

    rewind(fp);
    
    for(int i = 0; i < N; i++)
    {        
        fread(&s, strsize, 1, fp);//read primary file in s
        int count = 0;
        
        rewind(ft);
        while(fread(&t, trnsize, 1, ft) == 1)
        if(s.roll != t.roll)//checking for missing/outgoing rolls less than N
        count++;

        if(count == N/5)//copy if nt present or not missing
        fwrite(&s, strsize, 1, fu);
    }

    rewind(ft);
    while(fread(&t, trnsize, 1, ft) == 1)//Generating New Names
    if(t.status == 0)//Incoming
    {
        for(int j = 0; j < 9; j++)
        s.name[j] = 'A' + rand() % 26;
        s.name[9] = '\0';
        s.roll = t.roll;

        fwrite(&s, strsize, 1, fu);
    }

    int k = 0;
    rewind(fu);rewind(fp); sdt y;
    while(fread(&s, strsize, 1, fu) == 1)
    {
        k++;
        printf("\n%2d %s %2d", k, s.name, s.roll);
    }

    // To check increased outgoing count
    // rewind(fu);rewind(fp);
    // for(int i = 0; i < N + N/5; i++)
    // {
    //     fread(&s, strsize, 1, fu);
    //     fread(&y, strsize, 1, fp);
    //     printf("\n%2d --- ", y.roll);
    //     if(y.roll == s.roll || (s.roll > N && y.roll == N))
    //     printf("%2d", s.roll);
    //     else fseek(fu, -strsize, SEEK_CUR);
    // }
    
    printf("\n\nOutgoing : %d", out);
    printf("\nIncoming : %d", in);
    printf("\nCurrent Count : %d\n", k);

    fclose(fp);
    fclose(ft);
    fclose(fu);

    remove("19CL.DAT");
    remove("19CL_TRNASACTION.DAT");
    remove("19CL_UPDATED.DAT");

    return 0;
}

void linkfloat()
{
    float a = 0, *b;
    b = &a;/*cause emulator to be linked*/
    a = *b;/*suppress the warning – variable not used*/
}