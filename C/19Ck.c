#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>
#include<time.h>
#define N 10
//Solve 19Cf
int main()
{
    system("cls");

    srand(time(NULL));

    struct sdt
    {
        char name[10];
        int roll;
    };
    struct sdt s;
    char sdtname[10]; long int strsize;
    
    FILE *fp;

    fp = fopen("STU.DAT","wb+");

    if(fp == NULL)
    {
        puts("\nCannot open file\n");
        exit(1);
    }

    strsize = sizeof(s);

    int n = N; /*printf("\nEnter number of students : "); scanf("%d",&n);*/
    struct sdt st[N]; int r = 1;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < 9; j++)
        s.name[j] = 'A' + rand() % 26;
        s.name[9] = '\0';
        s.roll = 0 + r;
        r++;
        st[i] = s;
    }//Generated

    printf("\nGenerated : \n");

    rewind(fp);
    for(int i = 0; i < n; i++)
    {
        s = st[i];
        fwrite(&s, strsize, 1, fp);
    }//Stored

    rewind(fp);
    while(fread(&s, strsize, 1, fp) == 1)
    printf("\n%s %d", s.name, s.roll);

    printf("\n\nRandom nth name : \n");

    int count = 1 + rand() % 10;
    rewind(fp);
    for(int i = 0; i < n; i++)
    {
        fread(&s, strsize, 1, fp);
        if(i == count - 1)
        printf("\n%s",s.name);
    }//1st Provision

    printf("\n\nNames starting with S : \n");

    rewind(fp);
    for(int i = 0; i < n; i++)
    {
        fread(&s, strsize, 1, fp);
        if(s.name[0] == 'S')
        printf("\n%s",s.name);
    }//2nd Provision

    // printf("\nGenerated : \n");

    // int k=0;
    // for(int j = 0; j < 10-1; j++)
    // {
    //     for(int i = 0; i < 10-1-k; i++)
    //     {
    //         //ifcount++;
    //         if(strcmpi(st[i].name, st[i+1].name) > 0)
    //         {
    //             //swapcount++;
    //             //int tmp; char temp[10];
    //             struct sdt redu;
    //             //strcpy(temp, st[i].name); tmp = st[i].roll;
    //             redu = st[i];
    //             st[i] = st[i+1];
    //             st[i+1] = redu;
    //             //strcpy(st[i+1].name, temp); st[i+1].roll = tmp;
    //         }
    //     }
    //     k++;
    // }

    // rewind(fp);
    // while(fread(&s, strsize, 1, fp) == 1)
    // printf("\n%s %d", s.name, s.roll);
    // printf("\n\nBy Sorted Names : \n");

    fclose(fp);

    // for(int z = 0; z < 10; z++)
    // printf("\n%s %d",st[z].name, st[z].roll);
    // printf("\n");

    remove("STU.DAT");

    return 0;
}