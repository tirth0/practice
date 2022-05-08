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
    string s;
    cin >> s;
    if (s[0] == s[s.size()-1])
        cout << s << endl;
    else cout << s.substr(0, s.size()-1) + s[0] << endl;
}


int main(){
    int t;
    cin >> t;
    while (t-- >0){
        solve();
    }
    return 0;
}