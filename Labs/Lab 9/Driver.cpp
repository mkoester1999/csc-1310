/*
*/
#include<fstream>
#include "GraphList.h"

int main()
{
    //open graph.txt for reading
    ifstream inputFile("graph.txt");

    if(inputFile.is_open())
    {
        //read number of vertices
        int numVertices;
        inputFile >> numVertices;

        //create graph
        GraphList graph(numVertices);

        //read in the source and desitation nodes from inputFilej. Add the edge to the graph
        int source, destination;

        while(!inputFile.eof())
        {
            inputFile >> source >> destination;
            cout<<"Adding an edge from " << source << " to " << destination <<"." << endl;
            graph.addEdge(source, destination);
        }

        //print the graph
        cout<<"Adjacency List..." << endl;
        graph.printGraph();
        
    }

}