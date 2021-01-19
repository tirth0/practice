//Kefa and Restaurants codeforces *1500
#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>
using namespace std; 

#define mod 1000000007
#define gcd(a,b) __gcd(a,b)
#define lcm(a,b) (a*b)/gcd(a,b)
#define bits(x) __builtin_popcountll(x)
#define endl "\n"
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
typedef long long int ll;

struct Node{
    int label;
    int isCat;
    int catCount;
    bool wasVisited;
    Node() = default;
    Node(int label,int isCat){
        this->label = label;
        this->isCat = isCat;
        catCount = 0;
    }
};

class Graph{
    public :

    vector<int> * graph;
    Node ** tree;
    bool * visited;
    int res,count;

    Graph(int nodes){
        graph = new vector<int>[nodes];
        tree = new Node*[nodes];
        visited = new bool[nodes];
        res = 0;count =0;
    }
    void initNodes(vector<int> cats,int n){
        
    }
    void addEdge(int a, int b){
        // cout << a-1 << " " << b -1 << endl;
        graph[a-1].push_back(b-1);
        graph[b-1].push_back(a-1);
    }
    
    void dfs(int m){
        stack<Node *> s;

        s.push(tree[0]);
        visited[0] = true;
        
        bool consec = false;
        while (!s.empty()){
            Node * node = s.top();
            cout << node->label << " has " << node->isCat << endl;
            vector<int> neighbourList = graph[node->label];
            
            count = node->isCat == 0?0 : count +1;
            
            
            if (count > m){
                Node * n = s.top();
                count = n->catCount;
                s.pop();
            }
            else{
                if (node->label > neighbourList.back()){
                    
                    
                    Node * n = s.top();
                    count = n->catCount;
                    res++;
                    s.pop();
                
                }
                else{
                    bool allVis = true;
                    for (int neighbour : neighbourList){
                        if (!visited[neighbour]){
                            allVis = false;
                            tree[neighbour] -> catCount = count;
                            s.push(tree[neighbour]);
                            visited[neighbour] = true;
                        }
                    }
                    if (allVis){
                        Node * n = s.top();
                        count = n->catCount;
                        s.pop();
                        
                    }
                }
            }
        }

        cout << res;
    }
};

int main(){
    IOS;
    int n,m;
    cin >> n >> m;
    vector<int> cats(n);
    for (int i=0;i<n;i++)
        cin >> cats[i];
    Graph g(n);
    g.initNodes(cats,n);
    for (int i=0;i<n-1;i++){
        int a,b;
        cin >> a >> b;
        g.addEdge(a,b);
    }
    
    g.dfs(m);
    return 0;
}