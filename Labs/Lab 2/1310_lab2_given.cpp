/*
	Title:  Lab2.cpp
	Author: Mitchell
	Date:  TODAY'S DATE HERE!!!
	Purpose:  Demonstrate your knowledge of recursive functions
*/

#include <iostream>
#include <cstdlib>
#include <cctype>
#include <ctime>
using namespace std;

//function prototypes for the recursive functions
int sumOfNumbers(int);
bool isMember(int*, int, int);
void stringReverser(string, int);
bool isPalindrome(string);
int multiply(int, int);

const int ARRAY_SIZE = 10;

int main()
{
	int choice, num, num1, num2;
	int myArray[ARRAY_SIZE];
	srand(time(NULL));
	string userString, userStrModified;
	
	do{
		
		cout << "\n\nWhat do you want to do?\n";
		cout << "\t1.  Sum of Numbers\n";
		cout << "\t2.  IsMember Array Function\n";
		cout << "\t3.  String Reverser\n";
		cout << "\t4.  Palindrome Detector\n";
		cout << "\t5.  Recursive Multiplication\n";
		cout << "\t6.  End the Program\n";
		cout << "CHOOSE 1-6:  ";
		cin >> choice;
		while(choice < 1 || choice > 6)
		{
			cout << "\nInvalid input!  CHOOSE 1-6:  ";
			cin >> choice;
		}
		switch(choice)
		{
			case 1:
				cout << "\n\nSUM OF NUMBERS\n";
				cout << "Enter an integer:  ";
				cin >> num;
				//print out the result of the sumOfNumbers function here
				cout << sumOfNumbers(num);
				break;
				
				
			case 2:
				for(int x=0; x<ARRAY_SIZE; x++)
				{
					myArray[x] = (rand()%100)+1;
				}
				cout << "\n\nISMEMBER ARRAY FUNCTION\n";
				cout << "Enter an integer:  ";
				cin >> num;
				cout << "\nHere are the array values:  ";
				for(int x=0; x<ARRAY_SIZE; x++)
				{
					cout << myArray[x] << " ";
				}
				//print if the value that the user entered is in the array or not here
				if(isMember(myArray, ARRAY_SIZE, num))
				{
					cout << "Yes, "<< num << " is in the array.\n";
				}
				else
				{
					cout << "No! " << num << " is NOT in the array.\n";
				}
				
				
				break;
				
				
			case 3:
				cout << "\n\nSTRING REVERSER\n";
				cout << "Enter a string and I will reverse it:  ";
				cin.ignore();
				getline(cin, userString);
				//call string reverser function here
				stringReverser(userString, userString.size());
				
				break;
				
				
			case 4:
				cout << "\n\nPALINDROME DETECTOR\n";
				cout << "Enter a string and I will tell you if it is a palindrome:  ";
				cin.ignore();
				getline(cin, userString);
				
				//change string to be all uppercase
				for(int x=0; x<userString.length(); x++)
				{
					userString[x] = toupper(userString[x]);
				}
				
				//remove spaces and commas from string
				userStrModified = userString;
				for(int x=0; x<userStrModified.size(); x++)
				{
					if(userStrModified[x] == ' ') 
					{
						userStrModified.erase(x, 1);
					}
					if(userStrModified[x] == ',') 
					{
						userStrModified.erase(x, 1);
					}
				}
				
				//print out whether the user's string is a palindrome or not here.
				//when you print out the user's string, print out the uppercase version that doesn't have the spaces removed.
				if(isPalindrome(userStrModified))
				{
					cout << "Yes, " << userString << " is a palindrome.\n";
				}
				else
				{
					cout << "No, " << userString << " is NOT a palindrome.\n";
				}
				break;
				
				
			case 5:
				cout << "\n\nRECURSIVE MULTIPLICATION\n";
				cout << "Enter in the first integer:  ";
				cin >> num1;
				cout << "\nEnter in the second integer:  ";
				cin >> num2;
				//print out the value returned from the multiply function here
				cout << multiply(num1, num2);
				break;
				
		}		
	}while(choice != 6);
	
	cout << "\n\nGOODBYE!\n\n";
	return 0;
}


//implement the five recursive functions below!!!!


//sumOfNumbers function
//takes in an integer n and returns the sum of the numbers from 0 to n
//parameters: int n
//returns int
int sumOfNumbers(int num)
{
	if (num == 0) return 0;

	else
	{
		return (num + sumOfNumbers(num-1));
	}
}


bool isMember(int array[], int size, int value)
{
	//recursively search the array for the value

	//if at the end of the array, return false
	if (size == 0) return false;

	else
	 {
		//if the value is found, return true
		if(array[size] == value) return true;
		//else recursively search the rest of the array
		else return isMember(array, size-1, value);
	 }
}

//stringReverser function
//takes in a string and prints out reverse of string
//parameters: string str, int size
//returns void
void stringReverser(string str, int size)
{
	//recursively print out reverse of the string
    if (size == 0) return;
    
    else
    {
        cout << str[size-1];
        stringReverser(str, size-1);
        
    }
}

//isPalindrome function
//takes in a string and returns true if the string is a palindrome
//parameters: string str
//returns bool
bool isPalindrome(string str)
{
	//base case. If reached the end of the string, return true
	if (str.length() == 0) return true;
    
    //if not at end, check if the first and last characters are the same
	else if (str[0] != str[str.length()-1]) 
        return false;
    
    //return isPalindrome with the rest of the string
	else return isPalindrome(str.substr(1, str.length()-2));
}

int multiply(int num1, int num2)
{
	//base case
	if(num2 == 0) return 0;

	//else return num1 + multiply of num1 and num2-1
	else return (multiply(num1, num2-1) + num1);
}