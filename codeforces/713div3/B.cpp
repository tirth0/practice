#include<iostream>
#include<vector>
#include<stack>
#include<queue>
#include<cmath>
#include<algorithm>
#include<string>
#include<bitset>
#include<map>
#include<set>
#include<climits>
using namespace std; 

#define mod 1000000007
#define gcd(a,b) __gcd(a,b)
#define lcm(a,b) (a*b)/gcd(a,b)
#define bits(x) __builtin_popcountll(x)
#define endl "\n"
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
typedef long long int ll;

void solve(){
    int n;
    cin >> n;
    vector<vector<char>> v(n,vector<char>(n,0));
    vector<pair<int,int>> pos;
    for (int i=0;i<n;i++){
        for (int j=0;j<n;j++){
            
            cin >> v[i][j];
            if (v[i][j]=='*'){
                pos.push_back(make_pair(i,j));
            }
        }
    }
    //case 1: same row
    if (pos[0].first == pos[1].first){
        int x = pos[0].first;
        int y1 = pos[0].second,y2 = pos[1].second;
        if (x-1>=0){
            v[x-1][y1] = '*';
            v[x-1][y2] = '*';
        }
        else{
            v[x+1][y1] = '*';
            v[x+1][y2] = '*';
        }
    }
    //case 2: same col
    else if (pos[0].second == pos[1].second){
        int y = pos[0].second;
        int x1 = pos[0].first,x2 = pos[1].first;
        if (y-1>=0){
            v[x1][y-1] = '*';
            v[x2][y-1] = '*';
        }
        else{
            v[x1][y+1] = '*';
            v[x2][y+1] = '*';
        }
    }
    //case 3 : diff
    else{
        int x1 = pos[0].first;
        int x2 = pos[1].first;
        int y1 = pos[0].second;
        int y2 = pos[1].second;
        v[x1][y2] = '*';
        v[x2][y1] = '*';
    }

    for (int i=0;i<n;i++){
        for (int j=0;j<n;j++){
            cout << v[i][j];
        }
        cout << endl;
    }
}

int main(){
    int t;
    cin >> t;
    while (t>0){
        
        solve();
        t--;
    }
    return 0;
}