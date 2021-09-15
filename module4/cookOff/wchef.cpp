#include<iostream>
#include<vector>
#include<stack>
#include<queue>
#include<algorithm>
#include<string> 
#include<map>
#include<utility> 
using namespace std; 

#define mod 1000000007
#define gcd(a,b) __gcd(a,b)
#define lcm(a,b) (a*b)/gcd(a,b)
#define bits(x) __builtin_popcountll(x)
#define endl "\n"
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
typedef long long int ll;


void solve(){
    int w1,w2,x1,x2,M;
    cin >> w1 >> w2 >> x1 >> x2 >> M;
    int inc = w2 - w1;
    int minWt = x1*M;
    int maxWt = x2*M;
    if (inc >= minWt && inc <= maxWt) cout << 1 << endl;
    else cout << 0 << endl;
}

int main(){
    int t;
    cin >> t;
    while(t>0){
        t--;
        solve();
    }
}