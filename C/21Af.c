#include<stdio.h>
#include"showbits16.h"
#define BV(x) (1<<x)
typedef unsigned short int small;

int main()
{
    int data[] = {273, 548, 786, 1096};

    // printf("\n");
    // for(int j = 0; j < 4; j++)
    // {showbits16(data[j]);    printf("\n");}

    printf("Enter Room Number: "); int room_no, temp = 0;; scanf("%d",&room_no);

    for(int j = 0; j < 4; j++)
    {
        int num = 0;
        for(int i = 8; i < 16; i++)
        {
            if(data[j] & BV(i))
            switch (i)
            {
                case 8: num += 1; break;
                case 9: num += 2; break;
                case 10: num += 4; break;
                case 11: num += 8; break;
                case 12: num += 16; break;
                case 13: num += 32; break;
                case 14: num += 64; break;
                case 15: num += 128; break;
            }
        }
        if(room_no == num)
        {
            temp++;
            printf("Room No: %d\t",num);
            for(int i = 0; i < 8; i++)
            {
                if(data[j] & BV(i))
                {
                if(i < 4)
                    switch (i)
                    {
                        case 0: printf("1st Year\t"); break;
                        case 1: printf("3nd Year\t"); break;
                        case 2: printf("3rd Year\t"); break;
                        case 3: printf("4th Year\t"); break;
                    }
                else
                    switch (i)
                    {
                        case 4: printf("Mechanical");     break;
                        case 5: printf("Chemical");       break;
                        case 6: printf("Electronics");    break;
                        case 7: printf("Info. Tech.");    break;
                    }
                }
            }
        }
    }
    if(temp == 0)
    printf("Data Not Found");

    return 0;
}