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
    int n;
    cin >> n;
    vector<int> f(n);
    vector<int> l(n);
    for (int i=0;i<n;i++)
        cin >> f[i];
    for (int i=0;i<n;i++)
        cin >> l[i];
    
}

int main(){
    IOS;
    int t;
    cin >> t;
    while(t>0){
        solve();
        t--;
    }

    return 0;
}