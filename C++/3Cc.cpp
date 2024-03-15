#include<iostream>
using namespace std;

void display(char ch = '*', int num = 80)
{
    ;
    for(int i = 0; i < 3; i++)
    {
        switch (i)
        {
        case 0:
            for(int j = 0; j < 5; j++)
            cout << '*'; cout << endl;
            break;
        case 1:
            for(int j = 0; j < 10; j++)
            cout << '-'; cout << endl;
            break;
        case 2:
            for(int j = 0; j < 20; j++)
            cout << '='; cout << endl;
            break;
        }
    }
}

int main()
{
    display();

    return 0;
}