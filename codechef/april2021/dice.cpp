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
    ll n;
    cin >> n;
    if (n==1){
        cout << 20 << endl;
    }
    else if (n==2){
        cout << 36 << endl;
    }
    else if(n==3){
        cout << 51 << endl;
    }
    else{
        ll t = n%4;
        ll x = n- t - 4;
        ll sum = 0;
        sum+=(x/4)*(44);
        if (t == 0){
            sum+=60;
        }
        else if(t==1){
            sum+= 76;
        }
        else if(t==2){
            sum+=88;
        }
        else{
            sum+=99;
        }
        cout << sum << endl;
    }
    
}

int main(){
    int t;
    cin >> t;
    while (t>0){
        t--;
        solve();
    }
}