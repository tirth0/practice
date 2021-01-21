#include<iostream>
using namespace std;

void solve(int w,int h, int f){
    int count = 1;
    while (w%2==0){
        w=w/2;
        count = 2 * count;
    }
    while (h%2==0){
        h=h/2;
        count = 2 * count;
    }
    if (f <= count) cout << "YES" << endl;
    else cout << "NO" << endl;
}

int main(){
    int t;
    cin >> t;
    while(t>0){
        int w,h,f;
        cin >> w >> h >> f;
        solve(w,h,f);
        t--;
    }
    return 0;
}