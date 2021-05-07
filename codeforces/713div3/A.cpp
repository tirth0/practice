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
    int n;
    cin >> n;
    vector<int> v(n);
    map<int,int> mp;
    for (int i=0;i<n;i++){
        cin >> v[i];
        mp[v[i]]++;
    }
    
    int rep,spy;
    for (auto i:mp){
        if (i.second == 1)
            spy = i.first;
        else    
            rep = i.first;
    }
    for (int i=0;i<n;i++){
        if (v[i]==spy){
            cout << i+1 << endl;
            break;
        }
    }
}

int main(){
    int t;
    cin >> t;
    while(t>0){
        solve();
        t--;
    }
    return 0;
}