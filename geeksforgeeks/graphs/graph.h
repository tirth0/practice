//Graph insertion algorithm
#include<vector>
#include<queue>
#include<iostream>

using namespace std;

class Graph{
    public :

    vector<int> * graph;
    bool * visited;
    int nodes;

    Graph(int nodes){
        this->nodes = nodes;
        graph = new vector<int>[nodes];
        visited = new bool[nodes];
    }

    void init() {
        for (int i = 0; i< nodes; i++)
            visited[i] = false;
    }

    void addEdge(int a,int b){
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
};

