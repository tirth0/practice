#include<iostream>
#include<vector>

using namespace std;

int knapsack(int wt[],int profit[],int w,int n){
    if (n==0 || w==0) return 0;
    if (wt[n]>w)
        return knapsack(wt,profit,w,n-1);
    else
        return max(knapsack(wt,profit,w,n-1), profit[n] + knapsack(wt,profit,w-wt[n],n-1));
}

int main(){
    int n;
    cin >> n;
    int *wt = new int[n];
    int *price = new int[n];
    //take inputs
    int w;
    cin >> w; 
    cout << knapsack(wt,price,w,n);
    return 0;
}