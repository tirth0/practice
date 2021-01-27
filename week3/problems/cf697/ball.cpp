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

using namespace std;
#define int long long
using namespace std;
signed main(){
  int t;cin>>t;
  while(t--){
    int a,b,k,ans;cin>>a>>b>>k;
    ans=k*(k-1)/2;
    vector<int>A(a),B(b);
    for(int i=0;i<k;i++){
      int x;cin>>x;
      ans-=(A[--x]++);
    }
    for(int i=0;i<k;i++){
      int x;cin>>x;
      ans-=(B[--x]++);
    }
    cout<<ans<<endl;
  }
}