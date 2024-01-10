#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define COUNT 5
/*SORT THE NAMES*/
void swap(char *t, char *s)
{
    char temp[10] = "abcdefgh";
    strcpy(temp,t);
    strcpy(t,s);
    strcpy(s,temp);
}
int main()
{
    char a[COUNT][10] = {
                        "Cold",
                        "Play",
                        "Game",
                        "Tick",
                        "Aime"
                    };
                    
    int k=0;
    //int ifcount = 0, swapcount = 0;
    for(int j = 0; j < COUNT-1; j++)
    {
        for(int i = 0; i < COUNT-1-k; i++)
        {
            //ifcount++;
            if(strcmpi(a[i], a[i+1]) > 0)
            {
                //swapcount++;
                swap(a[i], a[i+1]);
            }
        }
        k++;
    }
    
    int o=0;
    printf("\n");
    while(o<COUNT)
    {
        printf("%s\t",a[o]);
        o++;
    }
    printf("\n");
    //int o=0; while(o<COUNT) { printf("%s\t",a[o]); o++; }
    //printf("\nifcount : %d, swapcount : %d",ifcount,swapcount);
    return 0;
}