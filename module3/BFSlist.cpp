//Breadth First Traversal using Adjacency List
#include<vector>
#include<queue>
#include<iostream>

using namespace std;



class Graph{
    public :

    vector<int> * graph;
    bool * visited;

    Graph(int nodes){
        graph = new vector<int>[nodes];
        visited = new bool[nodes];
    }

    void addEdge(int a,int b){
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    void bfs(int root){
        queue<int> q;
        q.push(root);
        visited[root] = true;
        while (!q.empty()){
            int node = q.front();q.pop();
            cout << node << " ";
            vector<int> neighbourList = graph[node];
            for (auto neighbour : neighbourList){
                if (!visited[neighbour]){
                    q.push(neighbour);
                    visited[neighbour] = true;
                }
            }
        }
    }
};

int main(){

    Graph g(7);
    
    g.addEdge(0,1);
    g.addEdge(0,2);
    g.addEdge(1,3);
    g.addEdge(1,4);
    g.addEdge(2,5);
    g.addEdge(2,6);

    g.bfs(0);

    return 0;

}