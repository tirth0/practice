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
    for (int i=0;i<n;i++){
        cin >> v[i];
    }
    map<int,int> freq;
    for (int i=0;i<n;i++){
        for (int j=i+1;j<n;j++)
        
    }
    
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