#include<stdio.h>
#include<stdlib.h>
//DE-Queue
int main()
{
    system("cls");

    int size; printf("\n\nSize : "); scanf("%d",&size); char a[size]; for(int i = 0; i < size; i++)  a[i]='0';printf("\n");
    for(int i = 0; i < size; i++) printf("%c ", a[i]); printf("\n\n");
    int temp = 1; char tpin; printf("Retrieve Left >> 1 \nInsert Left >> 2 \nInsert Right >> 3 \nRetrieve Right >> 4 \n\n");
    while(temp < 5 && temp > 0)//First understand how the dequeue truly works
    {
        scanf("%d", &temp); if(temp == 2 || temp == 3) { fflush(stdin); scanf("%c", &tpin); }//scan for insertion at any end
        //while((getchar()) != '\n');fflush(stdin); // clear input buffer
        switch (temp)
        {
            case 1:
                //retrieve left
                for(int i = 0; i < size; i++)
                {
                    if(a[i] != '0') {a[i] = '0'; break;}//empty it if not empty
                    else if(i == size - 1 && a[i] == '0')printf("Empty\n");//if even last cell is empty print empty
                }
                for(int j = 0; j < size; j++) printf("%c ", a[j]); printf("\n");
                break;
            case 2:
                //insert left
                for(int i = 0; i < size; i++)
                {
                    if(a[i] == '0' && (a[i+1] != '0' || i == size - 1)) {a[i] = tpin; break;}//if ith cell is empty and (i+1th cell is not empty or it is the this is the last cell) then put the scanned value here
                    else if(i == 0 && a[i] != '0')//if zeroth cell is not empty
                    {
                        int sum = 0;
                        for(int p = 0; p < size; p++) if(a[p] == '0') sum += 1;
                        if(sum == size) printf("Full\n"); //if the whole DE-Queue is full then print full
                        else if(sum < size)printf("This end of DE-Queue is full, can't insert from this side\n");//if left part of it is not empty then nothing can be inserted from left                          
                    }
                }
                for(int j = 0; j < size; j++) printf("%c ", a[j]); printf("\n");
                break;
            case 3:
                //insert right
                for(int i = size - 1; i >= 0; i--)
                {
                    if(a[i] == '0' && (a[i-1] != '0' || i == 0)) {a[i] = tpin; break;}
                    else if(i == size - 1 && a[i] != '0')
                    {
                        int sum = 0;
                        for(int p = 0; p < size; p++) if(a[p] == '0') sum += 1;
                        if(sum == size) printf("Full\n"); 
                        else if(sum < size)printf("This end of DE Queue is full, can't insert from this side\n");                        
                    }
                }
                for(int j = 0; j < size; j++) printf("%c ", a[j]); printf("\n");
                break;
            case 4:
                //retrieve right
                for(int i = size - 1; i >= 0; i--)
                {
                    if(a[i] != '0') {a[i] = '0'; break;}
                    else if(i == 0 && a[i] == '0'){printf("Empty\n"); }
                }
                for(int j = 0; j < size; j++) printf("%c ", a[j]); printf("\n");
                break;
            default:
            printf("\nInvalid Input\n");
        }        
    }
    printf("\n");

    return 0;
}