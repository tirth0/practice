#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int &x : a) {
    cin >> x;
  }

  vector<int> dp(n);
  for (int i = n - 1; i >= 0; i--) {
    dp[i] = a[i];
    int j = i + a[i];
    if (j < n) {
      dp[i] += dp[j];
    }
  }
  cout << *max_element(dp.begin(), dp.end()) << endl;
}

int main() {
  int tests;
  cin >> tests;
  while (tests-- > 0) {
    solve();
  }
  return 0;
}


// void solve(vector<int>& a,int n){
    
//     vector<int>sum(n);
//     for (int i=n-1;i>=0;i--){
//         sum[i] = a[i];
//         int j = i + a[i];
//         if (j<n)
//             sum[i]+=a[j];
//     }
//     cout << *max_element(sum.begin(),sum.end()) << endl;
// }

// int main(){
//     int t;
//     cin >> t;
//     while(t>0){
//         int n;
//         cin >> n;
//         vector<int> a(n);
//         for (int i=0;i<n;i++){
//             cin >> a[i];
//         }
//         solve(a,n);
//         t--;
//     }
//     return 0;
// }