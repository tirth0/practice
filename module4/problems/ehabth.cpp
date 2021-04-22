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
    IOS;
    // int n;
    // cin >> n;
    // n=2*n;
    // vector<int> v(n);
    // for (int i=0;i<n;i++){
    //     cin >> v[i];
    // }
    // vector<int> o = v;
    
    // sort(v.begin(),v.end());
    // bool flag=false;
    // for (int i=0;i<n;i++){
    //     if (v[i]!=o[i]){
    //         flag = true;
    //         break;
    //     }
    // }
    // if (!flag) cout << -1<<endl;
    // else
    //     for (auto i:v){
    //         cout << i << " ";
    //     }
    int n;
    cin >> n;
    n = 2*n;
    vector<int> v(n);
    set<int> s;
    for (int i=0;i<n;i++){
        cin >> v[i];
        s.insert(v[i]);
    }
    if (s.size()==1) cout << -1;
    else {
        sort(v.begin(),v.end());
        for (auto i:v){
            cout << i << " ";
        }
    }
    cout <<endl;
}