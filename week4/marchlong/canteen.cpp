#include<iostream>
#include<vector>
#include<stack>
#include<queue>
#include<cmath>
#include<algorithm>
#include<string>
#include<bitset>
#include<map>
using namespace std; 

#define mod 1000000007
#define gcd(a,b) __gcd(a,b)
#define lcm(a,b) (a*b)/gcd(a,b)
#define bits(x) __builtin_popcountll(x)
#define endl "\n"
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
typedef long long int ll;


/*
H : CHOCOLATE
E : EGG
A : PRICE OF OMLETTE
B : PRICE OF CHOCOLATE MILKSHAKE
C : PRICE OF CHOCOLATE CAKE
N : NUMBER OF FREN
INPUT FORMAT :
T
N E H A B C

Omlette : 2 eggs
Chocolate Shake : 3 chocolates
cake : 1 egg 1 chocolate
*/



void solve(){
    ll n,e,h,a,b,c;
    cin >> n >> e >> h >> a >> b >> c;
    multimap<ll,ll> mp;
    mp.insert({a,1});
    mp.insert({b,2});
    mp.insert({c,3});
    ll total=0;
    // for (auto i : mp){
    //     cout << i.first << " : " << i.second << endl;
    // }
    ll op=0,cp=0,kp=0;
    if (e/2>=n){
        op = a * n;
    }
    
    if (h/3>=n){
        cp = b * n;
    }

    if (h>=n && e >=n){
        kp = n * c;
    }
    
    for (auto it:mp){
        ll item = it.second;
        ll price = it.first;
        // cout << "ITEM " << item << endl;
        if (item == 1){
            //omlette
            if (e/2 >= n){
                total += n * price;
                n=0;
                // cout << "yay" << endl;
                break;
            }
            else{
                if (e>=2){
                    total += e/2 * price;
                    n = n - (e/2);
                    e = e%2;
                    
                    // cout << "\nN at omlette : " << n << "\nE at omlette : " << e << "\nH at omlette : " << h << endl;
                }
            }
        }
        else if(item == 2){
            //milkshake
            if (h/3 >= n){
                total+= n * price;
                n = 0;
                // cout << "yay" << endl;
                break;
            }
            else{
                if (h>=3){ 
                    total+=h/3*price;
                    n = n-(h/3);
                    h = h%3;
                    
                    // cout << "\nN at Milk : " << n << "\nE at milk : " << e << "\nH at milk : " << h << endl;
                }
            }
        }
        else if(item == 3){
            //cake
            if (e>=n && h>=n){
                total+= price * n;
                n = 0;
                // cout << "yay" << endl;
                break;
            }
            else{
                ll x = e<h?e:h;
                if (x>0){
                    total += x*price;
                    e = e-x;
                    h = h-x;
                    n = n-x;
                    // cout << "\nN at Cake : " << n << "\nE at Cake : " << e << "\nH at Cake : " << h << endl;
                }
            }
        }
    }
    if (op!=0){
        total = min(op,total);
    }
    if (cp!=0){
        total = min(cp,total);
    }
    if (kp!=0){
        total = min(kp,total);
    }
    
    if (n!=0) cout << -1;
    else cout << total;
    cout << endl;
}

int main(){
    IOS;
    ll t;
    cin >> t;
    while (t-->0) {
        
        solve();
        
    };
}