/*
	Driver for Program
	Project 2 - CSC1310
	Mitchell Koester & Bryant Koester

	10/13/23
*/

#include<fstream>
#include<iostream>
#include<string>
#include<sstream>
#include "County.h"
#include "List.h"

using namespace std;

int main()
{
	ifstream file;
	stringstream temp;
	string line, county, state;
	int index, pop;
	//file.open("counties_list.csv", ios::in);
	file.open("counties_ten.csv", ios::in);

	//create a new list of county pointers ------------------------------------------------------------------

	County* newCounty;
	
	List<County>* countyList = new List<County>();
	
	if(file.good()) {
	while(getline(file, line, ','))
	{
		temp.clear();
		temp.str(line);
		temp >> index;

		getline(file, line, ',');
		county = line;

		getline(file, line, ',');
		state = line;

		getline(file, line, '\n');
		temp.clear();
		temp.str(line);
		temp >> pop;

		newCounty = new County(index, county, state, pop);
		//append newCounty to your list-----------------------------------------------------------------------------------
		countyList->append(*newCounty);//pntr made error go away?
	}}

	file.close();

	//call mergesort---------------------------------------------------------------------------------------------
	countyList->mergesort();
	//print the list-----------------------------------------------------------------------------------------------------
	countyList->print();
	return 0;
}