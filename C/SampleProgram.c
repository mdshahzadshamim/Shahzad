/*A menu-driven program for elementary database management*/
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>
int main()
{
    FILE *fp, *ft;
    char another, choice;
    struct emp
    {
        char name[40];
        int age;
        float bs;
    };
    struct emp e;
    char empname[40];
    long int recsize;

    fp = fopen("EMP.DAT","rb+");

    if(fp == NULL)
    {
        fp = fopen("EMP.DAT","wb+");

        if(fp == NULL)
        {
            puts("\n\ncannot open file\n");
            exit(1);
        }
    }

    recsize = sizeof(e);

    while ( 1 )
    {
        system ( "cls" ); 
        printf ( "\n1. Add Records\n" ) ;
        printf ( "2. List Records\n" ) ;
        printf ( "3. Modify Records\n" ) ;
        printf ( "4. Delete Records\n" ) ;
        printf ( "0. Exit\n" ) ;
        printf ( "Your choice : " ) ;
        fflush ( stdin ) ;
        choice = getche( );

        switch ( choice )
        {
            case '1' :
               fseek ( fp, 0 , SEEK_END ) ;
               another = 'Y' ;
               while ( another == 'Y' )
               {
                    printf ( "\nEnter name, age and basic sal. " ) ;
                    scanf ( "%s %d %f", e.name, &e.age, &e.bs ) ;
                    fwrite ( &e, recsize, 1, fp ) ;
                    printf ( "\nAdd another Record (Y/N) " ) ;
                    fflush ( stdin ) ;
                    another = getche() ;
                }
                break ;
            case '2' :
                rewind ( fp ) ;
                while ( fread ( &e, recsize, 1, fp ) == 1 )
                    printf ( "\n%s %d %f", e.name, e.age, e.bs ) ;
                printf("\nPress Any Key to continue... "); fflush(stdin); getche();
                break ;
            case '3' :
                another = 'Y' ;
                while ( another == 'Y' )
                {
                    printf ( "\nEnter name of employee to modify " ) ; scanf ( "%s", empname ) ;
                    rewind ( fp ) ;
                    while ( fread ( &e, recsize, 1, fp ) == 1 )
                    {
                        if ( strcmp ( e.name, empname ) == 0 )
                        {
                            printf ( "\nEnter new name, age & bs" ) ;
                            scanf ( "%s %d %f", e.name, &e.age, &e.bs ) ;
                            fseek ( fp, - recsize, SEEK_CUR ) ;
                            fwrite ( &e, recsize, 1, fp ) ;
                            break ;
                        } 
                    }

                    printf ( "\nModify another Record (Y/N) " ) ;
                    fflush ( stdin ) ;
                    another = getche() ;
                }

                break ;
            case '4' :
                another = 'Y' ;
                while ( another == 'Y' )
                {
                    printf ( "\nEnter name of employee to delete " ) ;
                    scanf ( "%s", empname ) ;

                    ft = fopen ( "TEMP.DAT", "wb" ) ;
                
                    rewind ( fp ) ;
                    while ( fread ( &e, recsize, 1, fp ) == 1 )
                    {
                        if ( strcmp ( e.name, empname ) != 0 )
                            fwrite ( &e, recsize, 1, ft ) ;
                    }
                    fclose ( fp ) ;
                    fclose ( ft ) ;
                    remove ( "EMP.DAT" ) ;
                    rename ( "TEMP.DAT", "EMP.DAT" ) ;

                    fp = fopen ( "EMP.DAT", "rb+" ) ;
                    printf ( "Delete another Record (Y/N) " ) ;
                    fflush ( stdin ) ;
                    another = getche() ;
                }
                break ;
            case '0' :
                fclose ( fp ) ;
                exit(0) ; 
        }
    }    
}