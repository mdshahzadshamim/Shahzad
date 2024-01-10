#include<stdio.h>
#include<stdlib.h>
int xstrlen(char *word);
void xstrcpy(char *target, char *source);
void xstrcat(char *target, char *source);
int xstrcmpi(char *string, char *charset);
int main()
{
    system("cls");

    char source[30] = "Hello"; printf("Source String : %s\n",source);
    char target[30];

    xstrcpy(target, source);
    printf("Length of Target : %d\n", xstrlen(target));//5
    xstrcat(target, source);
    printf("Length of Target after Concatanation : %d\n", xstrlen(target));//10
    
    printf("Comparison String : ");
    char charset[30]; scanf("%s",charset); fflush(stdin);
    printf("The Comparison String is alphabetically ");
    int t = xstrcmpi(charset, source);//-ve if first string alphabetically before second
    if(t < 0) printf("before ");
    else if(t == 0) printf("same as ");
    else if(t > 0) printf("after ");
    printf("the Source String.\n");

    return 0;
}
int xstrlen(char *word)
{
    int l = 0;
    while(*word != '\0')
    {
        word++;
        l++;
    }
    return (l);
}
void xstrcpy(char *target, char *source)
{
    while(*source != '\0')
    {
        *target = *source;
        target++;
        source++;
    }
    *target = '\0';
}
void xstrcat(char *target, char *source)
{
    target += xstrlen(target);
    while(*source != '\0')
    {
        *target = *source;
        target++;
        source++;
    }
    *target = '\0';
}
int xstrcmpi(char *string, char *charset)
{
    while((*string != '\0' || *charset != '\0') && (*string == *charset || *string - 'a' == *charset - 'A' || *string - 'A' == *charset - 'a'))
    {
        string++;
        charset++;
    }

    if(*string == '\0' && *charset != '\0') string--;
    else if(*string != '\0' && *charset == '\0') charset--;
    else if(*string == '\0' && *charset == '\0') {string--; charset--;}
    
    int a = (*string - 'a' > -1 && *string - 'a' < 26 ? *string - 'a' : *string - 'A');
    //printf("%d %c ",a, *string);
    int b = (*charset - 'a' > -1 && *charset - 'a' < 26 ? *charset - 'a' : *charset - 'A');
    //printf("%d %c ",b, *charset);
    return (a-b);//-ve if first string alphabetically before second
}