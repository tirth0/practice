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
    ll n;
    cin >> n;
    vector<ll> a(n);
    vector<ll> b(n);
    ll min1 = 1e9;
    ll min2 = 1e9;
    for (ll i=0;i<n;i++){
        cin >> a[i];
        if (a[i]<min1) min1=a[i];
    }
    for (ll i=0;i<n;i++){
        cin >> b[i];
        if (b[i]<min2) min2=b[i];
    }
    ll m=0;
    ll c=0;
    while (c<n){
        if (a[c]>min1 && b[c]>min2){
            int x = min(a[c]-min1,b[c]-min2);
            a[c]-=x;b[c]-=x;
            m+=x;
            if (a[c]>min1) m+=a[c]-min1;
            if (b[c]>min2) m+=b[c]-min2;
        }
        else{
            if (a[c]>min1) m+=a[c]-min1;
            if (b[c]>min2) m+=b[c]-min2;
        }
        c++;
    }
    
    
    cout << m << endl;
    
    
}

int main(){
    IOS;
    ll t;
    cin >> t;
    while (t>0){
        t--;
        solve();
    }
    return 0;
}