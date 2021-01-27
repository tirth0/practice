#include<iostream>
#include<vector>
#include<stack>
#include<queue>
#include<algorithm>
using namespace std; 

#define mod 1000000007
#define gcd(a,b) __gcd(a,b)
#define lcm(a,b) (a*b)/gcd(a,b)
#define bits(x) __builtin_popcountll(x)
#define endl "\n"
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
typedef long long int ll;

using namespace std;
#define N 10000001


void solve(){
    ll n;
    cin >> n;
    int i = 2;
    while (n>1){
        if (i%2!=0){
            cout << "YES" << endl;
            return;
        }
        if (n%i==0) n = n/i;
        else i++;
    }
    cout << "NO" << endl;
}

int main(){
    int t;
    cin >> t;
    
    while (t>0){
        solve();
        t--;
    }
    return 0;
}

