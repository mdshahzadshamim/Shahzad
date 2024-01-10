#include<stdio.h>
char *ones[] = {"","One ","Two ","Three ","Four ","Five ","Six ","Seven ","Eight ","Nine ",
                "Ten ","Eleven ","Twelve ","Thirteen ","Fourteen ","Fifteen ","Sixteen ","Seventeen ","Eighteen ","Nineteen "};
char *tens[] = {"","","Twenty ","Thirty ","Forty ","Fifty ","Sixty ","Seventy ","Eighty ","Ninety "};
void character(int n);
void assign(int n, char *c);
int main()
{
    printf("Enter number : "); long signed int n; scanf("%ld",&n);
    character(n);
    return 0;
}
void character(int n)
{
    /*break into lacs, thousands, etc*/
    //Crore 0   0   Lakh 0   0   Thousand 0   0 Hundred   0   Ten -0   0
    assign(n/10000000,"Crore ");
    assign((n/100000)%100,"Lack ");
    assign((n/1000)%100,"Thousand ");
    assign((n/100)%10,"Hundred ");
    assign((n%100),"");
}
void assign(int n, char *c)
{
    /*break into ones or tens*/
    if(n>19) printf("%s%s",tens[n/10],ones[n%10]);
    else printf("%s",ones[n]);
    if(n) printf("%s",c);
}