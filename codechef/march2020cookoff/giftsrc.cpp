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
    int x=0,y=0;
    s = s;
    int j=0;
    
    int ax = 0;
    if (s[j]=='L' ){
        x-=1;
        ax=1;
    }
    else if (s[j]=='R'){
        x+=1;
        ax=1;
    }
    else if(s[j]=='U'){
        y+=1;
        ax=0;
    }
    else if(s[j]=='D'){
        y-=1;
        ax=0;
    }
    j++;
    while (j<n){
        int currax = (s[j]=='U' || s[j]=='D')?0:1;
        if (currax!=ax){
            if (s[j]=='L' ){
                x-=1;
                ax=currax;
            }
            else if (s[j]=='R'){
                x+=1;
                ax=currax;
            }
            else if(s[j]=='U'){
                y+=1;
                ax=currax;
            }
            else if(s[j]=='D'){
                y-=1;
                ax=currax;
            }
        }
        j++;
    }
    cout << x << " " << y << endl;
}

int main(){
    int t;
    cin >> t;
    while (t>0){
        t--;
        solve();
    }
}