#include <iostream>
#include<string>

using namespace std;

int main()
{
    int a, b, *p;

    a = b = 7;
    p = &a;

    *p = 3;

    p = &b;
    *p = 2 * *p - a;
    cout <<*p<<endl;


}