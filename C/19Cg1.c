/*Encryption-Decryption*/
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int main()
{
    system("cls");

    srand(time(NULL));
    
    FILE *fp;

    fp = fopen("19Cg1.txt","w+");
    if(fp == NULL)
    exit(1);

    int k, arr[100], w;
    printf("Enter a 6-digit encryption code : "); scanf("%d",&w);
    if(w < 0 || w > 999999) exit(1);
    int p1,p2,p3;
    p1 = (w % 100);
    p2 = ((w / 100) % 100);
    p3 = (w / 10000);
    char ch;

    for(int i = 0; i < 100; i++)
    {
        k = rand() % 3;
        switch (k)
        {
            case 0:
                ch = 'A' + rand() % 26 + p1;
                arr[i] = 0;
                break;
            case 1:
                ch = 'a' + rand() % 26 + p2;
                arr[i] = 1;
                break;
            case 2:
                ch = '0' + rand() % 9 + p3;
                arr[i] = 2;
                break;
        }
        fputc(ch, fp);
    }

    printf("\nEnter the decryption code : ");
    int word; scanf("%d",&word);
    if(word != w) word -= rand() % word;
    int t1,t2,t3;
    t1 = (word % 100);
    t2 = ((word / 100) % 100);
    t3 = (word / 10000);

    printf("\n"); char c; rewind(fp);
    for(int i = 0; i < 100; i++)
    {
        c = fgetc(fp);
        k = arr[i];
        switch (k)
        {
            case 0:
                printf("%c",c-t1);
                break;
            case 1:
                printf("%c",c-t2);
                break;
            case 2:
                printf("%c",c-t3);
                break;
        }
    }

    printf("\n"); 

    fclose(fp);
    remove("19Cg1.txt");

    return 0;
}