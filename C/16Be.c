#include<stdio.h>
#include<stdlib.h>
#include<string.h>
/*CREATE A DATABASE*/
#define N 100
int main()
{
    system("cls");

    /*
    A factory has 3 divisions and stocks 4 categories of products.
    An inventory table is updated for each division and for each product as they are received.
    There are three independent suppliers of products to the factory.
    
    1. Design a data format to represent each transaction
    2. Write a program to take a transaction and update the inventory
    3. If the cost per item is also given write a program to calculate the total inventory values
    */
    
    /*1.*/
    static float f[3][3][4][2]; /*Factory → Supplier → Division → Product → Count, Cost per item */
    int sup[N], div[N], prod[N], i = 0, inv = 0;
    float count[N], val_per_item[N];
    static int valid[N];
    
    char repeat[5] = "Yes";

    printf("\n\nFACTORY\n\n");
    
    /*2.*/
    while(strcmp(repeat,"No"))
    {
        printf("Supplier(0/1/2) : "); scanf("%d",&sup[i]);
        printf("Division(0/1/2) : "); scanf("%d",&div[i]);
        printf("Product(0/1/2/3) : "); scanf("%d",&prod[i]);
        printf("Count(real) : "); scanf("%f",&count[i]);
        printf("Value per item(real) : "); scanf("%f",&val_per_item[i]);

        /*               Supplier                      Division                         Product                   Count                Rate            */
        valid[i] = ( (sup[i] >= 0 && sup[i] < 3) && (div[i] >= 0 && div[i] < 3) && (prod[i] >= 0 && prod[i] < 4) && (count[i] > 0) && (val_per_item[i] > 0) );

        if(!valid[i])
        {
            printf("\nInvalid Input\n\n");
            i++;
            continue;
        }
        
        f [sup[i]] [div[i]] [prod[i]] [0] += count[i];
        f [sup[i]] [div[i]] [prod[i]] [1] += val_per_item[i];

        i++;

        fflush(stdin);
        printf("\nRepeat? . . . ");
        gets(repeat);printf("\n");
    }

    /*3.*/
    float value = 0.0;
    for(int s = 0; s < 3; s++)
    for(int d = 0; d < 3; d++)
    for(int p = 0; p < 4; p++)
    value += f[s][d][p][0] * f[s][d][p][1];

    printf("\n");
    printf("Tran\tSupp\tDiv\tProd\tCount\t\tRate\t\tValid?\n\n");
    for(int c = 0; c < i + inv; c++)
    {
        printf("%d\t%d\t%d\t%d\t%f\t%f\t",c,sup[c],div[c],prod[c],count[c],val_per_item[c]);
        if(valid[c] == 0) printf("Invalid\n");
        else if(valid[c]) printf("Valid\n");
    }
    printf("\n");

    printf("Total Value : %f\n\n",value);
    
    return 0;
}