#include<iostream>
#include<stack>
#include<vector>
#include<algorithm>

using namespace std;

struct Vertex{
    char label;
    bool wasVisited;
    Vertex()= default;
    Vertex(char label){
        this->label = label;
        wasVisited = false;
    }
};

class Graph{
    public :

    const int MAX_VERTS = 20;
    Vertex **vertexList;
    int ** adjMat;
    int nVerts;
    stack<int> s;

    Graph(){
        vertexList = new Vertex*[MAX_VERTS];
        adjMat = new int*[MAX_VERTS];
        for (int i=0;i<MAX_VERTS;i++)
            adjMat[i] = new int[MAX_VERTS]; 
        nVerts = 0;  
    } 
    void addVertex(char label){
        vertexList[nVerts++] = new Vertex(label);
    }
    void addEdge(int start,int end){
        adjMat[start][end] = 1;
        adjMat[end][start] = 1;
    }
    void displayVertex(int v){
        cout << vertexList[v]->label << " ";
    }
    int getAdjUnvisitedVertex(int v){
        for (int j=0;j<nVerts;j++){
            if (adjMat[v][j] == 1 && vertexList[j]->wasVisited == false){
                return j;
            } 
        }
        return -1;
    } 

    void dfs(){
        vertexList[0]->wasVisited = true;
        displayVertex(0);
        s.push(0);

        while (!s.empty()){
            int v =getAdjUnvisitedVertex(s.top());

            if (v == -1){
                s.pop();
            }
            else{
                vertexList[v] -> wasVisited = true;
                displayVertex(v);
                s.push(v);
            }
        }
    }
};

int main(){
    Graph g;
    g.addVertex('A');
    g.addVertex('B');
    g.addVertex('C');
    g.addVertex('D');
    g.addVertex('E');
    g.addVertex('F');

    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(0, 3);
    g.addEdge(0, 4);
    g.addEdge(4, 5);
    g.addEdge(1, 3);

    g.dfs();
    return 0;
}