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



void pc(int a,map<int,int>& div){
    int i=2;
    while (a>1){
        if (a%i==0){
            div[i]++;
            a/=i;
        }
        else i++;
    }

}

void solve(){
    map<int,int> div;
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i=0;i<n;i++)
        cin >> v[i];
    
    for(auto a:v){
        pc(a,div);
    }
    bool flag = false;
    for (auto i:div){
        if (i.second%2!=0){ 
            cout << "YES" << endl;
            flag = true;
            break;
        }
    }
    if (!flag) cout << "NO" << endl;
}


int main(){
    int t;
    cin >> t;
    while (t>0){
        t--;
        solve();
    }
    return 0;
}