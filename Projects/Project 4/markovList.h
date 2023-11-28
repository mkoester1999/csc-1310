#ifndef MARKOVLIST_H
#define MARKOVLIST_H

#include<map>
#include<fstream>
#include<sstream>
#include<iostream>
#include<stdlib.h>
using namespace std;

class markovList
{
	private:
		struct edge
		{
			string word;
			float weight;
			edge* next;
		};

		map<string, edge*> corpus;
		int corpusSize;	
	public:
		markovList(const char*);
		~markovList();
		
		string generate(int);
};

markovList::markovList(const char* filename)
{
	corpusSize = 0;
	ifstream file(filename);
	stringstream parser, splitter;
	string line, index, word;
	float weight;
	edge* newEdge;
	int i = 0;
	srand (time(0));
	
	if(file.good()) {
	file >> corpusSize;
	file.ignore(1, '\n');
	
	while(getline(file, line, '\n')) //map every word to a position in the matrix, keep the line in an array of buffers for later
	{
		parser.clear();
		parser << line;
		getline(parser, index,',');	//pulls the first word of the line, which is the node for which we're making a list of neighbors
		//initialize an empty list at the index---
		edge* currentEdge = nullptr;
		while(getline(parser, word, ','))
		{
			//allocate a new node in the edge list---
			splitter.clear();
			splitter.str(word);
			splitter >> word >> weight;
			//stick word and weight on the node you've just allocated---
			newEdge = new edge;
			newEdge->word = word;
			newEdge->weight = weight;
			newEdge->next = nullptr;
			//make sure your new node is attached to the list--- key might need to be word instead of index. Not sure.
			
			//check if list is empty
			if(!currentEdge)
			{
				corpus[index] = newEdge;
				currentEdge = newEdge;
			}
			else
			{
				currentEdge->next = newEdge;
				currentEdge = newEdge;
			}
		}
	}}
}

markovList::~markovList()
{
//write this
	//iterate through corpus
	map<string, edge*>::iterator it;
	for (it = corpus.begin(); it != corpus.end(); it++)
	{
		//iterate through the adjacency list
		edge* tempEdge = it->second;
		while(tempEdge)
		{
			//make new edge for iterating and delete old edge
			edge* tempNext = tempEdge->next;
			delete tempEdge;
			tempEdge = tempNext;
		}
	}
	//clear corpus
	corpus.clear();
}
		
string markovList::generate(int length)
{
	map<string, edge*>::iterator it = corpus.begin();	//initialize an iterator to find a random node in the next line
	advance(it,rand() % corpusSize);	//this grabs a random node from your corpus as a starting point
//write the rest of this
	//make randomnode float so it's not initialized every time the loop runs
	float randomNode;
	string returnString = "";
	for (int i = 0; i<length; i++)
	{
		randomNode = (float)rand()/RAND_MAX;
		//compare randomNode to every edge weight in the list
		//iterate through corpus starting at it
		edge* tempEdge = it->second;
		float sum = 0;
		while(tempEdge)
		{
			if (randomNode < tempEdge->weight + sum)
			{
				//add the word to the return string
				returnString = returnString + " " + tempEdge->word;
				//update the iterator
				tempEdge = tempEdge->next;
			}
			else
			{
				//increase sum by the tempEdge 
				sum += tempEdge->weight;
				tempEdge = tempEdge->next;
			}
			
		}
		return returnString;
	}
}


#endif