#include<iostream>
#include<vector>
#include<stack>
#include<queue>
#include<cstring>
#include<set>
#include<algorithm>
using namespace std; 

#define mod 1000000007
#define gcd(a,b) __gcd(a,b)
#define lcm(a,b) (a*b)/gcd(a,b)
#define bits(x) __builtin_popcountll(x)
#define endl "\n"
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
typedef long long int ll;

#define n 1000000
bool prime[n+1];

void sieve()
{
    memset(prime, true, sizeof(prime));
    for (int p = 2; p * p <= n; p++)
    {
        if (prime[p] == true) 
        {
            for (int i = p * p; i <= n; i += p)
                prime[i] = false;
        }
    }
}

void solve(){
    int x,y,i=0;
    cin >> x >> y;
    int ct = 0;
    for (int i=2;i<=x;i++){
        if (prime[i]){
            ct++;
        }
    }
    if (ct<y) cout << "Chef" << endl;
    else cout << "Divyam" << endl;
}

int main(){
    sieve();
    int t; cin >> t;
    while(t>0){
        solve();
        t--;
    } 
} 