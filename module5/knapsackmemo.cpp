//Source Geeks For Geeks

#include<iostream>

using namespace std;

int knapSackRec(int W,int wt[],int val[],int i,int ** dp){
    if (i<0) return 0;
    if (dp[i][W]!=-1) return dp[i][W];

    if (wt[i]<=W){
        dp[i][W] = max(val[i]+knapSackRec(W-wt[i], wt ,val, i-1,dp),knapSackRec(W,wt,val,i-1,dp));
        return dp[i][W];
    }
    else{
        dp[i][W] = knapSackRec(W,wt,val,i-1,dp);
        return dp[i][W];
    }
}

int main(){
    int n;
    cin >> n;
    int w;
    cin >> w;
    int **dp = new int*[n];
    for (int i=0;i<n;i++){
        dp[i] = new int[w+1];
    }
    int *val = new int[n];
    int *wt = new int[n];
    for (int i=0;i<n;i++){
        cin >> val[i];
    }
    
    for (int i=0;i<n;i++){
        cin >> wt[i];
    }

    for (int i=0;i<n;i++){
        for (int j=0;j<=w;j++){
            dp[i][j] = -1;
        }
    }
    cout << knapSackRec(w,wt,val,n-1,dp);
}
