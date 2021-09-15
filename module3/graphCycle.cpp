#include<iostream>
#include<vector>

using namespace std;




class Graph{
   vector<int> *graph;
   bool * visited;
   int nodes;
   int cycle;
   public:

   Graph(int nodes){
       graph = new vector<int>[nodes];
       visited = new bool[nodes];
       this->nodes = nodes;
       this->cycle = 0;
   }
   void addEdge(int a,int b){
       cout << "Edge ADded\n";
       graph[a].push_back(b);
       graph[b].push_back(a);
   }

   int countCycle(){
       for (int i=0;i<nodes;i++){
           if (!visited[i]) {
               if (hasCycle(i,-1)) cycle++;
           }
       }
       return cycle;
   }

   bool hasCycle(int node, int parent){
       visited[node] = true;
       vector<int> neighbourList = graph[node];
       for (auto neighbour : neighbourList){
           if (!visited[neighbour]){
               hasCycle(neighbour,node);
           }
           else if(neighbour!=parent)
                return true;
       }
       return false;
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
    
    int cycle = g.countCycle();
    
    
    cout << "No. Of cycles " << cycle ;

    return 0;
}