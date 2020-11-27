#include<bits/stdc++.h>
using namespace std; 

#define mod 1000000007
#define gcd(a,b) __gcd(a,b)
#define lcm(a,b) (a*b)/gcd(a,b)
#define bits(x) __builtin_popcountll(x)
#define endl "\n"
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
typedef long long int ll;

bool sortCmp(const pair<int,int> &a,const pair<int,int> &b){
    if (a.first>b.first) return true;
    else if(a.first == b.first){
        return a.second>b.second;
    }
    else return false;
}

void solve(vector<pair<int,int>> a,int k){
    sort(a.begin(),a.end(),sortCmp);
    k = k-1;
    int s = a[k].first;
    int m1=k,cnt=0,m2 = k-1;
    while(a[m1++].first==s) cnt++;
    while(a[m2--].first==s) cnt++;
    cout << cnt;
}
    


int main(){
    int n,k;
    IOS;
    cin >> n >> k;
   vector<pair<int,int>> inp;
   while (n>0){
       int x,y;
       cin >> x >> y;
       inp.push_back(make_pair(x,y));
       n--;
   }
   solve(inp,k);
}
    