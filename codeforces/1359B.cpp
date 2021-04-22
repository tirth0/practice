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
    int n,m,x,y;
    cin >> n >> m >> x >> y;
    y = min(2*x,y);
    vector<vector<char>> sq(n,vector<char>(m,'a'));
    ll sum=0;
    for (int i=0;i<n;i++){
        
        for(int j=0;j<m;j++){
            cin >> sq[i][j];
            
        }
        
    }
    for (int i=0;i<n;i++){
        int arr[] = {0,0};
        int j=0;
        bool flag = true;
        for (j=0;j<m-1;j++){
            if (sq[i][j]=='.' && sq[i][j+1]=='.'){
                arr[1]++;
                if (j+1 == m-1) flag = false;
                j++;
                
            }
            else if(sq[i][j]=='.'){
                arr[0]++;
            }
        }
        
        if (flag && sq[i][j]=='.') arr[0]++;
        // cout << arr[0] << " , " << arr[1] << endl;
        sum+= arr[1]*y + arr[0]*x;
    }
    
        
    cout << sum << endl;
}

int main(){
    int t;
    cin >> t;
    while(t>0){
        solve();
        t--;
    }
}