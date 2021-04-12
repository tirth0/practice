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

float roundIt(float val){
    val = (int)(val*100+0.5);
    return (float)val/100;
}

void solve(){
    float k1,k2,k3,v;
    cin >> k1 >> k2 >> k3 >> v;
    float time = 100/(k1*k2*k3*v);
    time = roundIt(time);
    // cout << time << endl;
    float t = 9.58;
    if (time < t) cout << "YES" << endl;
    else cout << "NO" << endl;
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