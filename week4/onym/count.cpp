#include<iostream>
#include<vector>
#include<stack>
#include<queue>
#include<cmath>
#include<algorithm>
#include<string>
#include<bitset>
#include<map>
#include<climits>
#include<set>
#include<numeric>
using namespace std; 

#define mod 1000000007
// #define gcd(a,b) __gcd(a,b)
#define lcm(a,b) (a*b)/gcd(a,b)
#define bits(x) __builtin_popcountll(x)
#define endl "\n"
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
typedef long long int ll;


int main(){
    int n;
    cin >> n;
    int half = n/2;
    vector<int> v(n);
    map<int,int> m;
    for (int i=0;i<n;i++){
        int x;
        cin >> x;
        m[x]++;
    }
    
    int maxi=INT_MIN,ind = 0;
    for (auto i:m){
        if (i.second > maxi){
            ind = i.first;
            maxi = i.second;
        }
    }
    cout << ind << endl;
    cout << maxi << endl;
}