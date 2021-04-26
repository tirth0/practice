#include<iostream>
#include<vector>
using namespace std;

int knapsack(int W,int wt[],int val[],int n){
    int i,j;
    vector<vector<int>> dp(n+1,vector<int>(W+1));
    for (i=0;i<=n;i++){
        for (j=0;j<=W;j++){
            if (i==0 || W==0)
                dp[i][j] = 0;
            else if(wt[i-1]<=j){
                dp[i][j] = max(val[i-1]+dp[i-1][j-wt[i-1]],dp[i-1][j]);
            }
            else
                dp[i][j] = dp[i-1][j];
        }
    }
}

int main(){
    int n;
    cin >> n;
    int *wt = new int[n];
    int *price = new int[n];
    //Take Inputs
    int w;
    cin >> w; 
    cout << knapsack(w,wt,price,n);
    return 0;
}

