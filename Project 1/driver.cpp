/*
	Header for Text Class
	Project 1 - CSC1310
	Mitchell Koester & Bryant Koester
	9/25/23
*/

#include <fstream>
#include<iostream>
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
    do{
    //create a 6 case switch statement that will allow the user to choose from the following options:
    //1:Load game from file
    //2:Save video game to file
    //3:add video game to library
    //4:remove a video game from library
    //5:display all video games
    //6:remove all video games from library and end program using do while set to a boolean variable

    switch(choice)
    {
                    case 1:
                        //Load game from file
                        
                        break;
                    case 2:
                        //Save video game to file
                        break;
                    case 3:
                        //add video game to library
                        break;
                    case 4:
                        //remove a video game from library
                        break;
                    case 5:
                        //display all video games
                        break;
                    case 6:
                        //remove all video games from library and end program using do while set to a boolean variable
                        endProgram = true;//exit condition for do while loop
                        break;
    }    
    }while (endProgram == false);
    return 0;
}