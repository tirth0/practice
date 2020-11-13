//program to find the modulo multiplicative inverse
//using Extended Euclid's theorem
#include<iostream>
using namespace std;

int modInverse(int a,int m){
    int m0 = m;
    int y=0,x=1;
    if (m==1) return 0;
    while (a>1){
        //q is quotient
        int q = a/m;
        int t=m;
        //m is remainder now

        m = a%m; a = t;
        t=y;
        //update x and y
        y = x-q*y;
        x = t;
    }
    if (x<0)
        if (x < 0) x+=m0;
    return x;
}

int main(){
    int a,m;
    cout << "Enter a and m";
    cin >> a >> m;
    int res = modInverse(a,m);
    if (res == 0) cout << "modulo multiplicative inv not possible";
    else cout << res;
    return 0;
}