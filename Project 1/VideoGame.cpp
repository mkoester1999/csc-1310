#include "VideoGame.h"

VideoGame::VideoGame(Text* videoGameTitle, Text* gameDeveloper, Text* gamePublisher, int gameYear)
{
    title = videoGameTitle;
    developer = gameDeveloper;
    publisher = gamePublisher;
    year = gameYear;
}

VideoGame::~VideoGame()
{
    delete title;
    delete developer;
    delete publisher;
}

void VideoGame::PrintVideoGameDetails()
{
    cout<<"Title: ";
    title->displayText();
    cout<<"Developer: ";
    developer->displayText();
    cout<<"Publisher: ";
    publisher->displayText();
    cout<<"Year: ";
    cout<<year<<endl;
    
}