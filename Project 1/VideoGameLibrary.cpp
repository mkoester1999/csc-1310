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
    cin.ignore();
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

void VideoGameLibrary::displayVideoGames()
{
    //iterate through array and call printvideogamedetails function
    for(int i = 0; i < numGames; i++)
    {
        videoGamesArray[i]->PrintVideoGameDetails();
    }
}


void VideoGameLibrary::displayVideoGameTitles()
{
    //iterate through array and call getvideogametitle function
    for(int i = 0; i < numGames; i++)
    {
        videoGamesArray[i]->getVideoGameTitle()->displayText();
    }
}


void VideoGameLibrary::loadVideoGamesFromFile(char* gamesFile)
{
    //create file stream
    fstream file;
    //open file
    file.open(gamesFile, ios::in);
    //check if file is open
    if(file.is_open())
    {
        //create temp variables
        char* title = new char[100];
        char* developer = new char[100];
        char* publisher = new char[100];
        int year;

        //while loop to read in data
        while(!file.eof())
        {
            //read in title
            file.getline(title, 100);
            //create text object with title as parameter
            Text* gameTitle = new Text(title);

            //read in developer
            file.getline(developer, 100);
            //create text object with developer as parameter
            Text* gameDeveloper = new Text(developer);

            //read in publisher
            file.getline(publisher, 100);
            //create text object with publisher as parameter
            Text* gamePublisher = new Text(publisher);

            //read in year
            file>>year;
            file.ignore();

            //create video game object with parameters we got from file
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
        //close file
        file.close();
    }
    else
    {
        cout<<"File failed to open."<<endl;
    }
}

void VideoGameLibrary::removeVideoGameFromArray()
{
    //check if numVideoGames > 1
    if (numGames > 1)
    {
        //display all video game titles
        displayVideoGameTitles();
        int section;
        do
        {
            //request for number between 1 and numGames
            cout<<"Please enter a number between 1 and " <<numGames << " : ";
            cin.clear();
            cin.ignore();
            cin>>section;

        }while(cin.fail());
        cin.ignore();

        //delete video game at position - 1 (because it's starting at 1)
        cout<<"Deleting " << videoGamesArray[section-1] <<endl;
        delete videoGamesArray[section-1];
        
    }
    //added edgecases
    else if (numGames == 1)
    {
        //delete video game at position 0
        cout<<"Deleting " << videoGamesArray[0] <<endl;
        delete videoGamesArray[0];
    }
    else
    {
        cout<<"No video games to delete."<<endl;
    }
}

void VideoGameLibrary::saveToFile(char* fileName)
{
    //create file stream
    fstream file;
    //open file
    cout <<"Attempting to Open File...\n";
    file.open(fileName, ios::out);
    //check if file is open
    if(file.is_open())
    {   
        cout <<"File Opened Successfully!\n";
        //iterate through array and call printvideogamedetailstofile function
        for(int i = 0; i < numGames; i++)
        {
            videoGamesArray[i]->PrintVideoGameDetailsToFile(file);
        }
        //close file
        cout <<"File Saved Successfully!\nClosing File...\n";
        file.close();
    }
    else
    {
        cout<<"File failed to open."<<endl;
    }
}
