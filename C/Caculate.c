#include<stdio.h>
#include<stdlib.h>
int main()
{
    system("cls");
    
    int a = 22396+5500+350;
    int b = 11498+13249+4345+581;
    int c = 2000+1915+1228+450+99+99+189+179+130;
    printf("\n%d : Salary\n",22396);
    printf("%d : Cash\n\n",5500+350);
    printf("%d : MyPhone EMI\n",11498);
    printf("%d : NewPhone + Earphones Payment\n",13249+581);
    printf("%d : Credit Card - Unacademy Subscription + KFC\n",4345);
    printf("\nOthers :\n");
    printf("%d : Electricity Bill\n",2000);    
    printf("%d : BeardOil + AlarmClock\n",1915);
    printf("%d : Internet Bill\n",1228);
    printf("%d : Recharges\n",450+99+99);
    printf("%d : Subscriptions\n",189+179+130);
    printf("%d : Others Total\n",c);
    printf("\n%d : Available Balance\n",a);
    printf("%d : Required Balance\n",b+c);
    printf("%d : Negative\n",a-b-c);

    
    return 0;
}