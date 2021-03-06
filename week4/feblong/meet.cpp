#include<iostream>
#include<vector>
#include<stack>
#include<queue>
#include<algorithm>
#include <string> 
using namespace std; 

#define mod 1000000007
#define gcd(a,b) __gcd(a,b)
#define lcm(a,b) (a*b)/gcd(a,b)
#define bits(x) __builtin_popcountll(x)
#define endl "\n"
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
typedef long long int ll;

struct tim{
    int hours;
    int min;
    string ap;
};

tim construct(string P1,string P2){
    char h1 = P1[0];
    char h0 = P1[1];
    char m1 = P1[3];
    char m0 = P1[4];
    // cout << "tim being constructed is " << (int)h1 << (int)h0 << ":" << (int)m1 << (int)m0 << P2 << endl;
    int hour = ((int)h1-48)*10 + ((int)h0-48);
    int min = ((int)m1-48)*10 + ((int)m0-48);
    if (P2 == "AM" && hour == 12) hour-=12;
    if (P2 == "PM" && hour!=12) hour+=12;
    cout << hour << ":" <<  min << endl;
    tim t = {hour,min};
    return t;
}

bool cmp_tim(tim A,tim B){
    if (A.hours == B.hours && A.min == B.min) return true;
    return false;
}

bool timeCmp(tim A,tim B){
    int a = A.hours*100 + A.min;
    int b = B.hours*100 + B.min;
    if (a>b)
        return true;
    return false;
}


bool cmp(tim P,tim A,tim B){
    int i = A.hours, j = A.min;
    tim iter = {i,j};
    if (cmp_tim(P,A) || cmp_tim(P,B)) return true;
    if (timeCmp(P,A) && timeCmp(B,P)) return true;
    return false;
}


void solve(){
    string P1,P2;
    cin >> P1 >> P2;
    tim P = construct(P1,P2);
    int x;
    cin >> x;
    string res="";
    while (x>0){
        string A1,B1,C1,D1;
        cin >> A1 >> B1 >> C1 >> D1;
        tim A = construct(A1,B1);
        tim B = construct(C1,D1);
        if (cmp(P,A,B)) res+="1";
        else res+="0";
        x--;
    }
    cout << res << endl;
}

int main(){
    int n;
    cin >> n;
    while (n>0){
        solve();
        n--;
    }
    return 0;
}