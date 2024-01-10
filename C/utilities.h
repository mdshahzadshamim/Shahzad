void xputs(char a[100])
{
    for(int i = 0; i < 50; i++)
    {
        printf("%c",a[i]);
        if(a[i] == '\0') break;
    }
}