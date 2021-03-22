#include<iostream>
#include<vector>
#include<stack>
#include<queue>
#include<cstring>
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
    string str;
    cin >> str;
    int i=0,j=0;
    string res = "";
    string temp1 = "";
    string temp2 = "";
    bool flag = false;
    while (j<str.size()){
        if (str[j] == 'p'){
            flag = true;
            i=j;
            res+=temp1;
            temp1="";
        }
        if (!flag){
            res += str[j++];
        }
        else{
            temp1+=str[j++];
            if (j-i==5){
                if (temp1 == "party") res+="pawri";
                else res+=temp1;
                flag = false;
                i=j;
                temp1="";
            }
            
        }
    }
    if (temp1!="") res+=temp1;
    cout << res << endl;

}

int main(){
    int t;
    cin >> t;
    while(t>0){
        t--;
        solve();
    }
}