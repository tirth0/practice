#include<bits/stdc++.h>
using namespace std; 

#define mod 1000000007
#define gcd(a,b) __gcd(a,b)
#define lcm(a,b) (a*b)/gcd(a,b)
#define bits(x) __builtin_popcountll(x)
#define endl "\n"
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
typedef long long int ll;

//hackkerrank repeated str

ll findA(string s){
    int i =0, j = s.length()-1;
    ll count = 0;
    while(i<=j){
        if (i == j){
            if (s[i] == 'a') count++;
        }
        else{
            if (s[i] == 'a') count++;
            if (s[j] == 'a') count++;
        }
        i++;j--;
    }
    return count;
}

void solve(string s,ll n){
    ll count = findA(s);
    ll l = s.length();
   
    ll n1 = n/l, n2 = n%l;
    
    count *= n1;
    if (n2!=0){
        string newst = s.substr(0,n2);
        count += findA(newst);
    }
    cout << count;
    
}

int main(){
    IOS;
    string s;
    cin >> s;
    ll n;
    cin >> n;
    
    solve(s,n);
    return 0;
}
