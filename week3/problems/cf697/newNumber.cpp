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

using namespace std;

string solve(){
    int n;
    cin >> n;
    if (n%2020==0){
        return "YES";
    }
    if (n%2021==0){
        return "YES";
    }
    int n1 = n/2020;
    int m1 = n/2021;
    int i=1,j=m1;
    while (i<=n1 && j>0){
        if (i*2020+j*2021 > n){
            j--;
        }
        else if(i*2020 + j*2021 < n){
            i++;
        }
        else{
            return "YES";
        }
    }
    return "NO";
}

int main(){
    int t;
    cin >> t;
    while (t>0){
        t--;
        string res = solve();
        cout << res << endl;
    }
    return 0;
}
