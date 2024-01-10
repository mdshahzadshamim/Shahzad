void showbits(unsigned char n)
{
    int i;
    unsigned char j, k, andmask;
    for(i = 7; i >= 0; i--)
    {
        andmask = 1<<i;
        k = n & andmask;
        k == 0 ? printf("0 ") : printf("1 ");
    }
}