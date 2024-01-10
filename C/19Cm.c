#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<conio.h>
#include<time.h>

#define N 25

typedef struct employee
{
    int number;
    char name[10];
    char sex;
    float salary;
}emp;
int size = sizeof(emp);

void generate();
int getkey();
void linkfloat();

int main()
{
    FILE *fp;
    fp = fopen("19CM.DAT", "wb+");
    if(fp == NULL)
    {
        printf("Error 1");
        exit(1);
    }
    emp e;
    generate();
    char choice;
    int count = N+1;
    int temp;
    
    while(choice != 27)
    {
        printf("\n\n1. List the record");
        printf("\n2. Add an employees");
        printf("\n3. Delete a record");
        printf("\n4. Update a salary");
        printf("\nExit . . . ");//27

        fflush(stdin);
        choice = getch();

        switch (choice)
        {
            case '1':
                rewind(fp);
                printf("\n\nE.No\t   Name   \tSex\tSalary\n");
                while(fread(&e, size, 1, fp) == 1)
                if(e.salary != 0)
                printf("\n%4d\t%10s\t%2c \t%.2f", e.number, e.name, e.sex, e.salary);
                break;
            case '2':
                fseek(fp, 0, SEEK_END);
                e.number = count;
                count++;
                printf("\n\nName : "); scanf("%s", e.name);
                printf("Sex : "); fflush(stdin); scanf("%c", &e.sex);
                printf("Salary : "); scanf("%f", &e.salary);
                fwrite(&e, size, 1, fp);
                break;
            case '3':
                rewind(fp);
                printf("\n\nEmployee No : "); scanf("%d", &temp);
                while(fread(&e, size, 1, fp) == 1)
                if(e.number == temp)
                {
                    e.salary = 0;
                    break;
                }
                fseek(fp, -size, SEEK_CUR);
                fwrite(&e, size, 1, fp);
                break;
            case '4':
                rewind(fp);
                printf("\n\nEmployee No : "); scanf("%d", &temp);
                float raise; printf("\nRaise Percentage : "); scanf("%f", &raise);
                while(fread(&e, size, 1, fp) == 1)
                if(e.number == temp)
                {
                    e.salary *= ((100 + raise) / 100);
                    break;
                }
                fseek(fp, -size, SEEK_CUR);
                fwrite(&e, size, 1, fp);
                break;
            default :
                choice = 27;
                break;
        }
    }
    fclose(fp);
    remove("19CM.DAT");

    return 0;
}

void generate()
{
    srand(time(NULL));
    FILE *fp;
    fp = fopen("19CM.DAT", "wb+");
    emp e;
    for(int i = 0, c = 1; i < N; i++, c++)
    {
        
        e.number = c;
        for(int j = 0; j < 9; j++)
        e.name[j] = 'A' + rand() % 26;
        e.name[9] = '\0';
        e.sex = (0 + rand() % 2 == 0? 'M' :'F');
        e.salary = 25000 + rand() % 75000;

        fwrite(&e, size, 1, fp);
    }
    fclose(fp);
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