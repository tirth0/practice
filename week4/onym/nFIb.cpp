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
#include<numeric>
using namespace std; 

#define mod 1000000007
// #define gcd(a,b) __gcd(a,b)
#define lcm(a,b) (a*b)/gcd(a,b)
#define bits(x) __builtin_popcountll(x)
#define endl "\n"
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
typedef long long int ll;

vector<ll> v(1000000+1);

void solve(ll n){
    v[1] = 0;
    v[2] = 0;
    v[3] = 1;
    for (int i=4;i<=n;i++){
        v[i] = (v[i-1]%mod+v[i-2]%mod+v[i-3]%mod)%mod;
    }
    cout << v[n];
}

int main(){
    ll n;
    cin >> n;
    solve(n);
}