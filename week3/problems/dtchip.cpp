//codechef easy tag A DT CHIP
#include<iostream>
#include<vector>
#include<algorithm>
#define mod 1000000007
#define gcd(a,b) __gcd(a,b)
#define lcm(a,b) (a*b)/gcd(a,b)
#define bits(x) __builtin_popcountll(x)
#define endl "\n"
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
typedef long long int ll;

using namespace std;

void fillB(vector<vector<int>> & v, int x1,int y1,int x2,int y2){
    vector<int> v1 = {x1,y1,x2,y2};
    v.push_back(v1);
}

bool isInBlock(vector<int> & i,int x1,int y1,int x2,int y2){
    
}

string solve(vector<vector<int>> & v, int x1,int y1,int x2,int y2){
    for (auto i:v){
        for (auto j:i){
            cout << j << "\t";
        }
        cout << endl;
    }
    for (auto i : v){
        if (isInBlock(i,x1,y1,x2,y2))
            return "NO";
    }
    return "YES";
}

int main(){
    IOS;
    int n,m,q;
    
    cin >> n >> m >> q;
    vector<vector<int>> constraints;
    while(q>0){
        int t,x1,y1,x2,y2;
        cin >> t >> x1 >> y1 >> x2 >> y2;
        if (t==1) fillB(constraints,x1,y1,x2,y2);
        if (t==2) {
            cout << solve(constraints,x1,y1,x2,y2) << endl;
        }
        q--;
    }
    return 0;
}