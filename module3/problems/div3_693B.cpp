#include<iostream>
#include<vector>
using namespace std;

void solve(int c1,int c2){
    
    if ((c1+2*c2)%2!=0) cout << "NO" << endl;
    else{
        int sum = (c1+2*c2);
        sum/=2;
        if (sum%2 == 0 || (c1 != 0)){
            cout << "YES" << endl;
        }
        else cout << "NO" << endl;
    }

}


int main(){
    int t;
    cin >> t;
    while(t>0){
        int c;
        cin >> c;
        int c1=0,c2=0;
        for (int i=0;i<c;i++){
            int x;cin >> x;
            x%2==0?c2++:c1++;
        }
        solve(c1,c2);
        t--;
    }
    return 0;
}