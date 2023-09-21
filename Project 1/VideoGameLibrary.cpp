#include"VideoGameLibrary.h"

using namespace std;

VideoGameLibrary::VideoGameLibrary(int maxGamesSize)
{
    videoGamesArray = new VideoGame*[maxGamesSize];
    maxGames = maxGamesSize;
    numGames = 0;
}

VideoGameLibrary::~VideoGameLibrary()
{
    delete[] videoGamesArray;
}

void VideoGameLibrary::resizeVideoGameArray(int maxGamesSize)
{
    //create new videogamesarray pointer
    VideoGame** newVideoGamesArray = new VideoGame*[maxGamesSize];
    
    //copy from old array to new array through iteration
    for(int i = 0; i < maxGames; i++)
    {
        newVideoGamesArray[i] = videoGamesArray[i];
    }

    //delete old videoGames array
    delete[] videoGamesArray;

    //set videoGamesArray to newVideoGamesArray
    videoGamesArray = newVideoGamesArray;

    //set size to new size
    maxGames = maxGamesSize;
}

void VideoGameLibrary::addVideoGameToArray()
{
    //ask for video game title as char pointer
    char* title = new char[100];
    cout<<"Enter video game title: ";
    cin.getline(title, 100);
    //create text object with title as parameter
    Text* gameTitle = new Text(title);
    delete[] title;

    //ask for video game developer as char pointer
    char* developer = new char[100];
    cout<<"Enter video game developer: ";
    cin.getline(developer, 100);
    //create text object with developer as parameter
    Text* gameDeveloper = new Text(developer);
    delete[] developer;

    //ask for video game publisher as char pointer
    char* publisher = new char[100];
    cout<<"Enter video game publisher: ";
    cin.getline(publisher, 100);
    //create text object with publisher as parameter
    Text* gamePublisher = new Text(publisher);
    delete[] publisher;

    //ask for video game year
    int year;
    

    //while loop to check if year is valid
    do
    {
        cout<<"Enter video game year. Must be a valid integer: ";
        cin.clear();
        cin.ignore();
        cin>>year;
    }while(cin.fail());
    cin.ignore();

    //create video game object with parameters we got from cin
    VideoGame* newVideoGame = new VideoGame(gameTitle, gameDeveloper, gamePublisher, year);

    //add video game to array if there is room. If not, resize array with double max size
    if(numGames < maxGames)
    {
        videoGamesArray[numGames] = newVideoGame;
        numGames++;
    }
    else
    {
        resizeVideoGameArray(maxGames*2);
        videoGamesArray[numGames] = newVideoGame;
        numGames++;
    }


}