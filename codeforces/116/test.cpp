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
    ll n,k;
    cin >> n >> k;
    vector<ll> numbers(n);
    for (int i=0;i<(int)n;i++){
        cin >> numbers[i];
    }
    sort(numbers.begin(), numbers.end());
    for (int i=0;i<n;i++){
        cout << numbers[i] << " ";
    }
    
    
    cout << endl;
    vector<vector<ll>> dp(n,vector<ll>(n,0));
    cout << "he" << endl;
    
    for (int i = 0; i < (int)n;i ++){
        dp[0][i] = numbers[i];
    }
    set<ll> num; 
    
    for (int i = 0; i< (int)(n-1); i++){
        dp[1][i] = dp[0][i+1] - dp[0][i]; 
        if (dp[1][i]%k ==0) {
            num.insert(dp[0][i+1]);
            num.insert(dp[0][i]);
        }
    }
    ll count = 0;
    for (int i = 2; i <(int)n; i++){
        for (int j=0; j< (int)(n - i); j++){
            dp[i][j] = dp[i-1][j] + dp[1][i+j-1];
            if (dp[i][j]%k == 0){
               
                num.insert(dp[0][j]);
                num.insert(dp[0][i+j]);
            }
        }
    }
    for (int i = 0; i < n;i++){
        for (int j=0 ;j <n-i;j++){
            cout << dp[i][j] <<  " ";
        }
        cout << endl;
    }
    
    for (auto i : num) cout << i << " ";
    cout << endl;
   
    cout << num.size() ;
}

int main() {
    int t;
    cin >> t;
    while (t-->0){
        solve();
    }
}
