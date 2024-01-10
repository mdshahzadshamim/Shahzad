#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"replace_substring.h"
#pragma +rch
/*FIND A CERTAIN SUB-STRING AND DELETE IT*/
char *replace(char *s,char *find,char *repwth)
{
    char a[strlen(s)+6*strlen(repwth)], *ptr, *p;
    int i=0;
    p = strstr(s,find);//find first appearance of search string
    do
    {
        while(*s != *p)//copy upto before apparance of search string
        { 
            a[i] = *s;
            i++;
            s++;
        }
        a[i]='\0';//end string
        s += strlen(find);//skip appearance from original string
        strcat(a,repwth);//concatenate with replacement after above copy
        i += strlen(repwth);//increase upto length of search string
        p = strstr(s,find);//find appearance of search string
    }while(p);//until the search string is found in the original string
    if(*(s) == '\0');//case 1 - search string not found because original string is over
    else if(*(s) != '\0') strcat(a,s);//case 2 - search string is not found in the string left
    ptr = (char *)malloc(strlen(a));
    strcpy(ptr,a);
    s = ptr;
}

int main()
{
    char *str[] = {
                    "We will teach you how to...",
                    "Move a mountain",
                    "Level a building",
                    "Erase the past",
                    "Make a million",
                    "...all through C!"
                    };
    
    int d=0;printf("\n");
    while(d<6)
    puts(str[d++]);
    
    char find[20],*f,repwth[20],*r;printf("\n");
    printf("Search String: ");scanf("%s",find);
    //f = (char *)malloc(strlen(find+1)); strcpy(f,find);
    printf("Replacement String: ");scanf("%s",repwth);
    //r = (char *)malloc(strlen(repwth+1)); strcpy(r,repwth);

    int i=0;
    while(i<6)
    {
        char *k;
        k = strstr(str[i],find);
        if(k)
        str[i] = rep(str[i],find,repwth);
        i++;
    }

    int o=0;printf("\n");
    while(o<6)
    puts(str[o++]);

    return 0;
}
