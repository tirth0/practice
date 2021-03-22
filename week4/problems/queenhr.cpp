#include<iostream>
#include<vector>
#include<stack>
#include<queue>
#include<cmath>
#include<algorithm>
#include<string>
#include<bitset>
#include<map>
using namespace std; 

#define mod 1000000007
#define gcd(a,b) __gcd(a,b)
#define lcm(a,b) (a*b)/gcd(a,b)
#define bits(x) __builtin_popcountll(x)
#define endl "\n"
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
typedef long long int ll;

void solve(int n,int k){
    
    vector<pair<int,int>> obs;
    int r,c;
    cin >> r >> c;
    for (int i=0;i<k;i++){
        int p,q;
        cin >> p >> q;
        obs.push_back(make_pair(p,q));
    }
    vector<vector<int>> board(n,vector<int>(n,0));
    
    board[r][c] = 1;
    for (int i=0;i<k;i++){
        cout << obs[i].first << "lul "<< obs[i].second << endl;
        int x = obs[i].first,y = obs[i].second;
        board[x-1][y-1] = 2;
    }
    
    int dx[] = {1,1,1,-1,-1,-1,0,0};
    int dy[] = {1,0,-1,-1,0,1,1,-1};
    
    int xarr[] = {r,r,r,r,r,r,r,r};
    int yarr[] = {c,c,c,c,c,c,c,c};
    int chk[] = {0,0,0,0,0,0,0,0};
    ll ct = 0;
    int lim=0;
    
    while (lim<=8){
        for (int i=0;i<8;i++){
            if (chk[i]==0){
                xarr[i]+=dx[i];
                yarr[i]+=dy[i];
                if (xarr[i]<0 || yarr[i]<0 || xarr[i]>=n || yarr[i]>=n || board[xarr[i]][yarr[i]]==2){
                    chk[i] = 1;
                    lim++;
                }
                else{
                    ct++;
                }
            }    
        }
    }
    cout << ct;
}

int main(){
    int n,k;
    cin >> n >> k;
    cout << k << endl;
    solve(n,k);
}

// int x1=r,y1=c;//south east
// int x2=r,y2=c;//east
// int x3=r,y3=c;//north east
// int x4=r,y4=c;//north west
// int x5=r,y5=c;//west
// int x6=r,y6=c;//south west
// int x7=r,y7=c;//south
// int x8=r,y8=c;//north