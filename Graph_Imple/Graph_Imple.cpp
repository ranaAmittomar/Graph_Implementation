// Graph_Imple.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<list>
#include<queue>
using namespace std;


class Graph {
    int V;
    list<int>* l;
public:
    Graph(int v) //Constructor to initialise the Graph Node with vertex and List..
    {
        V = v;
        l = new list<int>[V]; 
    }

    void addEdge(int i, int j, bool undirected = true)
    {
        l[i].push_back(j);//this makes the connected vertext of (i) with many different vertex (j)'s.Means-> j1,j2 would be neighbouring vertext of i.. 
        if (undirected)
        {
            l[j].push_back(i); //the condition is for undirected(bi-directional Graph) which means,i1,j1 will also be neighbour of (j)...
        }
    }

    void printAdjacencyList()
    {
        for (int i = 0; i < V; i++)
        {
            cout << i << "-->";

            for (auto node : l[i]) {
                cout << node << ",";
            }
            cout << endl;

        }

    }
};


int main()
{
    Graph g(6);
    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(3, 2);
    g.addEdge(2, 1);
    g.addEdge(3, 0);
    g.addEdge(4, 1);
    g.printAdjacencyList();


    return 0;
}

