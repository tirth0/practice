#include<iostream>
#include<vector>
#include<stack>
#include<queue>
#include<cstring>
#include<algorithm>
#include<string> 
#include<map>
#include<utility> 
using namespace std; 

#define mod 1000000007
#define gcd(a,b) __gcd(a,b)
#define lcm(a,b) (a*b)/gcd(a,b)
#define bits(x) __builtin_popcountll(x)
#define endl "\n"
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
typedef long long int ll;


// void solve(){
//     int k,n;
//     cin >> n >> k;
//     vector<int> v(n);
//     multimap<int,pair<int,int>> mp;
//     int sum = 0;
//     for (int i=0,j=0;j<n;j++){
//         cin >> v[j];
//         sum+=v[j];
//         if (j-i==k-1){
//             mp.insert(make_pair(sum,make_pair(i,j)));
//             sum -=v[i];
//             i++;
//         }
//     }
//     ll cost =0;
//     for (auto k:mp){
//         int i = k.second.first;
//         int j = k.second.second;
//         int ct=0;
//         while (i<=j){
            
//             if (v[i]==1){
//                 ct++;
//                 v[i]=0;
//             }
//             i++; 
//         }
//         cost += (int) ct * (ct+1) / 2;
//     }

//     cout << cost << endl;
// }

void solve(){
    int n,k;
    
}

int main(){
    ll t;
    cin >> t;
    while (t>0){
        solve();
        t--;
    }
}