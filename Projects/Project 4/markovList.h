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
			int weight;
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
		while(getline(parser, word, ','))
		{
			//allocate a new node in the edge list---
			splitter.clear();
			splitter.str(word);
			splitter >> word >> weight;
			//stick word and weight on the node you've just allocated---
			newEdge->word = word;
			newEdge->weight = weight;
			//make sure your new node is attached to the list--- key might need to be word instead of index. Not sure.
			corpus.insert(pair<string, edge*>(index, newEdge));
		}
	}}
}

markovList::~markovList()
{
//write this
}
		
string markovList::generate(int length)
{
	map<string, edge*>::iterator it = corpus.begin();	//initialize an iterator to find a random node in the next line
	advance(it,rand() % corpusSize);	//this grabs a random node from your corpus as a starting point
//write the rest of this
	float randomNode;
	for (int i = 0; i<length; i++)
	{
		randomNode = (float)rand()/RAND_MAX;
		//compare randomNode to every edge weight in the list
		//iterate through corpus starting at it
		edge* tempEdge = it->second;
		while(tempEdge)
		{
			if (randomNode < tempEdge->weight)
			{
				return tempEdge->word;
			}
			tempEdge = tempEdge->next;
		}
		//return empty string if we didn't find a weight smaller than the ranndom number
		return "";
	}
}


#endif