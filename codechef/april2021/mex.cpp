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
#include<climits>
using namespace std; 

#define mod 1000000007
#define gcd(a,b) __gcd(a,b)
#define lcm(a,b) (a*b)/gcd(a,b)
#define bits(x) __builtin_popcountll(x)
#define endl "\n"
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
typedef long long int ll;

set<int> subseq;

void getSubSeqRec(string str, int n,
                    int index = -1, string curr = "")
{
    // base case
    if (index == n)
        return;
 
    if (!curr.empty()) {
        int i=0;
        if (curr.size()>1){
            for (i=0;i<curr.size();i++){
                if (curr[i]=='1') break;
            }
        }
        string str = curr.substr(i);
        if (str!="")
            subseq.insert(stoi(str,0,2));
    }
 
    for (int i = index + 1; i < n; i++) {
        
        curr += str[i];
        getSubSeqRec(str, n, i, curr);
 
        // backtracking
        curr = curr.erase(curr.size() - 1);
    }
    return;
}

void solve(){
    set<int> st = {};
    subseq = st; 
    string s;
    cin >> s;
    int  n = s.size();
    getSubSeqRec(s,n);
    int i=0;
    for (auto j:subseq){
        if (j!=i){break;}
        i++;
    }
    cout << i << endl;
}

int main(){
    int t;
    cin >> t;
    while (t>0){
        t--;
        solve();
    }
    return 0;
}