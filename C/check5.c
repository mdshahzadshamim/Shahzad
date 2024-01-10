#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

/* T E S T */

int main()
{
    system("cls");
    printf("Initiating . . .\n");
    
    do
    {
        fflush(stdin);
        
        static int k[3][3][3][3][3];
        //printf("\nk = ");
        for(int i=0;i<3;i++)
        {for(int j=0;j<3;j++)
        {for(int l=0;l<3;l++)
        {for(int m=0;m<3;m++)
        {for(int n=0;n<3;n++)
        {k[i][j][l][m][n]=i+j+l+m+n;}}}}}

        for(int i=0;i<3;i++)
        {
            //printf("%d\n",i);
            for(int j=0;j<3;j++)
        {
            //printf("%d\n",j);
            for(int l=0;l<3;l++)
        {
            //printf("%d\n",l);
            for(int m=0;m<3;m++)
        {
            //printf("%d\n",m);
            for(int n=0;n<3;n++)
        {
            printf("%d ",k[i][j][l][m][n]);}
            printf("\n");}printf("\n");}printf("\n");}printf("\n");}

        if (getchar() != '\n')
        {fflush(stdin); printf("\nLoop terminated"); exit(1);}
    }while(1);
    
    return 0;
}