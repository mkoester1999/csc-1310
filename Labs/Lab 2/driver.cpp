#include<iostream>
#include<string>
using namespace std;



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

int main()
{  
    //initializae an integer array
    int myArray[] = {1, 2, 3, 4, 5, 6};

    
    cout << multiply(2,4) <<endl;    
    return 0;

    
}


