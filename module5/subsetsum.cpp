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

void solve(vector<int> set,int n,int sum){
    vector<vector<bool>> subset(n+1,vector<bool>(sum+1,false));
   for (int i=0;i<=n;i++){
       subset[i][0] = true;
   } 
   for (int i=1;i<=n;i++){
       for (int j=1;j<=sum;j++){
           if (j<set[i-1]){
               subset[i][j] = subset[i-1][j];
           }
           else{
               subset[i][j] = subset[i-1][j] || subset[i-1][j-set[i-1]];
           }
       }
   }
   if (subset[n][sum]) cout << "YES" <<endl;
   else cout << "NO" << endl;
}

int main(){
    //write driver code to run program
    return 0;
}