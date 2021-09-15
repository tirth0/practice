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

//Fit Squares

int squares(int b){
    if (b<4) return 0;
    if (b==4) return 1;
    int max = b/4;
    int space_left = b/2 - (b/4) * 2;
    return max*max + 2 * squares(b/2+space_left);
}

void solve(){
    int b;
    cin >> b;
    int res = squares(b);
    cout << "Result is : " << res << endl;
}

int main(){
    int t;
    cin >> t;
    while (t-->0){
        solve();
    }
    return 0;
}
