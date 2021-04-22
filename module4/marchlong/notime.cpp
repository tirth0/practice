#include<iostream>
#include<vector>
#include<stack>
#include<queue>
#include<algorithm>
using namespace std; 

#define mod 1000000007
#define gcd(a,b) __gcd(a,b)
#define lcm(a,b) (a*b)/gcd(a,b)
#define bits(x) __builtin_popcountll(x)
#define endl "\n"
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
typedef long long int ll;

int main(){
    int n,h,x;
    bool flag = false;
    cin >> n >> h >> x;
    vector<int> v(n);
    for (int i=0;i<n;i++){
        int t;
        cin >> t;
        if (t+x>=h){
            flag = true;
            break;
        }
    }
    if (flag) cout << "YES";
    else cout << "NO";
    return 0;
}