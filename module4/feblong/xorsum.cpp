#include<iostream>
#include<vector>
#include<set>
#include<queue>
#include<algorithm>
#include<string> 
#include<map>
#include<utility> 
#include<stack>
using namespace std; 

#define mod 998244353
#define gcd(a,b) __gcd(a,b)
#define lcm(a,b) (a*b)/gcd(a,b)
#define bits(x) __builtin_popcountll(x)
#define endl "\n"
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
typedef long long int ll;


//didn't work lol but still gg

vector<int> memo(1000000,-1);

ll sumStk(vector<pair<int,int>> & stk){
    ll sum=0;
    for (auto i : stk){
        sum = sum ^ i.first;
        
    }
    
    return sum;
}

void solve(vector<int> v){
    IOS;
    int m;
    cin >> m;
    ll gsum=0;
    if (memo[1]==-1){
        for (auto i:v){
            gsum = (gsum%mod + i%mod)%mod;
        }
    }
    else gsum = memo[1];
    for (int i=2;i<=m;i++){
        ll rsum = 0,k=0,k2=0;vector<pair<int,int>> stk;
        stk.push_back(make_pair(v[k],k));
        if (memo[i]!=-1){
            // cout << memo[i] << " @ " << i << endl;
            gsum = memo[i];
        } 
        else{
            while(!stk.empty()){
                if (stk.size()<i && k!=v.size()-1){
                    stk.push_back(make_pair(v[++k],k));
                }
                else if(stk.size() == i){
                    rsum = sumStk(stk);
                    gsum = (gsum%mod + rsum%mod)%mod;
                    k = stk[stk.size()-1].second;
                    stk.pop_back();
                }
                else if(k == v.size()-1){
                    k = stk[stk.size()-1].second;
                    stk.pop_back();
                    if (stk.size() == 0 && k!=v.size()-1) stk.push_back(make_pair(v[++k],k));
                }
            }
            memo[i] = gsum;
        }
        
    }
    cout << gsum << endl;
}   


int main(){
    IOS;
    int n,q;
    cin >> n;
    vector<int> v(100);
    for (int i=0;i<100;i++){
        v[i]=i;
    }
    cin >> q;
    while (q>0){
        solve(v);
        q--;
    }
}