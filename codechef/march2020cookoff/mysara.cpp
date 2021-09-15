#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 9;
const int mod = 1e9 + 7; 
 
inline int mul(int a, int b) {return (a * 1LL * b) % mod;}
 
int ara[maxn];
 
int bigMod(int n, int k)
{
    if(k == 0) return 1;
    int val = bigMod(n, k / 2);
    val = mul(val, val);
    if(k&1) val = mul(val, n);
    return val;
}
 
int main()
{
    int t, cs = 1;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int ans = 1;
        scanf("%d", &ara[1]);
        for(int i = 2; i <= n; i++){
            scanf("%d", &ara[i]);
            if((ara[i] & ara[i - 1]) != ara[i - 1]) ans = mul(ans, 0);
            else ans = mul(ans, bigMod(2, __builtin_popcount(ara[i - 1])));
        }
        printf("%d\n", ans);
    }
 
    return 0;
}