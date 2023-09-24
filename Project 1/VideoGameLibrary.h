/*
	Header for VideoGameLibrary class
	Project 1 - CSC1310
	Mitchell Koester & Bryant Koester
	9/25/23
*/

#ifndef _VideGameLibrary_h
#define _VideGameLibrary_h

#include "VideoGame.h"

using namespace std;

//create VideoGameLibrary class
class VideoGameLibrary
{
public:
    //constructor
    //parameter: int maxGamesSize
    VideoGameLibrary(int maxGamesSize);
    
    //destructor
    ~VideoGameLibrary();

    //resizeVideoGameArray function
    //parameter: int maxGamesSize
    //return: void
    void resizeVideoGameArray(int maxGamesSize);

    //addVideoGametoArray function
    //prompts for video game title, developer, publisher, and year, then adds to array
    //parameters: none
    //return: void
    void addVideoGameToArray();

    //displayVideoGames function
    //prints all video games in array   
    //parameters: none
    //returns: void
    void displayVideoGames();

    //displayVideoGameTitles function
    //prints all video game titles in array
    //parameters: none
    //returns: void
    void displayVideoGameTitles();

    //loadVideoGamesFromFile function
    //loads video games from file
    //parameters: char* fileName
    //returns: void
    void loadVideoGamesFromFile(char* fileName);

    //removeVideoGamesFromArray function
    //removes single video game from game library
    //parameters: none
    //returns: none
    void removeVideoGameFromArray();

    //saveToFile function
    //saves video games to file based on filename
    //parameters: char* fileName
    //returns: void
    void saveToFile(char* fileName);

private:
    VideoGame** videoGamesArray;
    int maxGames;
    int numGames;
    

};
#endif