#include<iostream>
#include<vector>
#include<stack>
#include<queue>
#include<cmath>
#include<algorithm>
#include<string>
#include<bitset>
using namespace std; 

#define mod 1000000007
#define gcd(a,b) __gcd(a,b)
#define lcm(a,b) (a*b)/gcd(a,b)
#define bits(x) __builtin_popcountll(x)
#define endl "\n"
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
typedef long long int ll;

string dectobin(ll c){
    string s = bitset<64> (c).to_string(); 
    const auto loc1 = s.find('1'); 
    if(loc1 != string::npos) 
        return s.substr(loc1); 
    return "0";
    
}

void solve(ll c){
    string tg = dectobin(c);
    int l = tg.size();
    string A="",B="";
    A+= '1';B+= '0';
    bool f1 = true;
    for (int i=1;i<l;i++){
        if (tg[i]=='0'){
            A += '1';
            B+= '1';
            f1=!f1;
        }
        else{
            A+='0';
            B+='1';
        }
    }
    ll a = stoll(A,nullptr,2);
    ll b = stoll(B,nullptr,2);
    cout << a * b << endl;
}

int main(){
    int t;
    cin >> t;
    while (t>0){
        ll c;
        cin >> c;
        solve(c);
        t--;
    }
}