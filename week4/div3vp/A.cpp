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
    vector<ll> a(n);
    for (int i=0;i<n;i++){
        cin >> a[i];
    }
    int ct=0;
    int i=0;
    while(ct<n){
        cout << a[i]<< " ";ct++;
        if (ct%2==0){
            i=(int)ct/2;
        }
        else{
            i=n-1-(int)ct/2;
        }
        
    }
    cout << endl;
}

int main(){
    IOS;
    int t;
    cin >> t;
    while(t>0){
        t--;
        solve();
    }
}