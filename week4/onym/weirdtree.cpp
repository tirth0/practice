#include<iostream>
#include<vector>
#include<stack>
#include<queue>
#include<cmath>
#include<algorithm>
#include<string>
#include<bitset>
#include<map>
#include<climits>
#include<set>
#include<numeric>
using namespace std; 

#define mod 1000000007
// #define gcd(a,b) __gcd(a,b)
#define lcm(a,b) (a*b)/gcd(a,b)
#define bits(x) __builtin_popcountll(x)
#define endl "\n"
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
typedef long long int ll;

using namespace std;
set<int> removed;


vector<int> res;
class Graph{
    public :

    bool * visited;
    vector<int> * graph;
    
    int nodes;
    Graph(int nodes){
        visited = new bool[nodes];
        graph = new vector<int>[nodes];
        this->nodes = nodes;
    }

    void addEdge(int a,int b){
        
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    void init(){
        for (int i=0;i<nodes;i++){
            visited[i] = false;
        }
    }
    void removeNode(int n){
        removed.insert(n);
    }
    

    int dfs(int start){
        stack<int> s;
        s.push(start);
        visited[start] = true;
        int conn = 1;
        while (!s.empty()){
            int node = s.top();s.pop();
            // cout << node << " ";
            
            vector<int> neighbourList = graph[node];
            for (int neighbour : neighbourList){
                if (removed.find(neighbour) == removed.end()) { 
                    if (!visited[neighbour]){
                            conn++;
                            s.push(neighbour);
                            visited[neighbour] = true;
                        
                    }
                }
            }

        }
        init();
        removed.insert(start);
        // cout << endl;
        return conn;
    }
};

void solve(Graph g,int t,int n){
    int x;
    cin >> x;
    int node = res[t]^x;
    node = node-1;
    
    // cout << "node to be visited " << node << endl;
    // for (auto i:removed){
    //         cout << "Removed " << i << endl;
    //     }
    if (t==0){ 
        // cout << "No of connected Components " << n << endl;
        res.push_back(n);
        removed.insert(node);
    }
    else{
        int conn = g.dfs(node);
        res.push_back(conn);
        // cout << "No of connected Components " << conn << endl;
    }
}

int main(){
    int n;
    cin >> n;
    
    Graph g(n);
    for (int i=0;i<n-1;i++){
        int a,b;cin >> a >> b;
        g.addEdge(a-1,b-1);
    }
    
    g.init();
    res.push_back(0);
    
    int q;
    cin >> q;
    int t=0;
    while(q>0){
        q--;
        solve(g,t,n);
        t++;
    }
    
    return 0;
}