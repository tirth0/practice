#include<iostream>
using namespace std; 

#define mod 1000000007
#define gcd(a,b) __gcd(a,b)
#define lcm(a,b) (a*b)/gcd(a,b)
#define bits(x) __builtin_popcountll(x)
#define endl "\n"
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
typedef long long int ll;

//convert neg module to pos modular eqv
int addMod(int a,int m){
    return (a%m+m)%m;
}



//product to find (a*b*c)%m where a*b*c 
//doesnt fit in long long int
int main(){
    cout << "enter the limit\n";
    IOS;
    //(a*b)%c = ((a%c)+(b%c))%c
    //the following is same as factorial
    ll n;
    cin >> n;
    ll f=1;
    for (ll i=1;i<=n;i++){
        f = ((i%mod)*(f%mod))%mod;
    }
    cout << f;
}

