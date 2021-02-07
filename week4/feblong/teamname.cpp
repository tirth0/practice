#include<iostream>
#include<vector>
#include<stack>
#include<queue>
#include<algorithm>
#include<string> 
#include<map>
#include<utility> 
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
    vector<string> names(n);
    for (int i=0;i<n;i++){
        cin >> names[i];
    }
   
    int count=0;
    for (int i=0;i<n-1;i++){
        for (int j=i+1;j<n;j++){
            if (names[i][0] != names[j][0]){
                string s1 = names[j][0] + names[i].substr(1);
                string s2 = names[i][0] + names[j].substr(1);
                bool flag = true;
                for (int k=0;k<n;k++){
                    if (s1 == names[k] || s2 == names[k]){
                        flag = false;
                        break;
                    }
                }
                if (flag) count += 2;
            }
        }
    }
    cout << count << endl;
}

int main(){
    IOS;
    int t;cin >>t;
    while (t>0){
        solve();
        t--;
    }
    return 0;
}