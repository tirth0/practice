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

void solve(){
    int n;
    cin >> n;
    string s;
    cin >> s;
    string s1="",s2="";
    int i=0;
    bool flag=false;
        if (s[0]=='2'){
            int k = n-3;
                if (s[k]=='0' && s[k+1]=='2' && s[k+2]=='0'){
                    flag = true;
                    
                }   
        }
        if (s[0]=='2' && s[1]=='0'){
            int k = n-2;
                if (s[k]=='2'&& s[k+1]=='0'){
                    flag = true;
                    
                }
        }
        if (s[0]=='2' && s[1]=='0' && s[2]=='2'){
                if (s[n-1]=='0'){
                    flag = true;
                    
                } 
        } 
    if (s.substr(0,4)=="2020" || s.substr(n-4,n)=="2020") flag = true;  
    if (flag) cout << "YES" << endl;
    else cout << "NO" << endl;
}

int main(){
    int t;
    cin >> t;
    while(t>0){
        t--;
        solve();
    }
}