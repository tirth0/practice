#include<iostream>
#include<vector>
#include<stack>
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
int dp[1000000];



void solve(){
    int n;
    cin >> n;
    vector<int> f(n);
    vector<int> l(n);
    for (int i=0;i<n;i++)
        cin >> f[i];
    for (int i=0;i<n;i++)
        cin >> l[i];
    map<int,int> mp,jump;
    for (int i=0;i<n;i++){
        mp.insert(make_pair(f[i],i));
        jump.insert(make_pair(f[i],l[i]));
    }
    ll count = 0;
    // for (auto i : mp){
    //     cout << i.first << " : " << i.second << endl;
    // }
    // for (auto i : jump){
    //     cout << i.first << " : " << i.second << endl;
    // }
    auto i = next(mp.begin(),1);
    for (auto j=mp.begin();i!=mp.end();i++,j++){
        // int currElem = i->first;
    
        // int prevElem = j->first;
        
        if (j->second >= i->second){
            int diff = j->second - i->second;
            int jmp = jump.at(i->first);
            int change = (int)(diff/jmp) + 1;
            int incr = change * jmp;
            i->second += incr;
            count += change;
        }

    }
    cout << count << endl;
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