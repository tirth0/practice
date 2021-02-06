#include<iostream>
#include<vector>
#include<stack>
#include<queue>
#include<algorithm>
#include <string> 
using namespace std; 

#define mod 1000000007
#define gcd(a,b) __gcd(a,b)
#define lcm(a,b) (a*b)/gcd(a,b)
#define bits(x) __builtin_popcountll(x)
#define endl "\n"
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
typedef long long int ll;

void solve(){
    ll n; cin >> n;
    vector<ll> A(n);
    for (ll i=0;i<n;i++)
        cin >> A[i];
    sort(A.begin(),A.end());
    ll x = 0, y = (A.size()-1)/2, z= A.size()-1;
    ll sum = A[z] -A[y] + A[y] - A[x] + A[z] - A[x];
    cout << sum << endl;
}


int main(){
    int t;cin >> t;
    while (t>0){
        t--;
        solve();
    }
    return 0;
}

//1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 5 6 7
//5-1 + 7-5 + 07-1 = 4 + 1 + 6 = 12
//1-1 +7-1 + 1-7 = 12