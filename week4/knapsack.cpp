//Fractional Knapsack problem
#include<iostream>
#include<vector>
#include<stack>
#include<queue>
#include<algorithm>
using namespace std; 

#define mod 1000000007
#define gcd(a,b) __gcd(a,b)
#define lcm(a,b) (a*b)/gcd(a,b)
#define bits(x) __builtin_popcountll(x)
#define endl "\n"
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
typedef long long int ll;

using namespace std;

struct Item{
    int val,wt;
    Item()=default;
    Item(int val,int wt){
        this->val = val;
        this->wt = wt;
    }
};

bool cmp(Item a,Item b){
    double r1 =(double)a.val/(double)a.wt;
    double r2 =(double)b.val/(double)b.wt;
    return r1>r2;
}

double fractionalKnapsack(int W, Item arr[],int n){
    sort(arr,arr+n,cmp);

    int curWt = 0;
    double finalVal = 0.0;
    
    for (int i=0;i<n;i++){
        if (curWt + arr[i].wt <= W){
            curWt += arr[i].wt;
            finalVal += arr[i].val;
        }
        else{
            int remain = W - curWt;
            finalVal += arr[i].val *((double)remain/(double)arr[i].wt);
            break;
        }
    }
    return finalVal;
}

int main(){
    int W=50;
    Item arr[] = {{60,10},{100,20},{120,30}};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout << "Maximum Obtainable Value : " << fractionalKnapsack(W,arr,n);
    return 0;
}