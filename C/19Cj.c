#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>
#include<time.h>
#define N 100
//Solve 19Cf

#pragma pack(1)
typedef struct Bloood_Donors
{
    /*Structure Declaration*/
    char name[21];
    char address[41];
    char age[3] ;
    char blood_type[2];
}bd;
#pragma pack()

void linkfloat();
void generate();


/*Start*/
int main()
{
    system("cls");

    int strsize = sizeof(bd);
    bd d; int count = 0;
    generate();

    FILE *fp;
    fp = fopen("19Cj.DAT","rb");
    if(fp == NULL) printf("Error");

    for(int i = 0; i < N; i++)
    {
        fread(&d, strsize, 1, fp);
        if(atoi(d.age) < 25 && d.blood_type[0] == '2')
        {
            printf("%s %s\n", d.name, d.age);
            count++;
        }
    }
    printf("Count : %d\n",count);
    
    fclose(fp); remove("19Cj.DAT"); printf("\nData Removed\n");
    
    return 0;
}

void generate()
{

    srand(time(NULL));

    FILE *fp;
    fp = fopen("19Cj.DAT","wb+");
    if(fp == NULL) printf("Error");

    int strsize = sizeof(bd);
    bd d;

    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < 20; j++)
        d.name[j] = 'A' + rand() % 26;
        d.name[20] = '\0';

        for(int j = 0; j < 40; j++)
        d.address[j] = 'A' + rand() % 26;
        d.address[40] = '\0';
        
        d.age[0] = '1' + rand() % 6;
        d.age[1] = '0' + rand() % 10;
        d.age[2] = '\0';
        
        d.blood_type[0] = '1' + rand() % 4;
        d.blood_type[1] = '\0';

        fwrite(&d, strsize, 1, fp);        
    }
    fclose(fp);    
}

void linkfloat()
{
    float a = 0, *b;
    b = &a;/*cause emulator to be linked*/
    a = *b;/*suppress the warning – variable not used*/
}