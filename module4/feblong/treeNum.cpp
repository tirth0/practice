#include<iostream>
#include<vector>
#include<stack>
#include<queue>
#include<algorithm>
#include <string> 
#include <cstring>
#include<set>
using namespace std; 

#define mod 1000000007
#define gcd(a,b) __gcd(a,b)
#define lcm(a,b) (a*b)/gcd(a,b)
#define bits(x) __builtin_popcountll(x)
#define endl "\n"
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
typedef long long int ll;

vector<int> chile(1000001,0);

class Graph{
    vector<int> * graph;
    public:
    Graph(int nodes){
        graph = new vector<int>[nodes+1];
    }
    // void addEdge(int a,int b){
    //     graph[a].push_back(b);
    // }
    void addEdgeWithoutChildren(int a,int b){
        graph[a].push_back(b);
    }
    void bfs(int v,int w,int n){
        vector<bool> visited(n+1,false);
        ll undone = 0;
        queue<pair<int,int>> q;
        q.push(pair<int,int>(v,w));
        visited[v] = true;
        while (!q.empty()){
            pair<int,int> node = q.front();q.pop();
            vector<int> neighbourList = graph[node.first];
            int childs = chile[node.first];
            if (childs==0){

            }
            else if (node.second%childs!=0){
                undone += node.second;
            }
            else{
                for (auto i : neighbourList){
                    if (!visited[i]){
                        q.push(pair<int,int>(i,node.second/childs));
                        visited[i] = true;
                    }
                }
            }
        }
        cout << undone << endl;
    }
    void dfs(int v,int w,int n){
        vector<bool> visited(n+1,false);
        ll undone = 0;
        stack<pair<int,int>> s;
        s.push(pair<int,int>(v,w));
        while(!s.empty()){
            pair<int,int> node = s.top();
            s.pop();
            visited[node.first] = true;
            vector<int> children = graph[node.first];
            int childs = chile[node.first];
            if (childs==0){

            }
            else if (node.second%childs!=0){
                undone += node.second;
            }
            else{
                for (auto i : children){
                    if (!visited[i])
                        s.push(pair<int,int>(i,node.second/childs));
                }
            }
        }
        cout << undone << endl;
    }

};

void solve(Graph g,int n){
    IOS;
    int v,w;
    cin >> v >> w;
    g.bfs(v,w,n);
}


int main(){
    int n;
    IOS;
    cin >> n;
    vector<int> inp(n+1,0);
    Graph g(n);
    for (int i=2;i<=n;i++){
        int p;cin >> p;
        inp[i] = p;
        chile[p]++;
    }
    for (int i=2;i<=n;i++){
        if (chile[i]!=0) g.addEdgeWithoutChildren(inp[i],i);
    }
    int t;
    cin >> t;
    while (t>0){
        solve(g,n);
        t--;
    }
    return 0;
}
// 11
// 1 1 2 2 2 3 4 5 5 7
// 1
