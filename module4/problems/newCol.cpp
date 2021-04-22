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
    int n;ll k;
    cin>>n>>k;
    vector<int> h(n);
    for (int i=0;i<n;i++){
        cin >> h[i];
    }
    int i=0;
    bool flag = false;
    while (k>0){
        i=0;
        while (h[i]>=h[i+1]){
            i++;
            if(i>n-2){
                flag = true;
                break;
            }
        }
        if (flag) break;
        k-=(h[i+1]-h[i]);
        h[i]=h[i+1];
    }
    if (flag) cout << -1 << endl;
    else{
    cout << i+1 << endl;}
    for (auto i:h){
        cout << i << " ";
    }
    cout << endl;
}

int main(){
    int t;
    cin >> t;
    while(t>0){
        solve();
        t--;
    }
}