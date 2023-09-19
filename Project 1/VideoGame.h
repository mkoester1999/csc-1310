#include "Text.h"
#include <fstream>

//create VideoGame class
class VideoGame
{
public:
    //constructor
    //parameters: Text* videoGameTitle, Text* gameDeveloper, Text* gamePublisher, int gameYear
    VideoGame(Text* videoGameTitle, Text* gameDeveloper, Text* gamePublisher, int gameYear);

    //destructor
    ~VideoGame();

    //PrintVideoGameDetails function
    //Print the title, developer, publisher, & year
    //parameters: none
    //returns: void
    void PrintVideoGameDetails();

    //PrintVideoGameDetailsToFile function
    //Print the title, developer, publisher, & year to a file
    //parameters: file stream by reference
    //returns: void
    void PrintVideoGameDetailsToFile(fstream& file);

    //getVideoGameTitle function
    //returns pointer to videoGameTitle
    //parameters: none
    //returns: Text*
    Text* getVideoGameTitle();

private:
    Text* title;
    Text* developer;
    Text* publisher;
    int year; 
};