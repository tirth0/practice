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
   ll n,m,kel2;
   cin >> n >> m >> kel2;
   vector<vector<ll>> matrix(n+1,vector<ll>(m+1,0));
//    vector<vector<int>> corr(n+1,vector<int>(m+1,0));
   for (int i=1;i<=n;i++){
       for (int j=1;j<=m;j++){
           cin >> matrix[i][j];
       }
   }
    
   for (int i=1;i<=n;i++){
       for (int j=1;j<=m;j++){
           matrix[i][j] = matrix[i][j]+matrix[i-1][j]+matrix[i][j-1]-matrix[i-1][j-1];
       }
   }
    ll c=0;

    int kkk=0;
    for (int i=1;i<=n;i++){
        for (int k=1;k<=i;k++){
            
            int high=m;
            int low = k;
            int ans = -1;
            while (low<=high){
                int mid = low + (high-low)/2;
                long double avg = (long double)(matrix[i][mid] + matrix[i-k][mid-k] - matrix[i-k][mid] - matrix[i][mid-k])/(k*k);
                // cout << "Avg at k "<< k << " at " << i << "," << mid << " is " << avg << endl;
                if (avg<kel2){
                    low = mid+1;
                }
                else{
                    ans = mid;
                    high = mid-1;
                }
            }
            if(ans == -1){
                //do absolutely nothing I'm tired as fuck man
            }
            else{
                c+=(m-ans+1);
            }
        }
    }
    cout << c << endl;
}

int main(){
    int t;
    cin >> t;
    while(t>0){
        solve();
        t--;

    }
    
}

//  ll n,m,k;
    
//     cin >> n >> m >> k;
//     vector<vector<ll>> matrix(n,vector<ll>(m));
//     for (int i=0;i<n;i++){
//         for (int j=0;j<m;j++){
//             ll x;
//             cin >> x;
//             if (j==0){
//                 matrix[i][j] = x;
//             }
//             else{
//                 matrix[i][j] = x+matrix[i][j-1];
//             }
//         }
//     }
//     // for (int i=0;i<n;i++){
//     //     for (int j=0;j<m;j++){
//     //         cout << matrix[i][j] << " ";
//     //     }
//     //     cout << endl;
//     // }
//     ll c =0;
    
//     int maxK = min(m,n);
//     vector<bool> chk(maxK,false);
//     bool flag = false;
//     for (int i=0;i<n;i++){
        
//         for (int j=0;j<m;j++){
//             vector<int> v;
//             ll kmax = min(i,j)+1;
//             ll it = 0;
//             int ct = 0;
//             // cout << "ROW " << i << " COl " << j << endl;
//             for (int it=0;it<kmax;it++){
//                 if (chk[it]) {
//                     continue;
//                     ct++;
//                 }
//                 ll r = j;
//                 ll col = i;
//                 ll sum=0;
//                 for (int jt =0;jt<=it;jt++){
//                     if (r-it-1<0){
//                         sum+=matrix[col][r];
//                     }
//                     else{
//                         // if (it == 1) cout << matrix[col][r] << " - " << matrix[col][r-it-1] << endl;
//                         sum+=matrix[col][r] - matrix[col][r-it-1];
//                     }
//                     col--;
//                 }
//                 // cout << "Sum for " << it+1 << " deg matrix is " << sum ;
                
//                 if (sum/((it+1)*(it+1) )>=k){
//                     // cout << " : YES" << endl;
//                     if(j==it){
//                         c+=(n-i)*(m-j);
//                         chk[it] = true;
//                     }
//                     else c+=1;

//                 }
//                 else {
//                     // cout << " : NO" << endl;
//                 }
//             }
//             if (ct==maxK) {
//                 flag =true;
//                 break;
//             }
//         }
//         if (flag) break;
//     }

//     cout << c << endl;