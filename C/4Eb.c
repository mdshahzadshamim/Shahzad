#include<stdio.h>
#include<stdlib.h>

int main()
{
    system("cls");

    int k,p;
    printf("k = ");
    scanf("%d",&k);
    printf("\n");

    p = ( k%100==0 ? ( k%400 == 0 ? 1 : 0) : ( k%4 == 0 ? 1 : 0 ) );
    
    if(p==1) printf("Yes");
    else printf("No");
    
    return 0;
}
