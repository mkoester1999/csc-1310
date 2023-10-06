/*
	Implementation for Text Class
	Project 1 - CSC1310
	Mitchell Koester & Bryant Koester

	9/25/23
*/

#include "Text.h"


Text::Text(const char* text)
{
    //dynamically allocate new text array to be a char array with the length of text +1
    char* newText = new char[strlen(text) + 1];

    //copy string from text to newText
    strcpy(newText, text);

    //point textArray to newText
    textArray = newText;
    
    textLength = strlen(textArray);
    //don't know if I need this
}

Text::~Text()
{
    delete[] textArray;
    cout<<"Text destructor: Released memory for textArray"<<endl;
}

void Text::displayText()
{
    //print textArray
    cout<<textArray<<endl;
}

const char* Text::getText()
{
    return textArray;
}

int Text::getLength()
{
    return strlen(textArray);
}
