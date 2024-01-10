#include<stdio.h>
#include<stdarg.h>
void func(int i, ...)
{
    va_list ptr;
    va_start(ptr, i);
    int n = va_arg(ptr, int);

    for(int count = 0; count < i; count++)
    {
        switch (n)
        {
            case 1: printf("\nPoint"); break;
            case 2: printf("\nLine"); break;
            case 3: printf("\nTriangle"); break;
            case 4: printf("\nQuadrilateral"); break;
            case 5: printf("\nPentagon"); break;
            case 6: printf("\nHexagon"); break;
            case 7: printf("\nHeptagon"); break;
            case 8: printf("\nOctagon"); break;
            case 9: printf("\nNonagon"); break;
            case 10: printf("\nDecagon"); break;
            default: printf("\nInvalid Input");
        }
        n = va_arg(ptr, int);
    }
}
int main()
{
    // int n; printf("\nEnter Number: "); scanf("%d", &n);
    // func(n); printf("\n");

    func(5, 1, 3, 5, 7, 9); printf("\n");

    return 0;
}