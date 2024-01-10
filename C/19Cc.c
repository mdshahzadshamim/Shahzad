#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>
#include<time.h>
int main()
{
    system("cls");

    srand(time(NULL));

    struct sdt
    {
        char name[10];
        int age;
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

    int n = 10; /*printf("\nEnter number of students : "); scanf("%d",&n);*/
    struct sdt st[10];
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < 9; j++)
        s.name[j] = 'A' + rand() % 26;
        s.name[9] = '\0';
        s.age = 10 + rand() % 10;
        fwrite(&s, strsize, 1, fp);
        st[i] = s;
    }
    printf("\nGenerated\n");

    int k=0;
    for(int j = 0; j < 10-1; j++)
    {
        for(int i = 0; i < 10-1-k; i++)
        {
            //ifcount++;
            if(strcmpi(st[i].name, st[i+1].name) > 0)
            {
                //swapcount++;
                int tmp; char temp[10];
                strcpy(temp, st[i].name); tmp = st[i].age;
                st[i] = st[i+1];
                strcpy(st[i+1].name, temp); st[i+1].age = tmp;
            }
        }
        k++;
    }

    rewind(fp);
    while(fread(&s, strsize, 1, fp) == 1)
    printf("\n%s %d", s.name, s.age);
    printf("\n");

    fclose(fp);

    for(int z = 0; z < 10; z++)
    printf("\n%s %d",st[z].name, st[z].age);
    printf("\n");

    remove("STU.DAT");

    return 0;
}