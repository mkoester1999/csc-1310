/*
	Header for Course Structure
	LAB 1 - CSC1310
	Mitchell Koester

	1/10/2019
*/

#ifndef Course_h
#define course_h
#include<iostream>

using namespace std;
//Structure Course
//Holds values for the Course
struct Course
{

    string name;
    string location; 
    string** sectionsPtr;    
    int numSections;
    int creditHours;
    

};

/*CreateCourse function
Creates Course struct
parameters: String course name, String location, int numSections, int creditHours
Returns Course pointer*/
Course * CreateCourse(string, string, int, int);


/*DestroyCourse Function
Destroys Course Struct
Parameters: Course*
Returns void*/
void DestroyCourse(Course* MyCourse);

void PrintCourse(Course* MyCourse);

#endif
