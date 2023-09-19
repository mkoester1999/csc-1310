#include<iostream>
#include "Text.h"

using namespace std;

int main()
{

    Text text("test");

    text.displayText();
    cout<<text.getLength()<<endl;
    return 0;
}