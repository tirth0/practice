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

bool sgn(ll n){
    return n>0;  
}

void solve(){
    int n;
    cin >> n;
    vector<ll> v(n);
    for (int i=0;i<n;i++){
        cin >> v[i];
    }
    ll sum = 0;
    for (int i=0;i<n;i++){
        int j=i;ll mx = v[i];
        while(j<n && (sgn(v[i])==sgn(v[j]))){
            mx = max(mx,v[j]);
            j++;
        }
        sum+=mx;
        i=j-1;
    }
    cout << sum << endl;
}

int main(){
    int t;
    cin >> t;
    while(t>0){
        t--;
        solve();
    }
}