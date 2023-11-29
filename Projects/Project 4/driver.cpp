/* File: driver.cpp
   Authors: Mitchell & Bryant Koester
   Due Date: 11/30/2023
   Program: Program 4 - Markov Chains
*/

#include<iostream>
//#include "markovMat.h"
#include "markovList.h"
using namespace std;

int main()
{
	//markovMat* chain = new markovMat("corpus.txt");
	markovList* chain = new markovList("corpus.txt");
	
	cout << chain->generate(100) << endl;
	return 0;
}