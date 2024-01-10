/*Copy text from two files one line at a time from each until end*/
#include<stdio.h>
#include<stdlib.h>
int main()
{
    system("cls");
    FILE *fs1, *fs2, *ft;
    char s1[80], s2[80];
    fs1 = fopen("19CeS1.txt","r");
    if(fs1 == NULL)
    {
        puts("Error\n");
        exit(1);
    }
    fs2 = fopen("19CeS2.txt","r");
    if(fs2 == NULL)
    {
        puts("Error\n");
        exit(2);
    }
    ft = fopen("19CeT.txt","w");
    if(ft == NULL)
    {
        puts("Error\n");
        exit(3);
    }

    char *temp1, *temp2;
    temp1 = fgets(s1,79,fs1);
    temp2 = fgets(s2,79,fs2);

    while(temp1 != NULL || temp2 != NULL)
    {
        if(temp1 != NULL && temp2 == NULL)
        fputs(s1,ft);
        else if(temp2 != NULL && temp1 == NULL)
        fputs(s2,ft);
        else if(temp1 != NULL && temp2 != NULL)
        {
            fputs(s1,ft);
            fputs(s2,ft);
        }
        temp1 = fgets(s1,79,fs1);
        temp2 = fgets(s2,79,fs2);
    }
    fclose(fs1);
    fclose(fs2);
    fclose(ft);
    printf("Done\n");
    return 0;
}