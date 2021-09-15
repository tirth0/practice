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

void solve(string s){
    s+='0';
    int one=0,group = 0;
    for (int i=0;i<s.size();i++){
        int n = s[i]-'0';
        if (n == 0){
            if (one>=1) group ++;
            one = 0;
        }
        if (n==1) one++;
    }
    cout << group << endl;
}

int main(){
    int t;
    cin >> t;
    for (int i=0;i<t;i++){
        string s;
        cin >> s;
        solve(s);
    }

}