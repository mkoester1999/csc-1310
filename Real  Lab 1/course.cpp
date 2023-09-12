/*
	Header for Course implementation
	LAB 1 - CSC1310
	Mitchell Koester

	8/31/23
*/

#include"course.h"

/*CreateCourse function
Created Course struct and assigns struct properties to parameters
parameters: string _coursename, string _location, int _numSections, int _creditHours
returns: Course*
 */
Course* CreateCourse(string _coursename, string _location, int _numSections, int _creditHours )
{
    //pointer that points to new Course struct
    Course* newCourse = new Course;

    //initialize Course properties to parameters
    newCourse->name = _coursename;
    newCourse->location = _location;
    newCourse->numSections = _numSections;
    newCourse->creditHours = _creditHours;

    //create pointer to array of strings lengh of numSections
    newCourse->sectionsPtr = new string[newCourse->numSections];

    //return address of newCourse
    return newCourse;

}

//destroyCourse function
//Destroys Course Struct
//Parameters: Course*
//Returns void
void destroyCourse(Course* newCourse)
{
    //delete sectionsPtr
    delete[] newCourse->sectionsPtr;
    //delete newCourse    
    delete newCourse;
}

//printCourse function
//Prints Course Struct
//Parameters: Course*
//Returns void
void printCourse(Course* newCourse)
{
    cout << "COURSE NAME:\t\t" << newCourse->name << endl;
    cout << "COURSE LOCATION:\t" << newCourse->location << endl;
    cout << "COURSE HOURS:\t\t" << newCourse->creditHours << endl;
    cout << "NUMBER OF SECTIONS:\t" << newCourse->numSections << endl;
    cout << "COURSE SECTIONS:\n";
    //print out values of the array sectionPtr points to
    for (int i = 0; i < newCourse->numSections; i++)
    {
        cout << "\t\t\t" << newCourse->sectionsPtr[i] << endl;
    }

    
}