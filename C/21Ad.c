//Animal Type : 5-bit Manipulation
#include<stdio.h>
#define BV(x) (1<<x)
int main()
{
    struct animal
    {
        char name[30];
        int type;
    };
    struct animal a = {"OCELOT", 18};
    printf("\n");
    printf("%s: ",a.name);
    if(BV(0) & a.type) printf("Canine ");
    else if(BV(1) & a.type) printf("Feline ");
    else if(BV(2) & a.type) printf("Cetacean ");
    else if(BV(3) & a.type) printf("Marsupial ");
    
    if(BV(4) & a.type) printf("Carnivore");
    else printf("Herbivore");
    printf("\n");
    return 0;
}