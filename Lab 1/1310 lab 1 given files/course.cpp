#include"course.h"

Course* CreateCourse(string _coursename, string _location, int _numSections, int _creditHours )
{
    Course* myCourse = new Course;
    myCourse->name = _coursename;
    myCourse->location = _location;
    myCourse->numSections = _numSections;
    myCourse->_creditHours = _creditHours;

    //create pointer to array of strings lengh of numSections
    myCourse->sectionsPtr = new string*[myCourse->numSections];
}


void DestroyCourse(Course* myCourse){
    delete myCoursecourse->sections;
    delete myCourse;
}