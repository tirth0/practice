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
    int mx = INT_MIN;
    vector<int> v(n,0);
    for (int i=0;i<n;i++){
        int x;
        cin >> x;
        mx = max(mx,x);
        v[i] = x;
    }
    int m1=INT_MIN;
    for (int i=0;i<n;i++){
        if (v[i]==mx){
            m1=i;break;
        }
    }
    int m2=INT_MIN;
    for (int i=n-1;i>=0;i--){
        if (v[i]==mx){
            m2=i;break;
        }
    }
    vector<int> l ={max(m1+n-m2-n/2,0)};
    int i=m1+1,j=m1+1,l1=0;
    
    while(j<=m2){
        if (v[j]==mx){
            l.push_back(max(j-i-n/2,0));
            i=j+1;
        }
        j++;
    }
    int k=0;
    for (int i=0;i<l.size();i++){
        k+=l[i];
        
    }
    
    cout << k << endl;
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