#include<iostream>
#include<vector>
#include<stack>
#include<queue>
#include<cstring>
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
    ll n,m,k;
    cin >> n >> m >> k;
    ll sum = 0;
    if (m%2 == 0){
        for (ll i=1;i<=n;i+=2){
            sum=sum^(k+i+1);
        }
        for (ll j=2;j<=m;j+=2){
            sum=sum^(k+j+n);
        }
    }
    else{
        for (ll i=1;i<=n;i+=2){
            sum=sum^(k+i+1);
        }
        for (ll j=3;j<=m;j+=2){
            sum=sum^(k+j+n);
        }
    }

    cout << sum << endl;
}

int main(){
    ll t;
    cin >> t;
    while (t>0){
        t--;
        solve();
    }
}