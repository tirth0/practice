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

vector<ll> v(10);

void precompute(){
    for (int i=1;i<=9;i++){
        for (int j=9;j>9-i;j++){
            v[i]+=j;
        }
    }
}

ll sumDig(ll d){
    ll s=0;
    while(d>0){
        s+=d%10;
        d/=10;
    }
    return s;
}

ll unique(ll d){
    ll c=0;
    set<ll> s;
    while(d>0){
        c++;
        s.insert(d%10);
        d/=10;
    }
    // cout << "Set " << s.size()<< endl;
    if (c==s.size()) return true;
    else return false;
}



void solve(){
    // ll n;
    // cin >> n;
    // ll i=1;bool flag = false;;
    // while (sumDig(i)<=n){
    //     if (sumDig(i)==n){
    //         if (unique(i)){ flag = true; break;}
    //     }
    //     i++;
    // }
    // if (flag) cout << i << endl;
    // else cout << -1 << endl;
    ll n;
    cin >> n;
    bool flag=false;
    ll i;
    for (i=1;i<=9;i++){
        if (n<=v[i]) {flag =true;break;}
    }

    if (!flag) cout << -1 << endl;
    else{
            ll j=1;bool f=false;
            while(sumDig(j)<=v[i]){
                if (sumDig(j)==n){
                    if (unique(j)){
                        f=true;
                        break;
                    }
                }
                
            }
            if (f) cout << j << endl;
            else cout << -1 << endl;
    }
}

int main(){
    int t;
    cin >> t;
    precompute();
    while (t>0){
        t--;
        solve();
    }
    return 0;
}