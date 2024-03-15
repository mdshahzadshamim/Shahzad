#include<iostream>
#include<string.h>
#include<stdlib.h>
using namespace std;
char * convert (int);
char * convert (double);
int main()
{
    char *result;
    result = convert(99.99);
    cout << result << endl;
    result = convert(100);
    cout << result << endl;

    return 0;
}
char * convert (int i)
{
    char* temp = (char*)malloc(10*sizeof(char));
    sprintf(temp, "%d", i);
    return temp;
}
char * convert (double i)
{
    char * temp = (char*)malloc(10*sizeof(char));
    sprintf(temp, "%f", i);
    return temp;
}