#include<iostream>
#include<vector>
#include<stack>
#include<queue>
#include<algorithm>
#include<bitset>
#include<string>
#include<map>
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
    vector<int> v(n+1);
    for (int i=1;i<=n;i++)
        cin >> v[i];
    sort(v.begin(),v.end());
    int s = 0;
    
    for (int i=1;i<=n;i++){
        if (v[i]>i) {
            cout << "Second" << endl;
            return;
        }
        s+= i-v[i];
    }
    if (s%2 == 0) cout << "Second";
    else cout << "First";
        
    cout << endl;
}

int main(){
    IOS;
    int t;
    cin >> t;
    while (t>0){
        t--;
        solve();
    }
}