#include <stdio.h>
int main()
{
    float speed;
    printf("\nEnter Speed : ");
    scanf("%f",&speed);
    
    int category;

    if(speed >= 74 && speed <= 95) category = 1;
    else if(speed >= 96 && speed <= 110) category = 2;
    else if(speed >= 111 && speed <=130) category = 3;
    else if(speed >= 131 && speed <= 155) category = 4;
    else if(speed > 155) category = 5;

    printf("Hurricane Category : %d\n",category);

    return 0;
}