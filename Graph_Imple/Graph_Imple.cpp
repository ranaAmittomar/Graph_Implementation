// Graph_Imple.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<list>
#include<queue>
using namespace std;


//Basic Implementation of Graph with Given number of Vertex....
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
        l[i].push_back(j);//this makes the connected vertex of (i) with many different vertex (j)'s.Means-> j1,j2 would be neighbouring vertext of i..
        if (undirected)
        {
            l[j].push_back(i); //the condition is for undirected(bi-directional Graph) which means,i1,j1 will also be neighbour of (j)...
        }
    }


    //BFS Implementation....

    void bfs(int source) //Source is -> From Where we'll start our Traversal....
    {
        queue<int> q;
        bool* visited = new bool[V]{0};

        q.push(source); //pushing the source into queue...
        visited[source] = true; //marking that source as visited..

        while (!q.empty()) //and repeating the process untill Queue is empty..
        {
            int f = q.front();  //here,getting front element of Queue and priting that element in below line..
            cout << f << " ";
            q.pop(); //after printing,we'll pop the element from the queue.

            for (auto nbr : l[f])  //for each element for neighbour till our queue is empty,we repeat the process..
            {
                if (!visited[nbr])
                {
                    q.push(nbr);
                    visited[nbr] = true;//marking every visited element as true or (1)..
                }
            }
        }
    }

    //DFS Implementation....

    void dfs_helper(int node, bool* visited) //helper function for the RECURSIVE CALLs for DFS..
    {
        visited[node] = true;
        cout << node << " ";
        for (int nbr : l[node])
        {
            if (!visited[nbr])
            {
                dfs_helper(nbr, visited);
            }
        }
    }

    void dfs(int source)
    {
        bool* visited = new bool[V] {0}; //initialising the Visited array with 0 to keep track of visited Node..
        dfs_helper(source, visited);
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
    /*
    
    Graph g(6);
    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(3, 2);
    g.addEdge(2, 1);
    g.addEdge(3, 0);
    g.addEdge(4, 1);
    g.printAdjacencyList();

    */

    Graph gdfs(5);
    gdfs.addEdge(0, 1);
    gdfs.addEdge(0, 2);
    gdfs.addEdge(0, 3);
    gdfs.addEdge(1, 2);
    gdfs.addEdge(2, 4);
    gdfs.addEdge(3, 3);
    gdfs.addEdge(4, 4);

    //gdfs.dfs(0); //calling the dfs function to print the path of visited node.
    //gdfs.bfs(0);
    //gdfs.printAdjacencyList();


    return 0;
}

