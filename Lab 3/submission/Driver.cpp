#include "Timer.h"
#include <iostream>
#include <fstream>
using namespace std;

struct wordCount{
	string word;
	int count;
};

void insertionSort(wordCount *wordArray, int numWords);
void bubbleSortReverse(wordCount *wordArray, int numWords);
void quicksort(wordCount *wordArray, int low, int high);
int partition(wordCount *wordArray, int left, int right);

int main()
{
	wordCount* wordArray = new wordCount[150000];
	int numWords = 0;
	string temp;
	int num;
	
	ofstream outfile;
	ifstream infile;

	time_t start, end;
	char filename[50];
	cout << "\nWhich file are you opening?\n";
	cin >> filename;
	infile.open(filename);
	
	if(!infile)
	{
		cout << "\nSorry, I couldn't find that file.\n";
		return 1;
	}

	while(getline(infile, temp) && numWords != 150000)
	{
		wordArray[numWords].word = temp;
		infile >> num;
		infile.ignore();
		wordArray[numWords].count = num;
		numWords++;
	}
	cout << "you've read in " << numWords << " words.\n";

	//sort the songs using insertion sort and print them out to the text file sortFileInsertion.txt
	start = getTime(); //Starts timer.   

	//LOOK!!!!  CALL THE INSERTION SORT ALGORITHM HERE
	insertionSort(wordArray, numWords);

	end = getTime(); //Ends timer.
	outfile.open("sortFileInsertion.txt");
	cout << "\nInsertion sort: " << totalTime(start, end) << " seconds\n\n";
	for(int x=0; x<numWords; x++)
	{
		outfile << wordArray[x].word << " : " << wordArray[x].count << endl;
	}
	outfile.close();

	//sort the songs in reverse order using bubble sort & print them out to the text file sortFileReverseBubble.txt
	start = getTime(); //Starts timer. 

	//LOOK!!!!  CALL THE REVERSE BUBBLE SORT ALGORITHM HERE
	bubbleSortReverse(wordArray, numWords);

	end = getTime(); //Ends timer.
	outfile.open("sortFileReverseBubble.txt");
	cout << "\nReverse bubble sort: " << totalTime(start, end) << " seconds\n\n";
	for(int x=0; x<numWords; x++)
	{
		outfile << wordArray[x].word << " : " << wordArray[x].count << endl;
	}
	outfile.close();

	//sort the songs with quick sort & print them out to sortFileQuick.txt
	start = getTime(); //Starts timer. 
	
	//LOOK!!!!  CALL THE QUICKSORT ALGORITHM HERE
	quicksort(wordArray, 0, numWords-1);

	end = getTime(); //Ends timer.
	cout << "\nQuicksort: " << totalTime(start, end) << " seconds\n\n";
	outfile.open("sortFileQuick.txt");
	for(int x=0; x<numWords; x++)
	{
		outfile << wordArray[x].word << " : " << wordArray[x].count << endl;
	}
	outfile.close();
	
	delete [] wordArray;
	return 0;
}

//LOOK!  WRITE YOUR INSERTION SORT FUNCTION HERE
void insertionSort(wordCount *wordArray, int numWords)
{
	for(int i=1; i<numWords; i++)
	{
		wordCount temp = wordArray[i];
		int j = i-1;
		while(j>=0 && temp.word < wordArray[j].word)
		{
			wordArray[j+1] = wordArray[j];
			j--;
		}
		wordArray[j+1] = temp;
	}
}



//LOOK!  WRITE YOUR REVERSE BUBBLE SORT FUNCTION HERE
void bubbleSortReverse(wordCount *wordArray, int numWords)
{
	//loop for numWords-1 
	for(int i=0; i<numWords-1; i++)
	{
		//check for each element to see if it's greater than the one in front.
		for(int j=0; j<numWords-i-1; j++)
		{
			if(wordArray[j].count < wordArray[j+1].count)
			{
				//create temp wordCount and swap if wodArray[j] is greater than wordArray[j+1]
				wordCount temp = wordArray[j];
				wordArray[j] = wordArray[j+1];
				wordArray[j+1] = temp;
			}
		}
	}
}





//LOOK!  WRITE YOUR RECURSIVE QUICK SORT FUNCTION HERE
void quicksort(wordCount *wordArray, int low, int high)
{
	if(low < high)
	{
		int pivot = partition(wordArray, low, high);
		quicksort(wordArray, low, pivot-1);
		quicksort(wordArray, pivot+1, high);
	}
}



//LOOK!  WRITE YOUR PARTITION FUNCTION HERE return pivot
int partition(wordCount* wordArray, int left, int right) {
    // Choose the right element as the pivot
    wordCount pivot = wordArray[right];
    wordCount temp;
    // Index of smaller element
    int i = left - 1;

    // Iterate through the array from left to right-1
    for (int j = left; j <= right - 1; j++) {
        // If current element is smaller than the pivot
        if (wordArray[j].count < pivot.count) {
            // Increment the smaller element index
            i++;
            // Swap wordArray[i] and wordArray[j]
            temp = wordArray[i];
			wordArray[i] = wordArray[j];
			wordArray[j] = temp;
        }
    }

    // Swap the pivot element with the element at the (i+1)th position
	temp = wordArray[i + 1];
	wordArray[i + 1] = wordArray[right];
	wordArray[right] = temp;


    // Return the partition index
    return i + 1;
}

