#include<iostream>
#include<vector>
#include<stack>
#include<map>
#include<queue>
#include<algorithm>
using namespace std; 

#define mod 1000000007
#define gcd(a,b) __gcd(a,b)
#define lcm(a,b) (a*b)/gcd(a,b)
#define bits(x) __builtin_popcountll(x)
#define endl "\n"
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
typedef long long int ll;

class Graph{
    public:
    vector<int> * graph;
    vector<int> incomingDegree;
    int nodes;
    queue<int> sourceQueue;

    Graph(int nodes){
        graph = new vector<int>[nodes];
        this->nodes = nodes;
        for (int i=0;i<nodes;i++){
            incomingDegree.push_back(0);
        }
    }
    
    void addEdge(int a,int b){
        graph[a].push_back(b);
        incomingDegree[b]++;
    }

    void showDegree(){
        for (int i=0;i<nodes;i++){
            cout << i << " : " << incomingDegree[i] << endl;
        }
    }

    void showGraph(){
        
    }

    vector<int> topoSort(){
        for (int i=0;i<nodes;i++){
            if (incomingDegree[i] == 0){
                sourceQueue.push(i);
            }
        }

        vector<int> result;
        while(!sourceQueue.empty()){
            int source = sourceQueue.front();
            sourceQueue.pop();
            result.push_back(source);
            cout << source << endl;
            vector<int> children = graph[source];

            for (int child : children){
                incomingDegree[child]--;

                if (incomingDegree[child]==0){
                    sourceQueue.push(child);
                }

            }
        }

        // if (result.size() != nodes){
        //     cout << "Graph is not acyclic";
        //     vector<int> v;
        //     return v;
        // }

        return result;
    }

};

int main(){
    int nodes = 10;
    Graph a(nodes);
    // a.addEdge(0, 1);
    // a.addEdge(0, 2);
    // a.addEdge(1, 3);
    // a.addEdge(1, 4);
    // a.addEdge(2, 4);
    // a.addEdge(3, 5);
    // a.addEdge(4, 5);

    
    a.addEdge(2, 1);
    a.addEdge(3, 1);
    a.addEdge(4, 1);
    a.addEdge(0, 1);
    a.addEdge(5, 0);
    a.addEdge(8, 0);
    a.addEdge(6, 4);
    a.addEdge(4, 5);
    a.addEdge(9, 8);
    a.showDegree();

    vector<int> res = a.topoSort();
    for (auto i: res){
        cout << i << " ";
    }
    cout << endl;
    return 0;
}