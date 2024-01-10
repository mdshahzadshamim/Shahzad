#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>
/*DELETE THE VOWELS*/
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
char *vowel[10] = {"A","a","E","e","I","i","O","o","U","u"};
char *first_occurence(char *s)
{
    char *v[10];
    int j = 0;
    for(int i = 0; i < 10; i++)
    {
        char *temp = strstr(s,vowel[i]);
        if(temp)
        {
            v[j] = temp;
            j++;
        }
    }
    j--;
    char *p = v[j];
    while(j > 0)
    {
        if(v[j-1] < p)
        p = v[j-1];
        j--;
    }
    return (p);
}
char *deletevowel(char *s)
{
    char a[strlen(s+1)], *ptr, *p, *p_all[10];
    int i = 0;
    
    p = first_occurence(s);
    do
    {
        while(*s != *p)//copy upto before apparance of search string
        { 
            a[i] = *s;
            i++;
            s++;
        }
        a[i]='\0';//end string
        s += 1;//increase upto length of search string
        p = first_occurence(s);
    }while(p);//until the search string is found in the original string
    if(*(s) == '\0');//case 1 - search string not found because original string is over
    else if(*(s) != '\0') strcat(a,s);//case 2 - search string is not found in the string left
    ptr = (char *)malloc(strlen(a));
    strcpy(ptr,a);
    s = ptr;
    return (s);
}
int main()
{
    system("cls");
    
    printf("\nInitiating . . . \n");
    
    int repeat = 0;
    while(repeat != 27)
    {
        char *sentence, s[100];
        printf("\nEnter string : "); gets(s);
        sentence = (char *)malloc(strlen(s+1));
        strcpy(sentence,s);
        sentence = deletevowel(sentence);
        printf("\nUpdated string : "); puts(sentence);

        fflush(stdin);
        printf("\nRepeat/Exit? . . . ");
        repeat = getkey(); printf("\n");
    }
    return 0;
}