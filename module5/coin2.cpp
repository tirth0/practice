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


void count(vector<int>&coins,int n,int cost){

    vector<vector<int>> dp(n+1,vector<int>(cost+1));
    for(int i=0;i<=n;i++){
        dp[i][0] = 1;
    }
    for (int i=1;i<=cost;i++){
        dp[0][i] = 0;
    }
    for (int i=1;i<=n;i++){
        for (int j=1;j<=cost;j++){
            if (j>=coins[i-1]){
                dp[i][j] = dp[i-1][j] + dp[i][j-coins[i-1]];
            }
            else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    cout << "The total number of ways : " << dp[n][cost];
}

int main(){
    IOS;
    int n;
    cin >> n;
    vector<int> coins(n);
    for (int i=0;i<n;i++)
        cin >> coins[i];
    int cost;
    cin >> cost;
    count(coins,n,cost);
}

