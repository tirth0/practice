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



void solve(vector<vector<int>> & grid,int m,int n){
    vector<vector<bool>> visited(m,vector<bool>(n));
    for (int i=0;i<m;i++){
        for (int j=0;j<n;j++)
            visited[i][j] = false;
    }
    vector<int> root = {grid[0][0],0,0};
    stack<vector<int>> s;
    s.push(root);
    int i=0,j=0;
    while(!s.empty()){
        vector<int> val = s.top();
        s.pop();
        i = val[1],j = val[2];
        visited[i][j] = true;
        cout << "Visiting Poistion i: " << i << " j: " << j << endl;
        if (i==n-1 && j==n-1){
            cout << "YES" << endl;
            return; 
        }
        if (val[0]!=1)
        {       
            // if (i-1>=0 && j+1<m)
            //         {   
            //             if (!visited[i-1][j+1])
            //                 s.push({grid[i-1][j+1],i-1,j+1});
            //         }
                if (!visited[i+1][j] && i+1<m)
                    s.push({grid[i+1][j],i+1,j});
                if (!visited[i+1][j+1] && i+1<m && j+1<n)
                    s.push({grid[i+1][j+1],i+1,j+1});
                if (!visited[i][j+1] && j+1<n)
                    s.push({grid[i][j+1],i,j+1});
                
                
                // if (j-1>=0 && i-1>=0){
                //     if (!visited[i-1][j-1])
                //         s.push({grid[i-1][j-1],i-1,j-1});
                // }
                // if (j+1<n && i-1>=0){
                //     if (!visited[i-1][j+1])
                //         s.push({grid[i-1][j+1],i-1,j+1});
                // }
                // if (j-1>=0 && i+1<=m){
                //     if (!visited[i+1][j-1])
                //         s.push({grid[i+1][j-1],i+1,j-1});
                // }    
                // if (i-1>=0){
                //      if (!visited[i-1][j]){
                //         s.push({grid[i-1][j],i-1,j});
                //      }

                // }    
            }
    }
    cout << "NO" << endl;   
} 

int main(){
    vector<vector<int>> grid = {
        {0,1,0,0,0},
        {0,1,1,1,0},
        {0,1,0,0,1},
        {1,0,1,0,0}
    };
    solve(grid,5,5);
}