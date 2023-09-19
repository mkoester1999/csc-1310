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

    //displayVideogGames function
    //prints all video games in array
    //parameters: none
    //returns: void
    void displayVideogGames();

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

    //removeVideoGasmesFromArray function
    //removes single video game from game library
    //

private:
    VideoGame** videoGamesArray;
    int maxGames;
    int numGames;
    

};