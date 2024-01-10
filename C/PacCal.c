#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>
#include"month.h"

int main()
{
    system("cls");
    printf("Initiating . . .\n");
    
    printf("\nBasic Pay : ");
    float basic;
    scanf("%f",&basic);printf("\n");
    
    do
    {
        fflush(stdin);
        
        printf("Increment (pcnt.) : ");
        float inc;
        scanf("%f",&inc);printf("\n");
        basic = (1 + (inc/100))*basic;
        int mon;
        float sum = 0;
        float salary;
        for(mon=1;mon<=12;mon++)
        {
            /*float hra = 0.5*basic; float bonus = 0.2*basic;
            float wbp = 0.415*basic; float pf = 0.154*basic;*/
            float ptpm = 492;/*PT & MEDPREM*/
            float varpay = 0.125*basic;

            if(mon==11 || mon==2 || mon==5 || mon==8)
            salary = (1.961*basic) + (3*varpay) - ptpm;
            else
            salary = (1.961*basic) - 492;
            /*printf("Salary for "); month(mon); printf(" : %f\n",salary);*/

            sum += salary;
        }
        
        printf("Salary : INR %f  approx",(1.961*basic)-492);
        printf("\nPackage : INR %f  approx\n\n",sum);

        basic = basic/(1 + (inc/100));
    
        if (getchar() != '\n')
        {fflush(stdin); printf("\nLoop terminated"); exit(1);}
    }while(1);    
    

    return 0;
}