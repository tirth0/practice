#include<iostream>
#include<vector>
#include<set>
#include<queue>
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

// 3
// 2
// suf mas
// 3
// good game guys
// 4
// hell bell best test

ll similar(vector<char> u, vector<char> v){
    set<char> a(u.begin(),u.end());
    ll temp=0;
    for (auto i : v){
        if (a.find(i)!=a.end()) temp++;
    }
    return temp;
}

void solve(){
    int n;ll ans=0;
    cin >> n;
    vector<string> names(n);
    for (int i=0;i<n;i++){
        cin >> names[i];
    }
    map<string,vector<char>> mp;
    for (int i=0;i<n;i++){
        vector<char> s = {};
        mp[names[i].substr(1)].push_back(names[i][0]);
    }
    for (auto i : mp){
        for (auto j: mp){
            ll temp = similar(i.second,j.second);
            ans += (i.second.size()-temp)*(j.second.size()-temp);
        }
    }
    cout << ans << endl;
}

int main(){
    IOS;
    int t;cin >>t;
    while (t>0){
        solve();
        t--;
    }
    return 0;
}