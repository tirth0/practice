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
using namespace std; 

#define mod 1000000007
#define gcd(a,b) __gcd(a,b)
#define lcm(a,b) (a*b)/gcd(a,b)
#define bits(x) __builtin_popcountll(x)
#define endl "\n"
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
typedef long long int ll;

void solve(){
    ll n,m,x;
    cin >> n >> m >> x;
    ll i=-1,j=-1;
    bool flag=false;
    for (j=0;j<m;j++){
        i = x-1-n*j;
        if (i<n && i>=0){
            break;
        }
    }
    ll num = m*i+j+1;
    cout << num << endl;
}

int main(){
    ll t;
    cin >> t;
    while(t>0){
        t--;
        solve();
    }
    return 0;
}