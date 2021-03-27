#include<iostream>
#include<vector>
#include<stack>
#include<queue>
#include<cmath>
#include<algorithm>
#include<string>
#include<cstring>
#include<bitset>
#include<map>
#include<set>
#include<stdlib.h>
#include<numeric>
using namespace std; 

#define mod 1000000007
// #define gcd(a,b) __gcd(a,b)
#define lcm(a,b) (a*b)/gcd(a,b)
#define bits(x) __builtin_popcountll(x)
#define endl "\n"
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
typedef long long int ll;

vector<bool> v(1000000+1,false);
vector<ll> lc;

void sieveOfEratosthenes(){
    ll n = 1000000;
    bool prime[n+1];
    memset(prime, true, sizeof(prime));

    for (ll p=2;p*p<=n;p++){
        if (prime[p]){
            for (ll i=p*p;i<=n;i+=p){
                prime[i] = false;
            }

        }

    }
    for (ll p=2;p<=n;p++){
        if(prime[p]) {
            v[p] = true;
            ll val = lc.empty()?p*p : ((p*p) +lc[lc.size()-1]);
            lc.push_back(val);
            
        }
    }
}

void solve(){
    ll l,r;
    cin >> l >> r;
    
    
    ll sum=0;
    if (l-1==0) sum = lc[r-1];
    else
        sum = lc[r-1]-lc[l-2];
    
    cout << sum%mod << endl;
    
}

int main() 
{   
    sieveOfEratosthenes(); 
    ll q;
    cin >> q;
    while (q>0){
        q--;
        solve();
    }
    return 0; 
} 