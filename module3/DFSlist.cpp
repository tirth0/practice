#include<vector>
#include<stack>
#include<iostream>

using namespace std;

class Graph{
    public :

    bool * visited;
    vector<int> * graph;
    Graph(int nodes){
        visited = new bool[nodes];
        graph = new vector<int>[nodes];
    }

    void addEdge(int a,int b){
        
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    void dfs(int start){
        stack<int> s;
        s.push(start);
        visited[start] = true;

        while (!s.empty()){
            int node = s.top();s.pop();
            cout << node << " ";
            vector<int> neighbourList = graph[node];

            for (int neighbour : neighbourList){
                if (!visited[neighbour]){
                    s.push(neighbour);
                    visited[neighbour] = true;
                }
            }

        }
    }
};

int main(){
    int nodes = 6;
    
    Graph g(nodes);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(2, 4);
    g.addEdge(3, 5);
    g.addEdge(4, 5);
    g.addEdge(4, 6);

    g.dfs(0);

    return 0;
}