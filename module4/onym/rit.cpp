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
    int n;string s;
    cin >> n >> s;
    
    int i=0,j;
    string temp = "";bool flag = false;
    bool f=false;
    // cout << n;
    for (j=0;j<n;j++){
        if (s[j]=='R'){
            f = true;
            temp="";
            i=j;
        }

        if (f){
            temp+=s[j];
            if (j-i==2){
                if (temp=="RIT"){
                    flag = true;
                    break;
                }
            }
        }
        
    }
    if (flag) cout << "YES" << endl;
    else cout << "NO";
}