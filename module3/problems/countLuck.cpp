#include<iostream>
#include<vector>
#include<stack>
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

using namespace std;

struct Node{
    char path;
    int i;
    int j;
    Node() = default;
    Node(char path,int i,int j){
        this->path = path;
        this->i = i;
        this->j = j;
    }
};

void displayStack(stack<Node *> s){
    stack<Node *> newStack = s;
    cout << "===============================================" << endl;
    while(!newStack.empty()){
        cout << newStack.top()->path << " " << newStack.top()->i << " " << newStack.top()->j << endl;
        newStack.pop();
    }
    cout << "===============================================" << endl;
}

void dfs(vector<vector<char>> & v, int g,int ri,int rj,int ki,int kj,int m,int n){
    vector<vector<bool>> visited(m,vector<bool>(n));
    for (int i=0;i<m;i++){
        for (int j=0;j<n;j++)
            visited[i][j] = false;
    }
    stack<Node *> s;
    char path = v[ri][rj];
    s.push(new Node(path,ri,rj));
    while (!s.empty()){
        displayStack(s);
        Node * node = s.top();
        s.pop();
        cout << "Visiting index i: " << node->i << " j: " << node->j << endl;
        
        visited[node->i][node->j] = true;
        if (node->i == ki && node->j == kj){
            cout << "Path found" << endl;
            return;
        }
        if(node->path!='X'){
            int i = node->i,j = node->j;
            if (j+1<n){
                if (!visited[i][j+1])
                    s.push(new Node(v[i][j+1],i,j+1));
            }
            if (i+1<m){
                if (!visited[i+1][j])
                    s.push(new Node(v[i+1][j],i+1,j));
            }
            if (j-1>=0){
                if (!visited[i][j-1])
                    s.push(new Node(v[i][j-1],i,j-1));
            }
            if (i-1>=0){
                if (!visited[i-1][j])
                    s.push(new Node(v[i-1][j],i-1,j));
            }
        }
    }
    cout << "Path Not Found";
}


void solve(){
    int m,n,ri,rj,ki,kj;
    cin >> m >> n;
    cout << m << " " << n << endl;
    vector<vector<char>> v(m,vector<char>(n));
    string row;
    for (int i=0;i<m;i++){
        cin >> row;
        for (int j=0;j<n;j++)
            {
                v[i][j] = row[j];
                if (v[i][j]=='M'){
                    ri = i,rj=j;
                }
                else if (v[i][j]=='*'){
                    ki=i,kj=j;
                }
            }
    }
    for (auto i : v){
        for (auto j : i){
            cout << j << " ";
        }
        cout << endl;
    }
    int guess;
    cin >> guess;
    dfs(v,guess,ri,rj,ki,kj,m,n);
}

int main(){
    IOS;
    int t;
    cin >> t;
    cout << t << endl;
    while(t >0){ 
        solve();
        t--;
    }
    return 0;
}