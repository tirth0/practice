#include<vector>
#include<iostream>

using namespace std;

void solve(vector<vector<int>>& v, int m, int n){
    vector<vector<int>> dp(m, vector<int>(n, 0));
    dp[0][0] = v[0][0];
    for (int i=1;i<m;i++){
        dp[i][0] = dp[i-1][0] + v[i][0];
    }
    for (int j=1;j<m;j++){
        dp[0][j] = dp[0][j-1] + v[0][j];
    }

    for (int i=1;i<m;i++){
        for (int j=1; j<n;j++){
            dp[i][j] = v[i][j] + min(dp[i-1][j], dp[i][j-1]);
        }
    }

    cout << dp[m-1][n-1];
}


int main(){
    int m,n;
    cout << "Enter Number of Rows and Number of Columns"  << "\n";
    cin >> m >> n;
    vector<vector<int>> v(m, vector<int>(n,0));
    for (int i =0;i<m;i++){
        for (int j=0;j<n;j++){
            cin >> v[i][j];
        }
    }

    
    //  for (int i =0;i<m;i++){
    //     for (int j=0;j<n;j++){
    //         cout << v[i][j];
    //     }
    // }
    solve(v, m ,n);
}