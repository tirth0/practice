#include<bits/stdc++.h>
using namespace std; 

#define mod 1000000007
#define gcd(a,b) __gcd(a,b)
#define lcm(a,b) (a*b)/gcd(a,b)
#define bits(x) __builtin_popcountll(x)
#define endl "\n"
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
typedef long long int ll;

//hackerrank in a string hackkerrank
void solve(string str,int N){
    int i=0,j=0;
    string pat = "hackerrank";
    int M = pat.length()-1;
    while(i<N){
        if (j == M) break;
        if (pat[j] == str[i]){
            j++;
            
        }
        
        i++;
    }
    if (j==M) cout << "YES" << endl;
    else cout << "NO" << endl;
    
}

int main(){
    IOS;
    int n;
    cin >> n;
    while (n>0){
        string inp;
        cin >> inp;
        
        int k = inp.length();
        
        solve(inp,k-1);
        n--;
    }
}
