//Colour Denoted by a 7-bit Number as per VIBGYOR: 7-bit Manipulation
#include<stdio.h>
#include"showbits.h"
#define BV(x) (1<<x)
int main()
{
    unsigned char color; unsigned char input;
    printf("\nEnter the colour code: ");
    scanf("%d",&input);
    showbits(input);printf("\n");
    for(int i = 0; i < 7; i++)
    {
        if(input & BV(i))
        switch (i)
        {
            case 0:
                printf("Voilet ");
                break;
            case 1:
                printf("Indigo ");
                break;
            case 2:
                printf("Blue ");
                break;
            case 3:
                printf("Green ");
                break;
            case 4:
                printf("Yellow ");
                break;
            case 5:
                printf("Orange ");
                break;
            case 6:
                printf("Red ");
                break;
        }
    }
    printf("\n");
    return 0;
}