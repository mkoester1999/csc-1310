#include <fstream>
#include<iostream>
#include "VideoGame.h"

using namespace std;

int main()
{

    //declare videogame object with parameters for Text class
    VideoGame* videogame = new VideoGame(new Text("The Legend of Zelda"), new Text("Nintendo"), new Text("Nintendo"), 1986);
    videogame->PrintVideoGameDetails();
    fstream file;

    file.open("videogame.txt", ios::out);
    videogame->PrintVideoGameDetailsToFile(file);
    file.close();

    Text* text;

    text = videogame->getVideoGameTitle();
    text->displayText();

    //delete text;
    delete videogame;
    delete text;
    
}