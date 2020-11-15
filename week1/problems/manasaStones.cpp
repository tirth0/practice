#include<bits/stdc++.h>
using namespace std; 

//manasa's stones hackerrank

#define mod 1000000007
#define gcd(a,b) __gcd(a,b)
#define lcm(a,b) (a*b)/gcd(a,b)
#define bits(x) __builtin_popcountll(x)
#define endl "\n"
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
typedef long long int ll;

void solve(int n,int a,int b){
    set <int> res;
    for (int i=0;i<=n-1;i++){
        int sum = a*i + b*(n-i-1);
        res.insert(sum);
    }
    for (auto it = res.begin();it!=res.end();it++){
        cout << *it << " ";
    }
    cout << endl;
}


int main(){
    IOS;
    int T,n,a,b;
    cin >> T;
    while(T>0){
        T--;
        cin >> n >> a >> b;
        solve(n,a,b);
    }
    return 0;
}