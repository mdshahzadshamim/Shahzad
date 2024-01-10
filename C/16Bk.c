# include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include<conio.h>
int p(int i);
void asn(int n);
void ones(int n);
void first_tens(int n);
void tens(int n);
void character(char *no);
int getkey();
int main()
{
    system("cls");

    printf("\nInitiating . . . \n\n");

    int repeat = 0;
    while(repeat != 27)
    {
        /*code*/

        char number[10], *c;
        gets(number);
        character(number);
        
        fflush(stdin);
        printf("\n\nRepeat . . . ");
        repeat = getkey(); printf("\n");
    }

    return 0;
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
void character(char *n)
{
    /*code*/
    int length = strlen(n);
    int no = atoi(n);
    //printf("%d\n",length);
    switch (length)
    {
        case 9: ;
        case 8: asn(no/p(8)); printf("Crore "); no %= p(8);
        case 7: ;
        case 6: asn(no/p(6)); if(no/p(6) != 0)  printf("Lakh "); no %= p(6);
        case 5: ;
        case 4: asn(no/p(4)); if(no/p(4) != 0)  printf("Thousand "); no %= p(4);
        case 3: asn(no/p(3)); if(no/p(3) != 0)  printf("Hundred "); no %= p(3);
        case 2: ;
        case 1: asn(no/p(1));
    }
}
void asn(int n)
{
    /*code*/
    if(n<10)
    ones(n);
    else if(n>=10 && n<20)
    first_tens(n);
    else
    {
        tens(n/10);
        ones(n%10);
    }
}
void ones(int n)
{
    /*code*/
    switch (n)
    {
        case 9: printf("Nine ");  break;
        case 8: printf("Eight "); break;
        case 7: printf("Seven "); break;
        case 6: printf("Six ");   break;
        case 5: printf("Five ");  break;
        case 4: printf("Four ");  break;
        case 3: printf("Three "); break;
        case 2: printf("Two ");   break;
        case 1: printf("One ");   break;
        case 0:break;
    }
}
void tens(int n)
{
    /*code*/
    switch (n)
    {
        case 9: printf("Ninety ");  break;
        case 8: printf("Eighty ");  break;
        case 7: printf("Seventy "); break;
        case 6: printf("Sixty ");   break;
        case 5: printf("Fifty ");   break;
        case 4: printf("Forty ");   break;
        case 3: printf("Thirty ");  break;
        case 2: printf("Twenty ");  break;
    }
}
void first_tens(int n)
{
    /*code*/
    switch (n)
    {
        case 19: printf("Nineteen ");  break;
        case 18: printf("Eighteen "); break;
        case 17: printf("Seventeen "); break;
        case 16: printf("Sixteen ");   break;
        case 15: printf("Fifteen ");  break;
        case 14: printf("Fourteen ");  break;
        case 13: printf("Thirteen "); break;
        case 12: printf("Twelve ");   break;
        case 11: printf("Eleven ");   break;
        case 10: printf("Eleven ");   break;
    }
}

//if(no < 20 && no > 10)first_tens(no);
int p(int i)
{
    /*code*/
    return(pow(10,i-1));
}