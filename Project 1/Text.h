/*
	Header for Text Class
	Project 1 - CSC1310
	Mitchell Koester

	9/25/23
*/

#ifndef text_h
#define text_h
#include<iostream>

using namespace std;


//create text class
class Text
{
public:
    //text constructor
    //parameters: const char* text
    Text(const char* text);
    
    //text destructor
    ~Text();

    //displayText function
    //print textArray to the screen
    //parameters: none
    //returns: void
    void displayText();


    //getText function
    //returns pointer to textArray
    //parameters: none
    //returns: const char*
    const char* getText();

    //getLength function
    //returns length of textArray
    //parameters: none
    //returns: int
    int getLength();
private:
    const char* textArray;
    int textLength;
};





#endif