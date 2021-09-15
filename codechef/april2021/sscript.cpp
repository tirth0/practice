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
    ll n,k;
    cin >> n >> k;
    string s;
    cin >> s;
    ll ct = 0;bool flag = false;
    ll j=0;
    while (j<n){
        if(s[j] == '*'){
            ct++;
            if (ct == k){
                flag = true;
                break;
            }
        }
        else{
            ct=0;
        }
        j++;
    }
    if (flag) cout << "YES" << endl;
    else
        cout << "NO" << endl;
}

int main(){
    ll t;
    cin >> t;
    while(t>0){
        t--;
        solve();
    }
}