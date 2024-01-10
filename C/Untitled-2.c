#include<stdio.h>
#include<stdarg.h>
enum status
{
    open, closed, pending
};
enum status s;  //declaration
enum marks
{
    correct = 4,
    partially_correct = 2,
    partially_incorrect = -1,
    partially_correct_partially_incorrect = 0,
    incorrect = -2
};

typedef unsigned long int REASON;
REASON k;

union value
{
    short int i;
    char ch[2];
};

typedef struct details
{
    char name[20];
    int age;
}info;
info people[5];

typedef struct employee
{
    unsigned gender : 1;            //male female
    unsigned marital_status : 3;    //single married divorced widowed
    unsigned hobby : 2;             //one of eight different hobbies
    unsigned scheme : 4;            //can choose from 15 schemes to pursue the hobby
}emp;

void showbits(unsigned char n)
{
    unsigned char i, k, andmask;
    for(i = 7; i >= 0; i--)
    {
        andmask = 1<<i;
        k = n & andmask;
        k == 0 ? printf("0") : printf("1");
    }
}

void display()
{
    printf("In the function\n");
}

int findmax(int tot_num, ...)
{
    int max, count, num;

    va_list ptr;
    va_start(ptr, tot_num);
    max = va_arg(ptr, int);

    for(count = 1; count < tot_num; count++)
    {
        num = va_arg(ptr, int);
        if(num > max)
            max = num;
    }

    return (max);
}

struct empinfo
{
    char name[20];
    char grade[4];
    int age;
    char hobby[10];
    int creditcardno;
    char vehicleno[10];
    int dist;
};
struct empinfo e;

struct info1
{
    char hobby[10];
    int creditcardno;
};
struct info2
{
    char vehicleno[10];
    int dist;
};
union info
{
    struct info1 a;
    struct info2 b;
};
struct employeee
{
    char name[20];
    char grade[4];
    int age;
    union info f;
};
struct employeee em;



int main()
{
    void (*fn_ptr)();
    fn_ptr = display;                   //assign address of function
    printf("Fn Address: %u\n", fn_ptr);   //name of function could also be used directly
    (*fn_ptr)();                        //invokes the function
    int max = findmax(3, 100, 300, 29);

    union value key;
    key.i = max;
}