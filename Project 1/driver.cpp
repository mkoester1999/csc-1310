/*
	Header for Text Class
	Project 1 - CSC1310
	Mitchell Koester & Bryant Koester
	9/25/23
*/

#include <fstream>
#include <iostream>
#include "VideoGame.h"
#include "VideoGameLibrary.h"

using namespace std;

int main()
{   //program asks the user “How many video games can your library hold?” Once it reads in this number, it 
    //should dynamically allocate a VideoGameLibrary object, sending this number as an argument.
    int maxGamesSize; //max number of games the library can hold
    int choice; //user input for menu
    bool endProgram = false; //exit condition for do while loop
    
    cout<<"How many video games can your library hold?"<<endl;
    cin>>maxGamesSize;
    VideoGameLibrary* videogameLibrary = new VideoGameLibrary(maxGamesSize);

    //create a 6 case switch statement that will allow the user to choose from the following options:
    //1:Load games from file
    //2:Save video game to file
    //3:add video game to library
    //4:remove a video game from library
    //5:display all video games
    //6:remove all video games from library and end program using do while set to a boolean variable
    do{
    cout << "What would you like to do?" << endl;
    cout << "1. Load video games from file." << endl;
    cout << "2. Save video games to a file." << endl;
    cout << "3. Add a video game." << endl;
    cout << "4. Remove a video game." << endl;
    cout << "5. Display all video games." << endl;
    cout << "6. Remove ALL video games from this library and end program." << endl;
    cout <<"CHOOSE 1-6: ";
    cin >> choice;
    //input validation 
    while (choice < 1 || choice > 6)
    {
        cout << "Invalid input. Please enter a number between 1 and 6: ";
        cin >> choice;
    }

    char* fileName = new char[100]; //initalize to avoid loading errors
    switch(choice)
    {
                    case 1:
                        //Load game from file
                        //If the user chooses to load a video game from a file, ask the name of the file and call the VideoGameLibrary’s 
                        //loadVideo gamesFromFile function, sending the filename as a string
                        cout<<"Enter the name of the file you would like to load from: "<<endl;
                        cin.ignore();
                        cin.getline(fileName, 100);
                        videogameLibrary->loadVideoGamesFromFile(fileName);
                        cout << "Video games loaded from file." << endl;
                        break;

                    case 2:
                        /*Save video game to file If the user chooses to save video games to a file, then ask the name of the file and call the VideoGameLibrary’s 
                        saveToFile function, sending the filename as a string.*/
                        cout<<"Enter the name of the file you would like to save to: "<<endl;
                        cin.ignore();
                        cin.getline(fileName, 100);
                        videogameLibrary->saveToFile(fileName);
                        cout << "Video games saved to file." << endl;
                        break;
                    
                    case 3:
                        //add video game to library, If the user chooses to add a video game, call the VideoGameLibrary’s addVideoGameToArray function.
                        videogameLibrary->addVideoGameToArray();
                        break;

                    case 4:
                        //remove a video game from library, If the user chooses to remove a video game, call the VideoGameLibrary’s removeVideoGameFromArray function.
                        videogameLibrary->removeVideoGameFromArray();
                        break;

                    case 5:
                        //display all video games, If the user chooses to display all video games, call the VideoGameLibrary’s displayVideoGames function.
                        videogameLibrary->displayVideoGames();
                        break;

                    case 6:
                        //remove all video games from library and end program using do while set to a boolean variable
                        cout << "Deleting video game library...Goodbye!" << endl;
                        delete videogameLibrary;
                        endProgram = true;//exit condition for do while loop
                        break;
    }    
    }while (endProgram == false); //exit condition
    return 0;
}