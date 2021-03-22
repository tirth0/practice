#include<iostream>
using namespace std; 

#define mod 1000000007
#define gcd(a,b) __gcd(a,b)
#define lcm(a,b) (a*b)/gcd(a,b)
#define bits(x) __builtin_popcountll(x)
#define endl "\n"
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
typedef long long int ll;

int main(){
    int n=5;
    float tbl[6][5] = {
        {1,0.75,0.50,0.25,0},
        {3.5597,2.7986,2.1281,1.5314,1},
        {0,0,0,0,0},
        {0,0,0,0,0},
        {0,0,0,0,0},
        {0,0,0,0,0},
    };
    for (int i=1;i<=n;i++){
            for (int j=0;j<n+1-i;j++){
                    float c = tbl[i][j]-tbl[i][j+1];
                    
                    tbl[i+1][j] = c;
                    
            }
        }
    for (int i=0;i<=n;i++){
        for (int j=0;j<n+1-i;j++){
            cout << tbl[i][j] << " ";
        }
        cout << endl;
    }
}