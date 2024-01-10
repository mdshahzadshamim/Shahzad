/*Low-level File-Copy Program that copies text, .com and .exe files*/

#include<fcntl.h>
#include<sys\\types.h> /* if present in sys directory use "c:tc\\include\\sys\\types.h" */
#include <sys\\stat.h> /* if present in sys directory use "c:\\tc\\include\\sys\\stat.h" */
#include<stdlib.h>
#include<stdio.h>
int main()
{  
    char buffer[512], source[128], target[128];
    int inhandle, outhandle, bytes;
    printf("\nEnter source file name : "); gets(source);
    inhandle = open ( source, O_RDONLY | O_BINARY ) ;
    if(inhandle == -1) { puts("\nCannot open file\n"); exit(1); }
    printf("\nEnter target file name : "); gets(target);
    outhandle = open ( target, O_CREAT | O_BINARY | O_WRONLY, S_IWRITE );
    if(outhandle == -1) { puts("\nCannot open file\n"); close(inhandle); exit(2); }
    while(1)
    {
        bytes = read(inhandle, buffer, 512);
        if(bytes > 0) write(outhandle, buffer, bytes);
        else break;
    }
    close(inhandle); close(outhandle); printf("\nDone\n");
    return 0;
}

/*FILE COPY PROGRAM
#include<stdio.h>
#include<stdlib.h>
int main()
{
    FILE *fs, *ft;
    char ch;
    fs = fopen("Source.txt","r");
    if(fs == NULL)
    {
        puts("Error\n");
        exit(1);
    }
    ft = fopen("Target.txt","w");
    if(ft == NULL)
    {
        puts("Error\n");
        exit(2);
    }
    while(1)
    {
        ch = fgetc(fs);

        if(ch == EOF)
            break;
        else
            fputc(ch,ft);
    }
    fclose(fs);
    fclose(ft);
    printf("Done\n");
    return 0;
}*/