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

int main(){
    int n,a,b;
    cin >> n >> a >> b;
    int res = (a+b)%n==0?n:(a+b)%n;
    res = res<0?res+n:res;
    cout << res;
}