#include<iostream>
#include<stdlib.h>
using namespace std;
int convert (const char *, int);
float convert (const char *, double);
int main()
{
    cout << convert("99.99", 0.1) << endl;
    cout << convert("99", 1) << endl;

    return 0;
}
int convert (const char *t, int i)
{
    return atoi(t);
}
float convert (const char *t, double i)
{
    return atof(t);
}